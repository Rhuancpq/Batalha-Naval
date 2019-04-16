//
// Created by rhuan on 13/04/19.
//

#ifndef EP1_EMBARCACAO_HPP
#define EP1_EMBARCACAO_HPP

#include <vector>
#include "Unidade.hpp"
using namespace std;

class Embarcacao{
private:
    vector<Unidade*>corpo;
public:
    Embarcacao();
    ~Embarcacao();
    virtual void defender() = 0;
};

#endif //EP1_EMBARCACAO_HPP
