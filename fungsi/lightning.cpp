void lighting(long long a){

    const GLfloat light_ambient[]  = { 1.0f*a, 1.0f*a, 1.0f*a, 1.0f*a };
    const GLfloat light_diffuse[]  = { 1.0f*a, 1.0f*a, 1.0f*a, 1.0f*a };
    const GLfloat light_specular[] = { 1.0f*a, 1.0f*a, 1.0f*a, 1.0f*a };
    const GLfloat light_position[] = { -7.0f*a, 5.0f*a, 13.0f*a, 1.0f*a };

    const GLfloat mat_ambient[]    = { 1.0f*a, 1.f*a, 1.f*a, 1.0f*a };
    const GLfloat mat_diffuse[]    = { 1.0f*a, 1.f*a, 1.f*a, 1.0f*a };
    const GLfloat mat_specular[]   = { 1.0f*a, 1.0f*a, 1.0f*a, 1.0f*a };
    const GLfloat high_shininess[] = { 100.0f *a};

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glShadeModel(GL_FLAT);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void lighting2(){

  //Mengaktifkan efek lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);

	const GLfloat light_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f };//ubah bayangan ?
	const GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular[]= {1.0f, 1.0f, 1.0f, 1.0f };//warna
	const float light_position[] = {0.0, 1.0, 1.0, 0.0 }; //tambah pasangan

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); //tambah pasangan

	glEnable(GL_COLOR_MATERIAL);

	const GLfloat mat_ambient[] = { 1.0f, 1.f, 1.0f, 1.0f };//ubah bayangan ?
	const GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.f, 1.0f };
	const GLfloat mat_specular[] = { 1.f, 1.f, 1.0f, 1.0f };//warna
	const GLfloat high_shininess[]= { 25.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	//glShadeModel(GL_FLAT);
}
