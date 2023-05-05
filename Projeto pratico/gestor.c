#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "gestor.h"

//! @brief Funcao para verificar a palavra-pass e o username no login de gestores
//! @param user variavel para verificar o username
//! @param pass variavel para verificar a palavra-pass
//! @return retorna 1 se a palavra-pass e o user name estiverem certos e 0 se nao
int loginManager(char user[], char pass[])
{
	if (strcmp(user, "LESI") == 0 && strcmp(pass, "LESI") == 0)
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

//! @brief Funcao para adicionar um novo gesstor na lista ligada Gestor
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Gestor
//! @param nome variavel com o nome do gestor a inserir
//! @param id variavel com o id do gestor a insesir
//! @param contacto variavel com o contacto do gestor a inserir
//! @param mail variavel com o mail do gestor a insesir
//! @return retorna a lista ligada Gestor atualizada com o novo gestor
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

//! @brief funcao para remover um gestor da lista ligada Gestor
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Gestor
//! @param id variavel para identificar o id do gestor
//! @return retorna a lista ligada Gestor atualizada sem o gestor removido
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

//! @brief funcao para mostrar o conteudo da lista ligada Gestor na consola
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Gestor 
void showManager(Gestor* inicio)
{
	while (inicio != NULL)
	{
		printf("Name: %s;ID: %d;Email: %s;Phonenumber: %d;\n", inicio->nome, inicio->id, inicio->mail, inicio->contacto);
		inicio = inicio->seguinte;
	}
}

//! @brief funcao para mudar as informacoe do gestor na lista ligada Gestor
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Gestor 
//! @param id variavel para identificar o id do gestor
void changeManager(Gestor* inicio, int id)
{
	Gestor* atual = inicio;
	char name[50], mail[50];
	int contacto = 0, op = 0;
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

//! @brief funcao para guardar as informacoes da lista ligada Gestor num ficheiro de texto
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Gestor
//! @return a funcao retorna 1 se as informacoes do ficheiro de texto forem guardadas com sucesso na lista ligada Historico e 0 se nao
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

//! @brief funcao para ler as informacoes do ficheiro de texto para a lista ligada Gestor
//! @return retorna a lista ligada Gestor atualizada com as informacoes do ficheiro de texto
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
			fscanf(fp, "%d;%[^;];%d;%[^\n]\n", &i, &na, &co, &ma);
			ci = addManager(ci, na, i, co, ma);
		}
		fclose(fp);
	}
	return(ci);
}

//! @brief funcao para ler as informacoes do ficheiro binario para a lista ligada Gestor
//! @return retorna a lista ligada Gestor atualizada com as informacoes do ficheiro binario
Gestor* readManagerB()
{
	FILE* fp;
	Gestor* aux = NULL;
	fp = fopen("gestor.bin", "rb");

	if (fp != NULL)
	{
		Gestor current;
		while (fread(&current, sizeof(Gestor), 1, fp) == 1)
		{
			aux = addManager(aux, current.nome, current.id, current.contacto, current.mail);
		}
		fclose(fp);
	}
	return aux;
}

//! @brief funcao para guardar as informacoes da lista ligada Gestor num ficheiro binario
//! @param inicio apontador da variavel a apontar para o inicio da lista ligada Gestor
void saveManagerB(Gestor* inicio)
{
	FILE* fp;

	fp = fopen("gestor.bin", "wb");

	if (fp != NULL)
	{
		Gestor* aux = inicio;
		while (aux != NULL)
		{
			fwrite(aux, sizeof(Gestor), 1, fp);
			aux = aux->seguinte;
		}
		fclose(fp);
	}
}


