//
// Created by rhuan on 30/04/19.
//

#ifndef EP1_EXCECAO_HPP
#define EP1_EXCECAO_HPP
#include <exception>
using namespace std;

class Excecao : public exception{
private:
    const char * mensagem;
    Excecao() = default;
public:
    Excecao(const char * s) noexcept(false) : mensagem(s) {};
    const char * what() const noexcept override;

};

#endif //EP1_EXCECAO_HPP
