//
// Created by rhuan on 15/04/19.
//

#ifndef EP1_SUBMARINO_HPP
#define EP1_SUBMARINO_HPP
#include "Embarcacao.hpp"

class Submarino : public Embarcacao{
private:
    Submarino() = default;
public:
    Submarino(int x0, int y0, int x1, int y1);
    ~Submarino() override ;
    void defender(int x, int y) override;
    bool get_vivo()override;
};

#endif //EP1_SUBMARINO_HPP
