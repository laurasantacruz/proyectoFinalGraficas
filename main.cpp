#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 1050
#define SCREEN_HEIGHT 900

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void DrawCube2(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void DrawCube3(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
GLfloat translationX = 0.0f;
GLfloat translationY = 0.0f;

GLfloat escalateX = 1.0f;
GLfloat escalateY = 1.0f;
GLfloat escalateZ = 1.0f;

int main(void)
{
    GLFWwindow* window;

    // Inicializar la librería
    if (!glfwInit())
    {
        return -1;
    }

    // Crear la ventana
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Modelo GLUT", NULL, NULL);

    // Declarar que se recibirán comando del teclado
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);



    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);


    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    // Se crea el contexto de la ventana
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, screenWidth, screenHeight); // Específica en que parte de la ventana se dibujaran los elementos
    glMatrixMode(GL_PROJECTION); // Se crea la matriz de proyección
    glLoadIdentity(); // Se crea de la matriz identidad
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); // Establecer el sistema de coordenadas
    glMatrixMode(GL_MODELVIEW); // Matriz de transformación


    // Se establece el sistema de coordenadas dentro de la ventana
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;


    // Loop en donde se estará dibujando la ventana
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);

        // Render (Se crea el cubo y se generan los cambios en los vectores de transformación

        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, -500); // Coloca el cubo al centro de la pantalla
        glTranslated(translationX, translationY, 0); // Mueve el cubo con las variables de las teclas (Vector de Traslación
        //Aquí se crearía el vector de escalado
        glScalef(
            escalateX,
            escalateY,
            escalateZ
        );
        glRotatef(rotationX, 1, 0, 0); // Rotar el cubo en X
        glRotatef(rotationY, 0, 1, 0); // Rotar el cubo en Y
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

        DrawCube3(halfScreenWidth, halfScreenHeight, -500, 200);
        DrawCube2(halfScreenWidth, halfScreenHeight, -500, 200);


        glPopMatrix();



        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}


// LLamar mandar las teclas
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{


    const GLfloat rotationSpeed = 10;

    // Switch en donde se determinan los movimientos del cubo en base a las teclas
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotationY -= rotationSpeed;
            break;
        case GLFW_KEY_A:
            translationX -= 10;
            break;
        case GLFW_KEY_S:
            translationX += 10;
            break;
        case GLFW_KEY_W:
            translationY += 10;
            break;
        case GLFW_KEY_X:
            translationY -= 10;
            break;
        case GLFW_KEY_J:
            escalateX += 0.5;
            escalateY += 0.5;
            escalateZ += 0.5;
            break;
        case GLFW_KEY_K:
            escalateX -= 0.5;
            escalateY -= 0.5;
            escalateZ -= 0.5;
            break;
        }


    }
}

void DrawCube2(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        //// una pata de la mesa
        // Cara Frontal
        centerPosX - halfSideLength + 50, centerPosY  , centerPosZ + 70, // Arriba Izquierda
        centerPosX + halfSideLength - 50, centerPosY , centerPosZ + 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY - 100, centerPosZ + 70, // Abajo Derecha
        centerPosX - halfSideLength + 50, centerPosY - 100, centerPosZ + 70, // Abajo Izquierda

        // Cara Posterior
        centerPosX - halfSideLength + 50, centerPosY , centerPosZ - 70, // Arriba Izquierda
        centerPosX + halfSideLength - 50, centerPosY , centerPosZ - 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY - 100, centerPosZ - 70, // Abajo Derecha
        centerPosX - halfSideLength + 50, centerPosY - 100, centerPosZ - 70, // Abajo Izquierda
    };

    GLfloat colour[] = {
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
    };

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

}

void DrawCube3(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;

    GLfloat vertices[] =
    {
        //// Cubo principal (la mesa)
        // Cara Frontal
        centerPosX - halfSideLength + 50, centerPosY  , centerPosZ + 70, // Arriba Izquierda
        centerPosX + halfSideLength - 50, centerPosY , centerPosZ + 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY - 40, centerPosZ + 70, // Abajo Derecha
        centerPosX - halfSideLength + 50, centerPosY - 40, centerPosZ + 70, // Abajo Izquierda

        // Cara Posterior
        centerPosX - halfSideLength + 50, centerPosY , centerPosZ - 70, // Arriba Izquierda
        centerPosX + halfSideLength - 50, centerPosY , centerPosZ - 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY - 40, centerPosZ - 70, // Abajo Derecha
        centerPosX - halfSideLength + 50, centerPosY - 40, centerPosZ - 70, // Abajo Izquierda

        // Cara Izquierda
        centerPosX - halfSideLength + 50, centerPosY , centerPosZ + 70, // Arriba Izquierda
        centerPosX - halfSideLength + 50, centerPosY , centerPosZ - 70, // Arriba Dereccha
        centerPosX - halfSideLength + 50, centerPosY - 40, centerPosZ - 70, // Abajo Derecha
        centerPosX - halfSideLength + 50, centerPosY - 40, centerPosZ + 70, // Abajo Izquierda

        // Cara Derecha
        centerPosX + halfSideLength - 50, centerPosY , centerPosZ + 70, // Arriba Izquierda
        centerPosX + halfSideLength - 50, centerPosY  , centerPosZ - 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY - 40, centerPosZ - 70, // Abajo Derecha
        centerPosX + halfSideLength - 50, centerPosY - 40, centerPosZ + 70, // Abajo Izquierda

        // Cara Superior
        centerPosX - halfSideLength + 50, centerPosY , centerPosZ + 70 , // Arriba Izquierda
        centerPosX - halfSideLength + 50, centerPosY  , centerPosZ - 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY  , centerPosZ - 70, // Abajo Derecha
        centerPosX + halfSideLength - 50, centerPosY  , centerPosZ + 70, // Abajo Izquierda

        // Cara Inferior
        centerPosX - halfSideLength + 50, centerPosY - 40, centerPosZ + 70, // Arriba Izquierda
        centerPosX - halfSideLength + 50, centerPosY - 40, centerPosZ - 70, // Arriba Derecha
        centerPosX + halfSideLength - 50, centerPosY - 40, centerPosZ - 70, // Abajo Derecha
        centerPosX + halfSideLength - 50, centerPosY - 40, centerPosZ + 70

    };
    GLfloat colour[] = {
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
           153.0, 77.0, 0.0,
    };

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}


