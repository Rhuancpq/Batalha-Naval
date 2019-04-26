//
// Created by rhuan on 23/04/19.
//
#include "Porta_avioes.hpp"
#include "Embarcacao.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Porta_avioes::Porta_avioes(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    set_corpo(0,x0,y0,1,'P');
    set_corpo(1,x1,y1,1,'P');
    set_corpo(2,x2,y2,1,'P');
    set_corpo(3,x3,y3,1,'P');
}

Porta_avioes::~Porta_avioes() = default;

bool Porta_avioes::get_vivo() {
    bool a = get_corpo(0)->get_vida()>0 && get_corpo(1)->get_vida() > 0;
    bool b = get_corpo(2)->get_vida()>0 && get_corpo(3)->get_vida() > 0;
    return a&&b;
}

void Porta_avioes::defender(int x, int y) {
    srand(x*y);
    if(rand()%2){
        bool pos_x0 = get_corpo(0)->get_coordenadas().first == x;
        bool pos_y0 = get_corpo(0)->get_coordenadas().first == y;
        bool pos_x1 = get_corpo(1)->get_coordenadas().first == x;
        bool pos_y1 = get_corpo(1)->get_coordenadas().first == y;
        bool pos_x2 = get_corpo(2)->get_coordenadas().first == x;
        bool pos_y2 = get_corpo(2)->get_coordenadas().first == y;
        bool pos_x3 = get_corpo(3)->get_coordenadas().first == x;
        bool pos_y3 = get_corpo(3)->get_coordenadas().first == y;
        if(pos_x0 && pos_y0){
            get_corpo(0)->soma_vida(-1);
        }else if(pos_x1 && pos_y1){
            get_corpo(1)->soma_vida(-1);
        }else if(pos_x2 && pos_y2){
            get_corpo(2)->soma_vida(-1);
        }else if(pos_x3 && pos_y3){
            get_corpo(3)->soma_vida(-1);
        }
    }else{
        cout<<"Um Porta Aviões desviou do seu ataque"<<endl;
    }
}