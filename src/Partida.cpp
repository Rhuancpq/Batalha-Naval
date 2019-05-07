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

void static limpar(int time){
    this_thread::sleep_for(chrono::seconds(time));
    cout << "\033[2J\033[1;1H";
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
        oponente->imprimir(nick_oponente);
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
    limpar(1);
}

void get_nicks(string& nick1, string& nick2){
    cout<<"Jogador 1, digite seu nickname"<<endl;
    getline(cin, nick1);
    cout<<"Jogador 2, digite seu nickname"<<endl;
    getline(cin, nick2);
    cout << "Então vamos começar a partida..." << endl;
}

void rodada(Jogo * oponente, string& nick,string& nick_oponente, bool cond, int& x, int& y){
    oponente->imprimir(nick_oponente);
    if(cond) {
        cout << "Rodada do Bombardeio" << endl;
    }
    cout << "Turno de "<<nick<< endl;
    cout << "Digite as coordenadas x e y do ataque(de 0 a 12):" << endl;
    input_coordenadas(x,y);
    if(cond){
        oponente->bombardeio(x,y);
    }else {
        oponente->atacar(x, y);
    }
    limpar(3);
}

void partida(){
    string path = "doc/map_";
    int d, m;
    escolher_modo_de_jogo(m);
    limpar(1);
    if(m==2){
        cout<<"No modo Bombardeio, a cada 3 rodadas, "
            <<"o próximo ataque realizado tem 4 tiros bônus e randômicos"<<endl;
    }
    escolher_mapa(d,path);
    string nick1, nick2;
    get_nicks(nick1,nick2);
    Jogo *jogo1 = new Jogo("# player_1", path);
    Jogo *jogo2 = new Jogo("# player_2", path);
    limpar(1);
    int i = 1, c = 1;
    while (true) {
        int x = 0, y = 0;
        if (i % 2) {
            bool is_bombard = (m == 2 && c%4 == 0);
            rodada(jogo2,nick1,nick2,is_bombard,x,y);
            if (verificar_condicao(jogo2,jogo1,nick1,nick2)) {
                break;
            }
            if(c % 4 == 0) c= 0;
            c++;
        } else {
            bool is_bombard = (m == 2 && i%8 == 0);
            rodada(jogo2,nick2,nick1,is_bombard,x,y);
            if (verificar_condicao(jogo1,jogo2,nick2,nick1)) {
                break;
            }
        }
        i++;
    }
}
