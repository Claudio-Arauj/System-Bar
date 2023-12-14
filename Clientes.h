// definicao do struct do programa
typedef struct pedido{
    char mesa[3];
    char comanda[5];
    float status; // 1 vai ser para pendente; 0 para feito/finalizado/recebido
    char pedidos[50][50];
    float valores[10];
    int quantidade[10];
    
}Pedido;

// Assinatura das Funcoes do menu cliente

void menu_cliente(void);
void tela_pedidos(void);
void tela_comidas(void);
void exibe_tudo(FILE* fp, Estoque* est);
void tela_visualizar_pedido(void);
void tela_ajuda(void);
void add_pedido(FILE* fp, Estoque* est);
char *strcasestr(const char *haystack, const char *needle);
void salvar_carrinho(Pedido *pedido);
void confere_numero_mesa(char* mesa);
int eh_s_ou_n(char sn);
void finaliza_pedido(void);
void esvaziarArquivo(FILE *arquivo);
void mostra_ficha(Pedido* ped);
void copiarArquivo(void);
void definir_nome_limitado(Pedido *estrutura, const char *novo_nome);