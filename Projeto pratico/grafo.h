#pragma once
#include <stdio.h>

typedef struct reg
{
    int valor;
    struct reg* seguinte;
} *Pilha;

typedef struct registo
{
    int id; // id de um v�rtice adjacente
    float peso; // peso da aresta permitindo transitar para o v�rtice adjacente
    struct registo* seguinte;
} Lista, * Adjacentes;

int inserirAresta(Adjacentes Grafo[], int v1, int v2, float p);
void inicializarGrafo(Adjacentes Grafo[]);
void listar(Adjacentes Grafo[]);