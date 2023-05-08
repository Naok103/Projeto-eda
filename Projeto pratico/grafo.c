#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "grafo.h"

#define VERTICES 10

// Inser��o de uma aresta no grafo 'Grafo' com origem em v1 e 
// destino em v2 e peso p
// Devolve 1 em caso de sucesso ou 0 caso caso contr�rio
int InserirAresta(Adjacentes Grafo[], int v1, int v2, float p)
{
    Adjacentes novo;
    if ((v1 >= 0) && (v1 < VERTICES) && (v2 >= 0) && (v2 < VERTICES) && (p >= 0))
    {
        novo = (Adjacentes)malloc(sizeof(struct registo));
        novo->id = v2;
        novo->peso = p;
        novo->seguinte = Grafo[v1];
        Grafo[v1] = novo;
        return(1);
    }
    else return(0);
}

void InicializarGrafo(Adjacentes Grafo[])
{
    int i;
    for (i = 0;i < VERTICES;i++) Grafo[i] = NULL;
}

void Listargrafo(Adjacentes Grafo[])
{
    int i;
    Adjacentes aux;
    for (i = 0;i < VERTICES;i++)
    {
        printf("Vertice %d: ", i);
        aux = Grafo[i];
        while (aux != NULL)
        {
            printf("%d(%.2f) ", aux->id, aux->peso);
            aux = aux->seguinte;
        }
        printf("\n");
    }
}

int InserirMeio(Adjacentes g, int vertice, int codigoMeio)
{
    while ((g != NULL) && (g->id == codigoMeio))
        g = g->seguinte;
    if (g == NULL) return(0);
    else {
        CM novo = malloc(sizeof(struct registo3));
        novo->codigo = codigoMeio;
        novo->seguinte = g->meio;
        g->meio = novo;
        return(1);
    }
}

int InserirCliente(Adjacentes g, int vertice, int codigoclient)
{
    while ((g != NULL) && (g->id == codigoclient))
        g = g->seguinte;
    if (g == NULL) return(0);
    else {
        CM novo = malloc(sizeof(struct registo3));
        novo->codigo = codigoclient;
        novo->seguinte = g->meio;
        g->meio = novo;
        return(1);
    }
}