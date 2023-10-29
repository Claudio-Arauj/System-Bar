// definicao do struct do programa
typedef struct login{
    char cpf[11];
    char nome[100];
    char senha[25];
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
int compara_senha(char* senha, char* conf_senha);