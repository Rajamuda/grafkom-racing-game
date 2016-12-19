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
        mobil[0].setSpeed(0.0);
        printf("berada di luar wilayah!\n");
    }

    if(checkFinish(cox,coy,coz)  && !isFinish){
//        if(mobil[0].getLap()1)
        int lapE = mobil[0].getLap()+1;

        if(lapE <= MAX_L){
            printf("Melewati garis gan!\n");
            mobil[0].setLap(lapE);
        }else{
            isFinish = true;
        }
    }else if(isFinish){
        if(mobil[0].getSpeed()>0){
            activeKey[GLFW_KEY_DOWN] = 0;
            activeKey[GLFW_KEY_UP] = activeKey[GLFW_KEY_LEFT] = activeKey[GLFW_KEY_DOWN] =0;
        }else{
            mobil[0].setSpeed(0.0);
        }
    }
}
