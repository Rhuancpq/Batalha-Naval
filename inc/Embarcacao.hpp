//
// Created by rhuan on 13/04/19.
//

#ifndef EP1_EMBARCACAO_HPP
#define EP1_EMBARCACAO_HPP

#include <vector>
#include <utility>
#include "Unidade.hpp"
using namespace std;

class Embarcacao{
private:
    Unidade * corpo[4] = {};
public:
    void set_corpo(int pos, int x, int y, int vida);
    virtual void defender() = 0;
    Unidade * get_corpo(int pos);
};

#endif //EP1_EMBARCACAO_HPP
