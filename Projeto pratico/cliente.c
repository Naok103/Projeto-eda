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


void showclient(Cliente* inicio)
{
	while (inicio != NULL)
	{
		printf("ID: %d; Name: %s; User: %s; Pass: %s; Phonenumber: %d; NIF: %d; Adress: %s; Balance: %.2f\n", inicio->id, inicio->name, inicio->user, inicio->pass, inicio->contacto, inicio->nif, inicio->morada, inicio->saldo);
		inicio = inicio->seguinte;
	}
}



int saveclient(Cliente* inicio)
{
	FILE* fp;

	fp = fopen("Cliente.txt", "w");

	if (fp != NULL)
	{
		Cliente* ci = inicio;
		while (ci != NULL)
		{
			fprintf(fp, "%d;%s;%s;%s;%d;%d;%s;%f\n", ci->id, ci->name, ci->user, ci->pass, ci->contacto, ci->nif, ci->morada, ci->saldo);
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

	fp = fopen("Cliente.txt", "r");
	int ni = 0, i = 0, co = 0, sa = 0;
	char na[50], pa[50], us[50], mo[50];

	if(fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%[^;];%d;%d;%[^;];%f\n", &i,&na,&us,&pa,&co,&ni,&mo,&sa);
			ci = addclient(ci, i, na, us, pa, co, ni, mo,sa);
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
			}
		}
		else
		{
			inicio = inicio->seguinte;
		}
		
			
	}
}

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


