#include<stdio.h>
#include<string.h>
#include<ctype.h>
char N[50];
char opc,resp;
int main()
	{
		printf("\n\t\t\t\t\tBasile Alvarez Andr%cs Jos%c\n\t\t\t\t\tGuzm%cn Mercado Sergio Francisco\n\t\t\t\t\tKeller Ascencio Rodolfo Andr%cs\n\t\t\t\t\tPardo Reyna Anelissa Allizon\n\t\t\t\t\tPulido Rodr%cguez Aramis de Jes%cs",130,130,160,130,161,163);
		printf("\n\n\t\t\t\t\tFundamentos de Programaci%cn\n\n\t\t\t\t\t\tGrupo: 1101\n\n\t\t\t\t\tM.C. Cintia Quezada Reyes",162); 
		printf("\n\n\t\tIngresa tu nombre: ");	//El usuario ingresa su nombre
		scanf(" %[^\n]",&N);
		resp='s';
		toupper(resp);
		while((resp=='s')||(resp=='S'))
			{
				printf("\nSELECCIONA UNA OPCI%cN: ",224);
				printf("\n\n\t [A] MODIFICACION%cN DE UN TEXTO ",224);
				printf("\n\n\t [B] OBTENCI%cN DEL TEXTO ORIGINAL \n\n\t",224);
				printf(" [C] SALIR DEL PROGRAMA \n\n\t\t\t\t");
				printf("Respuesta: ");
				scanf("%s",&opc);			
				system("cls");
				opc=toupper(opc);
				if(opc=='A')
				{
					printf("\n\n\t\t\t\t %c MODIFICACI%cN DE UN TEXTO %c",174,224,175); 
					printf("\n\n\tProporciona 5 letras del alfabeto, separados por comas\n\t");
					//Aqui se ordenan alfabeticamente
					printf("\n\n\n\tPara regresar al men%c, oprima una S: ",163);
					scanf("%s", &resp);
					system("cls");
								
				}
				else
				{
					if(opc=='B')
					{
						printf("\n\n\t\t\t\t %c OBTENCI%cN DEL TEXTO ORIGINAL %c",174,224,175);
						//SE DESENCRIPTA
						
						printf("\n\n\n\tPara regresar al men%c, oprima una S: ",163);
						scanf("%s", &resp);
						system("cls");
			
					}
					else
					{
						if(opc=='C')
						{
							return 0;
						}
						else
						{
							printf("\n\n\t\tOPCI%cN NO V%cLIDA, DEBES SELECCIONAR UNA OPCI%cN",224,181,224); 
							printf("\n\n\n\tPara regresar al men%c, oprima una S: ",163);
							scanf("%s", &resp);
							system("cls");
						}
					}
				}
			}
		getchar();
		getchar();
		return 0;
	}
