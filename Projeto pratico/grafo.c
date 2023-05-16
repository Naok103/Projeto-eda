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
        novo->adjacentes = NULL;
        novo->seguinte = *g;
        *g = novo;
        return(1);
    }
    else return(0);
}

int CriarAresta(Grafo g, int vOrigem, int vDestino, float peso)
{
    Adjacente novo;
    if (existeVertice(g, vOrigem) && existeVertice(g, vDestino))
    {
        while (g != NULL)
        {
            if (g->id == vOrigem)
            {
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
            else
            {
                g = g->seguinte;
            }
        }

    }
    else return(0);
    
}

int existeVertice(Grafo g, int id)
{
    while (g != NULL)
    {
        if (g->id == id)
        {
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
    /*
    Adjacente aux;
    
    while (g != NULL)
    {
        if (g->id == id) 
        {
            aux = g->adjacentes;
            while (aux != NULL)
            {
                printf("Adjacente:%d Peso:%.2f\n", aux->id, aux->peso);
                aux = aux->seguinte;
            }
        }
        else
        {
            g = g->seguinte;
        }
        
    }
   */
    if (g == NULL) {
        printf("Grafo não inicializado.\n");
        return;
    }

    while (g != NULL && g->id != id)
    {
        g = g->seguinte;
    }

    if (g == NULL) {
        printf("Vertice nao encontrado.\n");
        return;
    }

    if (g->adjacentes == NULL) {
        printf("Sem adjacentes.\n");
        return;
    }

    Adjacente aux = g->adjacentes;
    while (aux != NULL)
    {
        printf("Adjacente: %d Peso: %.2f\n", aux->id, aux->peso);
        aux = aux->seguinte;
    }
}

int InserirMeio(Grafo g, int id, int codigoMeio)
{
    while (g != NULL)
    {
        if (g->id == id)
        {
            Meios novo = malloc(sizeof(struct registo3));
            novo->codigo = codigoMeio;
            novo->seguinte = g->meio;
            g->meio = novo;
            return(1);
        }
        else
        {
            g = g->seguinte;
        }
    }
}

int InserirCliente(Grafo g, int id, int codigoclient)
{
    while ((g != NULL) && (g->id == codigoclient))
        g = g->seguinte;
    if (g == NULL) return(0);
    else {
        Clientes novo = malloc(sizeof(struct registo4));
        novo->codigo = codigoclient;
        novo->seguinte = g->cliente;
        g->cliente = novo;
        return(1);
    }
}

void ListarMeios(Grafo g, int id)
{
    
    while (g != NULL)
    {
        if (g->id == id)
        {
            Meios aux = g->meio;
            if (aux == NULL)
            {
                printf("sem meios de transporte\n");
            }
            else
            {
                while (aux != NULL)
                {
                    if (aux == NULL)
                    {
                        return(0);
                    }
                    else
                    {
                        printf("Codigo meio: %d\n", aux->codigo);
                        aux = aux->seguinte;
                    }
                }
            }
        }
        else
        {
            g = g->seguinte;
        }
    }
}

void GravarGrafoA(Grafo g)
{
    Adjacente adj;
    FILE* fp;
   
    int id = 0, peso = 0;
    fp = fopen("GrafoA.txt", "w");
    

    if (fp != NULL)
    {
        while (g != NULL)
        {
            adj = g->adjacentes;
            if (adj == NULL)
            {
                fwrite(fp,"%d;%d;%.2f",g->id,id,peso);
            }
            else
            {
                while (adj != NULL)
                {
                    fwrite(fp, "%d;%d;%d", g->id, adj->id, adj->peso);
                    adj = adj->seguinte;

                }
            }
            g = g->seguinte;
        }
    }
    else
    {
        printf("O ficheiro esta corrompido!\n");
    }
}
