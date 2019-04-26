//
// Created by rhuan on 13/04/19.
//

#include "Embarcacao.hpp"

Embarcacao::~Embarcacao() = default;

void Embarcacao::set_corpo(int pos, int x, int y, int vida,char selo) {
    corpo[pos] = new Unidade(x,y,vida,selo);
}

Unidade * Embarcacao::get_corpo(int pos) {
    Unidade * temp = corpo[pos];
    return  temp;
}
