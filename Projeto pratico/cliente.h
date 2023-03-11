#pragma once
#include <stdio.h>

typedef struct cliente
{
	int id;
	char name[50];
	char user[50];
	char pass[50];
	int contacto;
	int nif;
	char morada[50];
	struct cliente* seguinte;
}Cliente;

int loginclient(Cliente* inicio, char user[], char pass[]);
Cliente* removeclient(Cliente* inicio, int id);
Cliente* addclient(Cliente* inicio, int id, char name[], char user[], char pass[], int contacto, int nif, char morada[]);
void showclient(Cliente* inicio);
int existclient(Cliente* inicio, int id[]);
Cliente* changeclient(Cliente* inicio, int id, char name[], char user[], char pass[], int contacto, int nif, char morada[]);
int saveclient(Cliente* inicio);  
Cliente* readclient();
