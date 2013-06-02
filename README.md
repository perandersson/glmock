glmock
======

Mock framework for OpenGL application

### How does it work?

By linking with this framework instead of for example OpenGL32.lib we can highjack all OpenGL calls to the mock framework. We then build a chain of commands that we are expecting.
The purpose of this framework is NOT to test if OpenGL works in your application but rather to test if the application is doing as you think it does. If you are uncertain of why
we use mock frameworks then please read this: http://en.wikipedia.org/wiki/Mock_object

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
