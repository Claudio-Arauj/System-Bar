#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Biblioteca vista no canal https://youtu.be/hB6KFP6luL4 

// Assinatura das Funções para funcionar de acordo sem warning:
void menu_inicial(void);
void menu_sobre(void);
void menu_equipe(void);
void menu_gerencia(void);
void acesso_gerencia(void);


int main(void){

    setlocale(LC_ALL,"Portuguese_Brazil"); // Função vista no vídeo https://youtu.be/hB6KFP6luL4

    menu_inicial();
    menu_sobre();
    menu_equipe();
    acesso_gerencia();
    menu_gerencia();
    
    return 0;
}

//Funções abaixo - 

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
    printf("\t#                                      #\n");
    printf("\t#           1 - Menu Cliente           #\n");
    printf("\t#         2 - Menu de Gerência         #\n");
    printf("\t#   3 - Informações Sobre o Programa   #\n");
    printf("\t#         0 - Fechar o Programa        #\n");
    printf("\t#                                      #\n");
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
    printf("\t#    programação alem de prover uma    #\n");
    printf("\t# simulação do mercado de trabalho com #\n");
    printf("\t#   cobranças e cumprimento de metas   #\n");
    printf("\t# como base sendo um sistema de gestão #\n");
    printf("\t#   de bar e restaurante que tem como  #\n");
    printf("\t#     objetivo tornar o ambiente de    #\n");
    printf("\t#        trabalho mais dinâmico        #\n");
    printf("\t########################################\n");
    printf("\n");

}

void menu_equipe(){

    printf("\t########################################\n");
    printf("\t#               Créditos               #\n");
    printf("\t########################################\n");
    printf("\t#             Universidade:            #\n");
    printf("\t#          UFRN CERES - Caicó          #\n");
    printf("\t#                                      #\n");
    printf("\t#                Curso:                #\n");
    printf("\t# Bacharelado em Sistema de Informação #\n");
    printf("\t#                                      #\n");
    printf("\t#               Docente:               #\n");
    printf("\t#       Flavius da Luz e Gorgonio      #\n");
    printf("\t#                                      #\n");
    printf("\t#                Equipe:               #\n");
    printf("\t#  Cláudio Pereira Teixeira de Araújo  #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");

}


void acesso_gerencia(){
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
    printf("\t#        - Acesso da Gerência -        #\n");
    printf("\t#                                      #\n");
    printf("\t#         1. Login Funcionário         #\n");
    printf("\t#     2. Cadastramento Funcionário     #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");

}


void menu_gerencia(){
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
    printf("\t#        // - Menu Gerência - //       #\n");
    printf("\t#                                      #\n");
    printf("\t#    1. Visualizar Itens de Estoque    #\n");
    printf("\t#          2. Pedidos Pendentes        #\n");
    printf("\t#         3. Visualizar o Caixa        #\n");
    printf("\t#      4. Ver Relatório de Pedidos     #\n");
    printf("\t#      5. Visualizar Funcionários      #\n");
    printf("\t#            0. Sair da Tela           #\n");
    printf("\t#                                      #\n");
    printf("\t#           Insira sua Opção:          #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    
}