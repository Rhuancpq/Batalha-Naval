//
// Created by rhuan on 15/04/19.
//
#include "Submarino.hpp"

Submarino::Submarino(int x0, int y0, int x1, int y1) {
    set_corpo(0,x0,y0,2);
    set_corpo(1,x1,y1,2);
}

Submarino::~Submarino() = default;

void Submarino::defender(int x, int y) {
    bool posx0 = get_corpo(0)->get_coordenadas().first == x;
    bool posy0 = get_corpo(0)->get_coordenadas().first == y;
    bool posx1 = get_corpo(0)->get_coordenadas().first == x;
    bool posy1 = get_corpo(0)->get_coordenadas().first == y;
    if(posx0 && posy0){
        get_corpo(0)->soma_vida(-1);
    }else if(posx1 && posy1){
        get_corpo(1)->soma_vida(-1);
    }
}