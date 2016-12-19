#define fiCREATEMODEL(model); glmUnitize(model);glmFacetNormals(model);glmVertexNormals(model, 100.0);
#define SKYFRONT 3
#define SKYBACK  4
#define SKYLEFT  5
#define SKYRIGHT 6
#define SKYUP    7
#define SKYDOWN  8

#define NEW_GAME 11
#define ABOUT    12
#define EXIT     13
#define CONTINUE 19
#define EXIT_C   20

#define F_LINE   21


GLMmodel* porsche = NULL;
GLMmodel* tank = NULL;
GLMmodel* porscheR = NULL;
GLMmodel* tree1 = NULL;
GLMmodel* tree2 = NULL;

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
    loadTGA("texture/skybox2/deception_pass_ft.tga",SKYFRONT);
    loadTGA("texture/skybox2/deception_pass_bk.tga",SKYBACK);
    loadTGA("texture/skybox2/deception_pass_lf.tga",SKYLEFT);
    loadTGA("texture/skybox2/deception_pass_rt.tga",SKYRIGHT);
    loadTGA("texture/skybox2/deception_pass_up.tga",SKYUP);
    loadTGA("texture/skybox2/deception_pass_dn.tga",SKYDOWN);

    loadTGA("texture/splash_load.tga",9);
    loadTGA("texture/bahujalan.tga",10);

    loadTGA("texture/menu/menu1.tga", NEW_GAME);
    loadTGA("texture/menu/menu2.tga", ABOUT);
    loadTGA("texture/menu/menu3.tga", EXIT);
    loadTGA("texture/menu/menuO1.tga", CONTINUE);
    loadTGA("texture/menu/menuO2.tga", EXIT_C);

    loadTGA("texture/count/GO.tga", 14);
    loadTGA("texture/count/1.tga", 15);
    loadTGA("texture/count/2.tga", 16);
    loadTGA("texture/count/3.tga", 17);
    loadTGA("texture/count/4.tga", 18);

    loadTGA("texture/garis.tga", F_LINE);
}

void loadMenu(){
    glEnable(GL_TEXTURE_2D);
    if(screenState == 0)
        glBindTexture(GL_TEXTURE_2D, NEW_GAME);
    else if(screenState == 1)
        glBindTexture(GL_TEXTURE_2D, ABOUT);
    else if(screenState == 2)
        glBindTexture(GL_TEXTURE_2D, EXIT);
    else if(screenState == 5)
        glBindTexture(GL_TEXTURE_2D, CONTINUE);
    else if(screenState == 6)
        glBindTexture(GL_TEXTURE_2D, EXIT_C);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
		glVertex3f(-1024/1.5, -1024/2.75, 0);
		glTexCoord2f(1, 0);
		glVertex3f(1024/1.5, -1024/2.75, 0);
		glTexCoord2f(1, 1);
		glVertex3f(1024/1.5, 1024/2.75, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-1024/1.5, 1024/2.75, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
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
