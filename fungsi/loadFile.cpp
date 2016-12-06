#define fiCREATEMODEL(model); glmUnitize(model);glmFacetNormals(model);glmVertexNormals(model, 100.0);
#define SKYFRONT 3
#define SKYBACK  4
#define SKYLEFT  5
#define SKYRIGHT 6
#define SKYUP    7
#define SKYDOWN  8

GLMmodel* porsche = NULL;
GLMmodel* tank = NULL;
GLMmodel* porscheR = NULL;
GLMmodel* tree1 = NULL;
GLMmodel* tree2 = NULL;

void load_bmp(char *filename, unsigned int texture_id) {

    FILE *file;
    short int bpp;
    short int planes;
    long size;

    long imwidth;
    long imheight;
    char *imdata;

    if (!(file = fopen(filename, "rb"))) {
        fprintf(stderr, "Error: file %s not found!\n", filename);
    };
    fseek(file, 18, SEEK_CUR);

    fread(&imwidth, 4, 1, file);
    fread(&imheight, 4, 1, file);
    size = imwidth * imheight * 3;

    fread(&bpp, 2, 1, file);
    fread(&planes, 2, 1, file);

    fseek(file, 24, SEEK_CUR);
    imdata = (char *)malloc(size);

    fread(imdata, size, 1, file);

	char temp;
    for(long i = 0; i < size; i+=3){
        temp = imdata[i];
        imdata[i] = imdata[i+2];
        imdata[i+2] = temp;
    }

    fclose(file);

    glBindTexture(GL_TEXTURE_2D, texture_id); // now we bind the texture that we are working with

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imwidth, imheight, 0, GL_RGB, GL_UNSIGNED_BYTE, imdata);

    free(imdata); // free the texture
}

void glTga(void){
    glEnable (GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    loadTGA("texture/jalan2.tga",1);
    loadTGA("texture/perempatan.tga",2);

    /*Load Skybox*/
//    loadTGA("texture/skybox/sincity_ft.tga",SKYFRONT);
//    loadTGA("texture/skybox/sincity_bk.tga",SKYBACK);
//    loadTGA("texture/skybox/sincity_lf.tga",SKYLEFT);
//    loadTGA("texture/skybox/sincity_rt.tga",SKYRIGHT);
//    loadTGA("texture/skybox/sincity_up.tga",SKYUP);
//    loadTGA("texture/skybox/sincity_dn.tga",SKYDOWN);
    loadTGA("texture/skybox2/hills_ft.tga",SKYFRONT);
    loadTGA("texture/skybox2/hills_bk.tga",SKYBACK);
    loadTGA("texture/skybox2/hills_lf.tga",SKYLEFT);
    loadTGA("texture/skybox2/hills_rt.tga",SKYRIGHT);
    loadTGA("texture/skybox2/hills_up.tga",SKYUP);
    loadTGA("texture/skybox2/hills_dn.tga",SKYDOWN);

    loadTGA("texture/splash_load.tga",9);
    loadTGA("texture/bahujalan.tga",10);
}

void loadingScreen(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,9);
//    glColor3ub(212,0,12);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,0);
        glVertex2f(-400,-337.5);
        glTexCoord2f(0,1);
        glVertex2f(-400,337.5);
        glTexCoord2f(1,1);
        glVertex2f(400,337.5);
        glTexCoord2f(1,0);
        glVertex2f(400,-337.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void loadObj(){
    porsche = glmReadOBJ("obj/porsche.obj");
    tank = glmReadOBJ("obj/tank.obj");
    porscheR = glmReadOBJ("obj/Red-Porsche.obj");
    tree1 = glmReadOBJ("obj/tree.obj");
    tree2 = glmReadOBJ("obj/tree5.obj");

    fiCREATEMODEL(porsche);
    fiCREATEMODEL(tank);
    fiCREATEMODEL(porscheR);
    fiCREATEMODEL(tree1);
    fiCREATEMODEL(tree2);
}

void grid_floor(int baris, int kolom) {
    // draw grid on floor (0,0,0)
    int i;

    int kiri  = -kolom / 2;
    int kanan = kolom / 2;
    int bawah = -baris / 2;
    int atas  = baris / 2;

    glBegin(GL_LINES);
    glLineWidth(1);

    for (i = 0; i < baris + 1; i++) {
        glVertex3f(kiri, 0, baris / 2 - i);
        glVertex3f(kanan, 0, baris / 2 - i);
    }

    for (i = 0; i < kolom + 1; i++) {
        glVertex3f(kolom / 2 - i, 0, bawah);
        glVertex3f(kolom / 2 - i, 0, atas);
    }

    glEnd();
}

void putTree(float x,float y, float z, float scale){
    glPushMatrix();
        glTranslatef(x,y,z);
        glScalef(1,scale,1);
        glmDraw(tree1, GLM_SMOOTH|GLM_MATERIAL);
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
}

void loadArea(){
    glColor3f(1,1,1);
    grid_floor(1000,1000);
//    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, 1);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,0);
            glVertex3f(10,1,-500);
            glTexCoord2f(1,0);
            glVertex3f(-10,1,-500);
            glTexCoord2f(1,25);
            glVertex3f(-10,1,-10);
            glTexCoord2f(0,25);
            glVertex3f(10,1,-10);
        glEnd();
        glDisable(GL_TEXTURE_2D);
//    glPopMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, 1);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,0);
            glVertex3f(10,1,10);
            glTexCoord2f(1,0);
            glVertex3f(-10,1,10);
            glTexCoord2f(1,25);
            glVertex3f(-10,1,500);
            glTexCoord2f(0,25);
            glVertex3f(10,1,500);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        /* begin Persimpangan */
        glEnable(GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, 2);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,0);
            glVertex3f(10,1,-10);
            glTexCoord2f(1,0);
            glVertex3f(-10,1,-10);
            glTexCoord2f(1,1);
            glVertex3f(-10,1,10);
            glTexCoord2f(0,1);
            glVertex3f(10,1,10);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        /* end Persimpangan */

        glEnable(GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, 1);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,0);
            glVertex3f(500,1,-10);
            glTexCoord2f(1,0);
            glVertex3f(500,1,10);
            glTexCoord2f(1,25);
            glVertex3f(10,1,10);
            glTexCoord2f(0,25);
            glVertex3f(10,1,-10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, 1);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,0);
            glVertex3f(-500,1,-10);
            glTexCoord2f(1,0);
            glVertex3f(-500,1,10);
            glTexCoord2f(1,25);
            glVertex3f(-10,1,10);
            glTexCoord2f(0,25);
            glVertex3f(-10,1,-10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        drawSidewalk(10,1,-10,-490,5,0.25,1,75);
        drawSidewalk(-10,1,-10,-490,-5,0.25,1,75);
        drawSidewalk(-10,1,10,490,-5,0.25,1,75);
        drawSidewalk(10,1,10,490,5,0.25,1,75);
        drawSidewalk(15,1,-15,5,485,0.25,75,1);
        drawSidewalk(-15,1,-15,5,-485,0.25,75,1);
        drawSidewalk(15,1,15,-5,485,0.25,75,1);
        drawSidewalk(-15,1,15,-5,-485,0.25,75,1);
//        glClear(GL_COLOR_BUFFER_BIT);
}

void drawSkybox(float size){
    size = -size;
    float sizeX = -size;
    float sizeZ = -size;
    bool b1=glIsEnabled(GL_TEXTURE_2D);	//new, we left the textures turned on, if it was turned on
	glDisable(GL_LIGHTING);	//turn off lighting, when making the skybox
	glDisable(GL_DEPTH_TEST);	//turn off depth texting
	glEnable(GL_TEXTURE_2D);	//and turn on texturing
	glBindTexture(GL_TEXTURE_2D,SKYBACK);	//use the texture we want
	glBegin(GL_QUADS);	//and draw a face
		//back face
		glTexCoord2f(0,0);	//use the correct texture vector3d
		glVertex3f(sizeX/2,size/2,sizeZ/2);	//and a vertex
		glTexCoord2f(1,0);	//and repeat it...
		glVertex3f(-sizeX/2,size/2,sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(-sizeX/2,-size/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(sizeX/2,-size/2,sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYRIGHT);
	glBegin(GL_QUADS);
		//left face
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,size/2,sizeZ/2);
		glTexCoord2f(1,0);
		glVertex3f(-sizeX/2,size/2,-sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(-sizeX/2,-size/2,-sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,-size/2,sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYFRONT);
	glBegin(GL_QUADS);
		//front face
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,size/2,-sizeZ/2);
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,size/2,-sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,-size/2,-sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,-size/2,-sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYLEFT);
	glBegin(GL_QUADS);
		//right face
		glTexCoord2f(0,0);
		glVertex3f(sizeX/2,size/2,-sizeZ/2);
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,size/2,sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,-size/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(sizeX/2,-size/2,-sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYDOWN);
	glBegin(GL_QUADS);			//top face
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,size/2,sizeZ/2);
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,size/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,size/2,-sizeZ/2);
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,size/2,-sizeZ/2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,SKYUP);
	glBegin(GL_QUADS);
		//bottom face
		glTexCoord2f(1,1);
		glVertex3f(sizeX/2,-size/2,sizeZ/2);
		glTexCoord2f(0,1);
		glVertex3f(-sizeX/2,-size/2,sizeZ/2);
		glTexCoord2f(0,0);
		glVertex3f(-sizeX/2,-size/2,-sizeZ/2);
		glTexCoord2f(1,0);
		glVertex3f(sizeX/2,-size/2,-sizeZ/2);
	glEnd();
	glEnable(GL_LIGHTING);	//turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
	if(!b1)
		glDisable(GL_TEXTURE_2D);
}
