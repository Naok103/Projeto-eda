#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "gestor.h"


int loginManager(char user[], char pass[])
{
	if (strstr(user, "LESI") && strstr(pass, "LESI"))
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


int existManager(Gestor* inicio, int id)
{
	while (inicio != NULL)
	{
		if (inicio->id = id)
		{
			return(1);
		}
		inicio = inicio->seguinte;
	}
	return(0);
}

Gestor* addManager(Gestor* inicio, char nome[], int id, int contacto, char mail[])
{
	Gestor* new = malloc(sizeof(struct gestor));
	if (new != NULL)
	{
		strcpy(new->nome, nome);
		new->id = id;
		new->contacto = contacto;
		strcpy(new->mail, mail);
		new->seguinte = inicio;
		return(new);
	}
	else
	{
		return(inicio);
	}
}

Gestor* removeManager(Gestor* inicio, int id)
{
	Gestor* atual = inicio, * anterior = inicio, * aux;

	if (inicio == NULL)
	{
		return(NULL);
	}
	else if (atual->id == id)
	{
		aux = atual->seguinte;
		free(atual);
		printf("Manager removed\n");
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
			printf("Manager removed\n");
			return(inicio);
		}
	}
}

void showManager(Gestor* inicio)
{
	while (inicio != inicio)
	{
		printf("Name: %s;ID: %d;Email: %s;Phonenumber: %d;", inicio->nome, inicio->id, inicio->mail, inicio->contacto);
		inicio = inicio->seguinte;
	}
}

void changeManager(Gestor* inicio, int id)
{
	Gestor* atual = inicio;
	char name[50], mail[50];
	int nif = 0, contacto = 0, op = 0;
	while (inicio != NULL)
	{
		if (inicio->id == id)
		{
			printf("what do you wanna change?\n");
			printf("1-name\n2-mail\n3-phonenumber\n");
			scanf("%d", &op);
			switch (op)
			{
			case 1:
				printf("Digit the new name!\n");
				scanf("%s", name);
				strcpy(atual->nome, name);
				return(inicio);
				break;
			case 2:
				printf("Digit the new username!\n");
				scanf("%s", mail);
				strcpy(inicio->mail, mail);
				return(inicio);
				break;
			case 3:
				printf("Digit the new phonenumber!\n");
				scanf("%d ", &contacto);
				inicio->contacto = contacto;
				return(inicio);
				break;
			}
		}
		else
		{
			inicio = inicio->seguinte;
		}


	}
}

int saveManager(Gestor* inicio)
{
	FILE* fp;

	fp = fopen("Gestor.txt", "w");

	if (fp != NULL)
	{
		Gestor* ci = inicio;
		while (ci != NULL)
		{
			fprintf(fp, "%d;%s;%d;%s\n", ci->id, ci->nome, ci->contacto, ci->mail);
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

Gestor* readManager()
{
	FILE* fp;
	Gestor* ci = NULL;

	fp = fopen("Gestor.txt", "r");
	int ni = 0, i = 0, co = 0, sa = 0;
	char na[50], pa[50], us[50], ma[50];

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^\n]\n", &i, &na, &co, &ma);
			ci = addManager(ci, na, i, co, ma);
		}
		fclose(fp);
	}
	return(ci);
}



