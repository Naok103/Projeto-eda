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
    Mobilidade *meio;
    Cliente *cliente;
    float peso; // peso da aresta permitindo transitar para o v�rtice adjacente
    struct registo* seguinte;
} Lista, * Adjacentes;

int InserirAresta(Adjacentes Grafo[], int v1, int v2, float p);
void InicializarGrafo(Adjacentes Grafo[]);
void Listargrafo(Adjacentes Grafo[]);