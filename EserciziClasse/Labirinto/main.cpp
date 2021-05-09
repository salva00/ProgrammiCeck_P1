#include <iostream>
//#include "ArrayStack.h"
#include <array>
#include <stack>

enum class Direzione: int{
    NORD_OVEST,
    NORD,
    NORD_EST,
    OVEST,
    CENTER,
    EST,
    SUD_OVEST,
    SUD,
    SUD_EST

};

const std::array<Direzione,9> directions{Direzione::NORD_OVEST,
                                         Direzione::NORD,
                                         Direzione::NORD_EST,
                                         Direzione::OVEST,
                                         Direzione::CENTER,
                                         Direzione::EST,
                                         Direzione::SUD_OVEST,
                                         Direzione::SUD,
                                         Direzione::SUD_EST};

struct Movimento{
    int x;
    int y;
    Direzione dir;
};



Movimento getMovement(const Movimento* curr, const Direzione dir){
    Movimento next;
    switch (dir) {
        case Direzione::NORD_OVEST :
            next.x=curr->x-1;
            next.y=curr->y-1;
            break;
        case Direzione::NORD :
            next.x=curr->x-1;
            next.y=curr->y;
            break;
        case Direzione::NORD_EST :
            next.x=curr->x-1;
            next.y=curr->y+1;
            break;
        case Direzione::OVEST :
            next.x=curr->x;
            next.y=curr->y-1;
            break;
        case Direzione::CENTER :
            next.x=curr->x;
            next.y=curr->y;
            break;
        case Direzione::EST :
            next.x=curr->x;
            next.y=curr->y+1;
            break;
        case Direzione::SUD_OVEST :
            next.x=curr->x+1;
            next.y=curr->y-1;
            break;
        case Direzione::SUD :
            next.x=curr->x;
            next.y=curr->y+1;
            break;
        case Direzione::SUD_EST :
            next.x=curr->x+1;
            next.y=curr->y+1;
            break;
    }
    return next;
}



int       labirinto [11][15] = { 0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,
                                 1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,
                                 0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,
                                 1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,
                                 1,1,0,1,0,0,1,0,1,1,1,0,0,1,1,
                                 0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,
                                 0,1,1,1,1,0,0,1,1,0,1,1,0,1,1,
                                 0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,
                                 1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,
                                 0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,
                                 0,1,0,0,1,1,1,1,1,0,1,1,1,1,0
                                };



bool moveIsValid(const Movimento* curr, const Movimento* next){
    if( (curr->x==0 && next->x==-1)||   //bordo superiore
        (curr->y==0 && next->y==-1)||   //bordo sinistro
        (curr->x ==10 && next->x==11)|| //bordo inferiore
        (curr->y==14&&next->y==15) ){   //bordo destro
        return false;
    }
    if(labirinto[next->x][next->y]!=0){
        return false;
    }
    return true;
}


bool existAValidMove(Movimento* curr){
    Direzione prev = curr->dir;
    for(auto dir : directions ){
        Movimento next = getMovement(curr,dir);
        if(moveIsValid(curr,&next)&&(dir!=Direzione::CENTER)&&(dir!=prev)){
            curr->dir=dir;
            curr->x=next.x;
            curr->y=next.y;
            return true;
        }
    }
    return false;
}

void resolveLabirint(){
    std::stack<Movimento> mosse;
    int start = 4;
    mosse.push({0,0, Direzione::NORD});
    while (!mosse.empty()){
        Movimento move = mosse.top();
        mosse.pop();
        while (existAValidMove(&move)){
            Movimento next{move.x,move.y, move.dir};
            if(next.x==9 && next.y==14){
                std::cout<<"HAI VINTO"<<std::endl;
            }else if(moveIsValid(&move,&next)){
                labirinto[move.x][move.y]=-1;
                next.dir=directions[start++];
                mosse.push(next);
                move.x=next.x;
                move.y=next.y;
                move.dir=Direzione::CENTER;
            }else{
                move.dir=directions[start++];
            }
        }
    }

}

int main() {
    std::cout << "===START===" << std::endl;

    resolveLabirint();

    std::cout << "===END===" << std::endl;
    return 0;
}
