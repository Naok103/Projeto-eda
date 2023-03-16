#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "meio.h"

Mobilidade* addVehicle(Mobilidade* inicio, char meio[], char localizacao[], int id, float bat, float autonomia, float custo)
{
	Mobilidade* new = malloc(sizeof(struct mobilidade));
	if(new != NULL)
	{
		strcpy(new->meio, meio);
		strcpy(new->localizacao, localizacao);
		new->id = id;
		new->bat = bat;
		new->autonomia = autonomia;
		new->custo = custo;
		new->seguinte = inicio;
		return(new);
	}
	else
	{
		return(inicio);
	}
}

int saveVehicle(Mobilidade* inicio)
{
	FILE* fp;

	fp = fopen("Mobilidade.txt", "w");

	if (fp != NULL)
	{
		Mobilidade* ci = inicio;
		while (ci != NULL)
		{
			fprintf(fp, "%d;%s;%s;%f;%f;%f\n", ci->id, ci->meio, ci->localizacao, ci->bat,ci->autonomia,ci->custo);
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

Mobilidade* readVehicle()
{
	FILE* fp;
	Mobilidade* ci = NULL;

	fp = fopen("Mobilidade.txt", "r");
	int i = 0;
	char me[50], lo[50];
	float ba, au, cu;

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%f;%f;%f\n", &i, &me, &lo, &ba, &au, &cu);
			ci = addVehicle(ci, me, lo, i, ba, au, cu);
		}
		fclose(fp);
	}
	return(ci);
}

Mobilidade* removeVehicle(Mobilidade* inicio, int id)
{
	Mobilidade* atual = inicio, * anterior = inicio, * aux;

	if (inicio == NULL)
	{
		return(NULL);
	}
	else if (atual->id == id)
	{
		aux = atual->seguinte;
		free(atual);
		printf("Vehicle removed\n");
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
			printf("Vehicle removed\n");
			return(inicio);
		}
	}

}

void showVehicle(Mobilidade* inicio)
{
	while (inicio != NULL)
	{
		printf("Vehicle: %s;ID: %d;Location: %s;Batery: %f;Autonomy: %f;Cost: %f\n", inicio->meio, inicio->id, inicio->localizacao, inicio->bat, inicio->autonomia, inicio->custo);
		inicio = inicio->seguinte;
	}
}

void changeVehicle(Mobilidade* inicio, int id)
{
	Mobilidade* atual = inicio;
	int op = 0;
	float bat=0, aut=0, custo=0;
	while (inicio != NULL)
	{
		if (inicio->id == id)
		{
			printf("what do you wanna change?\n");
			printf("1-batery\n2-autonomy\n3-cost\n");
			scanf("%d", &op);
			switch (op)
			{
			case 1:
				printf("Digit the new amount of batery!\n");
				scanf("%s", bat);
				inicio->bat = bat;
				return(inicio);
				break;
			case 2:
				printf("Digit the new autonomy!\n");
				scanf("%f", aut);
				inicio->autonomia = aut;
				return(inicio);
				break;
			case 3:
				printf("Digit the new cost of the vehicle!\n");
				scanf("%f", &custo);
				inicio->custo = custo;
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



