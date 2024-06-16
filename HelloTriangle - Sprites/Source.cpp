/* Hello Triangle - código adaptado de https://learnopengl.com/#!Getting-started/Hello-Triangle 
 *
 * Adaptado por Rossana Baptista Queiroz
 * para a disciplina de Processamento Gráfico - Unisinos
 * Versão inicial: 7/4/2017
 * Última atualização em 14/08/2023
 *
 */

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>

//Classe que gerencia os shaders
#include "Shader.h"

//GLM
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//STB_IMAGE
#include <stb_image.h>

#include "Sprite.h"

//#include "Timer.h"


// Protótipo da função de callback de teclado
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

GLuint loadTexture(string filePath, int &imgWidth, int &imgHeight);
bool CheckCollision(Sprite &one, Sprite &two);

// Dimensões da janela (pode ser alterado em tempo de execução)
const GLuint WIDTH = 800, HEIGHT = 600;

// Função MAIN
int main()
{
	// Inicialização da GLFW
	glfwInit();

	//Muita atenção aqui: alguns ambientes não aceitam essas configurações
	//Você deve adaptar para a versão do OpenGL suportada por sua placa
	//Sugestão: comente essas linhas de código para desobrir a versão e
	//depois atualize (por exemplo: 4.5 com 4 e 5)
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

	//Essencial para computadores da Apple
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif

	// Criação da janela GLFW
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ola Triangulo! -- Caroline Moro", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Fazendo o registro da função de callback para a janela GLFW
	glfwSetKeyCallback(window, key_callback);

	// GLAD: carrega todos os ponteiros d funções da OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

	}

	// Obtendo as informações de versão
	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
	cout << "Renderer: " << renderer << endl;
	cout << "OpenGL version supported " << version << endl;

	// Definindo as dimensões da viewport com as mesmas dimensões da janela da aplicação
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, 400, 300);

    //Habilitando a  transparência
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Habilitando o teste de profundidade
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);
	


	// Compilando e buildando o programa de shader

	Shader shader("HelloTriangle.vs","HelloTriangle.fs");

    //Habilita o shader que sera usado (glUseProgram)
	shader.Use();

    int imgWidth, imgHeight;
	GLuint texID = loadTexture("../Textures/Enchantress/Idle.png", imgWidth, imgHeight);

	//Criação de um objeto Sprite
	Sprite princesa, estrelaum, estreladois, estrelatres, estrelaquatro, estrelacinco, estrelaseis, background, chao, sprite4, historia;
    princesa.inicializar(texID,1,5,glm::vec3(400.0,216.0,0.0), glm::vec3(imgWidth,imgHeight,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	princesa.setShader(&shader);

	texID = loadTexture("../Textures/Star.png", imgWidth, imgHeight);

	estrelaum.inicializar(texID,1,13,glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0),glm::vec3(imgWidth*1.2,imgHeight*1.2,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	estrelaum.setShader(&shader);

	estreladois.inicializar(texID,1,13,glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0),glm::vec3(imgWidth*1.2,imgHeight*1.2,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	estreladois.setShader(&shader);

	estrelatres.inicializar(texID,1,13,glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0),glm::vec3(imgWidth*1.2,imgHeight*1.2,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	estrelatres.setShader(&shader);

	estrelaquatro.inicializar(texID,1,13,glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0),glm::vec3(imgWidth*1.2,imgHeight*1.2,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	estrelaquatro.setShader(&shader);

	estrelacinco.inicializar(texID,1,13,glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0),glm::vec3(imgWidth*1.2,imgHeight*1.2,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	estrelacinco.setShader(&shader);

	estrelaseis.inicializar(texID,1,13,glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0),glm::vec3(imgWidth*1.2,imgHeight*1.2,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	estrelaseis.setShader(&shader);

	GLuint texID2 = loadTexture("../Textures/PNG/game_background_3/game_background_3. 2.png", imgWidth, imgHeight);

	background.inicializar(texID2,1,1,glm::vec3(400.0,300.0,0.0), glm::vec3(imgWidth/1.8,imgHeight/1.8,1.0),0.0,glm::vec3(0.8, 0.0, 0.5));
	background.setShader(&shader);

	GLuint texID3 = loadTexture("../Textures/chao.png", imgWidth, imgHeight);

	chao.inicializar(texID3,1,1,glm::vec3(400.0,50.0,0.0), glm::vec3(imgWidth*2.0,imgHeight*2.0,1.0),0.0,glm::vec3(0.8, 0.0, 0.5));
	chao.setShader(&shader);

	GLuint texID4 = loadTexture("../Textures/historia.png", imgWidth, imgHeight);

	historia.inicializar(texID4,1,1,glm::vec3(400.0,300.0,0.0), glm::vec3(imgWidth,imgHeight,1.0),0.0,glm::vec3(0.8, 0.0, 0.5));
	historia.setShader(&shader);

	glm::mat4 projection = glm::ortho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
	//Enviando para o shader via variável do tipo uniform (glUniform....)
	shader.setMat4("projection",glm::value_ptr(projection));

	glActiveTexture(GL_TEXTURE0);
	shader.setInt("texBuffer", 0);

	//Timer timer;

	float x = 400.0;

    float valor = 0.0;
	float lastTime = 0.0;
	float FPS = 60.0;

	int numero = 0;
	int conjuntodeestrela = 0;
	 

	// Loop da aplicação - "game loop"
	while (!glfwWindowShouldClose(window))
	{
		float now;
		float dt;
		do {
			now = (float)glfwGetTime();
			dt =  now - lastTime;
		} while (dt < 1.0 / FPS);
		lastTime = now;

		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as funções de callback correspondentes
		//timer.start();
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
		float velocity = 200.0 * dt;
        // move playerboard
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            if (x >= 64.0f)
                x -= velocity;
				princesa.setPos(glm::vec3(x,216.0,0.0));
				texID = loadTexture("../Textures/Enchantress/Walk.png", imgWidth, imgHeight);
                princesa.settexID(texID);
				princesa.setnFrames(8);
				princesa.inicializar(texID,1,8,glm::vec3(x,216.0,0.0), glm::vec3(-imgWidth,imgHeight,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
        }
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            if (x <= width - 64.0)
                x += velocity;
				princesa.setPos(glm::vec3(x,216.0,0.0));
				texID = loadTexture("../Textures/Enchantress/Walk.png", imgWidth, imgHeight);
                princesa.settexID(texID);
				princesa.setnFrames(8);
				princesa.inicializar(texID,1,8,glm::vec3(x,216.0,0.0), glm::vec3(imgWidth,imgHeight,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
        }

		if (CheckCollision(princesa,estrelaum) == true)
    	{
			estrelaum.setPos(glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0));
			conjuntodeestrela += 1;
    	}
		if (CheckCollision(princesa,estreladois) == true)
    	{
			estreladois.setPos(glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0));
			conjuntodeestrela += 1;
    	}
		if (CheckCollision(princesa,estrelatres) == true)
    	{
			estrelatres.setPos(glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0));
			conjuntodeestrela += 1;
    	}
		if (CheckCollision(princesa,estrelaquatro) == true)
    	{
			estrelaquatro.setPos(glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0));
			conjuntodeestrela += 1;
    	}
		if (CheckCollision(princesa,estrelacinco) == true)
    	{
			estrelacinco.setPos(glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0));
			conjuntodeestrela += 1;
    	}
		if (CheckCollision(princesa,estrelaseis) == true)
    	{
			estrelaseis.setPos(glm::vec3(80 + rand() % 800,600.0+32.0*1.2,0.0));
			conjuntodeestrela += 1;
    	}

		// Limpa o buffer de cor
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //cor de fundo
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float angulo = (float)glfwGetTime();
		sprite4.setAngulo(glm::degrees(angulo));

        glViewport(0, 0, 800, 600);
		glm::mat4 projection = glm::ortho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
	    //Enviando para o shader via variável do tipo uniform (glUniform....)
	    shader.setMat4("projection",glm::value_ptr(projection));
		if (numero <= 480)
        {
            historia.desenhar();
        }
		if (numero > 480)
        {
            historia.desenhar();
		    background.desenhar();
            estrelaum.desenhar();
		    estrelaum.moveItem();
			if (numero >= 600+480)
            {
                estreladois.desenhar();
			    estreladois.moveItem();
            }
		    if (numero >= 1200+480)
            {
                estrelatres.desenhar();
			    estrelatres.moveItem();
            }
		    if (numero >= 1800+480)
            {
                estrelaquatro.desenhar();
			    estrelaquatro.moveItem();
            }
		    if (numero >= 2400+480)
            {
                estrelacinco.desenhar();
			    estrelacinco.moveItem();
            }
		    if (numero >= 3000+480)
            {
                estrelaseis.desenhar();
			    estrelaseis.moveItem();
            }
		    chao.desenhar();
		    princesa.desenhar();
        }

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
			texID = loadTexture("../Textures/Enchantress/Idle.png", imgWidth, imgHeight);
		    princesa.settexID(texID);
		    princesa.setnFrames(5);
		    princesa.inicializar(texID,1,5,glm::vec3(x,216.0,0.0), glm::vec3(-imgWidth,imgHeight,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
        }
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
			if (dt < 1.0 / 4.0);
                texID = loadTexture("../Textures/Enchantress/Idle.png", imgWidth, imgHeight);
		    princesa.settexID(texID);
		    princesa.setnFrames(5);
		    princesa.inicializar(texID,1,5,glm::vec3(x,216.0,0.0), glm::vec3(imgWidth,imgHeight,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
        }
		//timer.finish();
        //double waitingTime = timer.calcWaitingTime(60, timer.getElapsedTimeMs());
        //if (waitingTime)
        //{
        //    std::this_thread::sleep_for(std::chrono::milliseconds((int)waitingTime));
        //}

		if (conjuntodeestrela == 20)
    	{
			glfwSetWindowShouldClose(window, GL_TRUE);
    	}

		if (numero == 60*150)
        {
			glfwSetWindowShouldClose(window, GL_TRUE);
        }

		numero += 1.0;

		// Troca os buffers da tela
		glfwSwapBuffers(window);
	}
	// Finaliza a execução da GLFW, limpando os recursos alocados por ela
	glfwTerminate();
	return 0;
}

// Função de callback de teclado - só pode ter uma instância (deve ser estática se
// estiver dentro de uma classe) - É chamada sempre que uma tecla for pressionada
// ou solta via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

GLuint loadTexture(string filePath, int &imgWidth, int &imgHeight)
{
	GLuint texID;

	// Gera o identificador da textura na memória 
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
    	if (nrChannels == 3) //jpg, bmp
    	{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    	}
    	else //png
    	{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    	}
    	glGenerateMipmap(GL_TEXTURE_2D);

		imgWidth = width;
		imgHeight = height;

		stbi_image_free(data);

		glBindTexture(GL_TEXTURE_2D, 0);

	}
	else
	{
    	 std::cout << "Failed to load texture" << std::endl;
	}


	return texID;
}

bool CheckCollision(Sprite &one, Sprite &two)
{
	// collision x-axis?
	bool collisionX = one.getPMax().x >= two.getPMin().x &&
	    two.getPMax().x >= one.getPMin().x;
	// collision y-axis?
	bool collisionY = one.getPMax().y >= two.getPMin().y &&
	    two.getPMax().y >= one.getPMin().y;
	// collision only if on both axes
	return collisionX && collisionY;
}

