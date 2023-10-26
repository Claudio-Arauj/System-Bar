// definicao do struct do programa
typedef struct estoque{
    char comida_bebida;
    int quantidade;
    char nome[50];
    float preco;
    int id;
    char status;
    
}Estoque;

// Assinatura das Funcoes do menu estoque

void tela_estoque(void);
Estoque* tela_cadastro_item(void);
void tela_procura_item(void);
void tela_lista_itens(void);
void tela_excluir_item(void);
void tela_atualizar_item(void);
void tela_atualizacao(void);