
void viewportMobil(GLFWwindow* window){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90,1,1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    setCamera();
}

void viewportLoad(GLFWwindow* window)
{

    glfwGetFramebufferSize(window, &widthWindow, &heightWindow);
    glViewport(0, 0, widthWindow, heightWindow);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-widthWindow/(double)2, widthWindow/(double)2, -heightWindow/(double)2, heightWindow/(double)2, 1.f, -1.f); // f itu float, bisa diganti jadi 1.0float
    //glOrtho(bataskiri, bataskanan, batas bawah, batasatas, batasdepan, batasbelakang)
    glMatrixMode(GL_MODELVIEW); //harus ada (syntax dari openGL nya)
    glLoadIdentity();
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position1); //tambah pasangan
}


GLFWwindow* createWindow(){
//    if(fullScreen == 'Y' || fullScreen == 'y')
//        return glfwCreateWindow(widthWindow, heightWindow, "Glu Tag Racing", glfwGetPrimaryMonitor(), NULL);
//    else
        return glfwCreateWindow(widthWindow, heightWindow, "Glu Tag Racing", NULL, NULL);
}
