#include <iostream>
#include <thread>
#include <chrono>
#include <exception>
#include "Excecao.hpp"
#include "Jogo.hpp"


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

int main(int argc, char ** argv) {
    try {
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
        int i = 1;
        while (true) {
            int x, y;
            if (i % 2) {
                cout << "Turno do jogador 1" << endl;
                cout << "Digite as coordenadas x e y do ataque(de 0 a 12):" << endl;
                while(true) {
                    x = getInput<int>();
                    y = getInput<int>();
                    if (x >= 0 && x < 13 && y < 13 && y >= 0) {
                        break;
                    }else{
                        cout<<"Entrada inválida, insira novamente as coordenadas:"<<endl;
                    }
                }
                player_2->atacar(x, y);
                player_2->imprimir();
                this_thread::sleep_for(chrono::seconds(2));
                player_2->limpar();
                if (player_2->condicao_de_vit()) {
                    cout << "Jogador 1 ganhou" << endl;
                    delete player_1;
                    delete player_2;
                    cout << "Gostaria de jogar novamente? (Y/N)" << endl;
                    string a;
                    while(true) {
                        a = getInput<string>();
                        if (a != "Y" || a != "N") {
                            cout<<"Entrada inválida, tente novamente:"<<endl;
                        }else{
                            break;
                        }
                    }
                    return 0;
                }
            } else {
                cout << "Turno do jogador 2" << endl;
                cout << "Digite as coordenadas x e y do ataque(de 0 a 12)" << endl;
                while(true) {
                    x = getInput<int>();
                    y = getInput<int>();
                    if (x >= 0 && x < 13 && y < 13 && y >= 0) {
                        break;
                    }else{
                        cout<<"Entrada inválida, insira novamente as coordenadas:"<<endl;
                    }
                }
                player_1->atacar(x, y);
                player_1->imprimir();
                this_thread::sleep_for(chrono::seconds(2));
                player_2->limpar();
                if (player_1->condicao_de_vit()) {
                    cout << "Jogador 2 ganhou" << endl;
                    delete player_1;
                    delete player_2;
                    return 0;
                }
            }
            i++;
        }
    }catch(Excecao &e){
        cout<< "Exceção capturada: "<<e.what()<<endl;
    }catch(exception &e){
        cout<< "Exception: "<<e.what()<<endl;
    }
}



