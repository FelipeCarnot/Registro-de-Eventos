/*
 * ALUNO: Felipe Nicolai Carnot Bastos
 * MATRÍCULA: 2025 0364 1323
 * DISCIPLINA: Programação de Software básico em C
 * TRABALHO: Registro de Eventos
 */

#ifndef FUNCOES_UTILITARIAS_H
#define FUNCOES_UTILITARIAS_H

#include <stddef.h>

void limpar_tela(void);
void limpar_buffer(void);
void obter_data_hora(char *buffer, size_t tamanho);
int ler_linha(char *buffer, size_t tamanho);
void pausar(void);

#endif
