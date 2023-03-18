#pragma once
#include <stdio.h>


typedef struct mobilidade {
	char meio[50];
	char localizacao[50];
	int id;
	float bat;
	float autonomia;
	float custo;
	int id_reserva;
	int reserva;
	struct mobilidade* seguinte;
}Mobilidade;

typedef struct historico {

	char meio[50];
	char localizacao[50];
	int id_c;
	int id_m;
	struct historico* seguinte;
}Historico;

Mobilidade* addVehicle(Mobilidade* inicio, char meio[], char localizacao[], int id, float bat, float autonomia, float custo, int id_reserva, int reserva);
Mobilidade* removeVehicle(Mobilidade* inicio, int id);
void changeVehicle(Mobilidade* inicio, int id);
int saveVehicle(Mobilidade* inicio);
Mobilidade* readVehicle();
void showVehicle(Mobilidade* inicio);
Mobilidade* reserveVehicle(Mobilidade* inicio, int id_reserva, int id_client);
Mobilidade* returnVehicle(Mobilidade* inicio, int id_reserva, int id_client);
void showVehicleD(Mobilidade* inicio);
void showVehicleR(Mobilidade* inicio);
void orderVehicle(Mobilidade* inicio);
void saveVehicleB(Mobilidade* inicio);
Mobilidade* readVehicleB();

Historico* addHistoric(Historico* inicio, Mobilidade* meios, int id_c, int id_m);
Historico* addHistoricL(Historico* inicio, char meio[], char localizacao[], int id_c, int id_m);
void showHistoric(Historico* inicio, int id_c);
void saveHistoricB(Historico* inicio);
Historico* readHistoricB();
int saveVehicle(Historico* inicio);