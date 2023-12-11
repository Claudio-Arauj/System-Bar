///////////////////////////////////////////////////////
//                                                   //
//      Arquivo para controle na tela clientes       //
//                                                   //
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Estoque.h"
#include "Clientes.h"
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
        printf("\t#   (Ao criar o carrinho, caso entre novamente o carrinho  #\n");
        printf("\t#   anterior sera perdido)                                 #\n");
        printf("\t#                                                          #\n");
        printf("\t#   1. Criar carrinho                                      #\n");
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
    
    est = (Estoque*) malloc(sizeof(Estoque));
    
    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#                // - Tela de Comidas - //                 #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n"); 
    fp = fopen("Estoque.dat", "rb+");
    if (fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        exibe_tudo(fp, est);
        printf("\t#                                                          #\n");
        printf("\t############################################################\n");
        printf("\t#                                                          #\n");
        add_pedido(fp, est);
        fclose(fp);
    }
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    free(est);
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void exibe_tudo(FILE* fp, Estoque* est){
    int comidas_exibidas = 0;
    int bebidas_exibidas = 0;

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
    printf("\t#----------------------------------------------------------#\n");
    rewind(fp); //função para ler o arquivo de novo e poder mostrar as bebidas e comidas separadas.
    while(fread(est, sizeof(Estoque), 1, fp)==1){
        if ((est->comida_bebida == 'b') && (est->quantidade > 0)) {
            if (!bebidas_exibidas) {
                printf("\t#   - Bebidas:                                             #\n");
                printf("\t# -                  Nome                  - Preco - Qnt - #\n");
                bebidas_exibidas = 1;
            }
            exibe_estoque_bebida(est);
        }
    }
}

void tela_visualizar_pedido(void){

    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#              // - Finalizacao de Pedido - //             #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Pedidos Escolhidos:                                  #\n"); 
    finaliza_pedido();
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

// Parte do código baseado em sugestões fornecidas por um assistente virtual.
// Referência: OpenAI GPT-3 ChatGPT
void add_pedido(FILE* fp, Estoque* est) {
    char escolha, nome[50];
    int quant;
    Pedido* ped;

    ped = (Pedido*)malloc(sizeof(Pedido));
    rewind(fp);

    for (int i = 0; i <= 9; i++) {
        printf("\t#   - Qual sua Escolha? ");
        fgets(nome, sizeof(nome), stdin);
        // Remover o \n
        nome[strcspn(nome, "\n")] = '\0';

        // Voltar para o início do arquivo
        rewind(fp);

        int itemEncontrado = 0;  // Adiciona uma variável para verificar se o item foi encontrado

        while (fread(est, sizeof(Estoque), 1, fp) == 1) {
            if (est->status != '0') {
                // Confere os nomes e se a quantidade do estoque ainda existe
                if ((strcmp(nome, est->nome) == 0) && (est->quantidade > 0)) {
                    strcpy(ped->pedidos[i], est->nome);
                    printf("\t#   - Informe a Quantidade (Apenas Numero): ");
                    scanf("%d", &quant);
                    getchar();  // Limpar o buffer do Enter

                    if (est->quantidade >= quant) {
                        est->quantidade -= quant;
                        ped->valores[i] = est->preco * quant;
                        ped->quantidade[i] = quant;
                        fseek(fp, -sizeof(Estoque), SEEK_CUR);
                        fwrite(est, sizeof(Estoque), 1, fp);
                        itemEncontrado = 1;  // Marca que o item foi encontrado
                        break;  // Saia do loop após encontrar o item desejado
                    } else {
                        printf("\t#                - Estoque indisponivel -                  #\n");
                        i--;
                        break;  // Saia do loop após tratar o item indisponível
                    }
                }
            }
        }
        if (!itemEncontrado) {
            printf("\t#                 - Item nao encontrado -                  #\n");
            i--;  // Decrementa o contador somente se o item não foi encontrado
        }

        printf("\t#     Adicionar mais pedidos? (s) ou (n): ");
        do {
            scanf(" %c", &escolha);
            limpar_buffer();
            eh_s_ou_n(escolha);
        } while (eh_s_ou_n(escolha) != 1);

        if (escolha != 's' || i == 9) {
            confere_numero_mesa(ped->mesa);
            gerarCodigoAleatorio(ped->comanda);
            salvar_carrinho(ped);
            break;
        }
    }
    getchar();
    free(ped);
}

// FUNCAO FEITA PELO CHATGPT PARA COMPARAR STRINGS E RETORNAR NULL CASO DUAS STRINGS 
// FOREM DIFERENTE EM ALGUM PONTO
char *strcasestr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && tolower((unsigned char)*h) == tolower((unsigned char)*n)) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;  // Encontrou a substring
        }

        haystack++;
    }

    return NULL;  // Substring não encontrada
}

void salvar_carrinho(Pedido *pedido) { // guardara apenas o carrinho atual
    FILE *fp = fopen("Carrinho.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo do carrinho.\n");
        return;
    }

    fwrite(pedido, sizeof(Pedido), 1, fp);
    fclose(fp);
}

void guardar_pedido(Pedido *pedido) { // guardara os pedidos ja realizados
    FILE *fp = fopen("Pedidos.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo do carrinho.\n");
        return;
    }

    fwrite(pedido, sizeof(Pedido), 1, fp);
    fclose(fp);
}

void confere_numero_mesa(char* mesa) { // Feito com a ajuda do ChatGPT
    do {
        printf("\t#  - Informe o numero da mesa (So numero de 2 digitos): ");
        scanf("%s", mesa);

        // Verifica se a string tem exatamente dois caracteres
        if (strlen(mesa) == 2) {
            // Verifica se ambos os caracteres são números
            int numeros = 1;
            for (int i = 0; i < 2; i++) {
                if (!isdigit(mesa[i])) {
                    numeros = 0;
                    break;
                }
            }

            // Se ambos os caracteres forem números, sai do loop
            if (numeros) {
                break;
            }
        }

        // Limpa o buffer do teclado em caso de entrada inválida
        while (getchar() != '\n');

        printf("\t#   - Entrada invalida. Tente novamente.\n");

    } while (1);
}

int eh_s_ou_n(char sn) { // Feito com ajuda do chat gpt
    return (sn == 's' || sn == 'n') ? 1 : 0;
}

void finaliza_pedido(void){

    FILE* fp;
    Pedido* ped;
    float preco_final = 0.0;
    char confirm[2];

    ped = (Pedido*)malloc(sizeof(Pedido));
    fp = fopen("Carrinho.dat", "rb+");
    if (fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        while(fread(ped,sizeof(Pedido), 1, fp)){
            int i;
            for (i = 0; i <= 9; i++) { // ajuste feito pelo chatGPT para nao aparecer lixo
                if (ped->pedidos[i][0] != '\0') {  // Verifica se o pedido não está vazio
                    printf("\t#    - %-30s R$ %-5.2f  - %-2d -     #\n", ped->pedidos[i], ped->valores[i], ped->quantidade[i]);
                    preco_final += ped->valores[i];
                } else {
                    break;  // Sai do loop se encontrar um pedido vazio
                }
            }
            printf("\t#                                                          #\n");
            printf("\t#  - Preco total: %.2f                                     \n", preco_final);
            printf("\t#                                                          #\n");
            printf("\t############################################################\n");
            printf("\t#                                                          #\n");
            printf("\t#    Mesa: %s                    Comanda: %s            #\n",ped->mesa, ped->comanda);
            printf("\t#                                                          #\n");
            do{
                printf("\t#   - Confirmar Pedido?(s) ou (n): ");
                scanf("%1s", confirm);
                limpar_buffer();
                s_ou_n(confirm);
            }while(s_ou_n(confirm) != 1);
            if (confirm[0] == 's'){
                ped->status = 'p';
                guardar_pedido(ped);
                printf("\t#             - Registro realizado com sucesso -           #\n");
                esvaziarArquivo(fp);
            }
            else{
                printf("\t#                 - Registro nao realizado -               #\n");
                fclose(fp);
            }
        }
    }
    free(ped);
}

void esvaziarArquivo(FILE *arquivo) { //funcao para esvaziar o carrinho do cliente feito pelo CHATGPT
    // Fecha o arquivo
    fclose(arquivo);

    // Reabre o arquivo em modo de escrita, truncando-o para tamanho 0
    arquivo = fopen("Carrinho.dat", "wb");  // Substitua "Carrinho.dat" pelo nome do seu arquivo
    if (arquivo == NULL) {
        perror("\t\tErro ao abrir o arquivo para esvaziar\n");
        return;
    }

    // Fecha novamente o arquivo
    fclose(arquivo);
}