/*
 * ALUNO: Felipe Nicolai Carnot Bastos
 * MATRÍCULA: 2025 0364 1323
 * DISCIPLINA: Programação de Software básico em C
 * TRABALHO: Registro de Eventos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes_utilitarias.h"

// Limpa o terminal
void limpar_tela(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

// Descarta o que sobrou no buffer do teclado
void limpar_buffer(void) {
  int caractere_descartado;
  while ((caractere_descartado = getchar()) != '\n' && caractere_descartado != EOF);
}

// Escreve a data/hora atual no buffer recebido (formato dd/mm/aaaa hh:mm:ss)
void obter_data_hora(char *buffer, size_t tamanho) {
  time_t tempo_atual = time(NULL);
  struct tm *data_hora = localtime(&tempo_atual);

  if (data_hora == NULL || strftime(buffer, tamanho, "%d/%m/%Y %H:%M:%S", data_hora) == 0) {
    buffer[0] = '\0'; // Em caso de falha, devolve string vazia
  }
}

// Lê uma linha inteira do console com fgets e remove o '\n'.
// Retorna 0 em sucesso e -1 em erro de leitura.
int ler_linha(char *buffer, size_t tamanho) {
  if (fgets(buffer, (int)tamanho, stdin) == NULL) {
    return -1;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';   // Remove o Enter
  } else {
    limpar_buffer();          // Linha maior que o buffer: descarta o excesso
  }
  return 0;
}

// Espera o usuário apertar Enter, para dar tempo de ler a tela antes de ela ser limpa de novo.
// 'static' = a função só existe dentro deste arquivo (main.c).
void pausar(void) {
  char descarte[10]; // Guarda o que o usuário digitar; o conteúdo é ignorado
  printf("\nPressione Enter para continuar...");
  ler_linha(descarte, sizeof(descarte)); // Bloqueia até o Enter
}


