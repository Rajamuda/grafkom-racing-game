#define ADD 5.5
bool sudahLewat = false;

bool collideArea(float xA, float yA, float zA){
    bool isCollide = true;

    for(int i=0; i<MAX_J; i++){
        std::map<std::string, float> theMap = jalanan[i].getArena();

        if(xA<=theMap["x1"]+ADD && xA>=theMap["x0"]-ADD && zA<=theMap["z0"]+ADD && zA>=theMap["z1"]-ADD)
            isCollide=false;
        if(xA<=theMap["x1"]+ADD && xA>=theMap["x0"]-ADD && zA>=theMap["z0"]-ADD && zA<=theMap["z1"]+ADD)
            isCollide=false;
        if(xA>=theMap["x1"]-ADD && xA<=theMap["x0"]+ADD && zA>=theMap["z0"]-ADD && zA<=theMap["z1"]+ADD)
            isCollide=false;
        if(xA>=theMap["x1"]-ADD && xA<=theMap["x0"]+ADD && zA<=theMap["z0"]+ADD && zA>=theMap["z1"]-ADD)
            isCollide=false;
    }

    if(!isCollide)
        return false;
    else
        return true; //true

}

bool checkFinish(float xA, float yA, float zA){
    std::map<std::string, float> theLine = line.getArena();

    if(xA<=theLine["x1"] && xA>=theLine["x0"] && zA<=(-1*theLine["z0"]) && zA>=(-1*theLine["z1"])){
        sudahLewat = false;
    }

    if(!sudahLewat){
//        printf("zA: %f\tz0: %f\n",ceil(zA),theLine["z0"]);
        if(xA<=theLine["x1"] && xA>=theLine["x0"] && zA>=theLine["z0"] && zA<=theLine["z1"]){
            sudahLewat = true;
            return true;
        }
    }else{
        return false;
    }

    return false;
}
