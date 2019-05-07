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

void input_coordenadas(int& x, int& y){
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
}

bool verificar_condicao(Jogo * oponente, Jogo * player,string& nick,string& nick_oponente){
    if (oponente->condicao_de_vit()) {
        cout << nick <<"ganhou" << endl;
        oponente->imprimir(nick);
        cout<<"Pontuação de "<<nick<<":"<<endl;
        cout<<oponente->pontuacao()<<" embarcações destruidas"<<endl;
        cout<<"Pontuação de "<<nick_oponente<<":"<<endl;
        cout<<player->pontuacao()<<" embarcações destruidas"<<endl;
        delete oponente;
        delete player;
        return true;
    }
    return false;
}

void escolher_mapa(int& digito, string& path){
    cout << "Você pode escolher um entre três mapas para jogar..." << endl;
    cout << "Digite 1 para escolher o mapa 1" << endl;
    cout << "Digite 2 para escolher o mapa 2" << endl;
    cout << "Digite 3 para escolher o mapa 3" << endl;
    cout << "Digite 4 para escolher um mapa diferente" << endl;
    while(true) {
        digito = getInput<int>();
        if (digito >= 1 && digito <= 4) {
            break;
        }else{
            cout<<"Entrada inválida, insira novamente:"<<endl;
        }
    }
    if(digito == 4){
        cout<<"Digite o nome e a extensão do arquivo"<<endl;
        string nome_do_arquivo;
        nome_do_arquivo = getInput<string>();
        path = "doc/";
        path = path + nome_do_arquivo;
    }else {
        char t = digito + '0';
        path = path + t + ".txt";
    }
}

void escolher_modo_de_jogo(int& modo){
    cout << "Bem vindo ao Batalha Naval" << endl;
    cout << "Escolha um modo de jogo:" << endl;
    cout << "1. Clássico" <<endl;
    cout << "2. Bombardeio"<<endl;
    while(true) {
        modo = getInput<int>();
        if (modo >= 1 && modo <= 2) {
            break;
        }else{
            cout<<"Entrada inválida, insira novamente:"<<endl;
        }
    }
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[2J\033[1;1H";
}

void partida(){
    string path = "doc/map_";
    int d, m;
    escolher_modo_de_jogo(m);
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[2J\033[1;1H";
    if(m==2){
        cout<<"No modo Bombardeio, a cada 3 rodadas, "
            <<"o próximo ataque realizado tem 4 tiros bônus e randômicos"<<endl;
    }
    escolher_mapa(d,path);
    string nick1, nick2;
    cout<<"Jogador 1, digite seu nickname"<<endl;
    getline(cin, nick1);
    cout<<"Jogador 2, digite seu nickname"<<endl;
    getline(cin, nick2);
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
            input_coordenadas(x,y);
            if(m == 2 && c%4 == 0){
                player_2->bombardeio(x,y);
                c = 0;
            }else {
                player_2->atacar(x, y);
            }
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\033[2J\033[1;1H";
            if (verificar_condicao(player_2,player_1,nick1,nick2)) {
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
            input_coordenadas(x,y);
            if(m == 2 && i%8 == 0){
                player_1->bombardeio(x,y);
            }else {
                player_1->atacar(x, y);
            }
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\033[2J\033[1;1H";
            if (verificar_condicao(player_1,player_2,nick2,nick1)) {
                break;
            }
        }
        i++;
    }
}
