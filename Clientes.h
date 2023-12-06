// definicao do struct do programa
typedef struct pedido{
    char mesa[2];
    char comanda[5];
    char status;
    
}Pedido;
// Assinatura das Funcoes do menu cliente

void menu_cliente(void);
void tela_pedidos(void);
void tela_comidas(void);
void tela_bebidas(void);
void tela_visualizar_pedido(void);
void tela_ajuda(void);