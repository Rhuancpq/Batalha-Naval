//
// Created by rhuan on 18/04/19.
//
#include "Canoa.hpp"

void Canoa::defender() {
    get_corpo(0)->soma_vida(-1);
    get_corpo(0)->torna_visivel();
}

Canoa::Canoa(int x, int y) {
    set_corpo(0,x,y,1,'X');
}

Canoa::~Canoa() = default;
