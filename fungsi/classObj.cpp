class Kamera{
    //untuk kamera tiap mobil
};

class Mobil{
    float p, l, t;
    float weight;
    float maxspeed;
    float acceleration;
    float breaking;
    float speed;
    GLMmodel* model;


    public:
        Mobil(){
            p = l = t = 0.0;
            weight = 0.0;
            maxspeed = 0.0;
            acceleration: 0.0;
            speed = 0.0;
            model = NULL;
        }

        void setMobil(float p, float l, float t, float weight, float acceleration, float maxspeed, float breaking, GLMmodel* model){
            this->p = p;
            this->l = l;
            this->t = t;
            this->weight = weight;
            this->acceleration = acceleration;
            this->maxspeed = maxspeed;
            this->breaking = breaking;
            this->model = model;
        }

        void setLocation(float xcar, float ycar, float zcar, float rotasi){
            glPushMatrix();
                glTranslatef(xcar,ycar,zcar);
                glRotatef(rotasi,0,1,0);
                glRotatef(180,0,1,0);
                glTranslatef(0,ycar,0.5);
                glScalef(1/this->p,1/this->l,1/this->t);
                glmDraw(this->model, GLM_SMOOTH|GLM_MATERIAL);
            glPopMatrix();
        }

        float getMaxSpeed(){
            return this->maxspeed;
        }

        float getWeight(){
            return this->weight;
        }

        float getAccel(){
            return this->acceleration;
        }

        float getBreaking(){
            return this->breaking;
        }

        float getSpeed(int satuan=0){
            if(satuan == 0)
                return this->speed;
            if(satuan == 1)
                return this->speed*3.6;
        }

        void setSpeed(float speed, int status=2){
            if(status == 0) //kendaraan maju
                this->speed += speed;
            else if(status == 1) //kendaraan mundur
                this->speed -= speed;
            else if(status == 2) //kendaraan dipaksa berhenti
                this->speed = speed;
        }
};

class Arena{
    //for map area
};

// OBJECT DECLARATION
Mobil *mobil = new Mobil[MAX_P];
