#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Estoque.h"
#include "Clientes.h"
#include "Gerencia.h"
#include "util.h"
#include "Globals.h"


// Assinatura das Funcoes para funcionar de acordo sem warning:

char menu_inicial(void);
void menu_sobre(void);
void menu_equipe(void);

//Programa Principal -

int main(void){

    char op;
    while (op!='0'){
        op = menu_inicial();
        switch (op){
            case '1':
                menu_cliente();
                break;

            case '2':
                acesso_gerencia();
                break;

            case '3':
                menu_sobre();
                break;

            case '4':
                menu_equipe();
                break;

            case '0':
                break;

            default:
                printf("\t>>>Insira algo valido<<<\n");
                getchar();
        }
    }

    printf("\n\tFim do Programa!\n");
    
    return 0;
}

//Funcoes abaixo - 

char menu_inicial(void){
    char op;
    system("clear||cls");
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
    printf("\t#                                      #\n");
    printf("\t#   1 - Menu Cliente                   #\n");
    printf("\t#   2 - Menu de Gerencia               #\n");
    printf("\t#   3 - Informacoes Sobre o Programa   #\n");
    printf("\t#   4 - Creditos do Programa           #\n");
    printf("\t#                                      #\n");
    printf("\t#         0 - Fechar o Programa        #\n");
    printf("\t#                                      #\n");
    printf("\t#   Insira sua Escolha: ");
    scanf("%c", &op);
    getchar();
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
    return op;

}

void menu_sobre(void){

    system("clear||cls");
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
    printf("\t#    programacao alem de prover uma    #\n");
    printf("\t# simulacao do mercado de trabalho com #\n");
    printf("\t#   cobrancas e cumprimento de metas   #\n");
    printf("\t# como base sendo um sistema de gestao #\n");
    printf("\t#   de bar e restaurante que tem como  #\n");
    printf("\t#     objetivo tornar o ambiente de    #\n");
    printf("\t#        trabalho mais dinamico        #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void menu_equipe(void){

    system("clear||cls");
    printf("\t########################################\n");
    printf("\t#               Creditos               #\n");
    printf("\t########################################\n");
    printf("\t#             Universidade:            #\n");
    printf("\t#          UFRN CERES - Caico          #\n");
    printf("\t#                                      #\n");
    printf("\t#                Curso:                #\n");
    printf("\t# Bacharelado em Sistema de Informacao #\n");
    printf("\t#                                      #\n");
    printf("\t#               Docente:               #\n");
    printf("\t#       Flavius da Luz e Gorgonio      #\n");
    printf("\t#                                      #\n");
    printf("\t#                Equipe:               #\n");
    printf("\t#  Claudio Pereira Teixeira de Araujo  #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}


