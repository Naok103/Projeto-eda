#pragma once
#include <stdio.h>


typedef struct mobilidade {
	char meio[50];
	int cod;
	float bat;
	float autonomia;
	float custo;
	struct mobilidade* seguinte;
}Mobilidade;

Mobilidade* addmeio(Mobilidade* inicio, char meio[], int cod, float bat, float autonomia, float custo);

Mobilidade* removemeio(Mobilidade* inicio, char meio[], int cod, float bat, float autonomia, float custo);

Mobilidade* changemeio(Mobilidade* inicio, char meio[], int cod, float bat, float autonomia, float custo);

Mobilidade* savemeio(Mobilidade* inicio, char meio[], int cod, float bat, float autonomia, float custo);

Mobilidade* readmeio(Mobilidade* inicio, char meio[], int cod, float bat, float autonomia, float custo);

void listarmeio(Mobilidade* inicio);