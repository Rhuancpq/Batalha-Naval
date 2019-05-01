//
// Created by rhuan on 13/04/19.
//

#ifndef EP1_UNIDADE_HPP
#define EP1_UNIDADE_HPP

#include <utility>
#include <vector>

using namespace std;

class Unidade{
private:
    pair<int, int> coordenadas;
    int vida;
    bool visibilidade = false;
    char selo;
    Unidade() = default;
public:
    Unidade(int x, int y, int vida, char selo);
    ~Unidade();
    void set_coordenadas(int x, int y);
    void set_vida(int vida);
    void soma_vida(int v);
    int get_vida();
    pair<int, int> get_coordenadas();
    void torna_visivel();
    bool get_visibilidade();
    void set_selo(char selo);
    char get_selo();
};

#endif //EP1_UNIDADE_HPP
