#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "grafo.h"
#include "meio.h"
#define INFINITO 999999

//! @brief Funcao para inserir o geocodigo na variavel location
//! @param location variavel para o geocodigo
//! @param l variavel para o id do vertice
//! @return retorna a variavel location com o geocodigo
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

//! @brief Funcao para inserir o local na variavel location
//! @param location variavel para o local
//! @param l variavel para o id do vertice
//! @return retorna a variavel location com o local
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

//! @brief Funcao para inserir um vertice no grafo
//! @param g variavel a com apontador a apontador para o inicio do grafo
//! @param Id variavel para o id do vertice
//! @param geo variavel para o geocodigo do vertice
//! @param local variavel para o nome local do vertice
//! @return retorna o grafo atualizado com um novo vertice
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

//! @brief Funcao para inserir um vertice no grafo
//! @param g variavel a com apontador a apontador para o inicio do grafo
//! @param Id variavel para o id do vertice
//! @param geo variavel para o geocodigo do vertice
//! @param local variavel para o nome do local do vertice
//! @return retorna o grafo atualizado com um novo vertice
int CriarVertice2(Grafo* g, int Id, char geo[], char local[])
{
    Grafo novo = malloc(sizeof(struct registo1));
    
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

//! @brief Funcao para inserir uma aresta no grafo
//! @param g variavel para aceder ao grafo 
//! @param vOrigem variavel para o id do vertice inicial
//! @param vDestino variavel para o id do vertice final
//! @param peso variavel para o peso da aresta
//! @param local variavel para o nome do local do vertice final
//! @return retorna o grafo atualizado com uma nova aresta
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
                    novo->origem = vOrigem;
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

//! @brief Funcao para inserir uma aresta no grafo
//! @param g variavel para aceder ao grafo 
//! @param vOrigem variavel para o id do vertice inicial
//! @param vDestino variavel para o id do vertice final
//! @param peso variavel para o peso da aresta
//! @param local variavel para o nome do local do vertice final
//! @return retorna o grafo atualizado com uma nova aresta
int CriarAresta2(Grafo g, int vOrigem, int vDestino, int peso, char local[])
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
                    novo->origem = vOrigem;
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

//! @brief Funcao para verificar se um vertice ja existe no grafo
//! @param g variavel para aceder ao grafo
//! @param id variavel para o id do vertice
//! @return retorna 1 se o vertice ja existir ou 0 se nao existir
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

//! @brief Funcao para verificar se um vertice ja existe no grafo
//! @param g variavel para aceder ao grafo
//! @param id variavel para o id do vertice
//! @return retorna 2 se o vertice ja existir ou 1 se nao existir
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

//! @brief Funcao para listar os adjacentes de um vertice 
//! @param g variavel para aceder ao grafo
//! @param id variavel para o id do vertice
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

//! @brief Funcao para inserir um meio de mobilidade num determinado vertice
//! @param g variavel para aceder ao grafo
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id variavel para o id do vertice
//! @param codigoMeio variavel para o id do meio de mobilidade
//! @return retorna 1 se o meio for inserido no vertice ou 0 se nao for
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

//! @brief Funcao para inserir um cliente de mobilidade num determinado vertice
//! @param g variavel para aceder ao grafo
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente 
//! @param id variavel para o id do vertice
//! @param codigoClient variavel para o id do cliente
//! @return retorna 1 se o cliente for inserido no vertice ou 0 se nao for
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

//! @brief Funcao para listar os meios presentes num certo vertice 
//! @param g variavel para aceder ao grafo
//! @param id variavel para o id do vertice
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

//! @brief Funcao para listar os clintes presentes num certo vertice 
//! @param g variavel para aceder ao grafo
//! @param id variavel para o id do vertice
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

//! @brief Funcao para gravar os vertices e arestas do grafo num ficheiro de texto
//! @param g variavel para aceder ao grafo
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
                    fprintf(fp, "%d;%d;%d\n", adj->origem, adj->id, adj->peso);
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

//! @brief Funcao para ler a informacao do ficheiro de texto para o grafo 
//! @param g variavel para aceder ao grafo
//! @return retorna o grafo com as informaçoes do ficheiro de texto
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

//! @brief Funcao para gravar os meios e os clientespresentes num vertice do grafo num ficheiro de texto
//! @param g variavel para aceder ao grafo
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

//! @brief Funcao para ler a informacao do ficheiro de texto para o grafo
//! @param g variavel para aceder ao grafo
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param c apontador da variavel a apontar para o inicio da lista ligada Cliente 
//! @return retorna o grafo com as informaçoes do ficheiro de texto
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

//! @brief Funcao para guardar as informacoes do grafo no ficheiro binario
//! @param g variavel para aceder ao grafo
void GravarGrafoB(Grafo g)
{
    FILE* fp, * fr;
    fp = fopen("GrafoA.bin", "wb");
    fr = fopen("GrafoV.bin", "wb");

    if (fp != NULL)
    {
        while (g != NULL)
        {
            fwrite(g, sizeof(struct registo1), 1, fp);
            g = g->seguinte;
        }
        fclose(fp);
    }
    else
    {
        printf("O ficheiro esta corrompido!");
    }

    if (fr != NULL)
    {
        while (g != NULL)
        {
            Adjacente adj = g->meio;
            while (adj != NULL)
            {
                fwrite(adj, sizeof(struct registo2), 1, fr);
                adj = adj->seguinte;
            }
            g = g->seguinte;
        }
        fclose(fr);
    }
    else
    {
        printf("O ficheiro esta corrompido!");
    }
}

//! @brief Funcao para ler a informacao do ficheiro de texto para o grafo
//! @param g variavel para aceder ao grafo
//! @return retorna o grafo com as informaçoes do ficheiro binario
Grafo LerGrafoB(Grafo g)
{
    FILE* fp, * fr;

    Grafo novo;
    Adjacente adj;

    novo = (Grafo)malloc(sizeof(struct registo1));
    adj = (Adjacente)malloc(sizeof(struct registo2));

    fp = fopen("GrafoA.bin", "rb");
    fr = fopen("GrafoV.bin", "rb");

    if (fp != NULL)
    {
        while (fread(novo, sizeof(struct registo1), 1, fp) == 1)
        {
            if (novo != NULL)
            {
                CriarVertice2(&g, novo->id, novo->geo, novo->localizaçao);
            }
        }
        fclose(fp);
    }
    else
    {
        printf("O ficheiro esta corrompido!");
    }

    if (fr != NULL)
    {
        while (fread(adj, sizeof(struct registo2), 1, fr) == 1)
        {
            if (adj != NULL)
            {
                CriarAresta2(g, adj->origem, adj->id, adj->peso, adj->localizaçao);
            }
        }
        fclose(fr);
    }
    else
    {
        printf("O ficheiro esta corrompido!");
    }

    free(novo);
    free(adj);

}

//! @brief Funcao para contar o numero de vertices presentes no grafo
//! @param g variavel para aceder ao grafo 
//! @return retorna o numero de vertices no grafo
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

//! @brief Funcao para ir buscar a localizaçao de um certo vertice
//! @param g variavel para aceder ao grafo
//! @param id variavel para o id do vertice
//! @return retorna a localizaçao de um certo vertice
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

//! @brief Funcao para auxiliar para listar os meios presentes no caminho
//! @param g variavel para aceder ao grafo
//! @param meio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param caminho variavel para o caminho feito ate agora
//! @param verticeAtual variavel para o id do vertice atual
//! @param tipo variavel para o tipo de meio de mobilidade
void listarMeiosCaminhoaux(Grafo g, Mobilidade* meio, int caminho[], int verticeAtual, char tipo[]) 
{
    if (caminho[verticeAtual] == -1)
        return;

    listarMeiosCaminhoaux(g, meio, caminho, caminho[verticeAtual], tipo);

    char* loca = Localizacao(g, verticeAtual);
    Meio(meio, loca, tipo);
}

//! @brief Funcao para auxiliar para listar os meios presentes no caminho
//! @param g variavel para aceder ao grafo
//! @param meio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param caminho variavel para o caminho feito ate agora
//! @param verticeAtual variavel para o id do vertice atual
//! @param inicio variavel para o id do vertice inicial
//! @param tipo variavel para o tipo de meio de mobilidade
void listarMeiosCaminho(Grafo g, Mobilidade* meio, int caminho[], int verticeAtual,int inicio, char tipo[])
{
    char* local = Localizacao(g, inicio);
    Meio(meio, local, tipo);

    if (caminho[verticeAtual] == -1)
        return;

    listarMeiosCaminhoaux(g, meio, caminho, caminho[verticeAtual], tipo);

    char* loca = Localizacao(g, verticeAtual);
    Meio(meio, loca, tipo);
}

//! @brief Funcao para imprimir os meios presentes no caminho
//! @param meio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param loca variavel para o nome do local do vertice
//! @param tipo variavel para o tipo de meio de mobilidade
void Meio(Mobilidade* meio, char loca[], char tipo[])
{
    int encontrado = 0;

    while (meio != NULL)
    {
        if (strcmp(meio->local, loca) == 0 && strcmp(meio->meio, tipo) == 0)
        {
            printf("==============================================================================================\n");
            printf("codigo: %d\nbateria: %.2f \nautonomia: %.2f \nlocalizacao: %s\ncusto: %.2f\ntipo: %s\n", meio->id, meio->bat,meio->autonomia, meio->local, meio->custo, meio->meio);
            printf("==============================================================================================\n");
            encontrado = 1;
        }
        meio = meio->seguinte;
    }

    if (!encontrado)
    {
        printf("Localizacao dentro do raio pretendido, porem, nao existe nenhum/a %s em %s\n", tipo, loca);
        printf("=============================================================================================\n");
    }
}

//! @brief Funcao para obter a menor distancia entre 2 vertices
//! @param distancias variavel para as distancias do caminho
//! @param visitado variavel para verificar se um vertice ja foi visitado ou nao
//! @param Vertices variavel para o numero de vertices presentes no grafo
//! @return retorna o menor caminho entre 2 vertices
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

//! @brief Funcao auxiliar para imprimir o caminho entre 2 vertices
//! @param g variavel para aceder ao grafo
//! @param caminho variavel para o caminho feito ate agora
//! @param verticeAtual variavel para o id do vertice atual
void imprimirCaminho(Grafo g, int caminho[], int verticeAtual)
{
    char* locaAtual = Localizacao(g, verticeAtual);
    if (caminho[verticeAtual] == -1)
    {
        printf("%d (%s) -> ", verticeAtual, locaAtual);
        return;
    }
    imprimirCaminho(g, caminho, caminho[verticeAtual]);
    printf("%d (%s) -> ", verticeAtual, locaAtual);
}

//! @brief Funcao para imprimir o caminho mais curto entre 2 vertices
//! @param g variavel para aceder ao grafo
//! @param caminho variavel para o caminho feito ate agora
//! @param distancias variavel para as distancias do caminho
//! @param inicio variavel para o id do vertice inicial
//! @param fim variavel para o id do vertice final
void imprimirCaminhoMaisCurto(Grafo g, int caminho[], int distancias[], int inicio, int fim)
{
    char* verticeInicio = Localizacao(g, inicio);
    char* verticeFim = Localizacao(g, fim);
    if(strcmp(verticeFim,verticeInicio) == 0)
    {
        return;
    }
    else
    {
        printf("Caminho mais curto entre %d (%s) e %d (%s):\n ", inicio, verticeInicio, fim, verticeFim);
        imprimirCaminho(g, caminho, fim);
        printf("\nDistancia total: %d METROS\n", distancias[fim]);
    }
    
}

//! @brief Funcao para calcular o caminho mais apartir de um vertice incial ate aos seguintes vertices sem ultrapassar um limite de distancia
//! @param g variavel para aceder ao grafo
//! @param meio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param inicio variavel para o id do vertice inicial
//! @param limite variavel para o limite da distancia a percorrer
//! @param tipo variavel para o tipo de meio de mobilidade
void encontrarCaminhosLimite(Grafo g, Mobilidade* meio, int inicio, int limite, char tipo[])
{
    int v = numVertices(g);
    v = v + 1;
    int* distancias = malloc(v * sizeof(int));
    int* visitado = malloc(v * sizeof(int));
    int* caminho = malloc(v * sizeof(int));

    if (existeVerticeaux(g, inicio) == 1)
    {
        printf("Vertice nao encontrado\n");
        return;
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

    printf("Caminhos a partir do vertice %d dentro do limite de distancia %d:\n", inicio, limite);
    for (int i = 0; i < v; i++)
    {
        if (distancias[i] <= limite)
        {
            imprimirCaminhoMaisCurto(g, caminho, distancias, inicio, i);
            listarMeiosCaminhoaux(g, meio, caminho, i, tipo);
        }
    }

    free(distancias);
    free(visitado);
    free(caminho);
}

