#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "meio.h"

Mobilidade* addVehicle(Mobilidade* inicio, char meio[], char localizacao[], int id, float bat, float autonomia, float custo,int id_r,int reserva)
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
		new->id_reserva = id_r;
		new->reserva = reserva;
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
			fprintf(fp, "%d;%s;%s;%f;%f;%f;%d;%d\n", ci->id, ci->meio, ci->localizacao, ci->bat,ci->autonomia,ci->custo,ci->id_reserva,ci->reserva);
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
	int i = 0, id_r = 0, r = 0;
	char me[50], lo[50];
	float ba, au, cu;

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%[^;];%f;%f;%f;%d;%d\n", &i, &me, &lo, &ba, &au, &cu, &id_r,&r);
			ci = addVehicle(ci, me, lo, i, ba, au, cu,id_r,r);
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
		printf("Vehicle: %s;ID: %d;Location: %s;Batery: %f;Autonomy: %f;Cost: %f;ID_R :%d;Reserve: %d\n", inicio->meio, inicio->id, inicio->localizacao, inicio->bat, inicio->autonomia, inicio->custo,inicio->id_reserva,inicio->reserva);
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

void showVehicleD(Mobilidade* inicio)
{
	while (inicio != NULL)
	{
		if (inicio->reserva == 0)
		{
			printf("Vehicle: %s;ID: %d;Location: %s;Batery: %f;Autonomy: %f;Cost: %f;ID_R :%d;Reserve: %d\n", inicio->meio, inicio->id, inicio->localizacao, inicio->bat, inicio->autonomia, inicio->custo, inicio->id_reserva, inicio->reserva);
			return(1);
		}
		else
		{
			inicio = inicio->seguinte;
		}
	}
	return(0);
}

void showVehicleR(Mobilidade* inicio) 
{
	while (inicio != NULL)
	{
		if (inicio->reserva == 1)
		{
			printf("Vehicle: %s;ID: %d;Location: %s;Batery: %f;Autonomy: %f;Cost: %f;ID_R :%d;Reserve: %d\n", inicio->meio, inicio->id, inicio->localizacao, inicio->bat, inicio->autonomia, inicio->custo, inicio->id_reserva, inicio->reserva);
			return(1);
		}
		else
		{
			inicio = inicio->seguinte;
		}
	}
	return(0);
}


Mobilidade* reserveVehicle(Mobilidade* inicio, int id_reserva, int id_client)
{
	while (inicio != NULL)
	{
		if (inicio->id == id_reserva)
		{
			inicio->id_reserva = id_client;
			inicio->reserva = 1; 
			return(inicio);
		}
		else
		{
			inicio = inicio->seguinte;
		}
	}

}

Mobilidade* returnVehicle(Mobilidade* inicio, int id_reserva, int id_client)
{
	while (inicio != NULL)
	{
		if ((inicio->id == id_reserva) && (inicio->id_reserva == id_client))
		{
			inicio->id_reserva = 0;
			inicio->reserva = 0;
			return(inicio);
		}
		else
		{
			inicio = inicio->seguinte;
		}
	}
}


void orderVehicle(Mobilidade* inicio)
{
	Mobilidade* i = inicio, * j = NULL;
	float aux;
	for (i;i!=NULL;i = i->seguinte)
	{
		for(j = i->seguinte;j!= NULL;j = j->seguinte)
		{
			if (j->autonomia > i->autonomia)
			{
				aux = j->autonomia;
				j->autonomia = i->autonomia;
				i->autonomia = aux;
			}
		}
	}
}

Mobilidade* readVehicleB()
{
	FILE* fp;
	Mobilidade* aux = NULL;
	fp = fopen("veiculos.bin", "rb");

	if (fp != NULL)
	{
		Mobilidade current;
		while (fread(&current, sizeof(Mobilidade), 1, fp) == 1)
		{
			aux = addVehicle(aux, current.meio, current.localizacao, current.id, current.bat,current.autonomia,current.custo,current.id_reserva,current.reserva);
		}
		fclose(fp);
	}
	return aux;
}

void saveVehicleB(Mobilidade* inicio)
{
	FILE* fp;

	fp = fopen("veiculos.bin", "wb");

	if (fp != NULL)
	{
		Mobilidade* aux = inicio;
		while (aux != NULL)
		{
			fwrite(aux, sizeof(Mobilidade), 1, fp);
			aux = aux->seguinte;
		}
		fclose(fp);
	}
}


Historico* addHistoric(Historico* inicio, Mobilidade * meios ,int id_c, int id_m)
{
	Historico* new = malloc(sizeof(struct historico));
	
	if (new != NULL)
	{
		while (meios != NULL)
		{
			if(meios->id_reserva == id_c && meios->id == id_m)
			{
			   strcpy(new->meio, meios->meio);
		       strcpy(new->localizacao, meios->localizacao);
			   new->id_c = id_c;
			   new->id_m = id_m;
			   new->seguinte = inicio;
			   return(new);
			}
			else
			{
				meios = meios->seguinte;
			}
		}
	}
	else
	{
		return(inicio);
	}
}

Historico* addHistoricL(Historico* inicio, char meio[], char localizacao[], int id_c, int id_m)
{
	Historico* new = malloc(sizeof(struct historico));
	if (new != NULL)
	{
		strcpy(new->meio, meio);
		strcpy(new->localizacao, localizacao);
		new->id_c = id_c;
		new->id_m = id_m;
		new->seguinte = inicio;
		return(new);
	}
	else
	{
		return(inicio);
	}
}

void showHistoric(Historico* inicio, int id_c) 
{
	while (inicio != NULL)
	{
		if (inicio->id_c == id_c)
		{
			printf("Vehicle: %s;Location :%s;ID client :%d; ID vehicle :%d\n", inicio->meio, inicio->localizacao, inicio->id_c, inicio->id_m);
			return(1);
		}
		else
		{
			inicio = inicio->seguinte;
		}
	}
	return(0);
}

void saveHistoricB(Historico* inicio)
{
	FILE* fp;

	fp = fopen("historico.bin", "wb");

	if (fp != NULL)
	{
		Historico* aux = inicio;
		while (aux != NULL)
		{
			fwrite(aux, sizeof(Historico), 1, fp);
			aux = aux->seguinte;
		}
		fclose(fp);
	}
}

Historico* readHistoricB()
{
	FILE* fp;
	Historico* aux = NULL;
	Mobilidade* meios = NULL;
	fp = fopen("historico.bin", "rb");

	if (fp != NULL)
	{
		Historico current;
		while (fread(&current, sizeof(Historico), 1, fp) == 1)
		{
			aux = addHistoricL(aux, current.meio, current.localizacao, current.id_c, current.id_m);
		}
		fclose(fp);
	}
	return aux;
}

int saveHistoric(Historico* inicio)
{
	FILE* fp;

	fp = fopen("Historico.txt", "w");

	if (fp != NULL)
	{
		Historico* ci = inicio;
		while (ci != NULL)
		{
			fprintf(fp, "%s;%s;%d;%d\n", ci->meio, ci->localizacao, ci->id_c, ci->id_m);
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