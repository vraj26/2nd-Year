#ifndef FOOD_H
#define FOOD_H

class Food
{
    private:
        objPos foodPos;

    public:
        //Food();
        Food();
        ~Food();

        void generateFood(objPosArrayList *blockOff); 
        

    
        void getFoodPos(objPos &returnPos);
};

#endif
