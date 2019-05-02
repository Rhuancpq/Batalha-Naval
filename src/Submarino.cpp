//
// Created by rhuan on 15/04/19.
//
#include <iostream>
#include "Submarino.hpp"
#include "Embarcacao.hpp"

Submarino::Submarino(int x0, int y0, int x1, int y1) {
    string t = "\033[92;48;5;18mS";
    set_corpo(0,x0,y0,2,t);
    set_corpo(1,x1,y1,2,t);
}

Submarino::~Submarino() = default;

bool Submarino::get_vivo() {
    return get_corpo(0)->get_vida()>0 && get_corpo(1)->get_vida() > 0;
}

void Submarino::defender(int x, int y) {
    string t = "\033[5;91;48;5;18mX";
    cout<<"Você atacou um submarino"<<endl;
    bool pos_x0 = get_corpo(0)->get_coordenadas().first == x;
    bool pos_y0 = get_corpo(0)->get_coordenadas().first == y;
    bool pos_x1 = get_corpo(1)->get_coordenadas().first == x;
    bool pos_y1 = get_corpo(1)->get_coordenadas().first == y;
    if(pos_x0 && pos_y0){
        get_corpo(0)->soma_vida(-1);
        get_corpo(0)->torna_visivel();
        if(get_corpo(0)->get_vida() <= 0){
            get_corpo(0)->set_selo(t);
            cout<<"Você destruiu um submarino"<<endl;
        }
    }else if(pos_x1 && pos_y1){
        get_corpo(1)->soma_vida(-1);
        get_corpo(1)->torna_visivel();
        if(get_corpo(1)->get_vida() <= 0){
            get_corpo(1)->set_selo(t);
            cout<<"Você destruiu um submarino"<<endl;
        }
    }
}