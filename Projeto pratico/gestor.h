#pragma once
#include <stdio.h>

typedef struct gestor {
	char nome[50];
	char pass[50];
	char user[50];
	int id[10];
	int contacto[10];
	char mail[50];
	struct gestor* seguinte;
}Gestor;

Gestor* addGestor(Gestor* inicio, char nome[], char pass[], char user[], int id[], int contacto[], char mail[]);

Gestor* saveGestor(Gestor* inicio, char nome[], char pass[], char user[], int id[], int contacto[], char mail[]);

Gestor* changeGestor(Gestor* inicio, char nome[], char pass[], char user[], int id[], int contacto[], char mail[]);

Gestor* readGestor(Gestor* inicio, char nome[], char pass[], char user[], int id[], int contacto[], char mail[]);

void listarGestor(Gestor* inicio);

Gestor* removeGestor(Gestor* inicio, int id[]);