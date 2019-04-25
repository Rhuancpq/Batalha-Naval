//
// Created by rhuan on 23/04/19.
//

#ifndef EP1_MAPA_HPP
#define EP1_MAPA_HPP

#include "Embarcacao.hpp"
#include <utility>
#include <string>

class Mapa{
private:
    string jogador;
    pair<bool, Embarcacao*> carta[13][13];
    int posicao_unidades[13][13] = {};
    Mapa();
public:
    Mapa(const string &jogador);
    void imprimir();
    ~Mapa();
};

#endif //EP1_MAPA_HPP
