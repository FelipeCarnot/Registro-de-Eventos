/*
 * ALUNO: Felipe Nicolai Carnot Bastos
 * MATRÍCULA: 2025 0364 1323
 * DISCIPLINA: Programação de Software básico em C
 * TRABALHO: Registro de Eventos
 */

#include <stdio.h>
#include "funcoes_principais.h"   // registrar_evento, listar_eventos e ARQUIVO_LOG
#include "funcoes_utilitarias.h"  // limpar_tela e ler_linha


// Tela de cadastro: lê a descrição e pede para registrar no log.
static void tela_registrar(void) {
  char descricao[200]; // Buffer que recebe o texto digitado (até 199 caracteres)

  printf("--- Registrar evento ---\n");
  printf("Descreva o evento: ");

  // ler_linha retorna 0 em sucesso e -1 em erro de leitura
  if (ler_linha(descricao, sizeof(descricao)) != 0) {
    printf("[ERRO] Falha ao ler a descrição.\n");
    return; // Sai da função sem tentar gravar
  }

  // Se o usuário só apertou Enter, a string fica vazia (primeiro caractere é '\0')
  if (descricao[0] == '\0') {
    printf("[ERRO] A descrição não pode ser vazia.\n");
    return;
  }

  // registrar_evento abre o log em modo "a", grava data/hora + descrição e fecha.
  // Retorna 0 em sucesso e -1 em erro.
  if (registrar_evento(descricao) != 0) {
    printf("[ERRO] O evento não foi registrado.\n");
    return;
  }

  // Só chega aqui se todas as etapas acima deram certo
  printf("Evento registrado com sucesso!\n");
}

// Tela de consulta: mostra tudo o que já foi registrado.
static void tela_listar(void) {
  printf("--- Eventos registrados ---\n");

  // listar_eventos imprime o conteúdo do log; retorna -1 se houver erro de leitura
  if (listar_eventos() != 0) {
    printf("[ERRO] Não foi possível exibir o histórico.\n");
  }
}

int main(void) {
  char entrada[10];    // Guarda a opção digitada no menu
  int executando = 1;  // Controle do loop: 1 = continua, 0 = encerra

  while (executando) {
    limpar_tela();
    printf("========== REGISTRO DE EVENTOS ==========\n");
    printf("Digite 1 | Registrar novo evento\n");
    printf("Digite 2 | Ver eventos registrados\n");
    printf("Digite 0 | Sair\n");
    printf("Escolha: ");

    // Lê a opção como texto (mais seguro que scanf, não deixa lixo no buffer)
    if (ler_linha(entrada, sizeof(entrada)) != 0) {
      break; // EOF ou erro de leitura: encerra o programa
    }

    limpar_tela();

    // Usa só o primeiro caractere digitado para decidir a opção
    switch (entrada[0]) {
      case '1':
        tela_registrar();
        pausar(); // Evita que a mensagem suma quando o menu limpar a tela
        break;
      case '2':
        tela_listar();
        pausar();
        break;
      case '0':
        executando = 0; // Faz o while terminar na próxima verificação
        printf("Até mais!\n");
        break;
      default: // Qualquer outra tecla
        printf("[ERRO] Opção inválida!\n");
        pausar();
    }
  }

  return 0; // 0 = programa terminou sem erro
}
