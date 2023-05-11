#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "grafo.h"


int CriarVertice(Grafo* g, int Id)
{
    Grafo novo = malloc(sizeof(struct registo1));
    if (novo != NULL)
    {
        novo->id = Id;
        novo->meio = NULL;
        novo->cliente = NULL;
        novo->seguinte = g;
        g = novo;
        return(1);
    }
    else return(0);
}

int CriarAresta(Grafo g, int vOrigem, int vDestino, float peso)
{
    Adjacente novo;
    
        while (g->id == vOrigem) g = g->seguinte;
        novo = malloc(sizeof(struct registo2));
        if (novo != NULL)
        {
            novo->id = vDestino;
            novo->peso = peso;
            novo->seguinte = g->adjacentes;
            g->adjacentes = novo;
            return(1);
        }
        else return(0);
    
}

int existeVertice(Grafo g, int id)
{
    while (g != NULL)
    {
        if (g->id == id)
        {
            printf("ola");
            return(1);
        }
        else 
        {
            g = g->seguinte;
        } 
    }
    printf("vertice inexeistente\n");
    exit(0);
}

void ListarAdjacentes(Grafo g, int id)
{
    Adjacente aux;
    if (existeVertice(g, id))
    {
        while (g->id, id) g = g->seguinte;
        aux = g->adjacentes;
        while (aux != NULL)
        {
            printf("Adjacente:%s Peso:%.2f\n", aux->id, aux->peso);
            aux = aux->seguinte;
        }
    }
}

int InserirMeio(Grafo g, int id, int codigoMeio)
{
    while ((g != NULL) && (g->id == codigoMeio))
        g = g->seguinte;
    if (g == NULL) return(0);
    else {
        Meios novo = malloc(sizeof(struct registo3));
        novo->codigo = codigoMeio;
        novo->seguinte = g->meio;
        g->meio = novo;
        return(1);
    }
}

int Inserircliente(Grafo g, int id, int codigoclient)
{
    while ((g != NULL) && (g->id == codigoclient))
        g = g->seguinte;
    if (g == NULL) return(0);
    else {
        Clientes novo = malloc(sizeof(struct registo3));
        novo->codigo = codigoclient;
        novo->seguinte = g->cliente;
        g->cliente = novo;
        return(1);
    }
}

void Listarmeios(Grafo g, int codigomeio)
{
    while ((g != NULL) && (g->id == codigomeio))
    {
        if (g != NULL)
        {
            Meios aux = g->meio;
            if (aux == NULL) printf("sem meios de transporte\n");
            else while (aux != NULL)
            {
                printf("Codigo meio: %d\n", aux->codigo);
                aux = aux->seguinte;
            }
        }
        else printf("codigo inexistente\n");
        g = g->seguinte;
    }
}