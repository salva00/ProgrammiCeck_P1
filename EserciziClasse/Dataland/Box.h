//
// Created by Salvatore Bramante on 31/05/21.
//

#ifndef DATALAND_BOX_H
#define DATALAND_BOX_H


class Box {
private:
    friend class Container;

public:
    Box(int boxid=0,float val=0.0,float wei=0.0,bool per=false):box_id(boxid),value(val),weight(wei),perishable(per){}
    int box_id;
    float weight;
    float value;
    bool perishable;

};


#endif //DATALAND_BOX_H
