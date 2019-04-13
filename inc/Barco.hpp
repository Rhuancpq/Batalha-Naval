//
// Created by rhuan on 13/04/19.
//

#ifndef EP1_BARCO_HPP
#define EP1_BARCO_HPP

#include <vector>
#include "Unidade.hpp"
using namespace std;

class Barco{
private:
    Unidade * corpo[];
public:
    Barco();
    ~Barco();
    virtual void defender() = 0;
};

#endif //EP1_BARCO_HPP
