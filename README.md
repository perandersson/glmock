glmock
======

Mock framework for OpenGL application

### How does it work?

By linking with this framework instead of the original OpenGL libraries we can highjack all OpenGL calls into the mock framework intsead. It is not possible to build a command chain of the expected function calls.

### Purpose

The purpose for this framework is NOT to test if OpenGL works in your application (i.e. if a triangle will be visible or not), but rather to test if the application is calling the OpenGL that you (the developer) is expecting.

If you are uncertain of why we use mock frameworks then please read this: http://en.wikipedia.org/wiki/Mock_object

### Example

```cpp
TestCase(MyTestCase)
{
	const GLsizei n = 1;
	const GLuint textures[1] = { 1 };

	glmock::IFramework* mock = glmock::Create();
	mock->glDeleteTextures()->Expect(n)->Result(textures);
	mock->glGetError()->Returns(GL_NO_ERROR);
	
	glDeleteTextures(n, textures);
	GLenum err = glGetError();

	glmock::Destroy(mock);
}
```
