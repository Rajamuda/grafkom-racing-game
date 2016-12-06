bool mundur = false;
float axisChange = 0.1589;
double posZAI = 475.0;
double sesuatu = 0.15;

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
        axisChange = 0.3589;
    }
    else if(mobil[0].getSpeed()>=5 && mobil[0].getSpeed()<10){
        axisChange = 0.4167;
    }
    else if(mobil[0].getSpeed()>=10 && mobil[0].getSpeed()<15){
        axisChange = 0.47889;
    }
    else if(mobil[0].getSpeed()>=15 && mobil[0].getSpeed()<20){
        axisChange = 0.52738;
    }
    else if(mobil[0].getSpeed()>=20 && mobil[0].getSpeed()<25){
        axisChange = 0.5898;
    }
    else if(mobil[0].getSpeed()>=25 && mobil[0].getSpeed()<32){
        axisChange = 0.6698;
    }
    else if(mobil[0].getSpeed()>=32){
        axisChange = 0.7490;
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

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    if(action == GLFW_PRESS){
        switch(key){
            case GLFW_KEY_UP:
                activeKey[GLFW_KEY_UP] = 1;
                break;
            case GLFW_KEY_DOWN:
                activeKey[GLFW_KEY_DOWN] = 1;
                break;
            case GLFW_KEY_LEFT:
                activeKey[GLFW_KEY_LEFT] = 1;
                break;
            case GLFW_KEY_RIGHT:
                activeKey[GLFW_KEY_RIGHT] = 1;
                break;
            case GLFW_KEY_ENTER:
//                activeKey[GLFW_KEY_ENTER] = 1;
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, TRUE);
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
        }
    }

}
