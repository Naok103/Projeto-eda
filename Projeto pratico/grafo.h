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

//! @brief 
typedef struct registo2
{
	int id; 
	int peso;
	int origem;
	char localizaçao[50];
	struct registo2* seguinte;
} *Adjacente;

//! @brief struct para os vertices do grafo
typedef struct registo1
{
	int id;
	char geo[50];
	char localizaçao[50];
	Adjacente adjacentes;
	Meios meio; 
	Clientes cliente;
	struct registo1* seguinte;
} *Grafo;

int CriarVertice(Grafo* g, int Id, char geo[],char local[]);
int CriarVertice2(Grafo* g, int Id, char geo[], char local[]);
int CriarAresta(Grafo g, int vOrigem, int vDestino, int peso,char local[]);
int CriarAresta2(Grafo g, int vOrigem, int vDestino, int peso, char local[]);
char geocodigoV(char location[], int l);
char geocodigoL(char loca[], int d);
int InserirMeio(Grafo g, Mobilidade* inicio, int id, int codigoMeio);
int InserirCliente(Grafo g,Cliente* inicio, int id, int codigoclient);
void ListarMeios(Grafo g, int id);
void ListarClientes(Grafo g, int id);
void ListarAdjacentes(Grafo g, int id);
int existeVertice(Grafo g, int id);
int existeVerticeaux(Grafo g, int id);
void GravarGrafoA(Grafo g);
Grafo LerGrafoA(Grafo g);
void GravarGrafoV(Grafo g);
Grafo LerGrafoV(Grafo g, Mobilidade* inicio, Cliente* c);
void GravarGrafoB(Grafo g);
Grafo LerGrafoB(Grafo g);
int numVertices(Grafo g);
char* Localizacao(Grafo g, int id);
void Meio(Mobilidade* meio, char loca[], char tipo[]);
int obterMenorDistancia(int distancias[], int visitado[], int Vertices);
void imprimirCaminho(Grafo g, int caminho[], int verticeAtual);
void imprimirCaminhoMaisCurto(Grafo g, int caminho[], int distancias[], int inicio, int fim);
void listarMeiosCaminho(Grafo g, Mobilidade* meio, int caminho[],int fim,int inicio, char tipo[]);
void listarMeiosCaminhoaux(Grafo g, Mobilidade* meio, int caminho[], int fim, char tipo[]);
void encontrarCaminhosLimite(Grafo g, Mobilidade* meio, int inicio, int limite, char tipo[]);
















