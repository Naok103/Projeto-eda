#pragma once
#include <stdio.h>

//! @brief lista ligada para guardar clientes
typedef struct cliente
{
	int id;
	char name[50];
	char user[50];
	char pass[50];
	int contacto;
	int nif;
	float saldo;
	char morada[50];
	struct cliente* seguinte;
}Cliente;

int loginclient(Cliente* inicio, char user[], char pass[]);
Cliente* removeclient(Cliente* inicio, int id);
Cliente* addclient(Cliente* inicio, int id, char name[], char user[], char pass[], int contacto, int nif, char morada[], float saldo);
void showclient(Cliente* inicio);
int existclient(Cliente* inicio, int id[]);
void changeclient(Cliente* inicio, int id);
int saveclient(Cliente* inicio);  
Cliente* readclient();
Cliente* addbalance(Cliente* inicio, int id, float saldo);
void saveclientB(Cliente* inicio);
Cliente* readclientB();
int idclient(Cliente* inicio, int id);



