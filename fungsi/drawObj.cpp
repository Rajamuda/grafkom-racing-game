void putTree(float x,float y, float z, float scale){
    glPushMatrix();
        glTranslatef(x,y,z);
        glScalef(1,scale,1);
        glmDraw(tree2, GLM_SMOOTH|GLM_MATERIAL);
    glPopMatrix();
}

void drawSidewalk(float x0, float y0, float z0, float p0, float l0, float t0, float xtex, float ztex){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,10);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,0);
            glVertex3f(x0+l0,y0+t0,z0+p0);
            glTexCoord2f(xtex,0);
            glVertex3f(x0,y0+t0,z0+p0);
            glTexCoord2f(xtex,ztex);
            glVertex3f(x0,y0+t0,z0);
            glTexCoord2f(0,ztex);
            glVertex3f(x0+l0,y0+t0,z0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glColor3ub(103,95,80);
        glBegin(GL_POLYGON);
            glVertex3f(x0,y0,z0);
            glVertex3f(x0,y0+t0,z0);
            glVertex3f(x0,y0+t0,z0+p0);
            glVertex3f(x0,y0,z0+p0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(x0,y0,z0);
            glVertex3f(x0,y0+t0,z0);
            glVertex3f(x0+l0,y0+t0,z0);
            glVertex3f(x0+l0,y0,z0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(x0+l0,y0,z0);
            glVertex3f(x0+l0,y0+t0,z0);
            glVertex3f(x0+l0,y0+t0,z0+p0);
            glVertex3f(x0+l0,y0,z0+p0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(x0,y0,z0+p0);
            glVertex3f(x0,y0+t0,z0+p0);
            glVertex3f(x0+l0,y0+t0,z0+p0);
            glVertex3f(x0+l0,y0,z0+p0);
        glEnd();
        glColor3ub(255,255,255);
}

void loadArea(){
    glColor3f(1,1,1);
//    grid_floor(1500,1500);
    line.setArena(-10,10,-20,-10,1.025,F_LINE,5);
    line.drawArena(1);

    /* -------------------- 1 ------------------------ */
    jalanan[0].setArena(-10,10,-10,-480,1,1,25);
    jalanan[0].drawArena(0);

    jalanan[1].setArena(-10,10,10,480,1,1,25);
    jalanan[1].drawArena(0);

    /* Persimpangan Tengah */
    jalanan[2].setArena(-10,10,-10,10,1,2,1);
    jalanan[2].drawArena(0);

    /* -------------------- 2 ------------------------ */
    jalanan[3].setArena(10,480,-10,10,1,1,25);
    jalanan[3].drawArena(1);

    jalanan[4].setArena(-10,-480,-10,10,1,1,25);
    jalanan[4].drawArena(1);

    /* -------------------- 3 ------------------------ */
    /* Persimpangan Atas */
    jalanan[5].setArena(-10,10,-500,-480,1,2,1);
    jalanan[5].drawArena(0);

    jalanan[6].setArena(-480,-10,-500,-480,1,1,25);
    jalanan[6].drawArena(1);

    /* Persimpangan KiriAtas */
    jalanan[7].setArena(-500,-480,-500,-480,1,2,1);
    jalanan[7].drawArena(0);

    jalanan[8].setArena(-500,-480,-480,-10,1,1,25);
    jalanan[8].drawArena(0);

    /* Persimpangan KiriTengah */
    jalanan[9].setArena(-500,-480,-10,10,1,2,1);
    jalanan[9].drawArena(0);

    /* -------------------- 4 ------------------------ */
    /* Persimpangan KananTengah */
    jalanan[10].setArena(480,500,-10,10,1,2,1);
    jalanan[10].drawArena(0);

    jalanan[11].setArena(10,480,480,500,1,1,25);
    jalanan[11].drawArena(1);

    /* Persimpangan KananBawah */
    jalanan[12].setArena(480,500,480,500,1,2,1);
    jalanan[12].drawArena(0);

    jalanan[13].setArena(480,500,10,480,1,1,25);
    jalanan[13].drawArena(0);

    /* Persimpangna Bawah */
    jalanan[14].setArena(-10,10,480,500,1,2,1);
    jalanan[14].drawArena(0);

    /* -------------------- 5 ------------------------ */
    drawSidewalk(10,1,-10,-490,5,0.25,1,75); //1- kanan a
    drawSidewalk(-10,1,-10,-470,-5,0.25,1,75); //1 - kiri a

    drawSidewalk(15,1,-500,-5,-515,0.25,75,1); // 3 - atas
    drawSidewalk(-15,1,-475,-5,-465,0.25,75,1); //3 - bawah
    drawSidewalk(-475,1,-15,-460,-5,0.25,1,65); // 3 - kanan
    drawSidewalk(-500,1,15,-520,-5,0.25,1,65);// 3 - kiri

    drawSidewalk(-10,1,10,490,-5,0.25,1,75); //1 - kiri b
    drawSidewalk(10,1,10,470,5,0.25,1,75); //1 - kanan b

    drawSidewalk(15,1,-15,5,485,0.25,75,1); //2 - atas ka
    drawSidewalk(-15,1,-15,5,-465,0.25,75,1);//2 - atas ki

    drawSidewalk(-15,1,500,5,515,0.25,75,1); // 4 - bawah
    drawSidewalk(15,1,475,5,465,0.25,75,1); //4 - atas
    drawSidewalk(475,1,15,460,5,0.25,1,65); // 4 - kanan
    drawSidewalk(500,1,-15,520,5,0.25,1,65);// 4 - kiri

    drawSidewalk(15,1,15,-5,465,0.25,75,1); //2 - bawah ka
    drawSidewalk(-15,1,15,-5,-485,0.25,75,1);// 2 - bawah ki
}

void drawSkybox(float size){
    float sizeX = size;
    float sizeZ = size;
    float sizeY = -size+500;

    bool b1=glIsEnabled(GL_TEXTURE_2D);	//new, we left the textures turned on, if it was turned on
	glDisable(GL_LIGHTING);	//turn off lighting, when making the skybox
	glDisable(GL_DEPTH_TEST);	//turn off depth texting
	glEnable(GL_TEXTURE_2D);	//and turn on texturing
	glBindTexture(GL_TEXTURE_2D,SKYBACK);	//use the texture we want
	glBegin(GL_QUADS);	//and draw a face
		//back face
		glTexCoord2f(0,0);	//use the correct texture vector3d
		glVertex3f(sizeX/2,sizeY/2,sizeZ/2);	//and a vertex
		glTexCoord2f(1,0);	//and repeat it...
		glVertex3f(-sizeX/2,sizeY/2,sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(-sizeX/2,-sizeY/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(sizeX/2,-sizeY/2,sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYRIGHT);
	glBegin(GL_QUADS);
		//left face
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,sizeY/2,sizeZ/2);
		glTexCoord2f(1,0);
		glVertex3f(-sizeX/2,sizeY/2,-sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(-sizeX/2,-sizeY/2,-sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,-sizeY/2,sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYFRONT);
	glBegin(GL_QUADS);
		//front face
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,sizeY/2,-sizeZ/2);
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,sizeY/2,-sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,-sizeY/2,-sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,-sizeY/2,-sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYLEFT);
	glBegin(GL_QUADS);
		//right face
		glTexCoord2f(0,0);
		glVertex3f(sizeX/2,sizeY/2,-sizeZ/2);
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,sizeY/2,sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,-sizeY/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(sizeX/2,-sizeY/2,-sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYDOWN);
	glBegin(GL_QUADS);			//top face
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,sizeY/2,sizeZ/2);
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,sizeY/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,sizeY/2,-sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,sizeY/2,-sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYUP);
	glBegin(GL_QUADS);
		//bottom face
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,-sizeY/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,-sizeY/2,sizeZ/2);
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,-sizeY/2,-sizeZ/2);
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,-sizeY/2,-sizeZ/2);
	glEnd();
	glEnable(GL_LIGHTING);	//turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
	if(!b1)
		glDisable(GL_TEXTURE_2D);
}
