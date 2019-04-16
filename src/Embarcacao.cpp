//
// Created by rhuan on 13/04/19.
//

#include "Embarcacao.hpp"

void Embarcacao::set_corpo(int pos, pair<int, int> * coord, int vida) {
    corpo[pos] = new Unidade(coord->first,coord->second,vida);
}

Unidade * Embarcacao::get_corpo(int pos) {
    Unidade * temp = corpo[pos];
    return  temp;
}