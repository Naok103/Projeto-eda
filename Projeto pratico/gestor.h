#pragma once
#include <stdio.h>


typedef struct gestor {
	char nome[50];
	int id;
	int contacto;
	char mail[50];
	struct gestor* seguinte;
}Gestor;

int loginManager(char user[], char pass[]);
Gestor* addManager(Gestor* inicio, char nome[], int id, int contacto, char mail[]);
int saveManager(Gestor* inicio);
void changeManager(Gestor* inicio, int id);
Gestor* readManager();
Gestor* removeManager(Gestor* inicio, int id);
void showManager(Gestor* inicio);
int existManager(Gestor* inicio, int id);
void saveManagerB(Gestor* inicio);
Gestor* readManagerB();

