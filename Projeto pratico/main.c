#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <conio.h>

#include "cliente.h"
//#include "gestor.h"
//#include "meio.h"

int menuC1()
{
	int op;
	printf(" -------------------------\n");
	printf("|       Menu client       |\n");
	printf("|1- Regist                |\n");
	printf("|2- Login                 |\n");
	printf("|3- Exit                  |\n");
	printf(" -------------------------\n");
	scanf("%d", &op);
	return (op);
}

int menuC2()
{
	int op;
	printf(" -------------------------\n");
	printf("|       Menu client       |\n");
	printf("|1- Remove client         |\n");
	printf("|2- Change client         |\n");
	printf("|3- Save client           |\n");
	printf("|4- Show client           |\n");
	printf("|6- Rent a mobility mean  |\n");
	printf("|0- Exit                  |\n");
	printf(" -------------------------\n");
	scanf("%d", &op);
	return (op);
}

int menuG()
{
	int op;
	printf(" ************************\n");
	printf("*                        *\n");
	printf("*      Menu Manager      *\n");
	printf("*                        *\n");
	printf("*1- Add manager          *\n");
	printf("*                        *\n");
	printf("*2- Remove manager       *\n");
	printf("*                        *\n");
	printf("*3- Change manager       *\n");
	printf("*                        *\n");
	printf("*4- Save manager         *\n");
	printf("*                        *\n");
	printf("*5- Show manager         *\n");
	printf("*                        *\n");
	printf("*6- Read manager         *\n");
	printf("*                        *\n");
	printf("*0- Exit                 *\n");
	printf("*                        *\n");
	printf(" ************************\n");
	scanf("%d", &op);
	return(op);
}



void clear() 
{
	system("@cls || clear");
}

int main()
{ 
	Cliente* client = NULL;
	client = readclient(client);
	int id, contacto, nif, rid;
	char name[50], user[50], morada[50], pass[50];
	//Gestor* manager = NULL;
	//Mobilidade* meio = NULL;
	int op = 0, c;
	printf("choose an opcion:\n");
	printf("1-gestor\n");
	printf("2-cliente\n");
	scanf("%d", &c);
	clear();

	if (c == 2) 
	{
		op = menuC1();
		clear();
		switch (op)
		{
		case 1:
			printf("write an id?\n");
			scanf("%d", &id);
			printf("whats your name?\n");
			scanf("%s", name);
			printf("whats your username?\n");
			scanf("%s", user);
			printf("whats your password?\n");
			scanf("%s", pass);
			printf("whats your phonenumber?\n");
			scanf("%d", &contacto);
			printf("whats your nif?\n");
			scanf("%d", &nif);
			printf("whats your adress?\n");
			scanf("%*c");
			gets(morada);
			client = addclient(client, id, name, user, pass, contacto, nif, morada);
			break;
		case 2:
			printf("whats your username?\n");
			scanf("%s", user);
			printf("whats your password?\n");
			scanf("%s", pass);
			loginclient(client, user, pass);
			break;
		case 0:
			exit(0);
			break;
		}
		clear();
		do
		{
			op = menuC2();
			clear();
			switch (op)
			{
			case 1:
				printf("whats the id of account you wanna remove?\n");
				scanf("%d", &rid);
				client = removeclient(client, rid);
				break;
			case 2:
				break;
			case 3:
				saveclient(client);
				break;
			case 4:
				showclient(client);
				break;
			case 5:
				break;
			case 6:
				break;
			case 0:
				exit(0);
				break;
			default:
				break;
			}
		} while (op != 0);
		//saveclient(client);
	}
	else if (c == 1) 
	{
		menuG();
	}

	return(0);
}