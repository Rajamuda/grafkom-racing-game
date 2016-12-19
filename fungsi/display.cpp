void printTxt(int x, int y,int z, char *string, int info){
    //set the position of the text in the window using the x and y coordinates
    glWindowPos2i(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

//    glColor3ub(120,255,12);
    //loop to display character by character
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }

    if(info == 0){
        char tx[] = " Km/h";
        len = (int) strlen(tx);
        for (int i=0; i < len; i++ )
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tx[i]);
    }else if(info == 1){
        char tx[] = " of 2";
        len = (int) strlen(tx);
        for (int i=0; i < len; i++ )
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tx[i]);
    }
}

void display(){
    if(posZAI <= -485)
        posZAI = 500;

    char txt1[] = "Speed: ";
    char txtBuff[10];
    snprintf(txtBuff,sizeof(txtBuff),"%.2f",(mobil[0].getSpeed(1)));
    strcat(txt1, txtBuff);
    printTxt(100,60,10, txt1,0);


    char txt2[] = "Lap: ";
    char txtBuff2[2];
    snprintf(txtBuff2,sizeof(txtBuff2),"%d",(mobil[0].getLap()));
    strcat(txt2,txtBuff2);
    printTxt(1100,60,10,txt2,1);

    glPushMatrix();
        putTree(12,4,-12,2.4);
        putTree(-12,4,-12,2.4);
        putTree(-12,4,12,2.4);
        putTree(12,4,12,2.4);
    glPopMatrix();

    mobil[0].setMobil(1.4,1.0,1.0,1.4,2.0,50,2.88,porscheR); //scaleX, scaleY, scaleZ, weight(ton), accel (m/s^2), maxspeed(m/s), breaking(percentage),model
    mobil[0].setLocation(x+lx,2.0,z+lz,ax);

    mobil[1].setMobil(0.5,0.4,0.4,1.4,2.0,50,2.88,porsche);
    mobil[1].setLocation(0.0,1.0,posZAI,0);


    lighting2();


    cekbtn();
}
