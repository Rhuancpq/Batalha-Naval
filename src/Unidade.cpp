//
// Created by rhuan on 11/04/19.
//
#include <utility>
#include "Unidade.hpp"

using namespace std;

Unidade::Unidade(int x, int y, int vida) {
    coordenadas.first = x;
    coordenadas.second = y;
    this->vida = vida;
}

Unidade::~Unidade() = default;

void Unidade::set_coordenadas(int x, int y){
    coordenadas.first = x;
    coordenadas.second = y;
}

void Unidade::set_vida(int v){
    this->vida = v;
}

void Unidade::soma_vida(int v) {
    this->vida += v;
}

int Unidade::get_vida(){
    return vida;
}

pair<int, int> Unidade::get_coordenadas() {
    return coordenadas;
}