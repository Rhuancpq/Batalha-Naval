//
// Created by rhuan on 15/04/19.
//

#ifndef EP1_SUBMARINO_HPP
#define EP1_SUBMARINO_HPP
#include "Embarcacao.hpp"

class Submarino : public Embarcacao{
public:
    Submarino();
    ~Submarino();
    void defender(int x, int y);
};

#endif //EP1_SUBMARINO_HPP
