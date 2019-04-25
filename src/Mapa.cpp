//
// Created by rhuan on 23/04/19.
//
#include "Mapa.hpp"
#include "Embarcacao.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Mapa::Mapa(const string &jogador) {

}


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