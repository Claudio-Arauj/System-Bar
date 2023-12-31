///////////////////////////////////////////////////////
//                                                   //
//        Arquivo para controle na gerencia          //
//                                                   //
///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Estoque.h"
#include "Gerencia.h"
#include "Clientes.h"
#include "util.h"

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
    fp = fopen("Cadastro.dat","ab");
    if (fp == NULL) {
        printf("Erro na criacao do arquivo\n!");
        exit(1);
    }
    log = preenche_login();
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
        printf("\t#    3. Ver Relatorio de Pedidos       #\n");
        printf("\t#    4. Visualizar Funcionarios        #\n");
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
                break;

            case '3':
                tela_relatorio();
                break;

            case '4':
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
    printf("\t#   - Total de pedidos pendentes                           #\n");
    pedidos_pendentes();
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
    printf("\t#   1. Ver todos os Relatorios de Pedidos ja feitos        #\n"); // Esta em forma ordenada, o primeiro da lista foi o ultimo pedido.
    printf("\t#                                                          #\n");
    printf("\t#   0. Sair                                                #\n");
    printf("\t#                                                          #\n");
    printf("\t#      Insira sua Escolha: ");
    scanf("%c", &op);
    getchar();
    switch (op){
    case '1':
        relatorio_pedidos_lista();
        break;

    case '0':
        break;
    
    default:
        printf("\t#               Digite uma opcao valida!!!                 #\n");
    }
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
    int eh_numero, eh_cpf;

    log = (Login*) malloc(sizeof(Login));
    
    do{
        ler_cpf(cpf);
        eh_cpf = verifica_cpf(cpf);
        if (eh_cpf == 0){
            printf("\t#        - CPF ja Existente!!! -       #\n");
            getchar();
        }
    }while(eh_cpf != 1);
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

void pedidos_pendentes(void) { //Feito com ajuda do ChatGPT
    FILE* fp;
    Pedido* ped;
    char coma[6], escolha[2];
    ped = (Pedido*)malloc(sizeof(Pedido));
    fp = fopen("Pedidos.dat", "rb+");
    if (fp == NULL) {
        printf("\t#              - Nenhum registro encontrado -              #\n");
    } else {
        int comandaEncontrada = 0;
        while (fread(ped, sizeof(Pedido), 1, fp) == 1) {
            if (ped->status != 1) {
                printf("\t#   - %-5s - Mesa %-2s                                      #\n", ped->comanda, ped->mesa);
                comandaEncontrada = 1;
            }
        }
        if (!comandaEncontrada) {
            printf("\t#              - Nenhum registro encontrado -              #\n");
        } else {
            printf("\t# - Informe ID da Comanda: ");
            fgets(coma, sizeof(coma), stdin);
            coma[strcspn(coma, "\n")] = '\0';
            printf("\t#                                                          #\n");
            rewind(fp);
            comandaEncontrada = 0;
            while (fread(ped, sizeof(Pedido), 1, fp)) {
                if ((strcmp(coma, ped->comanda) == 0) && (ped->status != 1)) {
                    mostra_ficha(ped);
                    printf("\t# - Confirmar Finalizacao do Pedido? (s) ou (n): ");
                    do {
                        scanf("%1s", escolha);
                        limpar_buffer();
                        s_ou_n(escolha);
                    } while (s_ou_n(escolha) != 1);
                    if (escolha[0] != 'n') {
                        ped->status = 1;
                        fseek(fp, -sizeof(Pedido), SEEK_CUR);
                        fwrite(ped, sizeof(Pedido), 1, fp);
                        printf("\t#                  - Pedido Realizado!!! -                 #\n");
                    }
                    comandaEncontrada = 1;
                    break;  // Saia do loop após encontrar e processar a comanda
                }
            }
            if (!comandaEncontrada) {
                printf("\t#              - Nenhum registro encontrado -              #\n");
            }
        }
        fseek(fp, -sizeof(Pedido), SEEK_CUR);
        fwrite(ped, sizeof(Pedido), 1, fp);
        fclose(fp);
    }
    free(ped);
}

void relatorio_pedidos_lista(void) { // Feito com ajuda do ChatGPT 
    FILE* fp;
    Pedido* ped;
    char coma[6];
    ped = (Pedido*)malloc(sizeof(Pedido));
    fp = fopen("Pedidos.dat", "rb+");
    if (fp == NULL) {
        printf("\t#              - Nenhum registro encontrado -              #\n");
    } else {
        int comandaEncontrada = 0;
        // Obtenha o tamanho total do arquivo
        fseek(fp, 0, SEEK_END);
        long tamanhoArquivo = ftell(fp);
        // Calcule a quantidade de registros no arquivo
        size_t tamanhoRegistro = sizeof(Pedido);
        long totalRegistros = tamanhoArquivo / tamanhoRegistro;
        // Retroceda para cada registro do final para o começo
        for (long i = totalRegistros - 1; i >= 0; i--) {
            fseek(fp, i * tamanhoRegistro, SEEK_SET);
            fread(ped, sizeof(Pedido), 1, fp);
            // Se o status for diferente de 0, exiba a comanda
            if (ped->status != 0) {
                printf("\t#   - %-4s - Mesa %-2s                                      #\n", ped->comanda, ped->mesa);
                comandaEncontrada = 1;
            }
        }
        if (!comandaEncontrada) {
            printf("\t#              - Nenhum registro encontrado -              #\n");
        } else {
            printf("\t# - Informe ID da Comanda: ");
            scanf("%5s", coma);
            getchar(); // Limpar o buffer
            printf("\t#                                                          #\n");
            comandaEncontrada = 0;
            // Retroceda novamente para procurar a comanda desejada
            for (long i = totalRegistros - 1; i >= 0; i--) {
                fseek(fp, i * tamanhoRegistro, SEEK_SET);
                fread(ped, sizeof(Pedido), 1, fp);
                if ((strcmp(coma, ped->comanda) == 0) && (ped->status == 1)) {
                    mostra_ficha(ped);
                    comandaEncontrada = 1;
                    break;  // Saia do loop após encontrar a comanda
                }
            }
            if (!comandaEncontrada) {
                printf("\t#              - Nenhum registro encontrado -              #\n");
            }
        }
        fclose(fp);
    }
    free(ped);
}
