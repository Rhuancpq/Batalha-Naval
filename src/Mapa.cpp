//
// Created by rhuan on 23/04/19.
//
#include "Mapa.hpp"
#include "Embarcacao.hpp"
#include "Canoa.hpp"
#include "Porta_avioes.hpp"
#include "Submarino.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Mapa::Mapa(const string &jogador) {
    fstream file;
    file.open("map_1.txt");
    string buff;
    while(true){
        getline(file,buff);
        cout<<buff<<endl;
        if(buff == jogador) break;
    }
    while(true){
        if(file.eof()) break;
        int x,y;
        string tipo, orientacao;
        getline(file, buff);
        if((buff == "# player_2")) break;
        if(buff[0] == 13 || buff == "\r" || buff.empty()){
            continue;
        }
        stringstream f;
        f<<buff;
        f>>x>>y>>tipo>>orientacao;
        if(tipo == "canoa"){
            carta[x][y].first = true;
            carta[x][y].second = new Canoa(x,y);
            posicao_unidades[x][y] = 0;
        }else if(tipo == "submarino"){
            carta[x][y].first = true;
            int x1,y1;
            if(orientacao == "direita"){
                x1 = x;
                y1 = y+1;
            }else if(orientacao == "esquerda"){
                x1 = x;
                y1 = y-1;
            }else if(orientacao == "cima"){
                x1 = x-1;
                y1 = y;
            }else if(orientacao == "baixo"){
                x1 = x+1;
                y1 = y;
            }else{
                x1 = 15;
                y1 = 15;
            }
            carta[x][y].second = new Submarino(x,y,x1,y1);
            carta[x1][y1].second = new Submarino(x,y,x1,y1);
            carta[x1][y1].first = true;
            posicao_unidades[x][y] = 0;
            posicao_unidades[x1][y1] = 1;
        }else if(tipo == "porta-avioes"){
            carta[x][y].first = true;
            int x0,x1,x2,x3,y0,y1,y2,y3;
            if(orientacao == "direita"){
                x0 = x1 = x2 = x3 =x;
                y0 = y;
                y1 = y+1;
                y2 = y+2;
                y3 = y+3;
            }else if(orientacao == "esquerda"){
                x0 = x1 = x2 = x3 =x;
                y0 = y;
                y1 = y-1;
                y2 = y-2;
                y3 = y-3;
            }else if(orientacao == "cima"){
                y0 = y1 = y2 = y3 =y;
                x0 = x;
                x1 = x-1;
                x2 = x-2;
                x3 = x-3;
            }else if(orientacao == "baixo"){
                y0 = y1 = y2 = y3 =y;
                x0 = x;
                x1 = x+1;
                x2 = x+2;
                x3 = x+3;
            }else{
                y0 = y1 = y2 = y3 =15;
                x0 = 15;
                x1 = 15;
                x2 = 15;
                x3 = 15;
            }
            carta[x0][y0].second = new Porta_avioes(x0,y0,x1,y1,x2,y2,x3,y3);
            carta[x1][y1].second = new Porta_avioes(x0,y0,x1,y1,x2,y2,x3,y3);
            carta[x2][y2].second = new Porta_avioes(x0,y0,x1,y1,x2,y2,x3,y3);
            carta[x3][y3].second = new Porta_avioes(x0,y0,x1,y1,x2,y2,x3,y3);
            carta[x1][y1].first = true;
            carta[x2][y2].first = true;
            carta[x3][y3].first = true;
            posicao_unidades[x0][y0] = 0;
            posicao_unidades[x1][y1] = 1;
            posicao_unidades[x2][y2] = 2;
            posicao_unidades[x3][y3] = 3;
        }
    }
}

Mapa::Mapa() = default;

Mapa::~Mapa() = default;

void Mapa::imprimir() {
    cout<<"~~~A~~~B~~~C~~~D~~~E~~~F~~~"<<
        "G~~~H~~~I~~~J~~~K~~~L~~~M~~"<<endl;
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 13; ++k) {
                if(k == 0 && j%4 == 1){
                    if(i < 10) cout<<" ";
                    cout<<i;
                }else if(k == 0 && j%3 == 2){
                    cout<<"~~";
                }else if(k == 0 && j%3 == 0){
                    cout<<" |";
                }
                switch (j%3){
                    case 0:
                        cout<<"   |";
                        break;
                    case 1: {
                        if(!carta[i][k].first) {
                            cout <<"   |";
                        }else{
                            cout<<" ";
                            if(carta[i][k].second->get_corpo(posicao_unidades[i][k])->get_visibilidade()){
                                cout<<carta[i][k].second->get_corpo(posicao_unidades[i][k])->get_selo()<<" |";
                            }
                        }
                        break;
                    }
                    case 2:
                        cout<<"~~~~";
                        break;
                }
            }
            cout<<endl;
        }
    }
}