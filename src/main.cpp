#include <iostream>
#include <exception>
#include "Excecao.hpp"
#include "Partida.hpp"

using namespace std;

int main(int argc, char ** argv) {
    try {
        while(true){
            partida();
            bool j = jogar_novamente();
            if(!j){
                break;
            }
        }
        return 0;
    }catch(Excecao &e){
        cout<< "Exceção capturada: "<<e.what()<<endl;
    }catch(exception &e){
        cout<< "Exception: "<<e.what()<<endl;
    }
}



