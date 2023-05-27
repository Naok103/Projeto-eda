#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "grafo.h"
#include "meio.h"
#define INFINITO 999999


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

char geocodigoL(char location[], int l)
{
    if (l == 1)
    {
        strcpy(location, "Rua do Raio");
        return(location);
    }
    else if (l == 2)
    {
        strcpy(location, "Rua do Souto");
        return(location);
    }
    else if (l == 3)
    {
        strcpy(location, "Avenida Central");
        return(location);
    }
    else if (l == 4)
    {
        strcpy(location, "Avenida da Liberdade");
        return(location);
    }
    else if (l == 5)
    {
        strcpy(location, "Rua 25 de Abril");
        return(location);
    }
    else if (l == 6)
    {
        strcpy(location, "Rua dos Chaos");
        return(location);
    }
    else if (l == 7)
    {
        strcpy(location, "Rua do Carmo");
        return(location);
    }
    else if (l == 8)
    {
        strcpy(location, "Rua Santa Margarida");
        return(location);
    }
    else if (l == 9)
    {
        strcpy(location, "Avenida 31 de Janeiro");
        return(location);
    }
    else
    {
        printf("Insira uma opcao valida!!");
        exit(0);
    }
}

int CriarVertice(Grafo* g, int Id, char geo[],char local[])
{
    Grafo novo = malloc(sizeof(struct registo1));
    geocodigoV(geo, Id);
    geocodigoL(local, Id);
    if (novo != NULL)
    {
        novo->id = Id;
        strcpy(novo->geo, geo);
        strcpy(novo->localizaçao, local);
        novo->meio = NULL;
        novo->cliente = NULL;
        novo->adjacentes = NULL;
        novo->seguinte = *g;
        *g = novo;
        return(1);
    }
    else return(0);
}

int CriarAresta(Grafo g, int vOrigem, int vDestino, int peso, char local[])
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
                    geocodigoL(local, vDestino);
                    novo->id = vDestino;
                    novo->peso = peso;
                    strcpy(novo->localizaçao, local);
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
                    if (strcmp(g->geo, meio->geocodigo) == 0)
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
                fprintf(fp, "%d;%d;%d\n", g->id, id, peso);
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

    int id1, id2, peso;
    char geo[50], local[50];
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d;%d;%d\n", &id1, &id2, &peso);
            
            if (id2 == 0 && peso == 0)
            {
                CriarVertice(&g, id1, geo, local);
            }
            else
            {
                if (existeVerticeaux(g, id1) == 2)
                {
                    if (existeVerticeaux(g, id2) == 2)
                    {
                        CriarAresta(g, id1, id2, peso, local);
                    }
                    else
                    {
                        CriarVertice(&g, id2, geo, local);
                        CriarAresta(g, id1, id2, peso, local);
                    }
                }
                else
                {
                    if (existeVerticeaux(g, id2) == 2)
                    {
                        CriarVertice(&g, id1, geo, local);
                        CriarAresta(g, id1, id2, peso, local);
                    }
                    else
                    {
                        CriarVertice(&g, id1, geo, local);
                        CriarVertice(&g, id2, geo, local);
                        CriarAresta(g, id1, id2, peso, local);
                    }
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

int numVertices(Grafo g)
{
    int count = 0;
    while (g != NULL)
    {
        if (g->id != NULL)
        {
            count++;
            g = g->seguinte;
        }
    }
    return(count);
}

char* Localizacao(Grafo g, int id)
{
    char* loca = malloc(50 * sizeof(char));
    while (g != NULL)
    {
        if (g->id == id)
        {
            strcpy(loca, g->localizaçao);
            return(loca);
        }
        else
        {
            g = g->seguinte;
        }
    }
    return NULL;
}

void Meio(Mobilidade* meio, char loca[], char tipo[])
{
    int encontrado = 0;

    while (meio != NULL)
    {
        if (strcmp(meio->local, loca) == 0 && strcmp(meio->meio, tipo) == 0)
        {
            printf("-------------------------------------------------------------------------------------------------------------------\n");
            printf("CODIGO %d\nBATERIA %.2f \nLOCALIZACAO %s\nCUSTO P/MIN %.2f\nTIPO %s\n", meio->id, meio->bat, meio->local, meio->custo, meio->meio);
            printf("-------------------------------------------------------------------------------------------------------------------\n");
            encontrado = 1;
        }
        meio = meio->seguinte;
    }

    if (!encontrado)
    {
        printf("Localizacao dentro do raio pretendido, porem, nao existe nenhum/a %s em %s\n", tipo, loca);
        printf("-------------------------------------------------------------------------------------------------------------------\n");
    }
}

int obterMenorDistancia(int distancias[], int visitado[], int Vertices)
{
    int min = INFINITO;
    int indiceMin = -1;
    for (int i = 0; i < Vertices; i++)
    {
        if (visitado[i] == 0 && distancias[i] <= min)
        {
            min = distancias[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}

void imprimirCaminho(Grafo g, int caminho[], int verticeAtual)
{
    char* locaAtual = Localizacao(g, verticeAtual);
    if (caminho[verticeAtual] == -1)
    {
        printf("%d(%s) -> ", verticeAtual, locaAtual);
        return;
    }
    imprimirCaminho(g, caminho, caminho[verticeAtual]);
    printf("%d(%s) -> ", verticeAtual, locaAtual);
}

void imprimirCaminhoMaisCurto(Grafo g, int caminho[], int distancias[], int inicio, int fim)
{
    char* verticeInicio = Localizacao(g, inicio);
    char* verticeFim = Localizacao(g, fim);
    printf("Caminho mais curto entre %d(%s) e %d(%s):\n ", inicio, verticeInicio, fim, verticeFim);
    imprimirCaminho(g, caminho, fim);
    printf("\nDistancia total: %d METROS\n", distancias[fim]);
}
/*
void encontrarCaminhoMaisCurto(Grafo g, Mobilidade* meio, int vertices, int inicio, int fim, int limite, char tipo[])
{

    int distancias[9];
    int visitado[9];
    int caminho[9];

    if ((existeVerticeaux(g, inicio) == 1) || (existeVerticeaux(g, fim) == 1))
    {
        printf("Vertice nao encontrado\n");
    }
    for (int i = 0; i < vertices; i++)
    {
        distancias[i] = INFINITO;
        visitado[i] = 0;
        caminho[i] = -1;
    }
    distancias[inicio] = 0;
    for (int i = 0; i < vertices - 1; i++)
    {
        int verticeAtual = obterMenorDistancia(distancias, visitado, vertices);
        visitado[verticeAtual] = 1;
        Grafo braga = g;
        while (braga != NULL)
        {
            if (braga->id == verticeAtual)
            {
                Adjacente adj = braga->adjacentes;
                while (adj != NULL)
                {
                    int verticeAdjacente = adj->id;
                    int pesoAresta = adj->peso;
                    if (!visitado[verticeAdjacente] && distancias[verticeAtual] != INFINITO &&
                        distancias[verticeAtual] + pesoAresta < distancias[verticeAdjacente])
                    {
                        distancias[verticeAdjacente] = distancias[verticeAtual] + pesoAresta;
                        caminho[verticeAdjacente] = verticeAtual;
                    }
                    adj = adj->seguinte;
                }
                break;
            }
            braga = braga->seguinte;
        }
    }
    if (distancias[fim] <= limite)
    {
        imprimirCaminhoMaisCurto(g, caminho, distancias, inicio, fim);
        char* eu = Localizacao(g, fim);
        Meio(meio, eu, tipo);
    }
}
*/

void encontrarCaminhoMaisCurto2(Grafo g, Mobilidade** meio, int inicio, int fim, int limite, char tipo[])
{
    int v = numVertices(g);
    int* distancias = malloc(v * sizeof(int));
    int* visitado = malloc(v * sizeof(int));
    int* caminho = malloc(v * sizeof(int));

    if ((existeVerticeaux(g, inicio) == 1) || (existeVerticeaux(g, fim) == 1))
    {
        printf("Vertice nao encontrado\n");
    }
    for (int i = 0; i < v; i++)
    {
        distancias[i] = INFINITO;
        visitado[i] = 0;
        caminho[i] = -1;
    }
    distancias[inicio] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int verticeAtual = obterMenorDistancia(distancias, visitado, v);
        visitado[verticeAtual] = 1;
        Grafo braga = g;
        while (braga != NULL)
        {
            if (braga->id == verticeAtual)
            {
                Adjacente adj = braga->adjacentes;
                while (adj != NULL)
                {
                    int verticeAdjacente = adj->id;
                    int pesoAresta = adj->peso;
                    if (!visitado[verticeAdjacente] && distancias[verticeAtual] != INFINITO &&
                        distancias[verticeAtual] + pesoAresta < distancias[verticeAdjacente])
                    {
                        distancias[verticeAdjacente] = distancias[verticeAtual] + pesoAresta;
                        caminho[verticeAdjacente] = verticeAtual;
                    }
                    adj = adj->seguinte;
                }
                break;
            }
            braga = braga->seguinte;
        }
    }
    if (distancias[fim] <= limite)
    {
        imprimirCaminhoMaisCurto(g, caminho, distancias, inicio, fim);
        char* eu = Localizacao(g, fim);
        Meio(meio, eu, tipo);
    }

    free(distancias);
    free(visitado);
    free(caminho);
}
