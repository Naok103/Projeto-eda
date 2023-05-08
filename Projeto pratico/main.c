#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#include "cliente.h"
#include "gestor.h"
#include "meio.h"
#include "grafo.h"

#define VERTICES 15
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
	printf(" ---------------------------\n");
	printf("|       Menu client         |\n");
	printf("|1- Remove client           |\n");
	printf("|2- Change client           |\n");
	printf("|3- Show client             |\n");
	printf("|4- Show client historic    |\n");
	printf("|5- Add a balance           |\n");
	printf("|6- Rent a vehicle          |\n");
	printf("|7- Return a vehicle        |\n");
	printf("|0- Exit                    |\n");
	printf(" ---------------------------\n");
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
	printf(" ==============================\n");
	printf("|         Menu Manager         |\n");
	printf("|1- Add vehicle                |\n");
	printf("|2- Remove vehicle             |\n");
	printf("|3- Change vehicle             |\n");
	printf("|4- Show vehicle               |\n");
	printf("|5- Order vehicle              |\n");
	printf("|6- Add client                 |\n");
	printf("|7- Remove client              |\n");
	printf("|8- Show client                |\n");
	printf("|9- Change client              |\n");
	printf("|10- Add balance to a client   |\n");
	printf("|11- Show client historic      |\n");
	printf("|12- create a graph            |\n");
	printf("|13- visualize a graph         |\n");
	printf("|0- Exit                       |\n");
	printf(" ==============================\n");
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
	client = readclientB();
	//client = readclient();
	int id_c, contacto_c, nif, rid;
	float saldo = 0;
	char name_c[50], user[50], morada[50], pass[50];
	Gestor* manager = NULL;
	//manager = readManager();
	manager = readManagerB();
	char mail[50], name_g[50];
	int id_g, contacto_g;
	Mobilidade* meios = NULL;
	//meios = readVehicle();
	meios = readVehicleB();
	int id_m, id_r = 0, r = 0;
	char meio[50], localizašao[50];
	float bat, aut, custo;
	Historico* historico = NULL;
	historico = readHistoricB();
	int op = 0, c;
	Pilha *p = NULL;
	float Matriz[VERTICES][VERTICES];
	Adjacentes porto[VERTICES];
	InicializarGrafo(porto);
	Adjacentes braga[VERTICES];
	InicializarGrafo(braga);
	Adjacentes lisboa[VERTICES];
	InicializarGrafo(lisboa);
	int fnode, lnode, peso;
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
				printf("Whats your id?\n");
				scanf("%d", &id_c);
				showHistoric(historico, id_c);
				break;
			case 5:
				printf("whats your id?\n");
				scanf("%d", &id_c);
				printf("How much do you wanna add to your balance?\n");
				scanf("%f", &saldo);
				client = addbalance(client, id_c, saldo);
				break;
			case 6:
				showVehicleD(meios);
				printf("Whats the id of the vehicle you wanna reserve?\n");
				scanf("%d", &id_m);
				printf("Whats your id?\n");
				scanf("%d", &id_c);
				existsreserv(meios, id_m);
				meios = reserveVehicle(meios, id_m, id_c);
				historico = addHistoric(historico, meios, id_c, id_m);
				break;
			case 7:
				showVehicleR(meios);
				printf("Whats the id of the vehicle you wanna return?\n");
				scanf("%d", &id_m);
				printf("Whats your id?\n");
				scanf("%d", &id_c);
				meios = returnVehicle(meios, id_m, id_c);
				break;
			case 0:
				saveclient(client);
				saveclientB(client);
				saveVehicle(meios);
				saveVehicleB(meios);
				saveHistoricB(historico);
				saveHistoric(historico);
				exit(0);
				break;
			default:
				printf("Choose an given opcion!!");
				break;
			}
		} while (op != 0);	
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
		do
		{
			printf("choose an option!\n");
			printf("1- manager\n");
			printf("2- vehicle and client\n");
			printf("0-exit\n");
			scanf("%d", &opcao);
			clear();
			if (opcao == 1)
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
					saveManager(manager);
					saveManagerB(manager);
					exit(0);
					break;
				default:
					printf("Choose an given option!");
					break;
				}

			}
			else if (opcao == 2)
			{
				op = menuM();
				char c = "";
				int cid = 0;
				switch (op)
				{
				case 1:
					printf("Whats the name of vehicle?\n");
					scanf("%s", meio);
					printf("Whats the location of the vehicle?\n");
					scanf("%s", localizašao);
					geocodigo(localizašao);
					printf("Whats the level of batery in the vehicle?\n");
					scanf("%f", &bat);
					printf("Whats the level of autonomy of the vehicle?\n");
					scanf("%f", &aut);
					printf("Whats the id of the vehicle?\n");
					scanf("%d", &id_m);
					printf("Whats the cost of the vehicle?\n");
					scanf("%f", &custo);
					meios = addVehicle(meios, meio, localizašao, id_m, bat, aut, custo, id_r, r);
					break;
				case 2:
					printf("Whats the id pf the vehicle you wanna remove?\n");
					scanf("%d", &id_m);
					meios = removeVehicle(meios, id_m);
					break;
				case 3:
					printf("Whats the ID of the vehicle");
					scanf("%d", id_m);
					changeVehicle(meios, id_m);
					break;
				case 4:
					showVehicle(meios);
					break;
				case 5:
					orderVehicle(meios);
					showVehicle(meios);
					break;
				case 6:
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
				case 7:
					printf("whats the id of account you wanna remove?\n");
					scanf("%d", &rid);
					client = removeclient(client, rid);
					clear();
					break;
				case 8:
					showclient(client);
					break;
				case 9:
					printf("whats your id?\n");
					scanf("%d", &id_c);
					changeclient(client, id_c);
					clear();
					break;
				case 10:
					printf("whats your id?\n");
					scanf("%d", &id_c);
					printf("How much do you wanna add to your balance?\n");
					scanf("%f", &saldo);
					client = addbalance(client, id_c, saldo);
					break;
				case 11:
					printf("Whats your id?\n");
					scanf("%d", &id_c);
					showHistoric(historico, id_c);
					break;
				case 12:
					printf("Which graph do you wanna use\n");
					printf("1-braga;2-lisboa;3-porto\n");
					scanf("%d", &cid);
					if (cid == 1)
					{
						do
						{
							printf("Whats the id of the first node!\n");
							scanf("%d", &fnode);
							printf("Whats the id of the last node!\n");
							scanf("%d", &lnode);
							printf("Whats the weight of the edge!\n");
							scanf("%d", &peso);
							InserirAresta(braga, fnode, lnode, peso);
							getchar();
							printf("Do you wanna continue(y/n)!\n");
							scanf("%c", &c);
						} while (c != 'n');
					}
					else if (cid == 2)
					{
						do
						{
							printf("Whats the id of the first node!\n");
							scanf("%d", &fnode);
							printf("Whats the id of the last node!\n");
							scanf("%d", &lnode);
							printf("Whats the weight of the edge!\n");
							scanf("%d", &peso);
							InserirAresta(lisboa, fnode, lnode, peso);
							printf("Do you wanna continue(y/n)!\n");
							scanf("%c", &c);
						} while (c != "n");
					}
					else if(cid == 3)
					{
						do
						{
							printf("Whats the id of the first location!\n");
							scanf("%d", &fnode);
							printf("Whats the id of the last location!\n");
							scanf("%d", &lnode);
							printf("Whats the distance between the 2 location!\n");
							scanf("%d", &peso);
							InserirAresta(porto, fnode, lnode, peso);
							getchar();
							printf("Do you wanna continue(y/n)!\n");
							scanf("%c", &c);
						} while (c != "n");
					}
				break;
				case 13:
					printf("Which graph do you wanna see\n");
					printf("1-braga;2-lisboa;3-porto\n");
					scanf("%d", &cid);
					if (cid == 1)
					{
						Listargrafo(braga);
					}
					else if (cid == 2)
					{
						Listargrafo(lisboa);
						
					}
					else if (cid == 3)
					{
						Listargrafo(porto);
					}
				break;
				case 0:
					saveVehicle(meios);
					saveVehicleB(meios);
					saveclient(client);
					saveclientB(client);
					exit(0);
					break;
				default:
					printf("Choose an given option!");
					break;
				}
				
			}
		} while (opcao != 0);	
	}
	return(0);
}