///////////////////////////////////////////////////////
//                                                   //
//        Arquivo para controle no estoque           //
//                                                   //
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Estoque.h"
#include "util.h"
#include "Globals.h"

void tela_estoque(void){

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
        printf("\t#        // - Itens Estoque - //       #\n");
        printf("\t#                                      #\n");
        printf("\t#   1. Cadastrar Novo Item no Estoque  #\n");
        printf("\t#   2. Procurar Itens                  #\n");
        printf("\t#   3. Listar Todos os Itens           #\n");
        printf("\t#   4. Excluir Item de Estoque         #\n");
        printf("\t#   5. Atualizar Item                  #\n");
        printf("\t#                                      #\n");
        printf("\t#            0. Sair da Tela           #\n");
        printf("\t#                                      #\n");
        printf("\t#   Insira sua Escolha: ");
        scanf("%c", &op);
        getchar();
        printf("\t#                                      #\n");
        printf("\t########################################\n");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();

        switch (op){
        case '1':
            tela_cadastro_item();
            break;

        case '2':
            tela_procura_item();
            break;
        
        case '3':
            tela_lista_itens();
            break;

        case '4':
            tela_excluir_item();
            break;

        case '5':
            tela_atualizar_item();
            break;
        
        case '0':
            break;
        
        default:
            printf("\t>>>Insira algo valido<<<\n");
            getchar();
        }
    }
}

void tela_cadastro_item(void){
    
    Estoque *est;
    FILE *fp;
    char escolha[2];

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
    printf("\t#              // - Tela de Cadastramento - //             #\n");
    printf("\t#                                                          #\n");
    fp = fopen("Estoque.dat","ab");
    if (fp == NULL) {
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }
    est = preenche_estoque();
    do{
        printf("\t#     Confirmar Cadastramento (s) ou (n): ");
        scanf("%1s", escolha);
        limpar_buffer();
        s_ou_n(escolha); 
    }while(s_ou_n(escolha) != 1);
    if(escolha[0] == 's'){
        fwrite(est, sizeof(Estoque), 1, fp);
    }
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    fclose(fp);
    free(est);
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void tela_procura_item(void){ // Mais adiante no codigo irei separar essa funcao em duas telas para ficar com um codigo mais limpo.

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
    printf("\t#              // - Tela de Busca de Item - //             #\n");
    printf("\t#                                                          #\n");
    printf("\t#     ID's Disponiveis:                                    #\n");
    printf("\t#     - 00000000000x (Produto)                             #\n");
    printf("\t#     - 00000000000x (Produto 2)                           #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item:                                   #\n");
    printf("\t#                                                          #\n");
    printf("\t#     Confirmar Busca (s) ou (n):                          #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Categoria do Item:                                   #\n");
    printf("\t#   - Nome do Item:                                        #\n");
    printf("\t#   - Em Estoque:                                          #\n");
    printf("\t#   - Preco Individual:                                    #\n");
    printf("\t#   - ID: 00000000000x                                     #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_lista_itens(void){

    FILE* fp;

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
    printf("\t#         // - Tela de Lista de Todos os Itens - //        #\n");
    printf("\t#                                                          #\n");
    fp = fopen("Estoque.dat", "rb");
    if (fp == NULL){
        printf("Erro na abertura do arquivo\n!");
        exit(1);
    }
    mostra_lista(fp);
    fclose(fp); 
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_excluir_item(void){ //pretendo aumentar a tela para oferecer mais adaptabilidade na hora de querer excluir algum item.
    
    char escolha[2];
    
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
    printf("\t#             // - Tela de Excluir Item - //               #\n");
    printf("\t#                                                          #\n");
    printf("\t#     ID's Disponiveis:                                    #\n");
    printf("\t#     - 00000000000x (Produto x)                           #\n");
    printf("\t#     - 00000000000x (Produto 2x)                          #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item:                                   #\n");
    printf("\t#                                                          #\n");
    do{
        printf("\t#     Confirmar Exclusao (s) ou (n): ");
        scanf("%1s", escolha);
        limpar_buffer();
        s_ou_n(escolha); 
    }while(s_ou_n(escolha) != 1);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void tela_atualizar_item(void){
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
    printf("\t#            // - Tela de Atualizar Item - //              #\n");
    printf("\t#                                                          #\n");
    printf("\t#     ID's Disponiveis:                                    #\n");
    printf("\t#     - 00000000000x (Produto x)                           #\n");
    printf("\t#     - 00000000000x (Produto 2x)                          #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item:                                   #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

    tela_atualizacao();
}

void tela_atualizacao(void){ // Essa aqui vai ser a tela dividida da atualizacao para a funcao nao ficar muito grande.

    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#              // - Tela de Atualizacao - //               #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#             // - Informacoes Originais - //              #\n");
    printf("\t#                                                          #\n"); // Aqui vai vim as informacoes do item consultado pelo usuario para fazer comparacao
    printf("\t#   - Categoria do Item: Comida/agua                       #\n"); // Depende do que o usuario for digitar na tela de atualizar item para consultar
    printf("\t#   - Nome do Item: Produto 0x                             #\n");
    printf("\t#   - Em Estoque: xx                                       #\n");
    printf("\t#   - Preco Individual: R$ xx,xx                           #\n");
    printf("\t#   - ID: 00000000000x                                     #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#               // - Informacoes Novas - //                #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Categoria do Item (apenas 'c' ou 'a'):               #\n"); // Depende do que o usuario for digitar na tela de atualizar item para consultar
    printf("\t#   - Nome do Item:                                        #\n");
    printf("\t#   - Em Estoque:                                          #\n");
    printf("\t#   - Preco Individual:                                    #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}

Estoque* preenche_estoque(void){
    Estoque *est;
    int eh_nome, bouc;
    int id_estoque_global = 0;
    est = (Estoque*) malloc(sizeof(Estoque));

    do{
        printf("\t#   - Bebida(b) ou Comida(c): ");
        scanf("%c", &est->comida_bebida);/*getchar();*/
        limpar_buffer();
        bouc = eh_b_ou_c(est->comida_bebida);
    }while(bouc == 0);
    printf("\t#   - Quantidade(apenas numeros inteiros): ");
    scanf("%d", &est->quantidade);getchar();
    do{
        printf("\t#   - Nome do Item: ");
        fgets(est->nome,50,stdin);
        eh_nome = valida_nome(est->nome);
    }while(eh_nome != 1);
    printf("\t#   - Preco Individual do Item: R$ ");
    scanf("%f", &est->preco);getchar();
    id_estoque_global++;
    est->id = id_estoque_global;
    printf("\t#   - ID Gerado do Item: %d\n",est->id);
    printf("\t#                                                          #\n");
    est->status = '1';

    return est;
}

int eh_b_ou_c(char bc) { // Feito com ajuda do chat gpt
    return (bc == 'b' || bc == 'c') ? 1 : 0;
}

void exibe_estoque_comida(Estoque* est){

    if ((est == NULL) || (est->status != '1')) {
        printf("\n\t#                 - Estoque Inexistente -                  #\n");
    }
    else{
        if(est->comida_bebida == 'c'){
            printf("\t#          ID: %d  \n", est->id);
            printf("\t#          Nome: %s  ", est->nome);
            printf("\t#          Preco: R$ %.2f  \n", est->preco); // Print dos correspondente
            printf("\t#          Quantidade: %d  \n", est->quantidade);
            printf("\t# -------------------------------------------------------- #\n");
        }
    }
}

void exibe_estoque_bebida(Estoque* est){
    if ((est == NULL) || (est->status != '1')) {
        printf("\n\t#                 - Estoque Inexistente -                  #\n");
    }
    else{
        if(est->comida_bebida == 'b'){
            printf("\t#          ID: %d  \n", est->id);
            printf("\t#          Nome: %s  ", est->nome);
            printf("\t#          Preco: R$ %.2f  \n", est->preco); // Print dos correspondente
            printf("\t#          Quantidade: %d  \n", est->quantidade);
            printf("\t# -------------------------------------------------------- #\n");
        }
    }
}

void mostra_lista(FILE* fp){ // criando outra função para o codigo nao ficar grande.

    Estoque* est;
    int bebidas_exibidas = 0;
    int comidas_exibidas = 0;

    est = (Estoque*) malloc(sizeof(Estoque));
    while(fread(est, sizeof(Estoque), 1, fp)==1){ // Loop interrompido para aparecer uma vez só, feito com ajuda do Chat GPT
        if (est->comida_bebida == 'c') {
            if (!comidas_exibidas) {
                printf("\t#   - Comidas:                                             #\n");
                comidas_exibidas = 1;
            }
            exibe_estoque_comida(est);
        }
    }
    rewind(fp); //função para ler o arquivo de novo e poder mostrar as bebidas e comidas separadas.
    while(fread(est, sizeof(Estoque), 1, fp)==1){
        if (est->comida_bebida == 'b') {
            if (!bebidas_exibidas) {
                printf("\t#   - Bebidas:                                             #\n");
                bebidas_exibidas = 1;
            }
            exibe_estoque_bebida(est);
        }
    }
    free(est);
}