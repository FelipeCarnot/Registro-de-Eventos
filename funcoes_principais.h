/*
 * ALUNO: Felipe Nicolai Carnot Bastos
 * MATRÍCULA: 2025 0364 1323
 * DISCIPLINA: Programação de Software básico em C
 * TRABALHO: Registro de Eventos
 */

#ifndef FUNCOES_PRINCIPAIS_H
#define FUNCOES_PRINCIPAIS_H

#define ARQUIVO_LOG "log.txt"

// Retorna 0 em sucesso e -1 em erro
int registrar_evento(const char *descricao);

// Mostra todos os eventos do log. Retorna 0 em sucesso e -1 em erro
int listar_eventos(void);

#endif
