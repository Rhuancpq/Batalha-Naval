//
// Created by rhuan on 11/04/19.
//

#ifndef EP1_UNIDADE_H
#define EP1_UNIDADE_H

#include <utility>
#include <vector>

using namespace std;

class Unidade{
private:
    pair<int, int> coordenadas;
    int vida;
public:
    Unidade();
    ~Unidade();
    void set_coordenadas(int x, int y);
    void set_vida(int vida);
    int get_vida();
    pair<int, int> get_coordenadas();
};

#endif
