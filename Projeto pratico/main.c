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
	printf(" ===================================\n");
	printf("|            Menu Manager           |\n");
	printf("|1- Add vehicle                     |\n");
	printf("|2- Remove vehicle                  |\n");
	printf("|3- Change vehicle                  |\n");
	printf("|4- Show vehicle                    |\n");
	printf("|5- Order vehicle                   |\n");
	printf("|6- Add client                      |\n");
	printf("|7- Remove client                   |\n");
	printf("|8- Show client                     |\n");
	printf("|9- Change client                   |\n");
	printf("|10- Add balance to a client        |\n");
	printf("|11- Show client historic           |\n");
	printf("|12- create a graph                 |\n");
	printf("|13- create an edge in a graph      |\n");
	printf("|14- visualize a graph              |\n");
	printf("|15- add a client to a vertex       |\n");
	printf("|16- add a vehicle to a vertex      |\n");
	printf("|17- Show the vehicles in a vertex  |\n");
	printf("|18- Show the clients in a vertex   |\n");
	printf("|19- Show the vehicles in a range   |\n");
	printf("|0- Exit                            |\n");
	printf(" ===================================\n");
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
	int id_c = 0, contacto_c, nif, rid;
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
	int id_m = 0, id_r = 0, r = 0;
	char meio[50], localizaçao[50];
	float bat, aut, custo;
	Historico* historico = NULL;
	historico = readHistoricB();
	int op = 0, c;
	Grafo* braga = NULL;
	braga = LerGrafoA(braga);
	//LerGrafoV(braga, meios, client);
	int fnode, lnode, peso, vertices;
	char local[50];
	printf("choose an opcion:\n");
	printf("1-gestor\n");
	printf("2-cliente\n");
	scanf("%d", &c);
	printf("\033[2J\033[H");;

	if (c == 2) 
	{
		
		op = menuC1();
		printf("\033[2J\033[H");
		switch (op)
		{
		case 1:
			id_c = idclient(client, id_c);
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
			geocodigo(morada);
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
		
		printf("\033[2J\033[H");
		do
		{
			op = menuC2();
			switch (op)
			{
			case 1:
				printf("whats the id of account you wanna remove?\n");
				scanf("%d", &rid);
				client = removeclient(client, rid);
				printf("\033[2J\033[H");
				break;
			case 2:
				printf("whats your id?\n");
				scanf("%d", &id_c);
				changeclient(client, id_c);
				printf("\033[2J\033[H");
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
		do 
		{
			printf("\033[2J\033[H");
			printf("Whats the username?");
			scanf("%s", user);
			printf("whats the password?");
			scanf("%s", pass);
		} while (loginManager(user, pass) != 1);
		
		printf("\033[2J\033[H");
		int opcao=0;
		do
		{
			printf("choose an option!\n");
			printf("1- manager\n");
			printf("2- vehicle and client\n");
			printf("0-exit\n");
			scanf("%d", &opcao);
			printf("\033[2J\033[H");
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
					printf("\033[2J\033[H");
					break;
				case 2:
					printf("Whats the id of manager you wanna remove?\n");
					scanf("%d", &id_g);
					manager = removeManager(manager, id_g);
					printf("\033[2J\033[H");
					break;
				case 3:
					printf("Whats yout id?\n");
					scanf("%d", &id_g);
					changeManager(manager, id_g);
					printf("\033[2J\033[H");
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
					printf("Whats the level of batery in the vehicle?\n");
					scanf("%f", &bat);
					printf("Whats the level of autonomy of the vehicle?\n");
					scanf("%f", &aut);
					id_m = idmeio(meios, id_m);
					geocodigo(localizaçao);
					geocodigoM(localizaçao,local);
					printf("Whats the cost of the vehicle?\n");
					scanf("%f", &custo);
					meios = addVehicle(meios, meio, localizaçao, local, id_m, bat, aut, custo, id_r, r);
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
					id_c = idclient(client, id_c);
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
					geocodigo(morada);
					client = addclient(client, id_c, name_c, user, pass, contacto_c, nif, morada, saldo);
					break;
				case 7:
					printf("whats the id of account you wanna remove?\n");
					scanf("%d", &rid);
					client = removeclient(client, rid);
					printf("\033[2J\033[H");
					break;
				case 8:
					showclient(client);
					break;
				case 9:
					printf("whats your id?\n");
					scanf("%d", &id_c);
					changeclient(client, id_c);
					printf("\033[2J\033[H");
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
					printf("\033[2J\033[H");
					do
					{
						printf("Whats the id of vertex?\n");
						scanf("%d", &fnode);
						geocodigoV(localizaçao, fnode);
						CriarVertice(&braga, fnode,localizaçao, local);
						getchar();
						printf("Do you want to continue(y/n)?\n");
						scanf("%c", &c);
					} while (c != 'n' && c != 'N');
				break;
				case 13:
					printf("\033[2J\033[H");
					do
					{
						printf("Whats the id of first vertex?\n");
						scanf("%d", &fnode);
						printf("Whats the id of last vertex?\n");
						scanf("%d", &lnode);
						printf("Whats the height of the edge?\n");
						scanf("%d", &peso);
						CriarAresta(braga, fnode,lnode,peso,local);
						getchar();
						printf("Do you want to continue(y/n)?\n");
						scanf("%c", &c);
					} while (c != 'n' && c != 'N');
				break;
				case 14:
					printf("\033[2J\033[H");
					printf("Whats the id of the vertex?\n");
					scanf("%d", &fnode);
					ListarAdjacentes(braga, fnode);
				break;
				case 15:
					printf("\033[2J\033[H");
					do
					{
						printf("Whats the id of the vertex?\n");
						scanf("%d", &fnode);
						printf("Whats the id of the client you wanna add to a vertex?\n");
						scanf("%d", &id_c);
						InserirCliente(braga,client, fnode, id_c);
						getchar();
						printf("Do you want to continue(y/n)?\n");
						scanf("%c", &c);
					} while (c != 'n' && c != 'N');	
				break;
				case 16:
					printf("\033[2J\033[H");
					do
					{
						printf("Whats the id of the vertex?\n");
						scanf("%d", &fnode);
						printf("Whats the id of the vehicle you wanna add to a vertex?\n");
						scanf("%d", &id_m);
						InserirMeio(braga,meios, fnode, id_m);
						getchar();
						printf("Do you want to continue(y/n)?\n");
						scanf("%c", &c);
					} while (c != 'n' && c != 'N');
				break;
				case 17:
					printf("Whats the id of the vertex you wanna see?\n");
					scanf("%d", &fnode);
					ListarMeios(braga, fnode);
				break;
				case 18:
					printf("Whats the id of the vertex you wanna see?\n");
					scanf("%d", &fnode);
					ListarClientes(braga, fnode);
				break;
				case 19:
					printf("Whats your location!\n");
					printf("1-Rua do Raio;2-Rua do Souto;3-Avenida Central;4-Avenida da Liberdade;5-Rua 25 de Abril;6-Rua dos Chaos;7-Rua do Carmo;8-Rua Santa Margarida;9-Avenida 31 de Janeiro\n");
					scanf("%d", &fnode);
					printf("How much do you wanna walk?\n");
					scanf("%d", &peso);
					printf("Whats the type of vehicle you wanna reserve?(troti/bike)\n");
					scanf("%s", meio);
					vertices = numVertices(braga);
					encontrarCaminhosLimite(braga, meios, fnode, peso, meio);
					printf("Do you wanna reserve some vehicle?(y/n)\n");
					scanf("%c", &c);
					if (c == 'y')
					{
						printf("Whats your id?\n");
						scanf("%d", &id_c);
						printf("Whats the id of vehicle you wanna reserve!\n");
						scanf("%d", &id_m);
						reserveVehicle(meios, id_m, id_c);
					}
				break;
				case 0:
					saveVehicle(meios);
					saveVehicleB(meios);
					saveclient(client);
					saveclientB(client);
					GravarGrafoA(braga);
					GravarGrafoV(braga);
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