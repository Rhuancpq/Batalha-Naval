//
// Created by rhuan on 23/04/19.
//
#include "Jogo.hpp"
#include "Embarcacao.hpp"
#include "Canoa.hpp"
#include "Porta_avioes.hpp"
#include "Submarino.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Jogo::Jogo(const string &jogador, const string &mapa) {
    pre_inicializar();
    fstream file;
    file.open(mapa);
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
            Mapa[x][y].first = true;
            Mapa[x][y].second = new Canoa(x,y);
            Embarcacoes.push_back(Mapa[x][y].second);
            posicao_unidades[x][y] = 0;
        }else if(tipo == "submarino"){
            Mapa[x][y].first = true;
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
            Mapa[x][y].second = new Submarino(x,y,x1,y1);
            Mapa[x1][y1].second = Mapa[x][y].second;
            Embarcacoes.push_back(Mapa[x][y].second);
            Mapa[x1][y1].first = true;
            posicao_unidades[x][y] = 0;
            posicao_unidades[x1][y1] = 1;
        }else if(tipo == "porta-avioes"){
            Mapa[x][y].first = true;
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
            Mapa[x0][y0].second = new Porta_avioes(x0,y0,x1,y1,x2,y2,x3,y3);
            Mapa[x1][y1].second = Mapa[x0][y0].second;
            Mapa[x2][y2].second = Mapa[x0][y0].second;
            Mapa[x3][y3].second = Mapa[x0][y0].second;
            Embarcacoes.push_back(Mapa[x0][y0].second);
            Mapa[x1][y1].first = true;
            Mapa[x2][y2].first = true;
            Mapa[x3][y3].first = true;
            posicao_unidades[x0][y0] = 0;
            posicao_unidades[x1][y1] = 1;
            posicao_unidades[x2][y2] = 2;
            posicao_unidades[x3][y3] = 3;
        }
    }
}

Jogo::Jogo() = default;

Jogo::~Jogo() {
    for (auto x:Embarcacoes){
        delete x;
    }
    Embarcacoes.clear();
}

void Jogo::imprimir() {
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
                        if(!Mapa[i][k].first) {
                            cout <<"   |";
                        }else{
                            cout<<" ";
                            if(Mapa[i][k].second->get_corpo(posicao_unidades[i][k])->get_visibilidade()){
                                cout<<Mapa[i][k].second->get_corpo(posicao_unidades[i][k])->get_selo()<<" |";
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

void Jogo::pre_inicializar() {
    for(auto x : Mapa){
        x->first = false;
    }
}

bool Jogo::condicao_de_vit() { //Retorna falso se tiver ao menos uma embarcação viva
    bool vivo = false;
    for(auto x : Embarcacoes){
        vivo = vivo||(x->get_vivo());
    }
    return !vivo;
}

void Jogo::atacar(int x, int y) {
    if(!(Mapa[x][y].first)){
        cout<<"Você errou o ataque"<<endl;
    }else{
        Mapa[x][y].second->defender(x,y);
    }
}

void Jogo::limpar() {
    cout << "\033[2J\033[1;1H";
}