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
	char localizaçao[50];
	struct registo2* seguinte;
} *Adjacente;

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
int CriarAresta(Grafo g, int vOrigem, int vDestino, int peso,char local[]);
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
char geocodigoL(char loca[], int d);
void GravarGrafoV(Grafo g);
Grafo LerGrafoV(Grafo g, Mobilidade* inicio, Cliente* c);
int numVertices(Grafo g);
char* Localizacao(Grafo g, int id);
void Meio(Mobilidade* meio, char loca[], char tipo[]);
int obterMenorDistancia(int distancias[], int visitado[], int Vertices);
void imprimirCaminho(Grafo g, int caminho[], int verticeAtual);
void imprimirCaminhoMaisCurto(Grafo g, int caminho[], int distancias[], int inicio, int fim);
//void encontrarCaminhoMaisCurto(Grafo g, Mobilidade* teste15,int vertices, int inicio, int fim, int limite, char tipo[]);
void encontrarCaminhoMaisCurto2(Grafo g, Mobilidade** meio, int inicio, int fim, int limite, char tipo[]);
void listarMeiosCaminho(Grafo g, Mobilidade* meio, int caminho[],int fim,int inicio, char tipo[]);
void listarMeiosCaminhoaux(Grafo g, Mobilidade* meio, int caminho[], int fim, char tipo[]);
















