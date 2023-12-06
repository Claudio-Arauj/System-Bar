///////////////////////////////////////////////////////
//                                                   //
//      Arquivo para controle na tela clientes       //
//                                                   //
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Clientes.h"
#include "Estoque.h"
#include "util.h"

void menu_cliente(void){ 

    char op;
    while (op != '0'){
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
        printf("\t#         // - Menu Cliente - //       #\n");
        printf("\t#                                      #\n");
        printf("\t#    1. Ver Cardapio                   #\n"); // Esse Menu vou reutilizar o "tela_lista_itens()" para ser mais facil e poupar mais linhas de codigo
        printf("\t#    2. Adicionar Pedido               #\n");
        printf("\t#    3. Finalizar meu Pedido           #\n");
        printf("\t#    4. Menu Ajuda                     #\n");
        printf("\t#                                      #\n");
        printf("\t#            0. Sair da Tela           #\n");
        printf("\t#                                      #\n");
        printf("\t#    Insira sua Escolha: ");
        scanf("%c", &op);
        getchar();
        printf("\t#                                      #\n");
        printf("\t########################################\n");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();

        switch (op){
        case '1':
            tela_lista_itens();
            break;
        
        case '2':
            tela_pedidos();
            break;

        case '3':
            tela_visualizar_pedido();
            break;

        case '4':
            tela_ajuda();
            break;

        case '0':
            break;

        default:
            printf("\t>>>Insira algo valido<<<\n");
            getchar();

        }
    }
}

void tela_pedidos(void){

    char op;
    while (op != '0'){
        system("clear||cls");
        printf("\t############################################################\n");
        printf("\t#            ______        ______                          #\n");
        printf("\t#            | ___ |       | ___ |                         #\n");
        printf("\t#            | |_/ / _   _ | |_/ /  __ _  _ __             #\n");
        printf("\t#            |  __/ | | | || ___ | / _` || '__|            #\n");
        printf("\t#            | |    | |_| || |_/ /| (_| || |               #\n");
        printf("\t#            |_|     |__, ||____/  |__,_||_|               #\n");
        printf("\t#                     __/ |                                #\n");
        printf("\t#                    |___/                                 #\n");
        printf("\t############################################################\n");
        printf("\t#                                                          #\n");
        printf("\t#                // - Tela de Pedidos - //                 #\n");
        printf("\t#                                                          #\n");
        printf("\t#   1. Adicionar Comida                                    #\n");
        printf("\t#   2. Adicionar Bebida                                    #\n");
        printf("\t#                                                          #\n");
        printf("\t#   0. Sair da Tela                                        #\n");
        printf("\t#                                                          #\n");
        printf("\t#      Insira sua Escolha: ");
        scanf("%c", &op);
        getchar();
        printf("\t#                                                          #\n");
        printf("\t############################################################\n");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();

        switch (op){
        case '1':
            tela_comidas();
            break;
        
        case '2':
            tela_bebidas();
            break;

        case '0':
            break;

        default:
            printf("\t>>>Insira algo valido<<<\n");
            getchar();

        }
    }
}

void tela_comidas(void){
    FILE* fp;
    Estoque* est;
    int comidas_exibidas = 0;
    
    est = (Estoque*) malloc(sizeof(Estoque));
    
    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#                // - Tela de Comidas - //                 #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n"); 
    fp = fopen("Estoque.dat", "rb");
    if (fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        while(fread(est, sizeof(Estoque), 1, fp)==1){ // Loop interrompido para aparecer uma vez só, feito com ajuda do Chat GPT
            if ((est->comida_bebida == 'c') && (est->quantidade > 0)) {
                if (!comidas_exibidas) {
                    printf("\t#   - Comidas Disponiveis:                                 #\n");
                    printf("\t# -                  Nome                  - Preco - Qnt - #\n");
                    comidas_exibidas = 1;
                }
                exibe_estoque_comida(est);
            }
        } // Vai colocando todos as comidas que estao disponiveis no momento que o estoque estiver maior que 1
        printf("\t#                                                          #\n");
        printf("\t############################################################\n");
        printf("\t#                                                          #\n");
        printf("\t#   - Qual sua Escolha? \n");
        printf("\t#   - Informe a Quantidade(Apenas Numero) \n");
        fclose(fp);
    }
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    free(est);
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_bebidas(void){
    FILE* fp;
    Estoque* est;
    int comidas_exibidas = 0;
    
    est = (Estoque*) malloc(sizeof(Estoque));

    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#                // - Tela de Bebidas - //                 #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    fp = fopen("Estoque.dat", "rb");
    if (fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        while(fread(est, sizeof(Estoque), 1, fp)==1){ // Loop interrompido para aparecer uma vez só, feito com ajuda do Chat GPT
            if ((est->comida_bebida == 'b') && (est->quantidade > 0)) {
                if (!comidas_exibidas) {
                    printf("\t#   - Bebidas Disponiveis: (Valor por Copo)                #\n");
                    printf("\t# -                  Nome                  - Preco - Qnt - #\n");
                    comidas_exibidas = 1;
                }
                exibe_estoque_bebida(est);
            }
        } // Vai colocando todos as comidas que estao disponiveis no momento que o estoque estiver maior que 1printf("\t#                                                          #\n");
        printf("\t############################################################\n");
        printf("\t#                                                          #\n");
        printf("\t#   - Qual sua Escolha? \n");
        printf("\t#   - Informe a Quantidade(Apenas Numero) \n");
        fclose(fp);
    }
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    free(est);
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_visualizar_pedido(void){

    char confirm[2];
    //char num[2];
    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#              // - Finalizacao de Pedido - //             #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n"); 
    printf("\t#   - Comidas Escolhidas:                                  #\n"); // Meramente ilustrativo
    printf("\t#     - Frango Assado            R$ xx,xx                  #\n");
    printf("\t#     - File                     R$ xx,xx                  #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Bebidas Escolhidas:                                  #\n");
    printf("\t#     - Chope                    R$ xx,xx                  #\n");
    printf("\t#     - Chope                    R$ xx,xx                  #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Informe o Numero da Mesa: \n");
    //scanf("%s", num);
    //getchar();
    printf("\t#   - Total: R$ xx,xx                                      #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - (Digite 0 para Excluir TODAS suas escolhas)          #\n");
    do{
        printf("\t#   - Confirmar Pedido?(s) ou (n): ");
        scanf("%1s", confirm);
        limpar_buffer();
        s_ou_n(confirm);
    }while(s_ou_n(confirm) != 1);
    printf("\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_ajuda(void){

    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#               ___     _             _                    #\n");
    printf("\t#              / _ |   (_)           | |                   #\n");
    printf("\t#             / /_| |   _  _   _   __| |  __ _             #\n");
    printf("\t#             |  _  |  | || | | | / _` | / _` |            #\n");
    printf("\t#             | | | |  | || |_| || (_| || (_| |            #\n");
    printf("\t#             |_| |_/  | | |__,_| |__,_| |__,_|            #\n");
    printf("\t#                     _/ |                                 #\n");
    printf("\t#                    |__/                                  #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   1. Como Usar?                                          #\n");
    printf("\t#      Primeiro Pode-se ver o Cardapio completo no menu    #\n");
    printf("\t#      na escolha 1, mas para escolher um pedido va para   #\n");
    printf("\t#      escolha 2 assim selecione oque for desejado noque   #\n");
    printf("\t#      estiver disponivel na lista que aparece ao entrar   #\n");
    printf("\t#      na tela, dai so digitar o numero do pedido que      #\n");
    printf("\t#      deseja, assim vai adicionar a lista de pedidos      #\n");
    printf("\t#      e para confirmar so entrar na escolha 3 para        #\n");
    printf("\t#      finalizar o pedido e ver o total a pagar ao caixa   #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}