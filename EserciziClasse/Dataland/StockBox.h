//
// Created by Salvatore Bramante on 31/05/21.
//

#ifndef DATALAND_STOCKBOX_H
#define DATALAND_STOCKBOX_H

#include "Box.h"

class StockBox : public Box {
public:
    StockBox(int containerid=0,int boxid=0,float val=0.0,float wei=0.0,bool per=false)
            :container_id(containerid),Box(boxid,val,wei,per){}
private:
    int container_id;
};


#endif //DATALAND_STOCKBOX_H
