#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

int main() {
    No *inicio = NULL;
    No *fim = NULL;
    No *novo;
    No *atual;

    novo = (No *)malloc(sizeof(No));

    novo->valor = 10;
    novo->anterior = NULL;
    novo->proximo = NULL;

    inicio = novo;
    fim = novo;

    novo = (No *)malloc(sizeof(No));

    novo->valor = 20;
    novo->anterior = fim;
    novo->proximo = NULL;

    fim->proximo = novo;
    fim = novo;

    novo = (No *)malloc(sizeof(No));

    novo->valor = 30;
    novo->anterior = fim;
    novo->proximo = NULL;

    fim->proximo = novo;
    fim = novo;

    atual = inicio;

    printf("Lista do inicio para o fim:\n");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");

    atual = fim;

    printf("Lista do fim para o inicio:\n");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }

    printf("\n");

    atual = inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}