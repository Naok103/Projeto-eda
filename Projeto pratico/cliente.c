#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cliente.h"

existclient(Cliente* inicio, int id) 
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

Cliente* addclient(Cliente* inicio, char name[], char user[], char pass[], int contacto, int id, int nif, char morada[])
{
	if(!existclient(inicio,id))
	{
		Cliente* new = malloc(sizeof(struct cliente));
		if (new != NULL)
		{
			new->contacto = contacto;
			new->id = id;
			new->nif = nif;
			strcpy(new->name, name);
			strcpy(new->user, user);
			strcpy(new->pass, pass);
			strcpy(new->morada, morada);
			new->seguinte = inicio;
			return(new);
		}
		else
		{
			return(inicio);
		}
	}
}

void showclient(Cliente* inicio)
{
	while (inicio != NULL)
	{
		printf("%s %s %s %d %d %d %s\n", inicio->name, inicio->user, inicio->pass, inicio->contacto, inicio->id, inicio->nif, inicio->morada);
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
			fprintf(fp, "%s;%s;%s;%d;%d;%d;%s\n", ci->name, ci->user, ci->pass, ci->contacto, ci->id, ci->nif, ci->morada);
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
			fscanf(fp, "%[^;]%[^;]%[^;]%d;%d;%d;%[^\n]\n", na, us, pa, co, i, ni, mo);
			ci = addclient(ci, na, us, pa, co, i, ni, mo);
		}
		fclose(fp);
	}
	return(ci);
}


