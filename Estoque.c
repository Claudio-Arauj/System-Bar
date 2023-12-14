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
    est = preenche_estoque();
    do{
        printf("\t#     Confirmar Cadastramento (s) ou (n): ");
        scanf("%1s", escolha);
        limpar_buffer();
        s_ou_n(escolha); 
    }while(s_ou_n(escolha) != 1);
    if(escolha[0] == 's'){
        fp = fopen("Estoque.dat","ab");
        if (fp == NULL) {
            printf("\t\tErro na criacao do arquivo\n!");
            exit(1);
        }else{
            fwrite(est, sizeof(Estoque), 1, fp);
            fclose(fp);
        }
    }
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    free(est);
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void tela_procura_item(void){ // Mais adiante no codigo irei separar essa funcao em duas telas para ficar com um codigo mais limpo.
    Estoque *est;
    FILE *fp;

    est = (Estoque*)malloc(sizeof(Estoque));
    fp = fopen("Estoque.dat","rb");
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
    if(fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        exibe_pesquisa(est, fp);
        fclose(fp);
    }
    free(est);
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
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        mostra_lista(fp);
        fclose(fp);
    }
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_excluir_item(void){ //pretendo aumentar a tela para oferecer mais adaptabilidade na hora de querer excluir algum item.
    
    FILE* fp;
    Estoque* est;
    
    est = (Estoque*)malloc(sizeof(Estoque));
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
    fp = fopen("Estoque.dat", "rb+"); // Abra o arquivo no modo "rb+" para permitir leitura e escrita
    if(fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        func_exclusao(est,fp);
        fclose(fp);
    }
    free(est);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void tela_atualizar_item(void){

    FILE* fp;
    Estoque* est;

    est = (Estoque*)malloc(sizeof(Estoque));
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
    fp = fopen("Estoque.dat", "rb+"); // Abra o arquivo no modo "rb+" para permitir leitura e escrita
    if(fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        func_edit(fp, est);
        fclose(fp);
    }
    free(est);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

    //tela_atualizacao();
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
    printf("\t#   - Categoria do Item (apenas 'c' ou 'b'):               #\n"); // Depende do que o usuario for digitar na tela de atualizar item para consultar
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
    long int id_estoque = lerUltimoID();
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
        ler_nome_item(est->nome);
        eh_nome = verifica_estoque_existente(est->nome);
        if (eh_nome == 0){
            printf("\t#                 - Estoque Ja Existente!!! -                #\n");
            getchar();
        }
    }while(eh_nome != 1);
    est->nome[strcspn(est->nome, "\n")] = '\0'; // Funcao para tirar o \n do fgets
    printf("\t#   - Preco Individual do Item: R$ ");
    scanf("%f", &est->preco);getchar();
    est->id = id_estoque + 1;
    escreverUltimoID(est->id);
    printf("\t#   - ID Gerado do Item: %d\n",est->id);
    printf("\t#                                                          #\n");
    est->status = '1';

    return est;
}

int eh_b_ou_c(char bc) { // Feito com ajuda do chat gpt
    return (bc == 'b' || bc == 'c') ? 1 : 0;
}

void exibe_estoque_comida(Estoque* est){

    if (est == NULL) {
        printf("\n\t#                 - Estoque Inexistente -                  #\n");
    }
    else{
        if((est->comida_bebida == 'c')&&(est->status != '0')){
            printf("\t# - %-38s - %-5.2f - %-4d  #\n", est->nome, est->preco, est->quantidade);
        }
    }
}

void exibe_estoque_bebida(Estoque* est){
    if (est == NULL) {
        printf("\n\t#                 - Estoque Inexistente -                  #\n");
    }
    else{
        if((est->comida_bebida == 'b')&&(est->status != '0')){
            printf("\t# - %-38s - %-5.2f - %-4d  #\n", est->nome, est->preco, est->quantidade);
        }
    }
}

void mostra_lista(FILE* fp){ // criando outra função para o codigo nao ficar grande.

    Estoque* est;
    int bebidas_exibidas = 0;
    int comidas_exibidas = 0;
    char opcao;

    printf("\t#     1 - Comidas                                          #\n");
    printf("\t#     2 - Bebidas                                          #\n");
    printf("\t#   Escolha a categoria que deseja ver: ");
    scanf("%c", &opcao); getchar();
    printf("\t#                                                          #\n");
    est = (Estoque*) malloc(sizeof(Estoque));
    switch (opcao){
    case '1':
        while(fread(est, sizeof(Estoque), 1, fp)==1){ // Loop interrompido para aparecer uma vez só, feito com ajuda do Chat GPT
            if (est->comida_bebida == 'c') {
                if (!comidas_exibidas) {
                    printf("\t#   - Comidas:                                             #\n");
                    printf("\t# -                  Nome                  - Preco - Qnt - #\n");
                    comidas_exibidas = 1;
                }
                exibe_estoque_comida(est);
            }
        }
        break;

    case '2':
        rewind(fp); //função para ler o arquivo de novo e poder mostrar as bebidas e comidas separadas.
        while(fread(est, sizeof(Estoque), 1, fp)==1){
            if (est->comida_bebida == 'b') {
                if (!bebidas_exibidas) {
                    printf("\t#   - Bebidas:                                             #\n");
                    printf("\t# -                  Nome                  - Preco - Qnt - #\n");
                    bebidas_exibidas = 1;
                }
                exibe_estoque_bebida(est);
            }
        }
        break;
    
    default:
        printf("\t#               - Digite uma opcao valida -                #\n");
        break;
    }
    free(est);
}

void procura_estoque(Estoque* est){
     char* com_ou_beb;

     if(est->comida_bebida == 'c'){
         com_ou_beb = "Comida";
     }
     else{
         com_ou_beb = "Bebida";
     }

     if (est == NULL) {
         printf("\n\t#                 - Estoque Inexistente -                  #\n");
     }
     else{
        printf("\t#  1 - Categoria do Item: %s\n", com_ou_beb);
        printf("\t#  2 - Nome do Item: %s\n", est->nome);
        printf("\t#  3 - Em Estoque: %d \n", est->quantidade);
        printf("\t#  4 - Preco Individual: %.2f\n", est->preco);
        printf("\t#  5 - ID: %d \n", est->id);
     }
     
 }

// Funções para ler o último ID do arquivo, Tirado com ajuda do Chat GPT para execução
long int lerUltimoID(void) {
    long int id = 0;
    FILE *idFile = fopen("ultimo_id.dat", "rb");
    if (idFile) {
        fscanf(idFile, "%ld", &id);
        fclose(idFile);
    }
    return id;
}
// Função para escrever o último ID no arquivo Tambem tirada do Chat GPT
void escreverUltimoID(long int id) {
    FILE *idFile = fopen("ultimo_id.dat", "wb");
    if (idFile) {
        fprintf(idFile, "%ld", id);
        fclose(idFile);
    }
}

void exibe_pesquisa(Estoque* est, FILE* fp){
    int pesquisa;
    char escolha[2];

    while(fread(est, sizeof(Estoque), 1, fp)){
        if(est->status != '0'){
            printf("\t#     - %d - %s\n",est->id,est->nome);
        }
    }
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item: ");
    scanf("%d", &pesquisa);
    printf("\t#                                                          #\n");
    do{
        printf("\t#     Confirmar Busca (s) ou (n): ");
        scanf("%1s", escolha);
        limpar_buffer();
        s_ou_n(escolha); 
    }while(s_ou_n(escolha) != 1);
    printf("\t# \n");
    if(escolha[0] != 'n'){
        exibe_busca(fp, est, pesquisa);
    }
}

void func_exclusao(Estoque* est, FILE* fp){

    int pesquisa;
    char escolha[2];

    while(fread(est, sizeof(Estoque), 1, fp)){
        if(est->status != '0'){
            printf("\t#     - %d - %s\n",est->id,est->nome);
        }
    }

    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item: ");
    scanf("%d", &pesquisa);
    printf("\t#                                                          #\n");
    do{
        printf("\t#     Confirmar Exclusao (s) ou (n): ");
        scanf("%1s", escolha);
        limpar_buffer();
        s_ou_n(escolha); 
    }while(s_ou_n(escolha) != 1);

    if(escolha[0] != 'n'){
        int encontrado = 0;
        rewind(fp);
        while(fread(est, sizeof(Estoque), 1, fp)){
            if (est->status != '0'){
                if (est->id == pesquisa) { // Feito com a ajuda do chat gpt para a exclusão Lógica
                    est->status = '0';
                    encontrado = 1;
                    fseek(fp, -sizeof(Estoque), SEEK_CUR);
                    fwrite(est, sizeof(Estoque), 1, fp);
                    break;
                }
            }
        }
        if(!encontrado){
            printf("\t#                 -- ID nao encontrado! --                 #\n");
        }
    }
}

void func_edit(FILE* fp, Estoque* est){

    int pesquisa;

    while(fread(est, sizeof(Estoque), 1, fp)){
        if(est->status != '0'){
            printf("\t#     - %d - %s\n",est->id,est->nome);
        }
    }

    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do item desejado: ");
    scanf("%d", &pesquisa);
    getchar();
    printf("\t#                                                          #\n");
    printf("\t#             // - Informacoes Originais - //              #\n");
    printf("\t#                                                          #\n");
    exibe_busca(fp, est, pesquisa);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");

    int encontrado = 0;
    rewind(fp);
    while(fread(est, sizeof(Estoque), 1, fp)){
        if (est->status != '0'){
            if (est->id == pesquisa) { 
                muda_estoque(fp, est);
                encontrado = 1;
                break;
            }
        }
    }
    if(!encontrado){
        printf("\t#                 -- ID nao encontrado! --                 #\n");
    }
}

void exibe_busca(FILE* fp, Estoque* est, int pesquisa){
    int encontrado = 0;
    rewind(fp);
    while(fread(est, sizeof(Estoque), 1, fp)){
        if (est->status != '0'){
            if(est->id == pesquisa){
                procura_estoque(est);
                encontrado = 1;
                break;
            }
        }
    }
    if(!encontrado){
        printf("\t#                 -- ID nao encontrado! --                 #\n");
    }
}

void muda_estoque(FILE* fp, Estoque* est){

    int bouc, eh_nome;
    char num;

    printf("\t#               // - Informacoes Novas - //                #\n");
    printf("\t#                                                          #\n"); // Depende do que o usuario for digitar na tela de atualizar item para consultar
    printf("\t#   - Insira o numero deseja editar: ");
    scanf("%c", &num); 
    limpar_buffer();
    switch (num){
        case '1':
            do{
                printf("\t#   - Categoria do Item (apenas 'c' ou 'b'): ");
                scanf(" %c", &est->comida_bebida);getchar();
                bouc = eh_b_ou_c(est->comida_bebida);
            }while(bouc == 0);
            break;
                    
        case '2':
            do{
                ler_nome_item(est->nome);
                eh_nome = verifica_estoque_existente(est->nome);
                if (eh_nome == 0){
                    printf("\t#                 - Estoque Ja Existente!!! -                #\n");
                    getchar();
                }
            }while(eh_nome != 1);
            break;
                    
        case '3':
            printf("\t#   - Em Estoque: ");
            scanf("%d", &est->quantidade);getchar();
            break;

        case '4':
            printf("\t#   - Preco Individual: ");
            scanf("%f", &est->preco);getchar();
            break;

        default:
            printf("\t#               - Digite uma opcao valida -                #\n");
            getchar();
            break;
    }
                
    fseek(fp, -sizeof(Estoque), SEEK_CUR);
    fwrite(est, sizeof(Estoque), 1, fp);
}