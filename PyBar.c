#include <stdio.h>
#include <locale.h> // Biblioteca vista no canal https://youtu.be/hB6KFP6luL4 

void menu_inicial(){
    printf("\t########################################\n");
    printf("\t#  ______        ______                #\n");
    printf("\t#  | ___ |       | ___ |               #\n");
    printf("\t#  | |_/ / _   _ | |_/ /  __ _  _ __   #\n");
    printf("\t#  |  __/ | | | || ___ | / _` || '__|  #\n");
    printf("\t#  | |    | |_| || |_/ /| (_| || |     #\n");
    printf("\t#  |_|     |__, ||____/  |__,_||_|     #\n");
    printf("\t#           __/ |                      #\n");
    printf("\t#          |___/                       #\n");
    printf("\t########################################\n");
    printf("\t#           1 - Menu Cliente           #\n");
    printf("\t#         2 - Menu de Ger�ncia         #\n");
    printf("\t#   3 - Informa��es Sobre o Programa   #\n");
    printf("\t#         0 - Fechar o Programa        #\n");
    printf("\t########################################\n");
    printf("\n");
}

void menu_sobre(){
    printf("\t########################################\n");
    printf("\t#   _____         _                    #\n");
    printf("\t#  /  ___|       | |                   #\n");
    printf("\t#  | `--.   ___  | |__   _ __   ___    #\n");
    printf("\t#   `--. | / _ | | '_ | | '__| / _ |   #\n");
    printf("\t#  /|__/ /| (_) || |_) || |   |  __/   #\n");
    printf("\t#  |____/  |___/ |_.__/ |_|    |___|   #\n");
    printf("\t########################################\n");
    printf("\t#   Projeto desenvolvido para fins de  #\n");
    printf("\t#    estudo com objetivo desenvolver   #\n");
    printf("\t#  praticidade em outras linguagens de #\n");
    printf("\t#    programa��o alem de prover uma    #\n");
    printf("\t# simula��o do mercado de trabalho com #\n");
    printf("\t#   cobran�as e cumprimento de metas   #\n");
    printf("\t# como base sendo um sistema de gest�o #\n");
    printf("\t#   de bar e restaurante que tem como  #\n");
    printf("\t#     objetivo tornar o ambiente de    #\n");
    printf("\t#        trabalho mais din�mico        #\n");
    printf("\t########################################\n");
    printf("\n");
}

void menu_equipe(){

    printf("\t########################################\n");
    printf("\t#               Cr�ditos               #\n");
    printf("\t########################################\n");
    printf("\t#             Universidade:            #\n");
    printf("\t#          UFRN CERES - Caic�          #\n");
    printf("\t#                                      #\n");
    printf("\t#                Curso:                #\n");
    printf("\t# Bacharelado em Sistema de Informa��o #\n");
    printf("\t#                                      #\n");
    printf("\t#               Docente:               #\n");
    printf("\t#       Flavius da Luz e Gorgonio      #\n");
    printf("\t#                                      #\n");
    printf("\t#                Equipe:               #\n");
    printf("\t#  Cl�udio Pereira Teixeira de Ara�jo  #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
}

int main(void){

    setlocale(LC_ALL,"Portuguese_Brazil"); // Fun��o vista no v�deo https://youtu.be/hB6KFP6luL4

    menu_inicial();
    menu_sobre();
    menu_equipe();
    
    return 0;
}
