///////////////////////////////////////////////////////
//                                                   //
//        Arquivo para controle na gerencia          //
//                                                   //
///////////////////////////////////////////////////////

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
                menu_gerencia();
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
    getchar();
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
    getchar();
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
    getchar();
    printf("\t############################################################\n");
    printf("\n");
    printf("\t>Pressione ENTER para continuar<\n");
    getchar();
    
}