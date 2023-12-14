
// Assinatura das Funcoes de utilidade geral

// validar nomes
int valida_nome(char *nome);
int eh_letra_acentuada(char c);
char* le_nome(char *nome);

// validar cpf
int validarCPF(char *cpf);
void ler_cpf(char cpf[]);
void removerCaracteresNaoNumericos(char cpf[]);

// funcoes uteis
void limpar_buffer();
int s_ou_n(char* op);
int validaTelefone(char *telefone);
void remove_nao_numericos(char *str);
void le_senha(char* senha);
int compara_senha(char* senha, char* conf_senha);
void le_numero(char* telefone);
void gerarCodigoAleatorio(char *id, unsigned int seed);
int verifica_cpf(char* cpf);
void minuscula_letras(char *str);
int verifica_estoque_existente(char* nome);
void ler_nome_item(char nome[]);