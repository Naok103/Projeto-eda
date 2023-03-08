#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct registo {
	int codigo;
	char tipo[50];
	float bateria;
	float autonomia;
	struct registo* seguinte;

}Meio ;