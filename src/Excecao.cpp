#include <Excecao.hpp>

//
// Created by rhuan on 30/04/19.
//

const char * Excecao::what() const noexcept{
    return mensagem;
}

