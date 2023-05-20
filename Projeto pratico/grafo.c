#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "grafo.h"
#include "meio.h"


char geocodigoV(char location[], int l)
{
    
    if (l == 1)
    {
        strcpy(location, "chique.indice.pessoa");
        return(location);
    }
    else if (l == 2)
    {
        strcpy(location, "cheio.questionario.avos");
        return(location);
    }
    else if (l == 3)
    {
        strcpy(location, "ficou.abra.rindo");
        return(location);
    }
    else if (l == 4)
    {
        strcpy(location, "param.alfaces.louro");
        return(location);
    }
    else if (l == 5)
    {
        strcpy(location, "piou.penhor.bagre");
        return(location);
    }
    else if (l == 6)
    {
        strcpy(location, "boate.tirem.direta");
        return(location);
    }
    else if (l == 7)
    {
        strcpy(location, "selecionados.notou.taba");
        return(location);
    }
    else if (l == 8)
    {
        strcpy(location, "minima.fofoca.cabana");
        return(location);
    }
    else if (l == 9)
    {
        strcpy(location, "pudins.povo.baleias");
        return(location);
    }
    else
    {
        printf("Insira uma opcao valida!!");
        exit(0);
    }
}

int CriarVertice(Grafo* g, int Id, char geo[])
{
    Grafo novo = malloc(sizeof(struct registo1));
    if (novo != NULL)
    {
        novo->id = Id;
        strcpy(novo->geo, geo);
        novo->meio = NULL;
        novo->cliente = NULL;
        novo->adjacentes = NULL;
        novo->seguinte = *g;
        *g = novo;
        return(1);
    }
    else return(0);
}

int CriarAresta(Grafo g, int vOrigem, int vDestino, int peso)
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
        printf("Adjacente: %d Peso: %d\n", aux->id, aux->peso);
        aux = aux->seguinte;
    }
}

int InserirMeio(Grafo g,Mobilidade* inicio, int id, int codigoMeio)
{
    Mobilidade* meio = inicio;
    while (g != NULL)
    { 
        if (g->id == id)
        {
            while (meio != NULL)
            {
                if (meio->id == codigoMeio)
                {
                    if (strcmp(g->geo, meio->localizacao) == 0)
                    {
                        Meios novo = malloc(sizeof(struct registo3));
                        novo->codigo = codigoMeio;
                        novo->seguinte = g->meio;
                        g->meio = novo;
                        return(1);
                    }
                    else
                    {
                        printf("O geocodigo do veiculo nao e o msm do verice!\n");
                        return(0);
                    }
                }
                else
                {
                    meio = meio->seguinte;
                }
            }
        }
        else
        {
            g = g->seguinte;
        }
    }
}

int InserirCliente(Grafo g, int id, int codigoClient)
{
    while (g != NULL)
    {
        if (g->id == id)
        {
            Clientes novo = malloc(sizeof(struct registo3));
            novo->codigo = codigoClient;
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
                    printf("Codigo meio: %d\n", aux->codigo);
                    aux = aux->seguinte;
                }
            }
        }
        else
        {
            g = g->seguinte;
        }
        g = g->seguinte;
    }
}

void ListarClientes(Grafo g, int id)
{
    while (g != NULL)
    {
        if (g->id == id)
        {
            Clientes aux = g->meio;
            if (aux == NULL)
            {
                printf("sem meios de transporte\n");
            }
            else
            {
                while (aux != NULL)
                {
                    printf("Codigo meio: %d\n", aux->codigo);
                    aux = aux->seguinte;
                }
            }
        }
        else
        {
            g = g->seguinte;
        }
        g = g->seguinte;
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
                fprintf(fp,"%d;%s;%d;%d\n",g->id,g->geo,id,peso);
            }
            else
            {
                while (adj != NULL)
                {
                    fprintf(fp, "%d;%s;%d;%d\n", g->id, g->geo, adj->id, adj->peso);
                    adj = adj->seguinte;

                }
            }
            g = g->seguinte;
        }
        fclose(fp);
    }
    else
    {
        printf("O ficheiro esta corrompido!\n");
    }
}

Grafo* LerGrafo() 
{
    Grafo* g = NULL;
    FILE* fp;

    fp = fopen("GrafoA.txt", "r");

    int id1 = 0, id2 = 0, peso = 0;
    char geo[50];
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d;%[^;]%d;%d\n", &id1, &geo, &id2, &peso);
            if (id2 == 0 && peso ==0)
            {
                CriarVertice(&g, id1,geo);
            }
            else
            {
                CriarVertice(&g, id1,geo);
                CriarVertice(&g, id2,geo);
                CriarAresta(g, id1, id2, peso);
            }
        }
        fclose(fp);
        return(g);
    }
    else
    {
        printf("O ficheiro esta corrompido!");
    }
    
}