# Fundamentos-da-Computacao-Grafica
Entregas dos exercícios

![image](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/a69c4f5c-5a6b-4349-a809-064d2ac2a526)

## Criando o ambiente de Programação
![Ola Triangulo! -- Caroline Moro 13_04_2024 00_17_51](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/4507ff93-6fdf-4e80-86b6-d20cb3543a03)

<sup>Print da execução do HelloTriangle</sup>

## Lista 1
0. Leitura OBRIGATÓRIA para começar:

    https://learnopengl.com/#!Getting-started/Hello-Triangle - Concluído

    https://learnopengl.com/#!Getting-started/Shaders - Concluído

    http://antongerdelan.net/opengl/hellotriangle.html - Concluído

    Sugere-se ainda a leitura:

    • Capítulo 2 do livro Real Time Rendering (pdf no Canvas, gerado pelo próprio
ebscohost)

    • Seção 5.1 (Etapas da Renderização) do livro Computação Gráfica - Teoria e Prática:
Geração de Imagens

1. O que é a GLSL? Quais os dois tipos de shaders são obrigatórios no pipeline programável
da versão atual que trabalhamos em aula e o que eles processam? - Concluído

2. O que são primitivas gráficas? Como fazemos o armazenamento dos vértices na OpenGL? - Concluído

3. Explique o que é VBO, VAO e EBO, e como se relacionam (se achar mais fácil, pode fazer
um gráfico representando a relação entre eles). - Concluído

4. Analise o código fonte do projeto Hello Triangle. Localize e relacione os conceitos de
shaders, VBOs e VAO apresentados até então. Não precisa entregar nada neste exercício. - Concluído

5. Faça o desenho de 2 triângulos na tela. Desenhe eles:

    a. Apenas com o polígono preenchido - Concluído

    b. Apenas com contorno - Concluído

    c. Apenas como pontos - Concluído

    d. Com as 3 formas de desenho juntas - Concluído

    i. Atualize o shader para receber uma cor de contorno - Concluído

6. Faça o desenho de um círculo na tela, utilizando a equação paramétrica do círculo para
gerar os vértices. Depois disso:

    a) Desenhe um octágono - Concluído

    b) Desenhe um pentágono - Concluído

    c) Desenhe um pac-man! - Concluído

    d) Desenhe uma fatia de pizza - Concluído

    e) DESAFIO: desenhe uma “estrela” - Concluído

7. Desenhe uma espiral, assim:

![Of - Google Chrome 04_05_2024 01_24_50](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/13981e8d-ae69-4f56-b4ee-d9abfa886d74)

8. Considerando o seguinte triângulo abaixo, formado pelos vértices P1, P2 e P3,
respectivamente com as cores vermelho, verde e azul.

    a. Descreva uma possível configuração dos buffers (VBO, VAO e EBO) para
representá-lo. - Concluído

    b. Como estes atributos seriam identificados no vertex shader? - Concluído

![Of - Google Chrome 04_05_2024 01_25_05](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/3ada3120-8820-4a87-8260-f01de15420df)

    Agora implemente!

9. Faça um desenho em um papel quadriculado (pode ser no computador mesmo) e
reproduza-o utilizando primitivas em OpenGL. Neste exercício você poderá criar mais de um
VAO e fazer mais de uma chamada de desenho para poder utilizar primitivas diferentes, se
necessário. - Concluído

![Of - Google Chrome 04_05_2024 01_25_16](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/23f79699-c1ed-4da9-a908-69e4c6e7b6d5)

10. Implemente (pode pegar do tutorial) uma classe para tratar os shaders a partir de
arquivos. - Concluído

## Lista 2
0. Leitura OBRIGATÓRIA para começar:

    • https://learnopengl.com/#!Getting-started/Transformations - Concluído

    • https://learnopengl.com/#!Getting-started/Coordinate-Systems - Concluído
   
    • https://learnopengl.com/In-Practice/2D-Game/Rendering-Sprites (primeira
parte que fala da projeção ortográfica (explica o exercício 2) - Concluído

1. Modifique a janela do mundo (window/ortho) para os limites: xmin=-10, xmax=10,
ymin=-10, ymax=10. - Concluído

2. Agora modifique para: xmin=0, xmax=800, ymin=600, ymax=0. - Concluído

   
3. Utilizando a câmera 2D do exercício anterior, desenhe algo na tela. O que acontece
quando posicionamos os objetos? Por que é útil essa configuração? - Concluído

4. Modifique o viewport para desenhar a cena apenas no seguinte quadrante da janela
da aplicação: - Concluído

![Of - Google Chrome 01_06_2024 22_26_58](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/53e9f297-6103-429b-a8ce-20a3a738e474)

5. Agora, desenhe a mesma cena nos 4 quadrantes. - Concluído

![Of - Google Chrome 01_06_2024 22_27_19](https://github.com/Shokinho/Fundamentos-da-Computacao-Grafica/assets/99108215/32766ee1-4e47-45ed-9fa5-8e0c9e90e3a7)
