//
// Created by rhuan on 23/04/19.
//

#ifndef EP1_PORTA_AVIOES_HPP
#define EP1_PORTA_AVIOES_HPP

#include "Embarcacao.hpp"

class Porta_avioes : public Embarcacao{
private:
    Porta_avioes() = default;
public:
    Porta_avioes(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
    ~Porta_avioes()override;
    void defender(int x, int y) override;
    bool get_vivo()override;
};

#endif //EP1_PORTA_AVIOES_HPP
