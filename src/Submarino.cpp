//
// Created by rhuan on 15/04/19.
//
#include "Submarino.hpp"

Submarino::Submarino(int x0, int y0, int x1, int y1) {
    set_corpo(0,x0,y0,2,'P');
    set_corpo(1,x1,y1,2,'P');
}

Submarino::~Submarino() = default;

void Submarino::defender(int x, int y) {
    bool pos_x0 = get_corpo(0)->get_coordenadas().first == x;
    bool pos_y0 = get_corpo(0)->get_coordenadas().first == y;
    bool pos_x1 = get_corpo(1)->get_coordenadas().first == x;
    bool pos_y1 = get_corpo(1)->get_coordenadas().first == y;
    if(pos_x0 && pos_y0){
        get_corpo(0)->soma_vida(-1);
    }else if(pos_x1 && pos_y1){
        get_corpo(1)->soma_vida(-1);
    }
}