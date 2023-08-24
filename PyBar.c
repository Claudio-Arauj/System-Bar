#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Biblioteca vista no canal https://youtu.be/hB6KFP6luL4 

// Assinatura das Fun��es para funcionar de acordo sem warning:

void menu_inicial(void);
void menu_sobre(void);
void menu_equipe(void);
void menu_gerencia(void);
void acesso_gerencia(void);
void menu_cadastramento(void);
void menu_login(void);
void tela_estoque(void);
void tela_cadastro_item(void);
void tela_procura_item(void);
void tela_lista_itens(void);
void tela_excluir_item(void);
void tela_atualizar_item(void);
void tela_atualizacao(void);

//Programa Principal -

int main(void){

    setlocale(LC_ALL,"Portuguese_Brazil"); // Fun��o vista no v�deo https://youtu.be/hB6KFP6luL4

    menu_inicial();
    menu_sobre();
    menu_equipe();
    acesso_gerencia();
    menu_cadastramento();
    menu_login();
    menu_gerencia();
    tela_estoque();
    tela_cadastro_item();
    tela_procura_item();
    tela_lista_itens();
    tela_excluir_item();
    tela_atualizar_item();
    tela_atualizacao();
    
    return 0;
}

//Fun��es abaixo - 

void menu_inicial(void){
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
    printf("\t#   2 - Menu de Ger�ncia               #\n");
    printf("\t#   3 - Informa��es Sobre o Programa   #\n");
    printf("\t#                                      #\n");
    printf("\t#         0 - Fechar o Programa        #\n");
    printf("\t#                                      #\n");
    printf("\t#   Insira sua Op��o: ");
    scanf("%c", &op);
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

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
    printf("\t#    programa��o alem de prover uma    #\n");
    printf("\t# simula��o do mercado de trabalho com #\n");
    printf("\t#   cobran�as e cumprimento de metas   #\n");
    printf("\t# como base sendo um sistema de gest�o #\n");
    printf("\t#   de bar e restaurante que tem como  #\n");
    printf("\t#     objetivo tornar o ambiente de    #\n");
    printf("\t#        trabalho mais din�mico        #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void menu_equipe(void){

    system("clear||cls");
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
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}


void acesso_gerencia(void){

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
    printf("\t#        - Acesso da Ger�ncia -        #\n");
    printf("\t#                                      #\n");
    printf("\t#         1. Login Funcion�rio         #\n");
    printf("\t#     2. Cadastramento Funcion�rio     #\n");
    printf("\t#                                      #\n");
    printf("\t#           Insira sua Op��o: ");
    scanf("%c", &op);
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void menu_cadastramento(void){

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
    printf("\t#          // - Cadastro - //          #\n");
    printf("\t#                                      #\n");
    printf("\t#        CPF:                          #\n");
    printf("\t#       Senha:                         #\n");
    printf("\t#   Confirmar Senha:                   #\n");
    printf("\t#                                      #\n");
    printf("\t#   Senha de Acesso:                   #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void menu_login(void){

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
    printf("\t#            // - Login - //           #\n");
    printf("\t#                                      #\n");
    printf("\t#        CPF:                          #\n");
    printf("\t#       Senha:                         #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void menu_gerencia(void){

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
    printf("\t#        // - Menu Ger�ncia - //       #\n");
    printf("\t#                                      #\n");
    printf("\t#    1. Visualizar Itens de Estoque    #\n");
    printf("\t#    2. Pedidos Pendentes              #\n");
    printf("\t#    3. Visualizar o Caixa             #\n");
    printf("\t#    4. Ver Relat�rio de Pedidos       #\n");
    printf("\t#    5. Visualizar Funcion�rios        #\n");
    printf("\t#                                      #\n");
    printf("\t#            0. Sair da Tela           #\n");
    printf("\t#                                      #\n");
    printf("\t#    Insira sua Op��o: ");
    scanf("%c", &op);
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}

void tela_estoque(void){

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
    printf("\t#   Insira sua Op��o: ");
    scanf("%c", &op);
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_cadastro_item(void){

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
    printf("\t#   - Bebida(b) ou Comida(c):                              #\n");
    printf("\t#   - Quantidade(apenas numeros inteiros):                 #\n");
    printf("\t#   - Nome do Item:                                        #\n");
    printf("\t#   - Pre�o Individual do Item: R$                         #\n");
    printf("\t#   - ID Gerado do Item: 00000000000x (N�o Alter�vel)      #\n");
    printf("\t#                                                          #\n");
    printf("\t#     Confirmar Cadastramento (s) ou (n):                  #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_procura_item(void){ // Mais adiante no c�digo irei separar essa fun��o em duas telas para ficar com um c�digo mais limpo.

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
    printf("\t#     ID's Dispon�veis:                                    #\n");
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
    printf("\t#   - Pre�o Individual:                                    #\n");
    printf("\t#   - ID: 00000000000x                                     #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_lista_itens(void){

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
    printf("\t#   - Comidas:                                             #\n");
    printf("\t#           ID            Nome           Pre�o     Qnt.    #\n");
    printf("\t#   -  00000000000x  -  Produto 0x  -  R$ xx,xx  -  xx  -  #\n"); // Apenas Exemplo mostrando como ficaria
    printf("\t#   -  00000000000x  -  Produto 0x  -  R$ xx,xx  -  xx  -  #\n");
    printf("\t#                                                          #\n");
    printf("\t# -------------------------------------------------------- #\n");
    printf("\t#   - Bebidas:                                             #\n");
    printf("\t#           ID            Nome           Pre�o     Qnt.    #\n");
    printf("\t#   -  00000000000x  -  Produto 0x  -  R$ xx,xx  -  xx  -  #\n"); // Apenas Exemplo mostrando como ficaria
    printf("\t#   -  00000000000x  -  Produto 0x  -  R$ xx,xx  -  xx  -  #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_excluir_item(void){ //pretendo aumentar a tela para oferecer mais adaptabilidade na hora de querer excluir algum item.
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
    printf("\t#     ID's Dispon�veis:                                    #\n");
    printf("\t#     - 00000000000x (Produto x)                           #\n");
    printf("\t#     - 00000000000x (Produto 2x)                          #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item:                                   #\n");
    printf("\t#                                                          #\n");
    printf("\t#     Confirmar Exclus�o (s) ou (n):                       #\n");
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
    printf("\t#     ID's Dispon�veis:                                    #\n");
    printf("\t#     - 00000000000x (Produto x)                           #\n");
    printf("\t#     - 00000000000x (Produto 2x)                          #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item:                                   #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void tela_atualizacao(void){ // Essa aqui vai ser a tela dividida da atualiza��o para a fun��o n�o ficar muito grande.

    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#              // - Tela de Atualiza��o - //               #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#             // - Informa��es Originais - //              #\n");
    printf("\t#                                                          #\n"); // Aqui vai vim as informa��es do item consultado pelo usu�rio para fazer compara��o
    printf("\t#   - Categoria do Item: Comida/�gua                       #\n"); // Depende do que o usu�rio for digitar na tela de atualizar item para consultar
    printf("\t#   - Nome do Item: Produto 0x                             #\n");
    printf("\t#   - Em Estoque: xx                                       #\n");
    printf("\t#   - Pre�o Individual: R$ xx,xx                           #\n");
    printf("\t#   - ID: 00000000000x                                     #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#               // - Informa��es Novas - //                #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Categoria do Item (apenas 'c' ou 'a'):               #\n"); // Depende do que o usu�rio for digitar na tela de atualizar item para consultar
    printf("\t#   - Nome do Item:                                        #\n");
    printf("\t#   - Em Estoque:                                          #\n");
    printf("\t#   - Pre�o Individual:                                    #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}