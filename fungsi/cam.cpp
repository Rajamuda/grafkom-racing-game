//float speed = 0.0; // m/s
//float accel = 0.95; // m/s^2
//float decel = 0.0;
//float dt = 0.0;
bool isFinish = false;

void setCamera() {
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);
}

void moveCamera(int h_direction, int v_direction, int leftorRight, float ang) {
//     move the camera (forward, backward, up, down)
    float cox=0,coy=0,coz=0;

	cox = x + h_direction*(mobil[0].getSpeed())*(lx)*0.035;
	coz = z + h_direction*(mobil[0].getSpeed())*(lz)*0.035;
	coy = y + v_direction*0.3;
	if(leftorRight!=0){
        lx = sin(ang);
        lz = -cos(ang);
	}

    if(!collideArea(cox, coy, coz)){
        x = cox;
        y = coy;
        z = coz;
    }else{
        mobil[0].setSpeed(mobil[0].getSpeed()-0.025, 1);
        printf("berada di luar wilayah!\n");
    }

    if(checkFinish(cox,coy,coz,0)  && !isFinish){
//        if(mobil[0].getLap()1)
        int lapE = mobil[0].getLap()+1;

        if(lapE <= maxLap){
            printf("Melewati garis gan!\n");
            mobil[0].setLap(lapE);
        }else{
            isFinish = true;
        }
    }else if(isFinish){
        if(mobil[0].getSpeed()>0){
            activeKey[GLFW_KEY_DOWN] = 0;
            activeKey[GLFW_KEY_UP] = activeKey[GLFW_KEY_LEFT] = activeKey[GLFW_KEY_RIGHT] = 0;
        }else{
            mobil[0].setSpeed(0.0);
        }
    }
}


bool isFinish2 = false;

void setCamera2() {
	glLoadIdentity();
	gluLookAt(x2, y2, z2, x2 + lx2, y2 + ly2, z2 + lz2, 0, 1, 0);
}

void moveCamera2(int h_direction, int v_direction, int leftorRight, float ang) {
//     move the camera (forward, backward, up, down)
    float cox=0,coy=0,coz=0;

	cox = x2 + h_direction*(mobil[1].getSpeed())*(lx2)*0.035;
	coz = z2 + h_direction*(mobil[1].getSpeed())*(lz2)*0.035;
	coy = y2 + v_direction*0.3;
	if(leftorRight!=0){
        lx2 = sin(ang);
        lz2 = -cos(ang);
	}

    if(!collideArea(cox, coy, coz)){
        x2 = cox;
        y2 = coy;
        z2 = coz;
    }else{
        mobil[1].setSpeed(0.0);
        printf("berada di luar wilayah!\n");
    }

    if(checkFinish(cox,coy,coz,1)  && !isFinish2){
//        if(mobil[1].getLap()1)
        int lapE = mobil[1].getLap()+1;

        if(lapE <= MAX_L){
            printf("Melewati garis gan!\n");
            mobil[1].setLap(lapE);
        }else{
            isFinish2 = true;
        }
    }else if(isFinish2){
        if(mobil[1].getSpeed()>0){
            activeKey[GLFW_KEY_S] = 0;
            activeKey[GLFW_KEY_W] = activeKey[GLFW_KEY_A] = activeKey[GLFW_KEY_D] =0;
        }else{
            mobil[1].setSpeed(0.0);
        }
    }
}
