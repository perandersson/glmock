glmock
======

Mock framework for OpenGL application

### How does it work?

By linking with this library instead of the original OpenGL libraries we can highjack all OpenGL calls into the mock framework instead. It is now possible to build a command chain of the expected function calls.

### Purpose

The purpose for this framework is NOT to test if OpenGL works in your application (i.e. if a triangle will be visible or not), but rather to test if the application is calling the OpenGL functions that you (the developer) is expecting.

If you are uncertain of why we use mock frameworks then please read this: http://en.wikipedia.org/wiki/Mock_object

### What is returned and what isn't? 

OpenGL is quite funny in this regard. Most OpenGL functions actually return a result using one of the supplied arguments instead of actually returning a value from the function. Examples are:

```cpp
GLuint textures;
glGenTextures(1, &textures);
```

```cpp
GLenum err = glGetError();
```

Both the functions above returns a value, but the first one is via the argument list instead of an actual return value. The framework assumes that all "result" parameters are actual results and not "asserts". For example:

```cpp
TestCase(MyTestCase)
{
	const GLsizei n = 1;
	const GLuint textures[1] = { 10 };

	glmock::IFramework* mock = glmock::Create();
	mock->glGenTextures(n, textures);
	
	GLuint texture;
	
	// Validates that the first parameter is 1 and sets the texture field into 10 (specified above)
	glGenTextures(n, &texture);

	glmock::Destroy(mock);
}
```

In cases where a value is actually returned then a return statement must be specified. This is usually dont using a *Returns* method. For example:

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

```cpp
TestCase(MyTestCase)
{
	const GLsizei n = 1;
	const GLuint textures[1] = { 1 };

	glmock::IFramework* mock = glmock::Create();
	mock->glDeleteTextures(n, textures);
	mock->glGetError()->Returns(GL_NO_ERROR);
	
	glDeleteTextures(n, textures);
	GLenum err = glGetError();

	glmock::Destroy(mock);
}
```
