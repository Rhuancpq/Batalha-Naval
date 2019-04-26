//
// Created by rhuan on 18/04/19.
//

#ifndef EP1_CANOA_HPP
#define EP1_CANOA_HPP

#include "Embarcacao.hpp"

class Canoa : public Embarcacao{
private:
    Canoa();
public:
    ~Canoa() override;
    Canoa(int x, int y);
    void defender(int x, int y) override;
    bool get_vivo() override;
};

#endif //EP1_CANOA_HPP
