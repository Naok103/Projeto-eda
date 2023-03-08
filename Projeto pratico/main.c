#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#include "cliente.h"
#include "gestor.h"
#include "meio.h"

int menuC()
{
	int op;
	printf("  Menu  \n\n");
	printf("1- Add client\n");
	printf("2- Remove client\n");
	printf("3- Change client\n");
	printf("4- Save client\n");
	printf("5- Show client\n");
	printf("6- Read client\n");
	printf("0- Exit\n");
	scanf("%d", &op);
	return (op);
}

int menuG()
{
	int op;
	printf("  Menu  \n\n");
	printf("1- Remove manager\n");
	printf("2- Change manager\n");
	printf("3- Save manager\n");
	printf("4- Show manager\n");
	printf("5- Read manager\n");
	printf("0- Exit\n");
	scanf("%d", &op);
	return(op);
}



main()
{ 
	Cliente* client = NULL;
	//readclient(client);
	int id, contacto, nif;
	char name[50], user[50], morada[50], pass[50];
	Gestor* manager = NULL;
	Mobilidade* meio = NULL;
	int op = 0, c;
	printf("choose an opcion:\n");
	printf("1-gestor\n");
	printf("2-cliente\n");
	scanf("%d", &c);

	if (c == 2) 
	{
		do
		{
			op = menuC();
			switch (op)
			{
			case 1:
				printf("whats your name?\n");
				scanf("%s", &name);
				printf("whats your username?\n");
				scanf("%s", &user);
				printf("whats your password?\n");
				scanf("%s", &pass);
				printf("whats your phonenumber?\n");
				scanf("%d", &contacto);
				printf("write an id?\n");
				scanf("%d", &id);
				printf("whats your nif?\n");
				scanf("%d", &nif);
				printf("whats your adress?\n");
				scanf("%s", &morada);
				client = addclient(client, name, user, pass, contacto, id, nif, morada);
				break;
			case 2:
			case 3:
			case 4:
				saveclient(client);
				break;
			case 5:
				showclient(client);
				break;
			case 6:
				readclient(client);
				break;
			case 0:
				exit(0);
				break;
			}
		} while(op != 0);
		saveclient(client);
	}
	else if (c == 1) 
	{
		menuG();
	}


}