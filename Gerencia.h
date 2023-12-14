// definicao do struct do programa
typedef struct login{
    char cpf[15];
    char nome[100];
    char senha[25];
    char telefone[16];
    char status;
}Login;

// Assinatura das Funcoes do menu gerencia

void acesso_gerencia(void);
void menu_cadastramento(void);
void menu_login(void);
void menu_gerencia(void);
void tela_pedidos_gerencia(void);
void tela_caixa(void);
void tela_relatorio(void);
void tela_funcionarios(void);
void tela_comanda(void);
Login* preenche_login(void);
void lista_funcionarios(FILE* fp);
void procura_funcionario(void);
void excluir_funcionario(void);
void atualiza_funcionario(void);
void muda_funcionario(FILE* fp, Login* log);
int confere_login(FILE* fp, Login* log);
void pedidos_pendentes(void);
void relatorio_pedidos_lista(void);