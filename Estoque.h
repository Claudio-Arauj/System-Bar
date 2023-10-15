// definicao do struct do programa
typedef struct estoque{
    char comida_bebida[2];
    int quantidade[0];
    char nome[50];
    float preco[0];
    char id[13];
    
}Estoque;

// Assinatura das Funcoes do menu estoque

void tela_estoque(void);
void tela_cadastro_item(void);
void tela_procura_item(void);
void tela_lista_itens(void);
void tela_excluir_item(void);
void tela_atualizar_item(void);
void tela_atualizacao(void);