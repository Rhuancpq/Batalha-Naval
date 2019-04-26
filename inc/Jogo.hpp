//
// Created by rhuan on 23/04/19.
//

#ifndef EP1_JOGO_HPP
#define EP1_JOGO_HPP

#include "Embarcacao.hpp"
#include <vector>
#include <utility>
#include <string>

class Jogo{
private:
    vector<Embarcacao*> Embarcacoes;
    pair<bool, Embarcacao*> Mapa[13][13];
    int posicao_unidades[13][13] = {};
    Jogo();
public:
    Jogo(const string &jogador, const string &mapa);
    void pre_inicializar();
    void imprimir();
    void limpar();
    bool condicao_de_vit();
    ~Jogo();
    void atacar(int x, int y);
};

#endif //EP1_JOGO_HPP
