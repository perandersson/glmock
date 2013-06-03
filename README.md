glmock (0.1 Alpha)
======

Mock framework for OpenGL application.

### How does it work?

By linking your application with this instead of the original OpenGL libraries we can highjack all OpenGL calls into this mock framework instead. This enables us to build a command chain of the expected function calls and validate those calls.

### Purpose

The purpose for this framework is **not** to test if OpenGL works in your application (i.e. if a triangle will be visible or not), but rather to test if the application is calling the OpenGL functions that you (the developer) is expecting.

If you are uncertain of why we use mock frameworks then please read this: http://en.wikipedia.org/wiki/Mock_object

### What can be expected by this framework?

This framework is not a complete TDD framework. This library only supplies functionality that gives you the power to mock OpenGL calls. If you are interested in a TDD framework for C++ then I would recommend:

http://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/index.html

Or if you are feeling really adventurous - you can try to understand/decrypt/parse my own TDD framework that I developed for my own game engine:

https://github.com/perandersson/playstate

### What is returned and what isn't? 

OpenGL is quite funny in this regard. Most OpenGL functions actually return a result using one of the supplied arguments instead of actually returning a value from the function. Examples are:

```cpp
GLuint textures;
glGenTextures(1, &textures);
```

And

```cpp
GLenum err = glGetError();
```

Both the functions above returns a value but the first example returns a value via the parameter list instead of an actual returned value. The framework assumes that all "result" parameters are actual results and will therefor not be validated. For example:

```cpp
TestCase(MyTestCase)
{
	const GLsizei n = 1;
	const GLuint textures[1] = { 10 };

	glmock::IFramework* mock = glmock::Create();
	mock->glGenTextures(n, textures);
	
	GLuint texture;
	
	// Validates that the first argument is the value "1" and then sets the texture field into 10 (as specified above)
	glGenTextures(n, &texture);

	glmock::Destroy(mock);
}
```

In cases where a value is actually returned then a return statement must be specified. This is usually done using a **Returns** method. For example:

```cpp
TestCase(MyTestCase)
{
	glmock::IFramework* mock = glmock::Create();
	mock->glGetError()->Returns(GL_NO_ERROR);
	
	// Will return GL_NO_ERROR
	GLenum err = glGetError();

	glmock::Destroy(mock);
}
```

### Example

If the mock-framework wouldn't be in use then this exampel would create a texture so that we can draw it on the screen in the future. To create a texture in OpenGL three things has to be done:

1. Generate a texture ID
2. Bind The texture
3. Fill the texture with data
4. Make sure that no errors has occured.

We know this. But it's not interesting to see if the actual texture works or not, but that we actually called the correct OpenGL commands. This is the purpose of this mock framework. 

```cpp
TestCase(MyTestCase)
{
	const GLsizei n = 1;
	const GLuint textures[1] = { 1 };
	const GLfloat width = 1;
	const GLfloat height = 1;
	const GLfloat pixels[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glmock::IFramework* mock = glmock::Create();
	mock->glGenTextures(n, textures);
	mock->glBindTexture(GL_TEXTURE_2D, textures[0]);
	mock->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_FLOAT, GL_RGBA, pixels);
	mock->glGetError()->Returns(GL_NO_ERROR);
	
	// Validates the following things:
	// 1. That the functions are called in the specified order above
	// 2. Validates the function parameters (as long as they aren't "return" values)
	// 3. Returns the value specified by the framework (using the Returns method).

	Texture* texture = new Texture2D(width, height, pixels);
	
	// The above code will do:
	//glGenTextures(n, textures);
	//glBindTexture(GL_TEXTURE_2D, textures[0]);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_FLOAT, GL_RGBA, pixels);
	//GLenum err = glGetError();

	// Releases allocated resources and validates that the functions have been invoked correctly
	glmock::Destroy(mock);
}
```
