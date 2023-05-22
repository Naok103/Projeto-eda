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
	int peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo1
{
	int id;
	char geo[50];
	Adjacente adjacentes;
	Meios meio; 
	Clientes cliente;
	struct registo1* seguinte;
} *Grafo;

int CriarVertice(Grafo* g, int Id, char geo[]);
int CriarAresta(Grafo g, int vOrigem, int vDestino, int peso);
int InserirMeio(Grafo g, Mobilidade* inicio, int id, int codigoMeio);
int InserirCliente(Grafo g,Cliente* inicio, int id, int codigoclient);
void ListarMeios(Grafo g, int id);
void ListarClientes(Grafo g, int id);
void ListarAdjacentes(Grafo g, int id);
void GravarGrafoA(Grafo g);
int existeVertice(Grafo g, int id);
int existeVerticeaux(Grafo g, int id);
Grafo LerGrafoA(Grafo g);
char geocodigoV(char location[], int l);
void Dijkstra(Grafo g, int origem, int peso);
void GravarGrafoV(Grafo g);
Grafo LerGrafoV(Grafo g, Mobilidade* inicio, Cliente* c);






