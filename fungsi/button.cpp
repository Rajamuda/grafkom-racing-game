double CG = 0.0856;
bool mundur = false;
bool mundur2 = false;
float axisChange = 0.1589;
float axisChange2 = 0.1589;
double posZAI = 475.0;
double sesuatu = 0.15;

void reset(){
    cameraAngle = 0.0;
    cameraAngle2 = 0.0;
    geser = 30.0;
    x = 0.0, y = 5.223, z = 0.0; // default camera position
    lx = 0, ly = -0.5, lz = -1;
    ax = 0, ay = 0, az = -1;
    x2 = 0.0, y2 = 5.223, z2 = 0.0; // default camera position
    lx2 = 0, ly2 = -0.5, lz2 = -1;
    ax2 = 0, ay2 = 0, az2 = -1;

    mobil[0].setLap(0);
    mobil[1].setLap(0);

    isFinish = isFinish2 = false;
    sudahLewat = sudahLewat2 = false;

    start = duration = durationPassed = 0.0;
    run = false;
    isSubmit = printScore = false;

    for(int i=0; i<300; i++){
        activeKey[i] = 0;
    }
}

void cekbtn(){
    bool backward = false;
    float angleChange = sin(axisChange*PI/180);
    double timeNow = glfwGetTime();
    double diff = timeNow - timeElapsed;

//    std::cout << diff << std::endl;

    posZAI -= mobil[1].getAccel()*diff*sesuatu;
    sesuatu += diff;

    if(sesuatu >= 11){
        sesuatu = 11;
    }

    if(mobil[0].getSpeed()>=0 && mobil[0].getSpeed()<5){
        axisChange = 0.51890+CG;
    }
    else if(mobil[0].getSpeed()>=5 && mobil[0].getSpeed()<10){
        axisChange = 0.55670+CG;
    }
    else if(mobil[0].getSpeed()>=10 && mobil[0].getSpeed()<15){
        axisChange = 0.67889+CG;
    }
    else if(mobil[0].getSpeed()>=15 && mobil[0].getSpeed()<20){
        axisChange = 0.71738+CG;
    }
    else if(mobil[0].getSpeed()>=20 && mobil[0].getSpeed()<25){
        axisChange = 0.78980+CG;
    }
    else if(mobil[0].getSpeed()>=25 && mobil[0].getSpeed()<32){
        axisChange = 0.86980+CG;
    }
    else if(mobil[0].getSpeed()>=32){
        axisChange = 0.94900+CG;
    }

    if(activeKey[GLFW_KEY_UP]==0 && activeKey[GLFW_KEY_DOWN]==0){
        if(mobil[0].getSpeed()>0){
            mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*(diff*mobil[0].getBreaking()),1);
            if(!mundur){
                moveCamera(1,0,0,0);
            }else{
                moveCamera(-1,0,0,0);
            }
        }else{
            mobil[0].setSpeed(0.0);
        }
    }

    if(activeKey[GLFW_KEY_DOWN]){
        if(mobil[0].getSpeed()>0 && !mundur){
            moveCamera(1,0,0,0);
            mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*(diff*mobil[0].getBreaking()),1);
//            printf("(1) pressed!\n");
        }else{
            if(mobil[0].getSpeed()-mobil[0].getMaxSpeed()<0){
                mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff, 0);
                mundur = true;
            }
            moveCamera(-1,0,0,0);

//            printf("(2) pressed!\n");
        }
    }
    if(activeKey[GLFW_KEY_UP]){
        moveCamera(1,0,0,0);
        if(mobil[0].getSpeed()-mobil[0].getMaxSpeed()<0){
            mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff, 0);
            mundur = false;
        }
    }
    if(activeKey[GLFW_KEY_LEFT]){
        if(mobil[0].getSpeed()>0.5){
            if(!mundur){
                cameraAngle -= angleChange;
                ax += axisChange;
            }else{
                cameraAngle += angleChange;
                ax -= axisChange;
            }
            if(mobil[0].getSpeed()>1 && !mundur)
                mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff*0.01,1);
            moveCamera(0,0,1,cameraAngle);
        }
    }
    if(activeKey[GLFW_KEY_RIGHT]){
        if(mobil[0].getSpeed()>0.5){
            if(!mundur){
                cameraAngle += angleChange;
                ax -= axisChange;
            }else{
                cameraAngle -= angleChange;
                ax += axisChange;
            }
            if(mobil[0].getSpeed()>1 && !mundur)
                mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff*0.01,1);
            moveCamera(0,0,-1, cameraAngle);
        }
    }

}

void cekbtn2(){
    bool backward = false;
    float angleChange = sin(axisChange*PI/180);
    bool backward2 = false;
    float angleChange2 = sin(axisChange2*PI/180);
    double timeNow = glfwGetTime();
    double diff = timeNow - timeElapsed;
    float c = 1.22879;

    if(mobil[0].getSpeed()>=0 && mobil[0].getSpeed()<5){
        axisChange = 0.51890+CG+c;
    }
    else if(mobil[0].getSpeed()>=5 && mobil[0].getSpeed()<10){
        axisChange = 0.55670+CG+c;
    }
    else if(mobil[0].getSpeed()>=10 && mobil[0].getSpeed()<15){
        axisChange = 0.67889+CG+c;
    }
    else if(mobil[0].getSpeed()>=15 && mobil[0].getSpeed()<20){
        axisChange = 0.71738+CG+c;
    }
    else if(mobil[0].getSpeed()>=20 && mobil[0].getSpeed()<25){
        axisChange = 0.78980+CG+c;
    }
    else if(mobil[0].getSpeed()>=25 && mobil[0].getSpeed()<32){
        axisChange = 0.86980+CG+c;
    }
    else if(mobil[0].getSpeed()>=32){
        axisChange = 0.94900+CG+c;
    }

    if(mobil[1].getSpeed()>=0 && mobil[1].getSpeed()<5){
        axisChange2 = 0.51890+CG+c;
    }
    else if(mobil[1].getSpeed()>=5 && mobil[1].getSpeed()<10){
        axisChange2 = 0.55670+CG+c;
    }
    else if(mobil[1].getSpeed()>=10 && mobil[1].getSpeed()<15){
        axisChange2 = 0.67889+CG+c;
    }
    else if(mobil[1].getSpeed()>=15 && mobil[1].getSpeed()<20){
        axisChange2 = 0.71738+CG+c;
    }
    else if(mobil[1].getSpeed()>=20 && mobil[1].getSpeed()<25){
        axisChange2 = 0.78980+CG+c;
    }
    else if(mobil[1].getSpeed()>=25 && mobil[1].getSpeed()<32){
        axisChange2 = 0.86980+CG+c;
    }
    else if(mobil[1].getSpeed()>=32){
        axisChange2 = 0.94900+CG+c;
    }

    if(activeKey[GLFW_KEY_UP]==0 && activeKey[GLFW_KEY_DOWN]==0){
        if(mobil[0].getSpeed()>0){
            mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*(diff*mobil[0].getBreaking())*0.01,1);
            if(!mundur){
                moveCamera(1,0,0,0);
            }else{
                moveCamera(-1,0,0,0);
            }
        }else{
            mobil[0].setSpeed(0.0);
        }
    }

    if(activeKey[GLFW_KEY_DOWN]){
        if(mobil[0].getSpeed()>0 && !mundur){
            moveCamera(1,0,0,0);
            mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*(diff*mobil[0].getBreaking())*0.01,1);
//            printf("(1) pressed!\n");
        }else{
            if(mobil[0].getSpeed()-mobil[0].getMaxSpeed()<0){
                mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff*0.01, 0);
                mundur = true;
            }
            moveCamera(-1,0,0,0);

//            printf("(2) pressed!\n");
        }
    }
    if(activeKey[GLFW_KEY_UP]){
        moveCamera(1,0,0,0);
        if(mobil[0].getSpeed()-mobil[0].getMaxSpeed()<0){
            mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff*0.01, 0);
            mundur = false;
        }
    }
    if(activeKey[GLFW_KEY_LEFT]){
        if(mobil[0].getSpeed()>0.5){
            if(!mundur){
                cameraAngle -= angleChange;
                ax += axisChange;
            }else{
                cameraAngle += angleChange;
                ax -= axisChange;
            }
            if(mobil[0].getSpeed()>1 && !mundur)
                mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff*0.0001,1);
            moveCamera(0,0,1,cameraAngle);
        }
    }
    if(activeKey[GLFW_KEY_RIGHT]){
        if(mobil[0].getSpeed()>0.5){
            if(!mundur){
                cameraAngle += angleChange;
                ax -= axisChange;
            }else{
                cameraAngle -= angleChange;
                ax += axisChange;
            }
            if(mobil[0].getSpeed()>1 && !mundur)
                mobil[0].setSpeed((mobil[0].getAccel()/mobil[0].getWeight())*diff*0.0001,1);
            moveCamera(0,0,-1, cameraAngle);
        }
    }

    if(activeKey[GLFW_KEY_W]==0 && activeKey[GLFW_KEY_S]==0){
        if(mobil[1].getSpeed()>0){
            mobil[1].setSpeed((mobil[1].getAccel()/mobil[1].getWeight())*(diff*mobil[1].getBreaking())*0.01,1);
            if(!mundur2){
                moveCamera2(1,0,0,0);
            }else{
                moveCamera2(-1,0,0,0);
            }
        }else{
            mobil[1].setSpeed(0.0);
        }
    }

    if(activeKey[GLFW_KEY_S]){
        if(mobil[1].getSpeed()>0 && !mundur2){
            moveCamera2(1,0,0,0);
            mobil[1].setSpeed((mobil[1].getAccel()/mobil[1].getWeight())*(diff*mobil[1].getBreaking())*0.01,1);
//            printf("(1) pressed!\n");
        }else{
            if(mobil[1].getSpeed()-mobil[1].getMaxSpeed()<0){
                mobil[1].setSpeed((mobil[1].getAccel()/mobil[1].getWeight())*diff*0.01, 0);
                mundur2 = true;
            }
            moveCamera2(-1,0,0,0);

//            printf("(2) pressed!\n");
        }
    }
    if(activeKey[GLFW_KEY_W]){
        moveCamera2(1,0,0,0);
        if(mobil[1].getSpeed()-mobil[1].getMaxSpeed()<0){
            mobil[1].setSpeed((mobil[1].getAccel()/mobil[1].getWeight())*diff*0.01, 0);
            mundur2 = false;
        }
    }
    if(activeKey[GLFW_KEY_A]){
        if(mobil[1].getSpeed()>0.5){
            if(!mundur2){
                cameraAngle2 -= angleChange2;
                ax2 += axisChange2;
            }else{
                cameraAngle2 += angleChange2;
                ax2 -= axisChange2;
            }
            if(mobil[1].getSpeed()>1 && !mundur2)
                mobil[1].setSpeed((mobil[1].getAccel()/mobil[1].getWeight())*diff*0.0001,1);
            moveCamera2(0,0,1,cameraAngle2);
        }
    }
    if(activeKey[GLFW_KEY_D]){
        if(mobil[1].getSpeed()>0.5){
            if(!mundur2){
                cameraAngle2 += angleChange2;
                ax2 -= axisChange2;
            }else{
                cameraAngle2 -= angleChange2;
                ax2 += axisChange2;
            }
            if(mobil[1].getSpeed()>1 && !mundur2)
                mobil[1].setSpeed((mobil[1].getAccel()/mobil[1].getWeight())*diff*0.0001,1);
            moveCamera2(0,0,-1, cameraAngle2);
        }
    }

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    switch(screenState){
        case 0:
        case 1:
        case 2:
            if(action == GLFW_PRESS){
                switch(key){
                    case GLFW_KEY_DOWN:
                        screenState++;
                        if(screenState>2) screenState = 0;
                        break;
                    case GLFW_KEY_UP:
                        screenState--;
                        if(screenState<0) screenState = 2;
                        break;
                    case GLFW_KEY_ENTER:
                        if(screenState==0){
                            screenState = 4;
                        }else if(screenState==1){
                            //doing nothing
                        }else if(screenState==2){
                            glfwSetWindowShouldClose(window, TRUE);
                        }
                        break;
                }
            }
            break;
        case 4:
        case 7:
            if(action == GLFW_PRESS){
                switch(key){
                    case GLFW_KEY_UP:
                        if(!isFinish)
                        activeKey[GLFW_KEY_UP] = 1;
                        break;
                    case GLFW_KEY_DOWN:
                        if(!isFinish)
                        activeKey[GLFW_KEY_DOWN] = 1;
                        break;
                    case GLFW_KEY_LEFT:
                        if(!isFinish)
                        activeKey[GLFW_KEY_LEFT] = 1;
                        break;
                    case GLFW_KEY_RIGHT:
                        if(!isFinish)
                        activeKey[GLFW_KEY_RIGHT] = 1;
                        break;
                    case GLFW_KEY_W:
                        if(!isFinish2)
                        activeKey[GLFW_KEY_W] = 1;
                        break;
                    case GLFW_KEY_S:
                        if(!isFinish2)
                        activeKey[GLFW_KEY_S] = 1;
                        break;
                    case GLFW_KEY_A:
                        if(!isFinish2)
                        activeKey[GLFW_KEY_A] = 1;
                        break;
                    case GLFW_KEY_D:
                        if(!isFinish2)
                        activeKey[GLFW_KEY_D] = 1;
                        break;
                    case GLFW_KEY_ENTER:
                        if(isFinish && screenState == 4)
                            screenState = 0;
                        break;
                    case GLFW_KEY_ESCAPE:
                        screenState = 5;
                        break;
                }
            }
            else if(action == GLFW_RELEASE){
                switch(key){
                    case GLFW_KEY_UP:
                        activeKey[GLFW_KEY_UP] = 0;
                        break;
                    case GLFW_KEY_DOWN:
                        activeKey[GLFW_KEY_DOWN] = 0;
                        break;
                    case GLFW_KEY_LEFT:
                        activeKey[GLFW_KEY_LEFT] = 0;
                        break;
                    case GLFW_KEY_RIGHT:
                        activeKey[GLFW_KEY_RIGHT] = 0;
                        break;
                    case GLFW_KEY_W:
                        activeKey[GLFW_KEY_W] = 0;
                        break;
                    case GLFW_KEY_S:
                        activeKey[GLFW_KEY_S] = 0;
                        break;
                    case GLFW_KEY_A:
                        activeKey[GLFW_KEY_A] = 0;
                        break;
                    case GLFW_KEY_D:
                        activeKey[GLFW_KEY_D] = 0;
                        break;
                }
            }
            break;
        case 5:
        case 6:
            if(action == GLFW_PRESS){
                switch(key){
                    case GLFW_KEY_DOWN:
                        screenState++;
                        if(screenState>6) screenState = 5;
                        break;
                    case GLFW_KEY_UP:
                        screenState--;
                        if(screenState<5) screenState = 6;
                        break;
                    case GLFW_KEY_ENTER:
                        if(screenState==5){
                            screenState = 4;
                        }else if(screenState==6){
                            screenState = 0;
                        }
                        break;
                }
            }
            break;
    }

}
