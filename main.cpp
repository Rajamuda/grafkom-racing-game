#define GLFW_INCLUDE_GLU
#define PI 3.141592265
#define MAX_P 5

#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <windows.h>
#include <mmsystem.h>

#include "lib/glm.cpp"
#include "lib/tga.h"
#include "lib/tga.c"
#include "lib/glWindowPos.cpp"

float cameraAngle = 0.0;;
float geser = 30.0;
float x = 0.0, y = 5.223, z = 475.0; // default camera position
float lx = 0, ly = -0.5, lz = -1;
float ax = 0, ay = 0, az = -1;
int activeKey[300] = {0};
int heightWindow = 675;
int widthWindow = 1200;
float ratioWindow = widthWindow / (float) heightWindow;
double timeElapsed;

#include "fungsi/loadFile.cpp"
#include "fungsi/collideArea.cpp"
#include "fungsi/classObj.cpp"
#include "fungsi/cam.cpp"
#include "fungsi/button.cpp"
#include "fungsi/viewport.cpp"
#include "fungsi/lightning.cpp"

void printTxt(int x, int y,int z, char *string){
    //set the position of the text in the window using the x and y coordinates
    glWindowPos2i(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

//    glColor3ub(120,255,12);
    //loop to display character by character
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }

    char tx[] = " Km/h";
    len = (int) strlen(tx);
    for (int i=0; i < len; i++ )
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tx[i]);
}

void display(){

    if(posZAI <= -500)
        posZAI = 500;
    if(z <= -475)
        z = 495;


    char txt1[] = "Speed: ";
    char txtBuff[10];

    snprintf(txtBuff,sizeof(txtBuff),"%.2f",(mobil[0].getSpeed(1)));
    strcat(txt1, txtBuff);
    printTxt(100,60,10, txt1);

    mobil[0].setMobil(1.4,1.0,1.0,1.4,2.0,50,2.88,porscheR); //scaleX, scaleY, scaleZ, weight(ton), accel (m/s^2), maxspeed(m/s), breaking(percentage),model
    mobil[0].setLocation(x+lx,2.0,z+lz,ax);

    mobil[1].setMobil(0.5,0.4,0.4,1.4,2.0,50,2.88,porsche);
    mobil[1].setLocation(0.0,1.0,posZAI,0);

    putTree(12,4,-12,2.4);
//    putTree(-12,4,-12,2.4);
//    putTree(-12,4,12,2.4);
//    putTree(12,4,12,2.4);


    cekbtn();
//    printTxt(x,y,z,"Hello");
//    printf("My curre nt locati8on: %f %f %f\n", x,y,z);

}

#include "fungsi/animate.cpp"

int main(void){

    GLFWwindow* window;
    char askFullScreen;

    if (!glfwInit()) exit(EXIT_FAILURE);

//    std::cout << "Fullscreen? (Y/N)";
//    std::cin >> askFullScreen;

    window = createWindow();

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);

    lighting2();
    glTga();
    loadObj();

    while (!glfwWindowShouldClose(window)){
        //
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        mciSendString("play sfx/music1.MP3", NULL, NULL, NULL);
        fpsSetting();
        if(ticks >= (2)/animationInterval){
            viewportMobil(window);
//        glHint(GLFW_CURSOR,GLFW_CURSOR_HIDDEN);
            timeElapsed = glfwGetTime();
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_LINE_SMOOTH);
            glEnable(GL_POLYGON_SMOOTH);
            glEnable(GL_POINT_SMOOTH);

            drawSkybox(1000.0);
            display();
            loadArea();
        }else{
            viewportLoad(window);
            loadingScreen();
        }


        glfwSwapBuffers(window);
        glFlush();
        glfwPollEvents();

    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
