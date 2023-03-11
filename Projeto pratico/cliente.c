#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "cliente.h"

int existclient(Cliente* inicio, int id) 
{
	while(inicio != NULL)
	{
		if (inicio->id = id)
		{
			return(1);
		}
		inicio = inicio->seguinte;	
	}
	return(0);
}


Cliente* addclient(Cliente* inicio, int id, char name[], char user[], char pass[], int contacto, int nif, char morada[])
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
		new->seguinte = inicio;
		return(new);
	}
	else
	{
		return(inicio);
	}
}


void showclient(Cliente* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %s %s %d %d %s\n", inicio->id, inicio->name, inicio->user, inicio->pass, inicio->contacto, inicio->nif, inicio->morada);
		inicio = inicio->seguinte;
	}
}



int saveclient(Cliente* inicio)
{
	FILE* fp;

	fp = fopen("Cliente", "w");

	if (fp != NULL)
	{
		Cliente* ci = inicio;
		while (ci != NULL)
		{
			fprintf(fp, "%d;%s;%s;%s;%d;%d;%s\n", ci->id, ci->name, ci->user, ci->pass, ci->contacto, ci->nif, ci->morada);
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

Cliente* readclient()
{
	FILE* fp;
	Cliente* ci = NULL;

	fp = fopen("Cliente", "r");
	int ni = 0, i = 0, co = 0;
	char na[50], pa[50], us[50], mo[50];

	if(fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%[^;];%d;%d;%[^\n]\n", &i,&na,&us,&pa,&co,&ni,&mo);
			ci = addclient(ci, i, na, us, pa, co, ni, mo);
		}
		fclose(fp);
	}
	return(ci);
}


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


/*
Cliente* removeclient(Cliente* inicio, int id) // Remover um meio a partir do seu código
{
	Cliente* aux;
	while (inicio != NULL)
	{
		if (inicio->id == id)
		{
			aux = inicio->seguinte;
			free(inicio);
			return(aux);
		}
		else {
			inicio = removeclient(inicio->seguinte, id);
			return(inicio);
		}
	}
}
*/

int loginclient(Cliente* inicio,char user[],char pass[])
{
	while (inicio != NULL)
	{
		if(strstr(inicio->user,user) && strstr(inicio->pass,pass))
		{
			printf("Login successful!\n");
			return(1);
		}
		else
		{
			printf("login unsuccessful!\n");
			exit(0);
			return(0);
		}
	}
}



