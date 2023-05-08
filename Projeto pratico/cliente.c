#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "cliente.h"



//! @brief Funcao para adicionar um novo cliente na lista ligada Cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente
//! @param id variavel com o id do cliente a inserir
//! @param name variavel com o nome do cliente a inserir
//! @param user variavel com o username do cliente a inserir
//! @param pass variavel com a palavra-pass do cliente a inserir
//! @param contacto variavel com o contacto do cliente a inserir
//! @param nif variavel com o nif do cliente a inserir
//! @param morada variavel com a morada do cliente a inserir
//! @param saldo variavel com o saldo do cliente a inserir
//! @return retorna a lista ligada Cliente atualizada com o novo cliente
Cliente* addclient(Cliente* inicio, int id, char name[], char user[], char pass[], int contacto, int nif, char morada[], float saldo)
{
	Cliente* new = malloc(sizeof(struct cliente));
	if (new != NULL)
	{
		new->id = id;
		strcpy(new->name, name);
		strcpy(new->user, user);
		strcpy(new->pass, pass);
		new->contacto = contacto;
		new->nif = nif;
		strcpy(new->morada, morada);
		new->saldo = saldo;
		new->seguinte = inicio;
		return(new);
	}
	else
	{
		return(inicio);
	}
}

//! @brief Funcao para mostrar as informacoes da lista ligada Cliente na consola
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente
void showclient(Cliente* inicio)
{
	while (inicio != NULL)
	{
		printf("ID: %d; Name: %s; User: %s; Pass: %s; Phonenumber: %d; NIF: %d; Adress: %s; Balance: %.2f\n", inicio->id, inicio->name, inicio->user, inicio->pass, inicio->contacto, inicio->nif, inicio->morada, inicio->saldo);
		inicio = inicio->seguinte;
	}
}


//! @brief Funcao para guardar as informacoes da lista ligada no ficheiro no ficheiro de texto
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente 
//! @return a funcao retorna 1 se as informacoes do ficheiro de texto forem guardadas com sucesso na lista ligada Cliente e 0 se nao
int saveclient(Cliente* inicio)
{
	FILE* fp;

	fp = fopen("Cliente.txt", "w");

	if (fp != NULL)
	{
		Cliente* ci = inicio;
		while (ci != NULL)
		{
			fprintf(fp, "%d;%s;%s;%s;%d;%d;%s;%f;%d\n", ci->id, ci->name, ci->user, ci->pass, ci->contacto, ci->nif, ci->morada, ci->saldo);
			ci = ci->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else
	{
		return(0);
	}
}

//! @brief Funcao para guardar as informacoes da lista ligada no ficheiro binario
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente 
void saveclientB(Cliente* inicio)
{
	FILE* fp;

	fp = fopen("client.bin", "wb");

	if (fp != NULL)
	{
		Cliente* aux = inicio;
		while(aux != NULL)
		{
			fwrite(aux, sizeof(Cliente), 1, fp);
			aux = aux->seguinte;
		}
		fclose(fp);
	}
}

//! @brief Funcao para ler a informacao do ficheiro do texto para a lista ligada Cliente
//! @return retorna a lista ligada Cliente com as informacoes do ficherio de texto
Cliente* readclient()
{
	FILE* fp;
	Cliente* ci = NULL;

	fp = fopen("Cliente.txt", "r");
	int ni = 0, i = 0, co = 0, sa = 0;
	char na[50], pa[50], us[50], mo[50];

	if(fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%[^;];%d;%d;%[^;];%f;%d\n", &i,&na,&us,&pa,&co,&ni,&mo,&sa);
			ci = addclient(ci, i, na, us, pa, co, ni, mo,sa);
		}
		fclose(fp);
	}
	return(ci);
}

//! @brief Funcao para ler a informacao do ficheiro binario para a lista ligada Cliente
//! @return retorna a lista ligada Cliente com as informacoes do ficherio binario
Cliente* readclientB()
{
	FILE* fp;
	Cliente* aux = NULL;
	fp = fopen("client.bin", "rb");

	if (fp != NULL)
	{
		Cliente current;
		while (fread(&current, sizeof(Cliente), 1, fp) == 1)
		{
			aux = addclient(aux, current.id, current.name, current.user, current.pass, current.contacto, current.nif, current.morada,current.saldo);
		}
		fclose(fp);
	}
	return aux;
}

//! @brief Funcao para remover um cliente da lista ligada Cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente 
//! @param id variavel com o id do cliente a remover
//! @return retorna a lista ligada atualizada
Cliente* removeclient(Cliente* inicio, int id)
{
	Cliente *atual = inicio, *anterior = inicio, *aux;

	if (inicio == NULL)
	{
		return(NULL);
	}
	else if(atual->id == id)
	{
		aux = atual->seguinte;
		free(atual);
		printf("client removed\n");
		return (aux);
	}
	else
	{
		while ((atual != NULL) && (atual->id != id))
		{
			anterior = atual;
			atual = atual->seguinte;	
		}
		if (atual == NULL)return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			printf("client removed\n");
			return(inicio);
		}
	}

}

//! @brief Funcao para fazer login do cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente
//! @param user variavel para comparar o username do cliente
//! @param pass variavel para comparar a palavra-pass do cliente
//! @return retorna 1 se a palavra-pass e o user name estiverem certos e 0 se nao
int loginclient(Cliente* inicio,char user[],char pass[])
{
	for(inicio;inicio != NULL;inicio = inicio->seguinte)
	{
		if (strstr(inicio->user, user) && strstr(inicio->pass, pass))
		{
			printf("Login successful!\n");
			return(1);
		}
	}
	
	printf("login unsuccessful!\n");
	exit(0);
	return(0);
}

//! @brief Funcao para mudar informacoes de um cliente na lista ligada Cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente
//! @param id variavel com o id do cliente
void changeclient(Cliente* inicio, int id)
{
	Cliente* atual = inicio;
	char novo_nome[50];
	char name[50], morada[50], user[50], pass[50];
	int nif=0, contacto=0, op=0;
	while (inicio != NULL)
	{
		if(inicio->id == id)
		{
			printf("what do you wanna change?\n");
			printf("1-name\n2-username\n3-password\n4-adress\n5-nif\n6-phonenumber\n");
			scanf("%d", &op);
			switch (op)
			{
			case 1:
				printf("Digit the new name!\n");
				scanf("%s", name);
				strcpy(atual->name, novo_nome);
				return(inicio);
				break;
			case 2:
				printf("Digit the new username!\n");
				scanf("%s", user);
				strcpy(inicio->user, user);
				return(inicio);
				break;
			case 3:
				printf("Digit the new pass!\n");
				scanf("%s", pass);
				strcpy(inicio->pass, pass);
				return(inicio);
				break;
			case 4:
				printf("Digit the new adress!\n");
				scanf("%s", morada);
				strcpy(inicio->morada, morada);
				return(inicio);
				break;
			case 5:
				printf("Digit the new nif!\n");
				scanf("%d", &nif);
				inicio->nif = nif;
				return(inicio);
				break;
			case 6:
				printf("Digit the new phonenumber!\n");
				scanf("%d ", &contacto);
				inicio->contacto = contacto;
				return(inicio);
				break;
			default:
				exit(0);
				break;
			}
		}
		else
		{
			inicio = inicio->seguinte;
		}
		
			
	}
}

//! @brief Funcao para adicionar saldo na conta de um cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Cliente
//! @param id variavel para identificar o id do cliente
//! @param saldo variavel para identificar quanto saldo um cliente quer adicionar 
//! @return retorna a lista ligada Cliente atualizada
Cliente* addbalance(Cliente* inicio, int id, float saldo)
{
	while (inicio != NULL)
	{
		if(inicio->id == id)
		{
			inicio->saldo += saldo;
			return(inicio);
		}
		else
		{
			inicio = inicio->seguinte;
		}

	}
}


