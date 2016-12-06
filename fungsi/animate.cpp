// how often the animate() function is called, in second
double animationInterval = 1.0/60;
double ticks = 0;

void animate(){
//    printf("anim Interval: %lf\n", animationInterval);
}

void fpsSetting () {

    // timing setup
    // leave this unchanged unless you know what you're doing
    double currentTime = glfwGetTime();
    while (currentTime / animationInterval > ticks) {
//        animate();

        ticks+=1;
        currentTime = glfwGetTime();
    }
}
