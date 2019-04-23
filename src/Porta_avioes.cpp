//
// Created by rhuan on 23/04/19.
//
#include "Porta_avioes.hpp"
#include "Embarcacao.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Porta_avioes::Porta_avioes(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    set_corpo(0,x0,y0,1);
    set_corpo(1,x1,y1,1);
    set_corpo(2,x2,y2,1);
    set_corpo(3,x3,y3,1);
}

Porta_avioes::~Porta_avioes() = default;

void Porta_avioes::defender(int x, int y) {
    srand(x*y);
    if(rand()%2){
        bool posx0 = get_corpo(0)->get_coordenadas().first == x;
        bool posy0 = get_corpo(0)->get_coordenadas().first == y;
        bool posx1 = get_corpo(1)->get_coordenadas().first == x;
        bool posy1 = get_corpo(1)->get_coordenadas().first == y;
        bool posx2 = get_corpo(2)->get_coordenadas().first == x;
        bool posy2 = get_corpo(2)->get_coordenadas().first == y;
        bool posx3 = get_corpo(3)->get_coordenadas().first == x;
        bool posy3 = get_corpo(3)->get_coordenadas().first == y;
        if(posx0 && posy0){
            get_corpo(0)->soma_vida(-1);
        }else if(posx1 && posy1){
            get_corpo(1)->soma_vida(-1);
        }else if(posx2 && posy2){
            get_corpo(2)->soma_vida(-1);
        }else if(posx3 && posy3){
            get_corpo(3)->soma_vida(-1);
        }
    }else{
        cout<<"Um Porta Aviões desviou do seu ataque"<<endl;
    }
}