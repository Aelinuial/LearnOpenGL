#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();//初始化glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//配置glfw，告诉glfw需要使用的opengl版本号为3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//配置glfw，告诉glfw需要使用的opengl版本号为3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//告诉glfw使用的是核心模式，即只能使用opengl功能的一个子集，不需要3.3之后版本的兼容功能。

	GLFWwindow* window = glfwCreateWindow(800, 600, "testOpengl", NULL, NULL);//创建窗口对象，该对象存放所有与窗口相关数据，且会被GLFW其他函数调用。
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //初始化glad
	{
		std::cout << "faild to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);//告诉opengl渲染窗口的尺寸大小，视口（-1~1）对应GLFW的（0,800）以及(0,600);该维度也可设置的比glfw小

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);// 告诉glfw，每当窗口调整大小时，调用此函数
	while (!glfwWindowShouldClose(window))//每次循环开始前检查一次GLFW是否被要求退出，若是则函数返回true，则渲染循环便结束。
	{
		processInput(window);//处理输入事件
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //设置清空屏幕所用的颜色（状态设置函数）
		glClear(GL_COLOR_BUFFER_BIT);//清楚颜色缓冲区之后，整个颜色缓冲会被填充glClearColor里所设置的颜色，深蓝绿色（状态使用函数）。
		glfwPollEvents();//检查是否触发事件（如键盘输入，鼠标移动等），更新窗口状态，并调用对应回调函数
		glfwSwapBuffers(window);//交换颜色缓冲，存储GLFW窗口没个像素颜色值的大缓冲，它在迭代中用来绘制图像，并输出到显示屏上
	}
	glfwTerminate(); //清理申请的资源，退出
	return 0;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) //调整视口大小
{
	glViewport(0, 0, width, height);
	std::cout << "viewport width:" << width << std::endl;
	std::cout << "viewport height:" << height << std::endl;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //按下escape键，关闭glfw
	{
		glfwSetWindowShouldClose(window, true);
	}
}