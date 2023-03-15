#pragma once
#include <stdio.h>


typedef struct mobilidade {
	char meio[50];
	char localizacao[50];
	int id;
	float bat;
	float autonomia;
	float custo;
	struct mobilidade* seguinte;
}Mobilidade;

Mobilidade* addVehicle(Mobilidade* inicio, char meio[], char localizacao[], int id, float bat, float autonomia, float custo);
Mobilidade* removeVehicle(Mobilidade* inicio, int id);
void changeVehicle(Mobilidade* inicio, int id);
int saveVehicle(Mobilidade* inicio);
Mobilidade* readVehicle();
void showVehicle(Mobilidade* inicio);


