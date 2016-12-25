#define GLFW_INCLUDE_GLU
#define PI 3.141592265
#define MAX_P 5
#define MAX_J 15
#define CD 5 // countdown 4-3-2-1-GO
#define MAX_L 2

#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

#include <windows.h>
#include <mmsystem.h>

#include "lib/glm.cpp"
#include "lib/tga.h"
#include "lib/tga.c"
#include "lib/glWindowPos.cpp"

float cameraAngle = 0.0;
float cameraAngle2 = 0.0;
float geser = 30.0;
float x = 0.0, y = 5.223, z = 0.0; // default camera position
float lx = 0, ly = -0.5, lz = -1;
float ax = 0, ay = 0, az = -1;
float x2 = 0.0, y2 = 5.223, z2 = 0.0; // default camera position
float lx2 = 0, ly2 = -0.5, lz2 = -1;
float ax2 = 0, ay2 = 0, az2 = -1;
int activeKey[300] = {0};
int heightWindow = 675;
int widthWindow = 1200;
float ratioWindow = widthWindow / (float) heightWindow;
double timeElapsed;
int screenState = 0;
bool countDown =  true;
bool run = false;
double start, duration, durationPassed = 0.0;
bool isSubmit = false, printScore = false;

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
#include "fungsi/scoring.cpp"

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

//    bool countDown =  true;
    int now = 0;

    int pY[5]={75, 50, 25, 0,-25};
    double arr[5];
    while (!glfwWindowShouldClose(window)){
        //
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        mciSendString("play sfx/music1.MP3", NULL, NULL, NULL);
        fpsSetting();
        if(ticks>= (1)/animationInterval){
            switch(screenState){
                case 0:
                case 1:
                case 2:
                    reset();
                    run = false;
//                    mciSendString("play sfx/music1.MP3", NULL, NULL, NULL);
                    countDown = true; //set true for countdown
                    viewportMenu(window);
                    loadMenu();
                    break;
                case 4:
//                        mciSendString("stop sfx/music1.MP3", NULL, NULL, NULL);
                        viewportMobilP(window);
                        glHint(GLFW_CURSOR_DISABLED,GLFW_CURSOR_HIDDEN);
                        timeElapsed = glfwGetTime();
                        glEnable(GL_BLEND);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glEnable(GL_LINE_SMOOTH);
                        glEnable(GL_POLYGON_SMOOTH);
                        glEnable(GL_POINT_SMOOTH);

                        drawSkybox(1850.0);
                        display();
                        loadArea();
                        viewportStart(window, 500, 500,200,200);
                        if(countDown){
                            if(now == 0){
                                now = (int)timeElapsed;
                            }
                            if((int)glfwGetTime() < now+5 ){
                                mobil[0].setSpeed(0.0);
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D, (now+5-(int)glfwGetTime())+13);
                                glBegin(GL_QUADS);
                                    glColor4f(1,1,1,0.75);
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
                                glColor3f(1,1,1);
                            }

                            if((int)glfwGetTime() == now+5){
                                now = 0;  // yang ini diaktifkan kalo mau countdown ulang!
                                countDown = false;
                            }
                        }
                        if(isFinish){
                            submitScore();
                            viewportStart(window,0,0,1000,1000);
                            if(!printScore){
                                getScore(arr);
                                printScore = true;

                            }
                            char buff[50];
                            for(int i=0; i<5; i++){
//                                printf("%f, %d\n", vek[i], i);
                                snprintf(buff, sizeof(buff), "%d       %.2d:%.2d.%.3d", i+1, int(arr[i]/60), int(arr[i])%60, int(arr[i]*1000)%1000);
                                printTxt(95,pY[i]-30,1,buff,4);
                            }
                            glPushMatrix();
                                glTranslatef(-70,-120,0);
                                glEnable(GL_TEXTURE_2D);
                                glBindTexture(GL_TEXTURE_2D, SKOR);
                                glBegin(GL_QUADS);
                                    glColor4f(1,1,1,0.8);
                                    glTexCoord2f(0,0);
                                    glVertex2f(20,20);
                                    glTexCoord2f(0,1);
                                    glVertex2f(20,230);
                                    glTexCoord2f(1,1);
                                    glVertex2f(500,230);
                                    glTexCoord2f(1,0);
                                    glVertex2f(500,20);
                                glEnd();
                                glDisable(GL_TEXTURE_2D);
                            glPopMatrix();
                            glColor3f(1,1,1);
                        }
                    break;

                case 5: // tampilkan menu pause!
                case 6:
                    run = false;
                    durationPassed = duration ;
                    countDown = false; //set true for countdown
                    viewportMenu(window);
                    loadMenu();
                    break;
                case 7:
                    cekbtn2();
                    mobil[0].setMobil(1.4,1.0,1.0,1.4,2.0,50,0.58,porscheR); //scaleX, scaleY, scaleZ, weight(ton), accel (m/s^2), maxspeed(m/s), breaking(percentage),model
                    mobil[1].setMobil(1.4,1.0,1.0,1.4,2.0,50,0.58,porsche);
                    viewportMobil2P(window);
                        glHint(GLFW_CURSOR_DISABLED,GLFW_CURSOR_HIDDEN);
                        glEnable(GL_BLEND);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glEnable(GL_LINE_SMOOTH);
                        glEnable(GL_POLYGON_SMOOTH);
                        glEnable(GL_POINT_SMOOTH);
                        drawSkybox(1850.0);
                        display2();
                        loadArea();
                    viewportMobil1P(window);
                        glHint(GLFW_CURSOR_DISABLED,GLFW_CURSOR_HIDDEN);
                        glEnable(GL_BLEND);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                        glEnable(GL_LINE_SMOOTH);
                        glEnable(GL_POLYGON_SMOOTH);
                        glEnable(GL_POINT_SMOOTH);
                        drawSkybox(1850.0);
                        display1();
                        loadArea();
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
