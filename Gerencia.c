///////////////////////////////////////////////////////
//                                                   //
//        Arquivo para controle na gerencia          //
//                                                   //
///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Gerencia.h"
#include "Estoque.h"
#include "util.h"
#include "Globals.h"

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
        getchar();
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
                menu_gerencia();
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
    
    Login *log;
    FILE *fp;

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
    log = preenche_login();
    fp = fopen("Cadastro.dat","ab");
    if (fp == NULL) {
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }
    fwrite(log, sizeof(Login), 1, fp);
    printf("\t#                                      #\n");
    printf("\t#   Senha de Acesso:                   #\n");
    printf("\t#                                      #\n");
    printf("\t########################################\n");
    fclose(fp);
    free(log);
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void menu_login(void){

    Login *log;
    FILE *fp;
    int confi;
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
    log = (Login*)malloc(sizeof(Login));
    fp = fopen("Cadastro.dat","rb");
    if (fp == NULL) {
        printf("Erro na leitura do arquivo\n!");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();
    }
    else{
        confi = confere_login(fp, log);
        fclose(fp);
        printf("\t#                                      #\n");
        printf("\t########################################\n");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();
        if (confi != 0){
            menu_gerencia();
        }
        else{
            printf("\n\t>CREDENCIAIS INVALIDAS<\n");
            getchar();
        }
    }
    free(log);
}

void menu_gerencia(void){

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
        getchar();
        printf("\t#                                      #\n");
        printf("\t########################################\n");
        printf("\n");
        printf("\t>Pressione ENTER para continuar<\n");
        getchar();
        
        switch (op){
            case '1':
                tela_estoque();
                break;

            case '2':
                tela_pedidos_gerencia();
                tela_comanda();
                break;

            case '3':
                tela_caixa();
                break;

            case '4':
                tela_relatorio();
                break;

            case '5':
                tela_funcionarios();
                break;
            
            case '0':
                break;

            default:
                printf("\t>>>Insira algo valido<<<\n");
                getchar();

        }
    }
}

void tela_pedidos_gerencia(void){

    //char entrega[9];
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
    printf("\t#     Lista dos ID's de Pedidos:                           #\n");
    printf("\t#                                                          #\n");
    printf("\t#     - 00000000x - Mesa XX                                #\n");
    printf("\t#     - 00000000x - Mesa XX                                #\n");
    printf("\t#                                                          #\n");
    printf("\t#     (Digite Apenas um 0 para sair)                       #\n");
    printf("\t#   - Informe ID da Comanda: "); 
    //scanf("%s", entrega);
    getchar();
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_comanda(void){

    char entrega[2];
    system("clear||cls");
    printf("\t############################################################\n");
    printf("\t#                 // - Tela de Comanda - //                #\n");
    printf("\t############################################################\n");
    printf("\t#                                                          #\n");
    printf("\t#        ID: 00000000x                                     #\n");
    printf("\t#        Comidas:                                          #\n");
    printf("\t#        - exemplo R$xx,xx                                 #\n");
    printf("\t#        - exemplo R$xx,xx                                 #\n");
    printf("\t#        - exemplo R$xx,xx                                 #\n");
    printf("\t#                                                          #\n");
    printf("\t#        Bebidas:                                          #\n");
    printf("\t#        - exemplo R$xx,xx                                 #\n");
    printf("\t#        - exemplo R$xx,xx                                 #\n");
    printf("\t#        - exemplo R$xx,xx                                 #\n");
    printf("\t#                                                          #\n");
    printf("\t#        Mesa: XX                                          #\n");
    printf("\t#        Total: R$xx,xx                                    #\n");
    printf("\t#                                                          #\n");
    do{
    printf("\t#   - Pedido Entregue? (s) ou (n) "); // Para confirmar se ele foi entregue ou nao para excluir do futuro dicionario e ficar algo mais dinamico alem de encurtar a tela
        scanf("%1s", entrega);
        limpar_buffer();
        s_ou_n(entrega);
    }while(s_ou_n(entrega) != 1);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}

void tela_caixa(void){

    char confirm[2];
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
    do{
        printf("\t#     Esvaziar Caixa? (s) ou (n) "); // Serve para ter uma metrica de quanto foi lucrado no dia
        scanf("%1s", confirm);
        limpar_buffer();
        s_ou_n(confirm);
    }while(s_ou_n(confirm) != 1);
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
    getchar();
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void tela_funcionarios(void){

    FILE* fp;
    Login* log;
    char op;

    log = (Login*)malloc(sizeof(Login));
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
    fp = fopen("Cadastro.dat", "rb");
    if (fp == NULL){
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    }
    else{
        lista_funcionarios(fp);
        fclose(fp);
    }
    free(log);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\t#    1 - Cadastrar Funcionario                             #\n");
    printf("\t#    2 - Procurar Funcionario                              #\n");
    printf("\t#    3 - Excluir Funcionario                               #\n");
    printf("\t#    4 - Atualizar Funcionario                             #\n");
    printf("\t#    0 - Sair                                              #\n");
    printf("\t#                                                          #\n");
    printf("\t#    Insira sua Escolha: ");
    scanf("%c", &op); getchar();
    printf("\t############################################################\n");

    switch (op){
    case '1':
        menu_cadastramento();
        break;
    
    case '2':
        procura_funcionario();
        break;

    case '3':
        excluir_funcionario();
        break;

    case '4':
        atualiza_funcionario();
        break;

    case '0':
        break;

    default:
        printf("\t#               - Digite uma opcao valida -                #\n");
        getchar();
    }
    
}

Login* preenche_login(void){
    Login* log;
    char cpf[15];
    int eh_numero;

    log = (Login*) malloc(sizeof(Login));
    
    ler_cpf(cpf);
    le_nome(log->nome);
    do {
        printf("\t#       Celular[Ex:(84)99923-2131]: "); 
        fgets(log->telefone, sizeof(log->telefone), stdin);
        log->telefone[strcspn(log->telefone, "\n")] = '\0';  // Remover o \n do final da string
        eh_numero = validaTelefone(log->telefone);
    } while(eh_numero != 1);

    strcpy(log->cpf,cpf);
    log->cpf[strcspn(log->cpf, "\n")] = '\0'; // Remover o \n do final da strings
    
    le_senha(log->senha);

    log->status = '1';

    return log;
}

void lista_funcionarios(FILE* fp){

    Login* log;
    log = (Login*) malloc(sizeof(Login));
    rewind(fp);

    while (fread(log, sizeof(Login), 1, fp) == 1) {
        if (log->status == '1') {
            // Verifica se a string do nome não está vazia
            printf("\t#    Nome: %-25s - CPF: %s \n", log->nome, log->cpf);
        }
    }

    free(log);
}

void procura_funcionario(void) { //Adaptada do ChatGPT
    FILE* fp;
    Login* log;
    char codigo[15];
    int encontrado = 0; // Variável para verificar se encontrou o registro

    log = (Login*)malloc(sizeof(Login));
    fp = fopen("Cadastro.dat", "rb");

    printf("\t#                                                          #\n");
    printf("\t#               // - Tela do Busca - //                    #\n");
    printf("\t#                                                          #\n");

    if (fp == NULL) {
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    } else {
        printf("\t#    Insira o CPF do Funcionario: ");
        fgets(codigo, sizeof(codigo), stdin);
        codigo[strcspn(codigo, "\n")] = '\0'; // Remover o \n do final da string

        rewind(fp);

        while (fread(log, sizeof(Login), 1, fp)) {
            if (log->status != '0') {
                if (strcmp(codigo, log->cpf) == 0) {
                    printf("\t#    - Nome: %s\n", log->nome);
                    printf("\t#    - CPF: %s\n", log->cpf);
                    printf("\t#    - Celular: %s\n", log->telefone);
                    encontrado = 1;
                    break; // Se encontrar, não precisa continuar procurando
                }
            }
        }
        if (!encontrado) {
            printf("\t#              - Nenhum registro encontrado -              #\n");
        }
        fclose(fp);
    }
    free(log);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void excluir_funcionario(void){

    FILE* fp;
    Login* log;
    char codigo[15];
    char escolha[2];
    int encontrado = 0; // Variável para verificar se encontrou o registro

    log = (Login*)malloc(sizeof(Login));
    fp = fopen("Cadastro.dat", "rb+");

    printf("\t#                                                          #\n");
    printf("\t#              // - Tela de Exclusao - //                  #\n");
    printf("\t#                                                          #\n");

    if (fp == NULL) {
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    } else {
        printf("\t#    Insira o CPF do Funcionario: ");
        fgets(codigo, sizeof(codigo), stdin);
        codigo[strcspn(codigo, "\n")] = '\0'; // Remover o \n do final da string

        rewind(fp);
        do{
            printf("\t#     Confirmar Exclusao (s) ou (n): ");
            scanf("%1s", escolha);
            limpar_buffer();
            s_ou_n(escolha); 
        }while(s_ou_n(escolha) != 1);
        if (escolha[0] != 'n'){
            while (fread(log, sizeof(Login), 1, fp)) {
                if (log->status != '0') {
                    if (strcmp(codigo, log->cpf) == 0) {
                        log->status = '0';
                        encontrado = 1;
                        fseek(fp, -sizeof(Login), SEEK_CUR);
                        fwrite(log, sizeof(Login), 1, fp);
                        printf("\t#              - Exclusao feita com sucesso -              #\n");
                        break; // Se encontrar, não precisa continuar procurando
                    }
                }
            }
        }
        if ((!encontrado) && (escolha[0] != 'n')) {
            printf("\t#              - Nenhum registro encontrado -              #\n");
        }
    }
    fclose(fp);
    free(log);
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
}

void atualiza_funcionario(void){

    FILE* fp;
    Login* log;
    char codigo[15];
    int encontrado = 0; // Variável para verificar se encontrou o registro

    log = (Login*)malloc(sizeof(Login));
    fp = fopen("Cadastro.dat", "rb+");

    printf("\t#                                                          #\n");
    printf("\t#             // - Tela de Atualizacao - //                #\n");
    printf("\t#                                                          #\n");

    if (fp == NULL) {
        printf("\t#             - Nao tem registro de cadastro -             #\n");
    } else {
        printf("\t#    Insira o CPF do Funcionario: ");
        fgets(codigo, sizeof(codigo), stdin);
        codigo[strcspn(codigo, "\n")] = '\0'; // Remover o \n do final da string
        while (fread(log, sizeof(Login), 1, fp)) {
            if (log->status != '0') {
                if (strcmp(codigo, log->cpf) == 0){
                    muda_funcionario(fp, log);
                    encontrado = 1;
                    break;
                }    
            }
        }
        if (!encontrado) {
            printf("\t#              - Nenhum registro encontrado -              #\n");
        }
    }
    fclose(fp);
    free(log);
    printf("\t#             - Registro realizado com sucesso -           #\n");
    printf("\t#                                                          #\n");
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();

}

void muda_funcionario(FILE* fp, Login* log){
    char escolha[2];
    int eh_numero;
    printf("\t#    1 - CPF                                               #\n");
    printf("\t#    2 - Nome                                              #\n");
    printf("\t#    3 - Numero                                            #\n");
    printf("\t#    4 - Senha                                             #\n");
    printf("\t#    0 - Sair                                              #\n");
    printf("\t#    Insira a opcao que deseja alterar: ");
    scanf("%1s", escolha);
    limpar_buffer();
    switch (escolha[0]){
        case '1':
            ler_cpf(log->cpf);
            break;

        case '2':
            le_nome(log->nome);
            break;

        case '3':
            do {
                printf("\t#       Celular[Ex:(84)99923-2131]: "); 
                fgets(log->telefone, sizeof(log->telefone), stdin);
                log->telefone[strcspn(log->telefone, "\n")] = '\0';  // Remover o \n do final da string
                eh_numero = validaTelefone(log->telefone);
            } while(eh_numero != 1);
            break;

        case '4':
            le_senha(log->senha);
            break;

        case '0':
            break;
        
        default:
            printf("\t#               - Digite uma opcao valida -                #\n");
            getchar();
            break;
    }
    fseek(fp, -sizeof(Login), SEEK_CUR);
    fwrite(log, sizeof(Login), 1, fp);
}

int confere_login(FILE* fp, Login* log){
    char senha[25];
    char cpf[15];
    printf("\t#       CPF: ");
    scanf("%s", cpf);
    limpar_buffer();

    printf("\t#       Senha: ");
    fgets(senha,25,stdin);
    senha[strcspn(senha, "\n")] = '\0'; // Funcao para tirar o \n do fgets

    while (fread(log, sizeof(Login), 1, fp)) {
        if (log->status != '0') {
            if (strcmp(cpf, log->cpf) == 0){
                if (strcmp(senha, log->senha) == 0){
                    return 1;
                }
            }    
        }
    }
    return 0;
}