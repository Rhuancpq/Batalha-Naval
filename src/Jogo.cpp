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
#include <Excecao.hpp>
#include <random>
#include <thread>
#include <chrono>

#define branco "\033[39;48;5;18m"
#define azul "\033[96;48;5;18m"
#define preto "\033[0m"

using namespace std;

Jogo::Jogo(const string &jogador, const string &mapa) {
    pre_inicializar();
    this->jogador = jogador;
    fstream file;
    file.open(mapa);
    if(file.fail()){
        string a = "../"+mapa;
        file.open(a);
        if(file.fail()) throw Excecao("Arquivo não encontrado");
    }
    string buff;
    while(true){
        if(file.eof()) throw Excecao("Arquivo vazio ou fora dos padrões");
        getline(file,buff);
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
    file.close();
}

Jogo::Jogo() = default;

Jogo::~Jogo() {
    for (auto x:Embarcacoes){
        delete x;
    }
}

void Jogo::imprimir(string& nome) {
    cout<<"\033[5m                 Mapa de "<<nome<<preto<<endl;
    for(int a = 0; a < 13; a++){
        if(a >= 10){
            cout<<azul<<"~~"<<preto;
            cout<<branco<<a<<preto;
        }else {
            cout << azul << "~~~" << preto;
            cout << branco << a << preto;
        }
    }
    cout<<azul<<"~~"<<preto<<endl;
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 13; ++k) {
                if(k == 0 && j%4 == 1){
                    if(i < 10) cout<<azul<<" "<<preto;
                    cout<<branco<<i<<preto;
                }else if(k == 0 && j%3 == 2){
                    cout<<azul<<"~~"<<preto;
                }else if(k == 0 && j%3 == 0){
                    cout<<azul<<" |"<<preto;
                }
                switch (j%3){
                    case 0:
                        cout<<azul<<"   |"<<preto;
                        break;
                    case 1: {
                        if(!Mapa[i][k].first) {
                            if(disparos[i][k]){
                                cout << azul << " ~ |" << preto;
                            }else {
                                cout << azul << "   |" << preto;
                            }
                        }else{
                            cout<<azul<<" "<<preto;
                            if(Mapa[i][k].second->get_corpo(posicao_unidades[i][k])->get_visibilidade()){
                                cout<<Mapa[i][k].second->get_corpo(posicao_unidades[i][k])->get_selo()<<
                                preto<<azul<<" |"<<preto;
                            }else{
                                cout<<azul<<"  |"<<preto;
                            }
                        }
                        break;
                    }
                    case 2:
                        cout<<azul<<"~~~~"<<preto;
                        break;
                }
            }
            cout<<endl;
        }
    }
    cout<<"\033[92;48;5;18mS"<<preto<<" - Submarino"<<endl;
    cout << azul << "~" << preto <<" Posições em que o míssil errou o ataque, vulgo caiu na água"<<endl;
    cout << "\033[5;91;48;5;18mX" << preto <<" - Unidades destruidas"<<endl;
}

void Jogo::pre_inicializar() {
    for(auto x : Mapa){
        for (int i = 0; i < 13; ++i) {
            x[i].first = false;
        }
    }
    for(auto x : disparos){
        for (int i = 0; i < 13; ++i) {
            x[i] = false;
        }
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
        cout<<"Você errou o ataque!!"<<endl;
        disparos[x][y] = true;
    }else{
        if(Mapa[x][y].second->get_corpo(posicao_unidades[x][y])->get_vida()<=0) {
            cout << "Você já destruiu uma unidade nessa posição!!" << endl;
        }else {
            Mapa[x][y].second->defender(x, y);
        }
    }

}

void Jogo::bombardeio(int x, int y) {
    int rand[8] = {}, cont = 0;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(0, 12);
    for (auto& i : rand) {
        i = dist(mt);
    }
    cout<<"Bombardeio começou..."<<endl;
    cout<<"...Coordenadas recebidas"<<endl;
    cout<<"Efetuando ataque..."<<endl;
    atacar(x,y);
    cout<<"Disparando mísseis extras..."<<endl;
    for (int j = 0; j < 8; j += 2) {
        int x_temp = rand[j], y_temp = rand[j+1];
        cout<<"Na coordenada ("<<x_temp<<","<<y_temp<<")"<<endl;
        if(!(Mapa[x_temp][y_temp].first)){
            if((dist(mt)%12)){
                cout<<"Míssil ao mar"<<endl;
            }else{
                cout<<"Alguém ensina o recruta a atirar!!"<<endl;
            }
            cont++;
            disparos[x_temp][y_temp] = true;
        }else{
            if(Mapa[x_temp][y_temp].second->get_corpo(posicao_unidades[x_temp][y_temp])->get_vida()<=0) {
            }else {
                Mapa[x_temp][y_temp].second->defender(x_temp,y_temp);
            }
        }
        this_thread::sleep_for(chrono::seconds(2));
    }
    switch(cont%5){
        case 0:
            cout<<"Parece que a sorte esteve ao seu lado!!"<<endl;
            break;
        case 1:
            cout<<"Uma sorte tanto média!!"<<endl;
            break;
        case 2:
            cout<<"Uma sorte baixa, meu caro!!"<<endl;
            break;
        case 3:
            cout<<"A um passo de quase nada!!"<<endl;
            break;
        case 4:
            cout<<"Quem Sabe da próxima seus mísseis acertem algo!!"<<endl;
            break;
    }
    this_thread::sleep_for(chrono::seconds(2));
}

int Jogo::pontuacao() {
    int pont = 0;
    for(auto x : Embarcacoes){
        if(x->get_vivo()){
            pont++;
        }
    }
    return pont;
}