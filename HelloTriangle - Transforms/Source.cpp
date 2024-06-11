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

#include "Sprite.h"

#include <stdlib.h>

enum directions {NONE = -1, LEFT, RIGHT, UP, DOWN};


// Protótipo da função de callback de teclado
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Dimensões da janela (pode ser alterado em tempo de execução)
const GLuint WIDTH = 800, HEIGHT = 600;

//Variáveis globais

int dir = NONE;

// Função MAIN
int main()
{
	// Inicialização da GLFW
	glfwInit();
	srand(glfwGetTime());

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
	glViewport(0, 0, width, height);
	


	// Compilando e buildando o programa de shader

	Shader shader("HelloTriangle.vs","HelloTriangle.fs");

    //Habilita o shader que sera usado (glUseProgram)
	shader.Use();

	//Criação de um objeto Sprite
	Sprite sprite, sprite2, sprite3, background, ground, sprite4, quadradinho, quadrado;
    sprite.inicializar(glm::vec3(400.0,300.0,0.0), glm::vec3(200.0,200.0,1.0),0.0,glm::vec3(0.2, 0.0, 0.0));
	sprite.setShader(&shader);

	sprite2.inicializar(glm::vec3(200.0,300.0,0.0), glm::vec3(100.0,50.0,1.0));
	sprite2.setShader(&shader);

	sprite3.inicializar(glm::vec3(600.0,300.0,0.0), glm::vec3(50.0,100.0,1.0),0.0,glm::vec3(0.0, 0.0, 0.2));
	sprite3.setShader(&shader);

	background.inicializar(glm::vec3(400.0,300.0,0.0), glm::vec3(800.0,600.0,1.0),0.0,glm::vec3(0.8, 0.0, 0.5));
	background.setShader(&shader);

	ground.inicializar(glm::vec3(400.0,100.0,0.0), glm::vec3(800.0,200.0,1.0),0.0,glm::vec3(0.8, 0.5, 0.0));
	ground.setShader(&shader);

	sprite4.inicializar(glm::vec3(200.0,500.0,0.0), glm::vec3(100.0,100.0,1.0),45.0,glm::vec3(0.8, 0.5, 0.0));
	sprite4.setShader(&shader);

	//quadrado.inicializar(glm::vec3(400,300,0.0), glm::vec3(80.0,80.0,1.0),0.0);
	//quadrado.setShader(&shader);

    glm::mat4 projection = glm::ortho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
	//Enviando para o shader via variável do tipo uniform (glUniform....)
	shader.setMat4("projection",glm::value_ptr(projection));

	glm::vec3 cor [6][6];

	for (int colunadois = 0; colunadois < 6; colunadois++)
	{
		for (int linhadois = 0; linhadois < 6; linhadois++)
		{
		    cor[linhadois][colunadois].r = rand() % 256 /255.0;
			cor[linhadois][colunadois].g = rand() % 256 /255.0;
			cor[linhadois][colunadois].b = rand() % 256 /255.0;
		}
	}

	// Loop da aplicação - "game loop"
	while (!glfwWindowShouldClose(window))
	{
		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as funções de callback correspondentes
		glfwPollEvents();

		//Verifica flags para movimentação do personagem
		if (dir == LEFT)
		{
			quadrado.moveLeft();
		}
		else if (dir == RIGHT)
		{
			quadrado.moveRight();
		}
		else if (dir == UP)
		{
			quadrado.moveUp();
		}
		else if (dir == DOWN)
		{
			quadrado.moveDown();
		}

		// Limpa o buffer de cor
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //cor de fundo
		glClear(GL_COLOR_BUFFER_BIT);

		float angulo = (float)glfwGetTime();
		sprite4.setAngulo(glm::degrees(angulo));

        float linha = 10.0;
		float coluna = 590.0;

        //Conjunto para a construção da grid
		//for (int colunadois = 0; colunadois < 6; colunadois++)
		//{
		//	float coluna = 590.0;
		//	for (int linhadois = 0; linhadois < 6; linhadois++)
		//	{
		//        quadradinho.inicializar(glm::vec3(linha,coluna,0.0), glm::vec3(20.0,20.0,1.0),0.0,cor[linhadois][colunadois]);
	    //        quadradinho.setShader(&shader);
		//	    quadradinho.desenhar();
		//		coluna -= 20.0;
		//	}
		//	linha += 20.0;
		//}

		//quadrado.desenhar();

		background.desenhar();
		sprite.desenhar();
        sprite2.desenhar();
		sprite3.desenhar();
		ground.desenhar();
		sprite4.desenhar();

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

	if (key == GLFW_KEY_A)
	{
        dir = LEFT;
	}
	if (key == GLFW_KEY_D)
	{
        dir = RIGHT;
	}
	if (key == GLFW_KEY_W)
	{
        dir = UP;
	}
	if (key == GLFW_KEY_S)
	{
        dir = DOWN;
	}

	if (action == GLFW_RELEASE)
	{
		dir = NONE;
	}
}

