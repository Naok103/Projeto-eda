#pragma once
#include <stdio.h>

#include "cliente.h"
#include "meio.h"

typedef struct registo4
{
	int codigo;
	struct registo4* seguinte;
} *Clientes;

typedef struct registo3
{
	int codigo;
	struct registo3* seguinte;
} *Meios;

typedef struct registo2
{
	int id; 
	float peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo1
{
	int id; 
	Adjacente adjacentes;
	Meios meio; 
	Clientes cliente;
	struct registo1* seguinte;
} *Grafo;

int CriarVertice(Grafo* g, int Id);
int CriarAresta(Grafo g, int vOrigem, int vDestino, float peso);
int InserirMeio(Grafo g, int id, int codigoMeio);
int InserirCliente(Grafo g, int id, int codigoclient);
void ListarMeios(Grafo g, int id);
void ListarAdjacentes(Grafo g, int id);
void GravarGrafoA(Grafo g);
int existeVertice(Grafo g, int id);

