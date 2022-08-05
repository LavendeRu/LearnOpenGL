//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
////设置屏幕的宽度/高度
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main1()
//{
//	//-------------------GLFW初始化----------------
//	glfwInit();
//	//该函数的所有的选项以及对应的值都可以在https://www.glfw.org/docs/latest/window.html#window_hints中找到
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////#ifdef __APPLE__
////	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
////#endif
//	//-------------------GLFW 窗口创建---------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	//-------------------通知GLFW将我们窗口的上下文设置为当前线程的主上下文---------------
//	glfwMakeContextCurrent(window);
//
//	//-------------------告诉OpenGL渲染窗口的尺寸大小，即视口(Viewport)-------------------
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	//---------------初始化GLAD---------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	//---------------渲染循环(Render Loop)：程序在我们主动关闭它之前不断绘制图像并能够接受用户输入。---------------
//	//glfwWindowShouldClose函数在每次循环的开始前检查一次GLFW是否被要求退出，如果是的话该函数返回true然后渲染循环便结束了，之后就可以关闭应用程序了。
//	while (!glfwWindowShouldClose(window))
//	{
//		//输入
//		processInput(window);
//
//		//清空屏幕的颜色缓冲
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		//清空屏幕所用的颜色
//		glClear(GL_COLOR_BUFFER_BIT);
//		//glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）。
//		glfwPollEvents();
//		//glfwSwapBuffers函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
//		glfwSwapBuffers(window);
//	}
//
//	//当渲染循环结束后需要正确释放/删除之前的分配的所有资源。可以在main函数的最后调用glfwTerminate函数来完成。
//	glfwTerminate();
//	return 0;
//}
//
///// <summary>
///// 在GLFW中实现一些输入控制
///// </summary>
///// <param name="window"></param>
//void processInput(GLFWwindow* window)
//{
//	//检查用户是否按下了返回键(Esc)（如果没有按下，glfwGetKey将会返回GLFW_RELEASE。
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
////当用户改变窗口的大小的时候，视口也应该被调整。我们可以对窗口注册一个回调函数(Callback Function)，它会在每次窗口大小被调整的时候被调用。
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//
//
////双缓冲(Double Buffer)
////应用程序使用单缓冲绘图时可能会存在图像闪烁的问题。 这是因为生成的图像不是一下子被绘制出来的，而是按照从左到右，由上而下逐像素地绘制而成的。
//// 最终图像不是在瞬间显示给用户，而是通过一步一步生成的，这会导致渲染的结果很不真实。
//// 为了规避这些问题，我们应用双缓冲渲染窗口应用程序。前缓冲保存着最终输出的图像，它会在屏幕上显示；
////而所有的的渲染指令都会在后缓冲上绘制。当所有的渲染指令执行完毕后，我们交换(Swap)前缓冲和后缓冲，这样图像就立即呈显出来，之前提到的不真实感就消除了。
//
//
////glClearColor函数是一个状态设置函数，而glClear函数则是一个状态使用的函数，它使用了当前的状态来获取应该清除为的颜色。
//
