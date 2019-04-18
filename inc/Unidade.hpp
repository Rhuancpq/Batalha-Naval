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
public:
    Unidade(int x, int y, int vida);
    ~Unidade();
    void set_coordenadas(int x, int y);
    void set_vida(int vida);
    void soma_vida(int v);
    int get_vida();
    pair<int, int> get_coordenadas();
};

#endif //EP1_UNIDADE_HPP
