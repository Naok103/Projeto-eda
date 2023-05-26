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
    /*
    else if (l == 0)
    {
        printf("0");
    }
    */
    else
    {
        printf("Insira uma opcao valida!!");
        exit(0);
    }
}

int CriarVertice(Grafo* g, int Id, char geo[])
{
    Grafo novo = malloc(sizeof(struct registo1));
    geocodigoV(geo, Id);
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

int existeVerticeaux(Grafo g, int id)
{
    int i = 1;
    while (g != NULL)
    {
        if (g->id == id)
        {
            i = 2;
            return(i);
        }
        else
        {
            g = g->seguinte;
        }
    }
    return(i);
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
                        printf("O geocodigo do veiculo nao e o msm do vertice!\n");
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

int InserirCliente(Grafo g,Cliente* inicio, int id, int codigoClient)
{
    Cliente* cliente = inicio;
    while (g != NULL)
    {
        if (g->id == id)
        {
            while (cliente != NULL)
            {
                if (cliente->id == codigoClient)
                {
                    if (strcmp(g->geo, cliente->morada) == 0)
                    {
                        Clientes novo = malloc(sizeof(struct registo4));
                        novo->codigo = codigoClient;
                        novo->seguinte = g->cliente;
                        g->cliente = novo;
                        return(1);
                    }
                    else
                    {
                        printf("O geocodigo do cliente nao e o msm do vertice!\n");
                        return(0);
                    }
                }
                else
                {
                    cliente = cliente->seguinte;
                }
            }
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
                printf("sem clientes\n");
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
                fprintf(fp,"%d;%d;%d\n",g->id,id,peso);
            }
            else
            {
                while (adj != NULL)
                {
                    fprintf(fp, "%d;%d;%d\n", g->id, adj->id, adj->peso);
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

Grafo LerGrafoA(Grafo g)
{
    FILE* fp;
    fp = fopen("GrafoA.txt", "r");

    int id1 = 0, id2 = 0, peso = 0;
    char geo[50];
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d;%d;%d\n", &id1, &id2, &peso);
            if (id2 == 0 && peso == 0)
            {
                if (existeVerticeaux(g, id1) == 1)
                {
                    CriarVertice(&g, id1, geo);
                }
            }
            else
            {
                if (existeVerticeaux(g,id1) == 2)
                {
                    if (existeVerticeaux(g,id2) == 2)
                    {
                      
                        CriarAresta(g, id1, id2, peso);
                    }
                    else
                    {
                        CriarVertice(&g, id2, geo);
                        CriarAresta(g, id1, id2, peso);
                    }
                }
                else
                {
                    CriarVertice(&g, id1, geo);
                    CriarVertice(&g, id2, geo);
                    CriarAresta(g, id1, id2, peso);
                }
            }
        }
        fclose(fp);
        return(g);
    }
    else
    {
        printf("O ficheiro esta corrompido!\n");
    }
}

void GravarGrafoV(Grafo g)
{
    Meios meios;
    Clientes clientes;
    FILE* fp;

    int diff = 0;
    fp = fopen("GrafoV.txt", "w");


    if (fp != NULL)
    {
        while (g != NULL)
        {
            meios = g->meio;
            while (meios != NULL)
            {
                diff = 111;
                fprintf(fp, "%d;%d;%d\n", g->id, meios->codigo, diff);
                meios = meios->seguinte;
            }
            clientes = g->cliente;
            while (clientes != NULL)
            {
                diff = 112;
                fprintf(fp, "%d;%d;%d\n", g->id, clientes->codigo, diff);
                clientes = clientes->seguinte;
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

Grafo LerGrafoV(Grafo g, Mobilidade* inicio, Cliente* c)
{
    FILE* fp;
    Mobilidade* meio = inicio;
    Cliente* cliente = c;
    fp = fopen("GrafoV.txt", "r");

    int id1 = 0, id2 = 0, diff = 0;
    char geo[50];
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d;%d;%d\n", &id1, &id2, &diff);
            if (diff == 111)
            {
                InserirMeio(g, meio, id1, id2);
            }
            else if (diff == 112)
            {
                InserirCliente(g, cliente, id1, id2);
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

int Caminhocurto(Grafo g,Grafo b,int raio,int peso,int destino,int origem)
{
    int pesso;
    while (g != NULL)
    {
        if (g->id == origem)
        {
            Adjacente aux = g->adjacentes;
            while (aux != NULL)
            {
                if (aux->id != destino)
                {
                    while (b != NULL)
                    {
                        if(b->id = aux->id)
                        {
                            Adjacente aux2 = b->adjacentes;
                            while (aux2 != NULL)
                            {
                                if (aux2->id == destino) 
                                {
                                    pesso = aux->peso + aux2->peso;
                                    if(pesso < peso)
                                    {
                                        printf("caminho: %d -> %d -> %d\n", g->id,aux->id,aux2->id);
                                        printf("Distancia total : %d\n", pesso);
                                        return(2);
                                    }
                                    else
                                    {
                                        return(1);
                                    }
                                }
                                else
                                {
                                    aux2 = aux2->seguinte;
                                }
                            }
                        }
                        else
                        {
                            b = b->seguinte;
                        }
                    }
                }
                else
                {
                    aux = aux->seguinte;
                }
            }
        }
        else
        {
            g = g->seguinte;
        }
    }
}

void MeiosRaio(Grafo g,Grafo b, Mobilidade* inicio, int origem, int raio, char veiculo[])
{
    while (g != NULL)
    {
        if (g->id == origem)
        {
            Adjacente aux = g->adjacentes;
            while (aux != NULL)
            {
                if (aux->peso < raio)
                {
                    if (Caminhocurto(g, b, raio, aux->peso, aux->id, origem) == 1)
                    {
                        printf("Caminho: %d -> %d\n", origem, aux->id);
                        printf("Distancia total : %d\n", aux->peso);
                    }
                    
                }
                aux = aux->seguinte;
            }
        }
        else
        {
            g = g->seguinte;
        }
    }
}

