#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "meio.h"

//! @brief Funcao para adicionar um novo veiculo a lista ligada Mobilidade
//! @param inicio apontador a apontar para o inicio da lista ligada Mobilidade
//! @param meio variavel para o tipo de veiculo a inserir
//! @param localizacao variavel para a localizacao do veiculo a inserir
//! @param id variavel para o id do veiculo a inserir
//! @param bat variavel para a bateria do veiculo a inserir
//! @param autonomia variavel para a autonomia a inserir
//! @param custo variavel para o custo a inserir
//! @param id_r variavel para o id do cliente que vai reservar o veiculo
//! @param reserva variavel para distinguir se o veiculo esta reservado ou nao
//! @return 
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

//! @brief Funcao prar salvar as informacoes da lista ligada Mobilidade num ficheiro de texto
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @return a funcao retorna 1 se as informacoes do ficheiro de texto forem guardadas com sucesso na lista ligada Mobilidade e 0 se nao
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

//! @brief Funcao para ler as informacoes do ficheiro de texto para a lisra ligada Mobilidade
//! @return retorna a lista ligada Mobilidade atualizada
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

//! @brief Funcao para remover um veiculo da lista ligada Mobilidade
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id variavel para o id do cliente
//! @return retorna a lista ligada Mobilidade atualizada
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

//! @brief Funcao para mostrar a lista ligada na consola
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
void showVehicle(Mobilidade* inicio)
{
	while (inicio != NULL)
	{
		printf("Vehicle: %s;ID: %d;Location: %s;Batery: %f;Autonomy: %f;Cost: %f;ID_R :%d;Reserve: %d\n", inicio->meio, inicio->id, inicio->localizacao, inicio->bat, inicio->autonomia, inicio->custo,inicio->id_reserva,inicio->reserva);
		inicio = inicio->seguinte;
	}
}

//! @brief Funcao para mudar informacoes do veiculo na lista ligada Mobilidade
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id variavel para o id do cliente
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

//! @brief Funcao para mostrar a lista ligada Mobilidade na consola com os veiculos disponiveis para reserva
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
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

//! @brief Funcao para mostrar a lista ligada Mobilidade na consola com os veiculos reservados
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
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

//! @brief Funcao para verificar se um meio ja esta reservado
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id variavel com o codigo que identifica o meio
void existsreserv(Mobilidade* inicio, int id)
{
	while (inicio != NULL)
	{
		if (inicio->id == id && inicio->id_reserva == 1) {
			printf("The vehicle you chose is alredy reserved!\n");
		}
		inicio = inicio->seguinte;
		
	}
}

//! @brief Funcao para reservar um veiculo por parte de um cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id_reserva variavel para o id do veiculo 
//! @param id_client variavel para o id do cliente
//! @return retorna a lista ligada Mobilidade atualizada
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

//! @brief Funcao para retornar um veiculo por parte de um cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id_reserva variavel para o id do veiculo
//! @param id_client variavel para o id do cliente
//! @return retorna a lista ligada Mobilidade atualizada 
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

//! @brief Funcao para ordenar por ordem decrescente de autonomia a lista ligada Mobilidade
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade
void orderVehicle(Mobilidade* inicio)
{
	Mobilidade* i = inicio, * j = NULL, *aux = NULL;
	for (i;i!=NULL;i = i->seguinte)
	{
		for(j = i->seguinte;j!= NULL;j = j->seguinte)
		{
			if (j->autonomia > i->autonomia)
			{
				strcpy(aux->meio, i->meio);
				strcpy(j->meio, j->meio);
				strcpy(i->meio, aux->meio);
				strcpy(aux->localizacao, i->localizacao);
				strcpy(j->localizacao, j->localizacao);
				strcpy(i->localizacao, aux->localizacao);
				aux->id = j->id;
				j->id = i->id;
				i->id = aux->id;
				aux->bat = j->bat;
				j->bat = i->bat;
				i->bat = aux->bat;
				aux->autonomia = j->autonomia;
				j->autonomia = i->autonomia;
				i->autonomia = aux->autonomia;
				aux->custo = j->custo;
				j->custo = i->custo;
				i->custo = aux->custo;
				aux->id_reserva = j->id_reserva;
				j->id_reserva = i->id_reserva;
				i->id_reserva = aux->id_reserva;
				aux->reserva = j->reserva;
				j->reserva = i->reserva;
				i->reserva = aux->reserva;
			}
		}
	}
}

//! @brief Funcao para ler informacoes do ficheiro binario para a lista ligada Mobilidade
//! @return esta funcao retorna a lista ligada Mobilidade com as informacoes presentes no ficheiro binario
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

//! @brief funcao para guardar as informacoes da lista ligada Mobilidade num ficherio binario
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Mobilidade 
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

//! @brief Funcao para inserir o geocodigo na lista ligada Mobilidade
//! @param location variavel com a localizacao do meio
char geocodigo(char location[])
{
	
	if((strcmp(location, "braga") == 0) || (strcmp(location, "Braga") == 0) || (strcmp(location, "BRAGA") == 0))
	{
		printf("Choose one of this location!\n");
		printf("0-");
		//strcpy(location, "calha.recodificado.juros");
		return (location);
	}
	else if (strcmp(location, "porto") == 0 || strcmp(location, "Porto") == 0 || strcmp(location, "PORTO") == 0)
	{
		strcpy(location, "acha.topete.ervilhas");
		return (location);
	}
	else if (strcmp(location, "lisboa") == 0 || strcmp(location, "Lisboa") == 0 || strcmp(location, "LISBOA") == 0)
	{
		strcpy(location, "dera.espiou.afeto");
		return (location);
	}	
	else
	{
		printf("Insira uma localizacao valida(braga,lisboa ou porto!!");
		exit(0);
	}
}

//! @brief Funcao para adicionar um historico de uma reserva de um cliente na lista ligada Historico
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Historico 
//! @param meios apontador da variavel a apontar para o inicio da lista ligada Mobilidade
//! @param id_c variavel para o id do cliente a inserir
//! @param id_m variavel para o id do meio a inserir
//! @return esta funcao retorna a lista ligada Historico com uma nova reserva
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

//! @brief Funcao para adicionar um historico de uma reserva de um cliente na lista ligada Historico
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Historico
//! @param meio variavel para o tipo de meio a inserir
//! @param localizacao variavel para a localizacao do meio a inserir
//! @param id_c variavel para o id do cliente a inserir
//! @param id_m variavel para o id do meio a inserir
//! @return esta funcao retorna a lista ligada Historico com uma nova reserva
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

//! @brief Funcao para mostrar na consola o historico de reservas de um cliente
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Historico
//! @param id_c variavel para o id do cliente
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

//! @brief Funcao para guardar as informacoes da lista ligada Historico no ficheiro binario
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Historico
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

//! @brief Funcao para ler informacoes do ficheiro binario para a lista ligada Historico
//! @return esta funcao retorna a lista ligada Historico com as informacoes presentes no ficheiro binario
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

//! @brief Funcao para guardar as informacoes da lista ligada Historico num ficheiro de texto
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Historico
//! @return a funcao retorna 1 se as informacoes do ficheiro de texto forem guardadas com sucesso na lista ligada Historico e 0 se nao
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