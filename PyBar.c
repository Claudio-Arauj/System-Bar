#include <stdio.h>
#include <stdlib.h>

// Assinatura das Funcoes para funcionar de acordo sem warning:

char menu_inicial(void);
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
void tela_pedidos_gerencia(void);
void tela_caixa(void);
void tela_relatorio(void);
void tela_funcionarios(void);
void menu_cliente(void);
void tela_pedidos(void);
void tela_comidas(void);
void tela_bebidas(void);
void tela_visualizar_pedido(void);
void tela_ajuda(void);

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

    // menu_sobre();
    // menu_equipe();
    // acesso_gerencia();
    // menu_cadastramento();
    // menu_login();
    // menu_gerencia();
    // tela_estoque();
    // tela_cadastro_item();
    // tela_procura_item();
    // tela_lista_itens();
    // tela_excluir_item();
    // tela_atualizar_item();
    // tela_atualizacao();
    // tela_pedidos_gerencia();
    // tela_caixa();
    // tela_relatorio();
    // tela_funcionarios();
    // menu_cliente();
    // tela_pedidos();
    // tela_comidas();
    // tela_bebidas();
    // tela_visualizar_pedido();
    // tela_ajuda();
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


void acesso_gerencia(void){

    char op;
    while (op!='0'){
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
        printf("\t#        - Acesso da Gerencia -        #\n");
        printf("\t#                                      #\n");
        printf("\t#         1. Login Funcionario         #\n");
        printf("\t#     2. Cadastramento Funcionario     #\n");
        printf("\t#            0. Sair da Tela           #\n");
        printf("\t#                                      #\n");
        printf("\t#           Insira sua Escolha: ");
        scanf("%c", &op);
        printf("\t#                                      #\n");
        printf("\t########################################\n");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();

        switch (op){
            case '1':
                menu_login();
                break;

            case '2':
                menu_cadastramento();
                break;

            case '0':
                break;

            default:
                printf("\t>>>Insira algo valido<<<\n");
                getchar();
        }
    }
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
    printf("\t#       Nome:                          #\n");
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
    printf("\t#        // - Menu Gerencia - //       #\n");
    printf("\t#                                      #\n");
    printf("\t#    1. Visualizar Itens de Estoque    #\n");
    printf("\t#    2. Pedidos Pendentes              #\n");
    printf("\t#    3. Visualizar o Caixa             #\n");
    printf("\t#    4. Ver Relatorio de Pedidos       #\n");
    printf("\t#    5. Visualizar Funcionarios        #\n");
    printf("\t#                                      #\n");
    printf("\t#            0. Sair da Tela           #\n");
    printf("\t#                                      #\n");
    printf("\t#    Insira sua Escolha: ");
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
    printf("\t#   Insira sua Escolha: ");
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
    printf("\t#   - Preco Individual do Item: R$                         #\n");
    printf("\t#   - ID Gerado do Item: 00000000000x (Nao Alteravel)      #\n");
    printf("\t#                                                          #\n");
    printf("\t#     Confirmar Cadastramento (s) ou (n):                  #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
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
    printf("\t#           ID            Nome           Preco     Qnt.    #\n");
    printf("\t#   -  00000000000x  -  Produto 0x  -  R$ xx,xx  -  xx  -  #\n"); // Apenas Exemplo mostrando como ficaria
    printf("\t#   -  00000000000x  -  Produto 0x  -  R$ xx,xx  -  xx  -  #\n");
    printf("\t#                                                          #\n");
    printf("\t# -------------------------------------------------------- #\n");
    printf("\t#   - Bebidas:                                             #\n");
    printf("\t#           ID            Nome           Preco     Qnt.    #\n");
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
    printf("\t#     ID's Disponiveis:                                    #\n");
    printf("\t#     - 00000000000x (Produto x)                           #\n");
    printf("\t#     - 00000000000x (Produto 2x)                          #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Insira ID do Item:                                   #\n");
    printf("\t#                                                          #\n");
    printf("\t#     Confirmar Exclusio (s) ou (n):                       #\n");
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

void tela_pedidos_gerencia(void){

    char entrega;
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
    printf("\t#               // - Pedidos Pendentes - //                #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Total de pedidos pendentes (x)                       #\n");
    printf("\t#     Lista dos Pedidos:                                   #\n");
    printf("\t#                                                          #\n");
    printf("\t#     1. Comida: exemplo R$xx,xx                           #\n");
    printf("\t#        Bebida: exemplo R$xx,xx                           #\n");
    printf("\t#        Mesa: XX                                          #\n");
    printf("\t#        Total: R$xx,xx                                    #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Pedido Entregue? (s) ou (n) "); // Para confirmar se ele foi entregue ou nao para excluir do futuro dicionario e ficar algo mais dinamico alem de encurtar a tela
    scanf("%c", &entrega);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_caixa(void){

    char confirm;
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
    printf("\t#                 // - Tela do Caixa - //                  #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Total: R$ xxx,xx                                     #\n");
    printf("\t#     Esvaziar Caixa? (s) ou (n) "); // Serve para ter uma metrica de quanto foi lucrado no dia
    scanf("%c", &confirm);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_relatorio(void){

    char op;
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
    printf("\t#               // - Tela do Relatorio - //                #\n");
    printf("\t#                                                          #\n");
    printf("\t#   1. Ver todos os relatorios de pedidos                  #\n");
    printf("\t#   2. Ver ultimos 4 relatorios de pedidos                 #\n");
    printf("\t#                                                          #\n");
    printf("\t#      Insira sua Escolha: ");
    scanf("%c", &op);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_funcionarios(void){

    char escolha;
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
    printf("\t#              // - Tela de Funcionarios - //              #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Funcionarios:                                        #\n");
    printf("\t#     - Fulano de Tal                                      #\n");
    printf("\t#     - Joao de Fulano                                     #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#   - Deseja Excluir algum? (s) ou (n) ");
    scanf("%c", &escolha);
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}

void menu_cliente(void){ 

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
    printf("\t#         // - Menu Cliente - //       #\n");
    printf("\t#                                      #\n");
    printf("\t#    1. Ver Cardapio                   #\n"); // Esse Menu vou reutilizar o "tela_lista_itens()" para ser mais facil e poupar mais linhas de codigo
    printf("\t#    2. Adicionar Pedido               #\n");
    printf("\t#    3. Visualizar meu Pedido          #\n");
    printf("\t#    4. Menu Ajuda                     #\n");
    printf("\t#                                      #\n");
    printf("\t#            0. Sair da Tela           #\n");
    printf("\t#                                      #\n");
    printf("\t#    Insira sua Escolha: ");
    scanf("%c", &op);
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}

void tela_pedidos(void){

    char op;
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
    printf("\t#      Insira sua Escolha: ");
    scanf("%c", &op);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_comidas(void){

    char escolha;
    char quantidade[2];
    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#                // - Tela de Comidas - //                 #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n"); 
    printf("\t#   - Comidas Disponiveis:                                 #\n"); // Meramente ilustrativo
    printf("\t#     1. Frango Assado            R$ xx,xx                 #\n");
    printf("\t#     2. File                     R$ xx,xx                 #\n");
    printf("\t#     3. Salada                   R$ xx,xx                 #\n");
    printf("\t#     4. Carne de Sol             R$ xx,xx                 #\n"); // Vai colocando todos as comidas que estao disponiveis no momento que o estoque estiver maior que 1
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Qual sua Escolha?(Apenas Numero) ");
    scanf("%c", &escolha);
    printf("\t#   - Informe a Quantidade(Apenas Numero) ");
    scanf("%s", quantidade);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    getchar();

}

void tela_bebidas(void){

    char escolha;
    char quantidade[2];
    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#                // - Tela de Bebidas - //                 #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n"); 
    printf("\t#   - Bebidas Disponiveis: (Valor por Copo)                #\n"); // Meramente ilustrativo
    printf("\t#     1. Whisky                   R$ xx,xx                 #\n");
    printf("\t#     2. Chope                    R$ xx,xx                 #\n");
    printf("\t#     3. Cerveja                  R$ xx,xx                 #\n");
    printf("\t#     4. Pinga                    R$ xx,xx                 #\n"); // Vai colocando todos as bebidas que estao disponiveis no momento que o estoque estiver maior que 1
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#   - Qual sua Escolha?(Apenas Numero) ");
    scanf("%c", &escolha);
    printf("\t#   - Informe a Quantidade(Apenas Numero) ");
    scanf("%s", quantidade);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    getchar();

}

void tela_visualizar_pedido(void){

    char confirm;
    char num[2];
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
    printf("\t#   - Informe o Numero da Mesa: ");
    scanf("%s", num);
    printf("\t#   - Total: R$ xx,xx                                      #\n");
    printf("\t#                                                          #\n");
    printf("\t#   - (Digite 0 para Excluir TODAS suas escolhas)          #\n");
    printf("\t#   - Confirmar Pedido?(s) ou (n): ");
    scanf("%c",&confirm);
    getchar();
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
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