//
// Created by rhuan on 18/04/19.
//
#include <iostream>
#include "Canoa.hpp"

void Canoa::defender(int x, int y) {
    cout<<"Você atacou uma canoa"<<endl;
    get_corpo(0)->soma_vida(-1);
    get_corpo(0)->torna_visivel();
}

Canoa::Canoa(int x, int y) {
    string t = "\033[5;91;48;5;18mX";
    set_corpo(0,x,y,1,t);
}

Canoa::~Canoa() = default;

bool Canoa::get_vivo() {
    return get_corpo(0)->get_vida() > 0;
}
