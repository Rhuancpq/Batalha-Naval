# BATALHA NAVAL EP1 - OO 2019.1
*by Rhuan Carlos*

## Contexto do Projeto

&nbsp;&nbsp;Este projeto consiste em criar um jogo em C++ similar ao game Battleship (ou batalha naval) utilizando os conhecimentos aprendidos na disciplina de Orientação a Objetos.

## Como instalar

**Certifique-se que tem instalado o git em seu sistema**

* Procure pelo botão **clone** na parte superior direita do site, copie o endereço SSH ou HTTPS
* Abra o terminal no diretório em que deseja instalar o jogo
* Execute o comando ***sem os colchetes***:
```
$ git clone [Endereço SSH ou HTTPS]
```


## Como jogar

De forma básica, a execução do projeto se faz da seguinte maneira:

Para construir os objetos definidos pelo projeto, juntamente com o binário para realizar a execução:
```
$ make all
```

Para executar e iniciar o programa:
```
$ make run
```

## Embarcações

Nesta versão as embarcações tem habilidades especiais:

* Porta-Aviões:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Tem 50% de chance de desviar de um míssil.

* Submarino:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Tem o dobro de vida (2) em suas unidades.

* Canoa:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A ilustre habilidade de não ter habilidade.

## Modos de Jogo
* Clássico:

Segue as mesmas regras do jogo original, Batalha naval.

* Bombardeio:

Neste modo mais rápido ou não dependendo da sua **sorte**, a cada 3 rodadas o próximo ataque realizado tem 4 tiros bônus adicionais e aleatórios