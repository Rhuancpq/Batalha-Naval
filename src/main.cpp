#include <iostream>
#include <thread>
#include <chrono>
#include "Jogo.hpp"


using namespace std;

int main(int argc, char ** argv){
    string path = "../doc/map_";
    int d;
    cout<<"Bem vindo ao Batalha Naval"<<endl;
    cout<<"Você pode escolher um entre três mapas para jogar..."<<endl;
    cout<<"Digite 1 para escolher o mapa 1"<<endl;
    cout<<"Digite 2 para escolher o mapa 2"<<endl;
    cout<<"Digite 3 para escolher o mapa 3"<<endl;
    cin>>d;
    char t = d + '0';
    path = path + t + ".txt";
    cout<<"Então vamos começar a partida..."<<endl;
    Jogo * player_1 = new Jogo("# player_1",path);
    Jogo * player_2 = new Jogo("# player_2",path);
    int i = 1;
    while(true){
        int x,y;
        if(i%2){
            cout<<"Turno do jogador 1"<<endl;
            cout<<"Digite as coordenadas x e y do ataque"<<endl;
            cin>>x>>y;
            player_2->atacar(x,y);
            player_2->imprimir();
            this_thread::sleep_for(chrono::seconds(2));
            player_2->limpar();
            if(player_2->condicao_de_vit()){
                cout<<"Jogador 1 ganhou"<<endl;
                return  0;
            }
        }else{
            cout<<"Turno do jogador 2"<<endl;
            cout<<"Digite as coordenadas x e y do ataque"<<endl;
            cin>>x>>y;
            player_1->atacar(x,y);
            player_1->imprimir();
            this_thread::sleep_for(chrono::seconds(2));
            player_2->limpar();
            if(player_1->condicao_de_vit()){
                cout<<"Jogador 2 ganhou"<<endl;
                return 0;
            }
        }
        i++;
    }
}
