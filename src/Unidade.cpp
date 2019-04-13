//
// Created by rhuan on 11/04/19.
//
#include <utility>
#include "Unidade.hpp"

using namespace std;

void Unidade::set_coordenadas(int x, int y){
    coordenadas.first = x;
    coordenadas.second = y;
}

void Unidade::set_vida(int vida){
    this->vida = vida;
}

int Unidade::get_vida(){
    return vida;
}

pair<int, int> Unidade::get_coordenadas() {
    return coordenadas;
}