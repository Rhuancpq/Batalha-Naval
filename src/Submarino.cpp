//
// Created by rhuan on 15/04/19.
//
#include "Submarino.hpp"

Submarino::Submarino(int x0, int y0, int x1, int y1) {
    auto * temp1 = new pair<int,int>(x0,y0);
    auto * temp2 = new pair<int,int>(x1,y1);
    set_corpo(0,temp1,2);
    set_corpo(1,temp2,2);
}

void Submarino::defender(int x, int y) {

}