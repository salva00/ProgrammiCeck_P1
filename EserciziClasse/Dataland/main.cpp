#include <iostream>
#include "Container.h"
#include "LinkedQueue.h"
#include "StockBox.h"
#include <fstream>

#define MAX_VALUE 45

LinkedList<Box> clearance(LinkedQueue<Container> & cont){
    float weightTot,valueTot;
    for (int box=0; box<cont.front().getNBox();box++){
        weightTot += cont.front().boxes[box].weight;
        valueTot += cont.front().boxes[box].value;
    }
    std::cout<< "Container Id: "<< cont.front().getIdContainer()<<"\n";

    std::cout<< "Value tot: " << valueTot<<"\n";
    std::cout<< "Weight tot: " << weightTot<<"\n";
    if (valueTot>MAX_VALUE){
        LinkedList<Box> stock;
        for (int box=0; box<cont.front().getNBox();box++){
            Box b = cont.front().boxes[box];
            if (b.perishable == true){
                StockBox temp(cont.front().getIdContainer(),b.box_id,b.value,b.weight,b.perishable);
                stock.addFront(temp);
            }
        }
        return stock;
    }
    cont.dequeue();
}

LinkedList<Box> clearence_excess(int id,LinkedQueue<Container> & cont){

    if (!id == cont.front().getIdContainer()){
        cont.dequeue();
    }else{
        LinkedList<Box>box=cont.front().boxes;
        LinkedList<Box> newList;

        for (int i=0;i<box.size();i++){
            Box current = box[i];
            if(current.perishable== false){
                newList.addFront(current);
            }
        }
        return newList;
    }
}

int main() {
    LinkedQueue<Container> containers;

    std::ifstream contFile("containers.txt", std::ios::in);
    if (!contFile){
        std::cerr<<"File not found";
        exit(EXIT_FAILURE);
    } else{

        int num;
        std::string tempA;
        std::string st;
        std::string carrier;
        int boxid;
        float weigh;
        float value;
        bool perishable;
        int nbox;
        while ( !contFile.eof()){
            contFile>>num;
            getline(contFile,tempA);
            getline(contFile,st);
            getline(contFile,carrier);
            contFile>>nbox;
            Container temp(num,st,carrier,nbox);
            for (int i=0; i<nbox;i++){
                contFile>>boxid>>weigh>>value>>perishable;
                temp.addToBoxes(Box(boxid,weigh,value,perishable));
            }
            containers.enqueue(temp);
        }
    }
    LinkedList<Box> stock = clearance(containers);
    LinkedList<Box> newStock = clearence_excess(containers.front().getIdContainer(),containers);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
