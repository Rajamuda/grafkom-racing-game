#define GLFW_INCLUDE_GLU
#define PI 3.141592265
#define MAX_P 5
#define MAX_J 15
#define CD 5 // countdown 4-3-2-1-GO
#define MAX_L 2

#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <string>

#include <windows.h>
#include <mmsystem.h>

#include "lib/glm.cpp"
#include "lib/tga.h"
#include "lib/tga.c"
#include "lib/glWindowPos.cpp"

float cameraAngle = 0.0;;
float geser = 30.0;
float x = 0.0, y = 5.223, z = 0.0; // default camera position
float lx = 0, ly = -0.5, lz = -1;
float ax = 0, ay = 0, az = -1;
int activeKey[300] = {0};
int heightWindow = 675;
int widthWindow = 1200;
float ratioWindow = widthWindow / (float) heightWindow;
double timeElapsed;
int screenState = 0;

#include "fungsi/loadFile.cpp"
#include "fungsi/classObj.cpp"
#include "fungsi/drawObj.cpp"
#include "fungsi/collideArea.cpp"
#include "fungsi/cam.cpp"
#include "fungsi/button.cpp"
#include "fungsi/viewport.cpp"
#include "fungsi/lightning.cpp"
#include "fungsi/display.cpp"
#include "fungsi/animate.cpp"

int main(void){

    GLFWwindow* window;

    if (!glfwInit()) exit(EXIT_FAILURE);

    window = createWindow();

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);

    glTga();
    loadObj();

    bool countDown =  true;
    int now = 0;
    while (!glfwWindowShouldClose(window)){
        //
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        mciSendString("play sfx/music1.MP3", NULL, NULL, NULL);
        fpsSetting();
        if(ticks>= (4)/animationInterval){
            switch(screenState){
                case 0:
                case 1:
                case 2:
                    reset();
//                    mciSendString("play sfx/music1.MP3", NULL, NULL, NULL);
                    countDown = true; //set true for countdown
                    viewportMenu(window);
                    loadMenu();
                    break;
                case 4:
//                        mciSendString("stop sfx/music1.MP3", NULL, NULL, NULL);
                        viewportMobil(window);
                        glHint(GLFW_CURSOR_DISABLED,GLFW_CURSOR_HIDDEN);
                        timeElapsed = glfwGetTime();
                        glEnable(GL_BLEND);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glEnable(GL_LINE_SMOOTH);
                        glEnable(GL_POLYGON_SMOOTH);
                        glEnable(GL_POINT_SMOOTH);

                        drawSkybox(1500.0);
                        display();
                        loadArea();
//                        viewportMap(window);
//                        display();
//                        loadArea();
                        viewportStart(window, 500, 500);
                        if(countDown){
                            if(now == 0){
                                now = (int)timeElapsed;
                            }
                            if((int)glfwGetTime() < now+5 ){
                                mobil[0].setSpeed(0.0);
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D, (now+5-(int)glfwGetTime())+13);
                                glBegin(GL_QUADS);
                                    glTexCoord2f(0,0);
                                    glVertex2f(0,0);
                                    glTexCoord2f(0,1);
                                    glVertex2f(0,500);
                                    glTexCoord2f(1,1);
                                    glVertex2f(500,500);
                                    glTexCoord2f(1,0);
                                    glVertex2f(500,0);
                                glEnd();
                                glDisable(GL_TEXTURE_2D);
                            }

                            if((int)glfwGetTime() == now+5){
                                now = 0;  // yang ini diaktifkan kalo mau countdown ulang!
                                countDown = false;
                            }
                        }

                    break;

                case 5: // tampilkan menu pause!
                case 6:
                    countDown = false; //set true for countdown
                    viewportMenu(window);
                    loadMenu();
                    break;
            }

        }else{
            viewportMenu(window);
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
