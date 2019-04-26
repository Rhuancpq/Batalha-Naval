#include <iostream>


using namespace std;

int main(int argc, char ** argv){
    string path = "../inc/map_";
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
    cout << "\033[2J\033[1;1H";
    return 0;
}
