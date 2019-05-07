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
    int d, m;
    cout << "Bem vindo ao Batalha Naval" << endl;
    cout << "Escolha um modo de jogo:" << endl;
    cout << "1. Clássico" <<endl;
    cout << "2. Bombardeio"<<endl;
    while(true) {
        m = getInput<int>();
        if (m >= 1 && m <= 2) {
            break;
        }else{
            cout<<"Entrada inválida, insira novamente:"<<endl;
        }
    }
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[2J\033[1;1H";
    if(m==2){
        cout<<"No modo Bombardeio, a cada 3 rodadas, "
            <<"o próximo ataque realizado tem 4 tiros bônus e randômicos"<<endl;
    }
    cout << "Você pode escolher um entre três mapas para jogar..." << endl;
    cout << "Digite 1 para escolher o mapa 1" << endl;
    cout << "Digite 2 para escolher o mapa 2" << endl;
    cout << "Digite 3 para escolher o mapa 3" << endl;
    cout << "Digite 4 para escolher um mapa diferente" << endl;
    while(true) {
        d = getInput<int>();
        if (d >= 1 && d <= 4) {
            break;
        }else{
            cout<<"Entrada inválida, insira novamente:"<<endl;
        }
    }
    if(d == 4){
        cout<<"Digite o nome e a extensão do arquivo"<<endl;
        string nome_do_arquivo;
        nome_do_arquivo = getInput<string>();
        path = "doc/";
        path = path + nome_do_arquivo;
    }else {
        char t = d + '0';
        path = path + t + ".txt";
    }
    string nick1, nick2;
    cout<<"Jogador 1, digite seu nickname"<<endl;
    nick1 = getInput<string>();
    cout<<"Jogador 2, digite seu nickname"<<endl;
    nick2 = getInput<string>();
    cout << "Então vamos começar a partida..." << endl;
    Jogo *player_1 = new Jogo("# player_1", path);
    Jogo *player_2 = new Jogo("# player_2", path);
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[2J\033[1;1H";
    int i = 1, c = 1;
    while (true) {
        int x, y;
        if (i % 2) {
            player_2->imprimir(nick2);
            if(m == 2 && c%4 == 0) {
                cout << "Rodada do Bombardeio" << endl;
            }
            cout << "Turno de "<<nick1<< endl;
            cout << "Digite as coordenadas x e y do ataque(de 0 a 12):" << endl;
            while(true) {
                cin>>x>>y;
                if ((x >= 0 && x < 13 && y < 13 && y >= 0) && !cin.fail()) {
                    cin.ignore(32767,'\n');
                    break;
                }else{
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"Entrada inválida, insira novamente as coordenadas:"<<endl;
                }
            }
            if(m == 2 && c%4 == 0){
                player_2->bombardeio(x,y);
                c = 0;
            }else {
                player_2->atacar(x, y);
            }
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\033[2J\033[1;1H";
            if (player_2->condicao_de_vit()) {
                cout << nick1 <<" ganhou" << endl;
                player_2->imprimir(nick2);
                cout<<"Pontuação de "<<nick1<<":"<<endl;
                cout<<player_2->pontuacao()<<endl;
                cout<<"Pontuação de "<<nick2<<":"<<endl;
                cout<<player_1->pontuacao()<<endl;
                delete player_1;
                delete player_2;
                break;
            }
            c++;
        } else {
            player_1->imprimir(nick1);
            if(m == 2 && i%8 == 0) {
                cout << "Rodada do Bombardeio" << endl;
            }
            cout << "Turno de "<< nick2 << endl;
            cout << "Digite as coordenadas x e y do ataque(de 0 a 12)" << endl;
            while(true) {
                cin>>x>>y;
                if ((x >= 0 && x < 13 && y < 13 && y >= 0) && !cin.fail()) {
                    cin.ignore(32767,'\n');
                    break;
                }else{
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"Entrada inválida, insira novamente as coordenadas:"<<endl;
                }
            }
            if(m == 2 && i%8 == 0){
                player_1->bombardeio(x,y);
            }else {
                player_1->atacar(x, y);
            }
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\033[2J\033[1;1H";
            if (player_1->condicao_de_vit()) {
                cout << nick2 <<"ganhou" << endl;
                player_1->imprimir(nick1);
                cout<<"Pontuação de "<<nick2<<":"<<endl;
                cout<<player_1->pontuacao()<<endl;
                cout<<"Pontuação de "<<nick1<<":"<<endl;
                cout<<player_2->pontuacao()<<endl;
                delete player_1;
                delete player_2;
                break;
            }
        }
        i++;
    }
}
