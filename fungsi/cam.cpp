//float speed = 0.0; // m/s
//float accel = 0.95; // m/s^2
//float decel = 0.0;
//float dt = 0.0;

void setCamera() {
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0, 1, 0);

    printf("lx: %f ly: %f lz: %f\n", lx, ly, lz);
}

void moveCamera(int h_direction, int v_direction, int leftorRight, float ang) {
    // move the camera (forward, backward, up, down)
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
//        printf("sampai sini\n");
    }else{
        mobil[0].setSpeed(0.0);
        printf("berada di luar wilayah!\n");
    }
}

void rotateCamera(float ang) {
    // rotate the camera (left / right)
	lx = sin(ang);
	lz = -cos(ang);

    setCamera();
}
