#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#include "cliente.h"
#include "gestor.h"
//#include "meio.h"

int menuC1()
{
	int op;
	printf(" -------------------------\n");
	printf("|       Menu client       |\n");
	printf("|1- Regist                |\n");
	printf("|2- Login                 |\n");
	printf("|0- Exit                  |\n");
	printf(" -------------------------\n");
	scanf("%d", &op);
	return (op);
}

int menuC2()
{
	int op;
	printf(" -----------------------\n");
	printf("|       Menu client     |\n");
	printf("|1- Remove client       |\n");
	printf("|2- Change client       |\n");
	printf("|3- Show client         |\n");
	printf("|4- Add a balance       |\n");
	printf("|5- Rent a vehicle      |\n");
	printf("|6- Return a vehicle    |\n");
	printf("|0- Exit                |\n");
	printf(" -----------------------\n");
	scanf("%d", &op);
	return (op);
}

int menuG()
{
	int op;
	printf(" =============================\n");
	printf("|         Menu Manager        |\n");
	printf("|1- Add manager               |\n");
	printf("|2- Remove manager            |\n");
	printf("|3- Change manager            |\n");
	printf("|4- Show manager              |\n");
	printf("|0- Exit                      |\n");
	printf(" =============================\n");
	scanf("%d", &op);
	return(op);
}

int menuM()
{
	int op;
	printf(" =============================\n");
	printf("|         Menu Manager        |\n");
	printf("|1- Add vehicle               |\n");
	printf("|2- Remove vehicle            |\n");
	printf("|3- Change vehicle            |\n");
	printf("|4- Show vehicle              |\n");
	printf("|5- Add client                |\n");
	printf("|6- Remove client             |\n");
	printf("|7- Show client               |\n");
	printf("|8- Add balance to a client   |\n");
	printf("|0- Exit                      |\n");
	printf(" =============================\n");
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
	client = readclient();
	int id_c, contacto_c, nif, rid;
	float saldo = 0;
	char name_c[50], user[50], morada[50], pass[50];
	Gestor* manager = NULL;
	//manager = readManager();
	char mail[50], name_g[50];
	int id_g, contacto_g;
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
			scanf("%d", &id_c);
			printf("whats your name?\n");
			scanf("%s", name_c);
			printf("whats your username?\n");
			scanf("%s", user);
			printf("whats your password?\n");
			scanf("%s", pass);
			printf("whats your phonenumber?\n");
			scanf("%d", &contacto_c);
			printf("whats your nif?\n");
			scanf("%d", &nif);
			printf("whats your adress?\n");
			scanf("%*c");
			gets(morada);
			client = addclient(client, id_c, name_c, user, pass, contacto_c, nif, morada, saldo);
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
		default:
			printf("Choose an given opcion!!");
			break;
		}
		clear();
		do
		{
			op = menuC2();
			switch (op)
			{
			case 1:
				printf("whats the id of account you wanna remove?\n");
				scanf("%d", &rid);
				client = removeclient(client, rid);
				clear();
				
				break;
			case 2:
				printf("whats your id?\n");
				scanf("%d", &id_c);
				changeclient(client, id_c);
				clear();
				break;
			case 3:
				showclient(client);
				break;
			case 4:
				printf("whats your id?\n");
				scanf("%d", &id_c);
				printf("How much do you wanna add to your balance?\n");
				scanf("%f", &saldo);
				client = addbalance(client, id_c, saldo);
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				printf("Choose an given opcion!!");
				break;
			}
		} while (op != 0);
		saveclient(client);
	}
	else if (c == 1) 
	{
		printf("Whats the username?");
		scanf("%s", user);
		printf("whats the password?");
		scanf("%s", pass);
		loginManager(user, pass);
		clear();
		int opcao=0;
		printf("choose an option!\n");
		printf("1- manager\n");
		printf("2- vehicle and client\n");
		scanf("%d", &opcao);
		clear();
		if(opcao == 1)
		{
			
			
				op = menuG();
				switch (op)
				{
				case 1:
					printf("Whats your name?\n");
					scanf("%s", name_g);
					printf("Whats your email?\n");
					scanf("%*c");
					gets(mail);
					printf("writte an id?\n");
					scanf("%d", &id_g);
					printf("Whats your phonenumber?\n");
					scanf("%d", &contacto_g);
					manager = addManager(manager, name_g, id_g, contacto_g, mail);
					clear();
					break;
				case 2:
					printf("Whats the id of manager you wanna remove?\n");
					scanf("%d", &id_g);
					manager = removeManager(manager, id_g);
					clear();
					break;
				case 3:
					printf("Whats yout id?\n");
					scanf("%d", &id_g);
					changeManager(manager, id_g);
					clear();
					break;
				case 4:
					showManager(manager);
					break;
				case 0:
					exit(0);
					break;
				default:
					break;
				}
			
			saveManager(manager);
		}
		else if (opcao == 2)
		{
			do 
			{
				op = menuM();
				switch (op)
				{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 0:
					exit(0);
					break;
				default:
					break;
				}
			} while (op != 0);
		}
	}

	return(0);
}