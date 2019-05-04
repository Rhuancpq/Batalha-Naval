//
// Created by rhuan on 01/05/19.
//
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <exception>
#include "Partida.hpp"
#include "Excecao.hpp"
#include "Jogo.hpp"
#include "Partida.hpp"
using namespace std;

template <typename T1>
T1 getInput(){
    while(true){
        T1 valor;
        cin >> valor;
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada inválida. Insira novamente: ";
        }
        else{
            cin.ignore(32767,'\n');
            return valor;
        }
    }
}

bool jogar_novamente() {
    cout << "Gostaria de jogar novamente? (S/N)" << endl;
    string a;
    while (true) {
        cin>>a;
        if (cin.fail() || (a != "S" && a != "N")) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Entrada inválida, tente novamente:" << endl;
        } else {
            cin.ignore(32767, '\n');
            break;
        }
    }
    return a == "S";
}

void partida(){
    string path = "doc/map_";
    int d;
    cout << "Bem vindo ao Batalha Naval" << endl;
    cout << "Você pode escolher um entre três mapas para jogar..." << endl;
    cout << "Digite 1 para escolher o mapa 1" << endl;
    cout << "Digite 2 para escolher o mapa 2" << endl;
    cout << "Digite 3 para escolher o mapa 3" << endl;
    while(true) {
        d = getInput<int>();
        if (d >= 1 && d <= 3) {
            break;
        }else{
            cout<<"Entrada inválida, insira novamente:"<<endl;
        }
    }
    char t = d + '0';
    path = path + t + ".txt";
    cout << "Então vamos começar a partida..." << endl;
    Jogo *player_1 = new Jogo("# player_1", path);
    Jogo *player_2 = new Jogo("# player_2", path);
    this_thread::sleep_for(chrono::seconds(2));
    player_2->limpar();
    int i = 1;
    while (true) {
        int x, y;
        if (i % 2) {
            player_2->imprimir();
            cout << "Turno do jogador 1" << endl;
            cout << "Digite as coordenadas x e y do ataque(de 0 a 12):" << endl;
            while(true) {
                cin>>x>>y;
                if ((x >= 0 && x < 13 && y < 13 && y >= 0) || !cin.fail()) {
                    cin.ignore(32767,'\n');
                    break;
                }else{
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"Entrada inválida, insira novamente as coordenadas:"<<endl;
                }
            }
            player_2->atacar(x, y);
            this_thread::sleep_for(chrono::seconds(2));
            player_2->limpar();
            if (player_2->condicao_de_vit()) {
                cout << "Jogador 1 ganhou" << endl;
                player_2->imprimir();
                delete player_1;
                delete player_2;
                break;
            }
        } else {
            player_1->imprimir();
            cout << "Turno do jogador 2" << endl;
            cout << "Digite as coordenadas x e y do ataque(de 0 a 12)" << endl;
            while(true) {
                cin>>x>>y;
                if ((x >= 0 && x < 13 && y < 13 && y >= 0) || !cin.fail()) {
                    cin.ignore(32767,'\n');
                    break;
                }else{
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"Entrada inválida, insira novamente as coordenadas:"<<endl;
                }
            }
            player_1->atacar(x, y);
            this_thread::sleep_for(chrono::seconds(2));
            player_2->limpar();
            if (player_1->condicao_de_vit()) {
                cout << "Jogador 2 ganhou" << endl;
                player_1->imprimir();
                delete player_1;
                delete player_2;
                break;
            }
        }
        i++;
    }
}
