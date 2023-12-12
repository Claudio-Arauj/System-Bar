#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"
#include "Gerencia.h"
#include "Estoque.h"
#include "Clientes.h"

int valida_nome(char *nome) { // Adaptada do Chat GPT
  int tam = strlen(nome);
    
  if ((tam - 1) < 2) {
    return 0;
   }
    
  for (int i = 0; i < tam - 1; i++) {
    if (!(isalpha(nome[i]) || isspace(nome[i]) || eh_letra_acentuada(nome[i]))) {
      return 0;
    }
  }

  if ((isspace(nome[0])) || (isspace(nome[tam - 2]))) { // Inspirada no código de Matheus Diniz Fernandes
    return 0;
  }

  for (int j = 0; j < tam - 1; j++) {
    if((nome[j] == ' ') && (nome[j+1] == ' ')){
      return 0;
    }
  }
  
    
  return 1;
}

int eh_letra_acentuada(char c) { // Adaptada do Chat GPT e com ajuda de Matheus Diniz Fernandes
  char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç";
    
  for (int j = 0; letras_acentuadas[j] != '\0'; j++) {
    if (c == letras_acentuadas[j]) {
      return 1; // caso ache validação retorna true
    }
  }
    
  return 0;
}

char* le_nome(char *nome){
  int confirm;
  do{
    printf("\t#       Nome: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';  // Remover o \n do final da string
    confirm = valida_nome(nome);
  } while(confirm != 1);

  return nome;
}

int validarCPF(char *cpf){ //Total credito da funcao para Eduardo Edson Batista Cordeiro Alves / @eduardoedson no github no link https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3

  //validação de cpf retirado do site http://wurthmann.blogspot.com/ e sofreu algumas adpatações por Matheus Diniz
    // Remova os caracteres de pontuação (.) e hífen (-) do CPF
    removerCaracteresNaoNumericos(cpf);

    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ( 
          (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) ||
          (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
          (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) ||
          (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
      return 0;
    else {
      // Digito 1
      for (i = 0, j = 10; i < 9; i++, j--) {
          digito1 += (cpf[i] - '0') * j;
      }
      digito1 %= 11;
      if (digito1 < 2)
          digito1 = 0;
      else
          digito1 = 11 - digito1;
      if ((cpf[9] - '0') != digito1)
          return 0;

      // Digito 2
      for (i = 0, j = 11; i < 10; i++, j--) {
          digito2 += (cpf[i] - '0') * j;
      }
      digito2 %= 11;
      if (digito2 < 2)
          digito2 = 0;
      else
          digito2 = 11 - digito2;
      if ((cpf[10] - '0') != digito2)
          return 0;
    }

    return 1;
}

void ler_cpf(char cpf[]) {
    //função reutilizável para realizar a leitura do cpf
    int c;
    do{
      printf("\t#       CPF: ");
      scanf("%s", cpf);
      //função utilizada para limpar o buffer
      limpar_buffer();
      c=validarCPF(cpf);
    }while(c!=1);
}

void limpar_buffer() { // Funcao criada por Matheus Diniz Fernandes / @Matheusdnf - detem todos os creditos.
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
    }
}

int s_ou_n(char* op){

  if(isspace(op[0])){
    return 0;
  }

  if ((strlen(op) == 1) && (*op == 's' || *op == 'n')) {
    return 1; // O caractere é válido ('s' ou 'n')
  }

  return 0;
}

int validaTelefone(char *telefone) // Apenas Brasil. Feito por Felipe Augusto github:@fel-ps
{
    // Remove o '\n' do final da string (se existir)
    if (telefone[strlen(telefone) - 1] == '\n')
    {
        telefone[strlen(telefone) - 1] = '\0';
    }

    int tamanho = strlen(telefone);
    int digitos = 0;
    

    // Verifica se o tamanho está dentro do intervalo [min, max]
    int min = 10;
    int max = 14;
    if (tamanho < min || tamanho > max) 
    {
        return 0; // Tamanho inválido
    }

    if (telefone[0] != '(' || telefone[3] != ')')
    {
        return 0; // Parênteses do DDD na posição incorreta
    }

    // Verifica se todos os caracteres são dígitos ou separadores
    for (int i = 0; i < tamanho; i++) 
    {
        if (i != 0 && i != 3)
        {
            if (!isdigit(telefone[i]) && (telefone[i] != ' ') && (telefone[i] != '-'))
            {
                return 0;
            }
        }
        if ((telefone[i] >= '0' && telefone[i] <= '9') || (telefone[i] != ' ' && telefone[i] != '-')) 
        {
            digitos++;
        }
    }

    // Verifica se há pelo menos o número mínimo de dígitos
    if (digitos < min) 
    {
        return 0;
    }

    return 1;
}

void remove_nao_numericos(char *str) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0'; // Adiciona o caractere nulo ao final da nova string
}

void removerCaracteresNaoNumericos(char cpf[]) {
    //feita pelo chat gpt
    int len = strlen(cpf);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cpf[k] = cpf[i];
            k++;
        }
    }
    cpf[k] = '\0'; // Adicione o terminador nulo ao final
}

void le_senha(char* senha){
    char conf_senha[25];
    int eh_igual;
    do{
        printf("\t#       Senha: ");
        fgets(senha,25,stdin);
        senha[strcspn(senha, "\n")] = '\0'; // Funcao para tirar o \n do fgets
        printf("\t#     Confirmar Senha: ");
        fgets(conf_senha,25,stdin);
        conf_senha[strcspn(conf_senha, "\n")] = '\0'; // Funcao para tirar o \n do fgets
        eh_igual = compara_senha(senha, conf_senha);
        if(eh_igual != 1){
            printf("\n\t(Senha Desigual ou maior que 25 caracteres)\n");
        }
    }while(eh_igual != 1);
}

int compara_senha(char* senha, char* conf_senha){
  int tam,tam2;

  tam = strlen(senha);
  tam2 = strlen(conf_senha);

  if((tam > 25)||(tam2 > 25)){
    return 0;
  }

  if(strcmp(senha, conf_senha)!= 0){
    return 0;
  }
  return 1;

}

void le_numero(char* telefone){

  int eh_numero;
  do {
    printf("\t#       Celular[Ex:(84)99923-2131]: "); 
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';  // Remover o \n do final da string
    eh_numero = validaTelefone(telefone);
  } while(eh_numero != 1);

}

// GERADOR DE CHAVE (CHATGPT) Funcao de @fel-ps
void gerarCodigoAleatorio(char *id, unsigned int seed) {
    srand(seed);
    srand(time(NULL));

    // Gera uma sequência aleatória de 5 caracteres alfanuméricos
    for (int i = 0; i < 5; ++i) {
        id[i] = '0' + (rand() % 10);  // Números de 0 a 9
    }

    // Adiciona o caractere nulo no final para formar uma string válida
    id[5] = '\0';
}

int verifica_cpf(char* cpf){ // Feita com ajuda de @fel-ps

  FILE* fp;
  Login* log;

  log = (Login*)malloc(sizeof(Login));
  fp = fopen("Cadastro.dat", "rb");

  if (fp == NULL) {
    printf("\n\tErro na criacao\n");
    return 0;
  }

  while(fread(log, sizeof(Login), 1, fp)) {
    if ((strcmp(log->cpf, cpf) == 0) && (log->status != '0')) {
        return 0;
    }
  }
  fclose(fp);
  free(log);
  return 1;

}