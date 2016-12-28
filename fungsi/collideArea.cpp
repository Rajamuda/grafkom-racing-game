#define ADD 3.5 //toleransi

bool sudahLewat = false;
bool sudahLewat2 = false;

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

bool checkFinish(float xA, float yA, float zA, int id){
    std::map<std::string, float> theLine = line.getArena();

    //check finish line
    if(xA<=theLine["x1"] && xA>=theLine["x0"] && zA<=(-1*theLine["z0"]) && zA>=(-1*theLine["z1"])){
        if(id == 0)
            sudahLewat = false;
        else
            sudahLewat2 = false;
    }

    if(!sudahLewat){
        //checkpoint
        if(xA<=theLine["x1"] && xA>=theLine["x0"] && zA>=theLine["z0"] && zA<=theLine["z1"]){
            if(id == 0)
                sudahLewat = true;
            else
                sudahLewat2 = true;
            return true;
        }
    }else{
        return false;
    }
//
    return false;
}

