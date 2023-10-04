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
    printf("\n");
    confirm = valida_nome(nome);

    if (confirm == 0){
      printf("\tInvalido, Digite novamente: ");
    }
  }while(confirm != 1);
}