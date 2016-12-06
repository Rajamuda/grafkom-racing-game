bool collideArea(float xA, float yA, float zA){
//    char* syarat;
//    syarat = (char*)malloc(sizeof(syarat));

    if((xA<10 && xA>-10 && zA<495 && zA>-495) || (zA<10 && zA>-10 && xA<495 && xA>-495)){
        return false;
    }else{
        return true;
    }

}
