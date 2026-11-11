/*
 * ALUNO: Felipe Nicolai Carnot Bastos
 * MATRÍCULA: 2025 0364 1323
 * DISCIPLINA: Programação de Software básico em C
 * TRABALHO: Registro de Eventos
 */

#include <stdio.h>
#include <errno.h>
#include "funcoes_principais.h"
#include "funcoes_utilitarias.h"

int registrar_evento(const char *descricao) {
  char data_hora[30];
  obter_data_hora(data_hora, sizeof(data_hora));

  FILE *arquivo = fopen(ARQUIVO_LOG, "a"); // "a" = append, preserva o histórico
  if (arquivo == NULL) {
    perror("[ERRO] Não foi possível abrir o arquivo de log");
    return -1;
  }

  if (fprintf(arquivo, "[%s] %s\n", data_hora, descricao) < 0) {
    perror("[ERRO] Falha ao gravar no arquivo de log");
    fclose(arquivo);
    return -1;
  }

  if (fclose(arquivo) != 0) {
    perror("[ERRO] Falha ao fechar o arquivo de log");
    return -1;
  }

  return 0;
}

int listar_eventos(void) {
  FILE *arquivo = fopen(ARQUIVO_LOG, "r"); // "r" = somente leitura
  if (arquivo == NULL) {
    if (errno == ENOENT) { // Arquivo ainda não existe: nada foi registrado
      printf("Nenhum evento registrado ainda.\n");
      return 0;
    }
    perror("[ERRO] Não foi possível abrir o arquivo de log");
    return -1;
  }

  char linha[300];
  int total = 0;

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    printf("%s", linha); // A linha já traz o '\n' gravado
    total++;
  }

  if (ferror(arquivo)) {
    perror("[ERRO] Falha ao ler o arquivo de log");
    fclose(arquivo);
    return -1;
  }

  fclose(arquivo);

  if (total == 0) {
    printf("O log está vazio.\n");
  }
  return 0;
}
