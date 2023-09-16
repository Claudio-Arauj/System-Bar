///////////////////////////////////////////////////////
//                                                   //
//        Arquivo para controle no estoque           //
//                                                   //
///////////////////////////////////////////////////////

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
    printf("\t#     Confirmar Exclusao (s) ou (n):                       #\n");
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