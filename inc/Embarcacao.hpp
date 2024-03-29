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
    virtual ~Embarcacao();
    void set_corpo(int pos, int x, int y, int vida, string selo);
    Unidade * get_corpo(int pos);
    virtual void defender(int x, int y) = 0;
    virtual bool get_vivo() = 0;
};

#endif //EP1_EMBARCACAO_HPP
