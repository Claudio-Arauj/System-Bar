#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

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
  int tam = strlen(letras_acentuadas);
    
  for (int j = 0; j < tam; j++) {
    if (c == letras_acentuadas[j]) {
      return 1; // caso ache validação retorna true
    }
  }
    
  return 0;
}

void le_nome(char *nome){
  int confirm;
  do{
    fgets(nome,100,stdin);
    confirm = valida_nome(nome);

    if (confirm == 0){
      printf("\tInvalido, Digite novamente: ");
    }
  }while(confirm != 1);
}


int validarCPF(char *cpf){ //Total credito da funcao para Eduardo Edson Batista Cordeiro Alves / @eduardoedson no github no link https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3

  int i, j, digito1 = 0, digito2 = 0;

  if(strlen(cpf) != 11){
    return 0;
  }
  else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) || (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
    (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) || (strcmp(cpf,"99999999999") == 0)){
      ///se o CPF tiver todos os números iguais ele é inválido.
      return 0;
    }
  else{
    ///digito 1---------------------------------------------------
    for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--){ ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
      digito1 += (cpf[i]-48) * j;
    } 
    digito1 %= 11;
    if(digito1 < 2){
      digito1 = 0;
    }
    else{
      digito1 = 11 - digito1;
    }
    if((cpf[9]-48) != digito1){ ///se o digito 1 não for o mesmo que o da validação CPF é inválido
      return 0;
    }
    else{
      ///digito 2--------------------------------------------------
      ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
      for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--){ 
        digito2 += (cpf[i]-48) * j;
      }
      digito2 %= 11;
      if(digito2 < 2){
        digito2 = 0;
      }
      else{
        digito2 = 11 - digito2;
      }
      if((cpf[10]-48) != digito2){ ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        return 0;
      } 
    }
  }
    return 1;
}

void le_cpf(char *cpf){

  int confirm;
  
  do{
    fgets(cpf,12,stdin);
    limpar_buffer();
    confirm = validarCPF(cpf);

    if (confirm == 0){
      printf("\tInvalido, Digite novamente(Apenas Numeros!): ");
    }
  }while(confirm != 1);
}

void limpar_buffer() { // Funcao criada por Matheus Diniz Fernandes / @Matheusdnf - detem todos os creditos.
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
    }
}

int s_ou_n(char* op){

  if ((strlen(op) == 1) && (*op == 's' || *op == 'n')) {
    return 1; // O caractere é válido ('s' ou 'n')
  }
  else{
    return 0;
  }
}