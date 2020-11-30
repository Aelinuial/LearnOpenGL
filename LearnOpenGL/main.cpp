#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();//��ʼ��glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//����glfw������glfw��Ҫʹ�õ�opengl�汾��Ϊ3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//����glfw������glfw��Ҫʹ�õ�opengl�汾��Ϊ3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//����glfwʹ�õ��Ǻ���ģʽ����ֻ��ʹ��opengl���ܵ�һ���Ӽ�������Ҫ3.3֮��汾�ļ��ݹ��ܡ�

	GLFWwindow* window = glfwCreateWindow(800, 600, "testOpengl", NULL, NULL);//�������ڶ��󣬸ö����������봰��������ݣ��һᱻGLFW�����������á�
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //��ʼ��glad
	{
		std::cout << "faild to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);//����opengl��Ⱦ���ڵĳߴ��С���ӿڣ�-1~1����ӦGLFW�ģ�0,800���Լ�(0,600);��ά��Ҳ�����õı�glfwС

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);// ����glfw��ÿ�����ڵ�����Сʱ�����ô˺���
	while (!glfwWindowShouldClose(window))//ÿ��ѭ����ʼǰ���һ��GLFW�Ƿ�Ҫ���˳���������������true������Ⱦѭ���������
	{
		processInput(window);//���������¼�
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //���������Ļ���õ���ɫ��״̬���ú�����
		glClear(GL_COLOR_BUFFER_BIT);//�����ɫ������֮��������ɫ����ᱻ���glClearColor�������õ���ɫ��������ɫ��״̬ʹ�ú�������
		glfwPollEvents();//����Ƿ񴥷��¼�����������룬����ƶ��ȣ������´���״̬�������ö�Ӧ�ص�����
		glfwSwapBuffers(window);//������ɫ���壬�洢GLFW����û��������ɫֵ�Ĵ󻺳壬���ڵ�������������ͼ�񣬲��������ʾ����
	}
	glfwTerminate(); //�����������Դ���˳�
	return 0;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) //�����ӿڴ�С
{
	glViewport(0, 0, width, height);
	std::cout << "viewport width:" << width << std::endl;
	std::cout << "viewport height:" << height << std::endl;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //����escape�����ر�glfw
	{
		glfwSetWindowShouldClose(window, true);
	}
}