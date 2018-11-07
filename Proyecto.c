#include<stdio.h>
#include<string.h>
#include<ctype.h>
char N[50];
char opc,resp,x[5],y[10],Leer[100],mayusLeer[100];
char letras[5];
char ordenado[5];
char matrix[6][7];
char matrizABC[28] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',165,'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char enie = 164, ENIE = 165;
//PARA ARCHIVO RESULTANTE
FILE *archivoRES;
char nombre_archivoRES[50];
//PARA ARCHIVO DE LECTURA
FILE *archivoLEER;
char nombre_archivoLEER[50];

int i,j,k,a,b;	
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
					printf("\n\n\tProporciona 5 letras del alfabeto (una tras otra, sin espacios entre cada una. Presione enter.)\n\t");
					scanf("%s",&letras);
					
					
					
					if(strlen(letras)!=5)
						printf("Solamente se pueden ingresar 5 letras.");
					else
					{
						printf("Ingrese el nombre del archivo de donde se va a leer el texto (presionar enter al finalizar):");
						scanf(" %[^\n]",&nombre_archivoLEER);
						archivoLEER = fopen(nombre_archivoLEER,"r");
						if(archivoLEER==NULL)
						{
							printf("ERROR, no existe ese archivo");
							/*printf("\n\n\n\tPara regresar al men%c, oprima una S: ",163);
							scanf("%s", &resp);
							system("cls");*/
						}
						else
						{
						
						printf("Ingrese el nombre del archivo resultante. Presione enter al finalizar: ");
						scanf(" %[^\n]",&nombre_archivoRES);
						archivoRES = fopen(nombre_archivoRES,"w");
						strupr(letras); //Pasamos a mayus
						for(k=0;k<5;k++)
							{
								if(enie == letras[k] || ENIE == letras[k])
									{
										letras[k] = 165;
									}
							}
						strcpy(ordenado,letras); //Copiamos letras en ordenado para realizar el ordenamiento alfabetico
						
						for(j=0;j<28;j++)
							{
								for(i=0;i<5;i++)
									{
										if(ordenado[i]==matrizABC[j])
											{
												fprintf(archivoRES,"%c",ordenado[i]);		
											}
									}
							}
					fclose(archivoRES);
					archivoRES = fopen(nombre_archivoRES,"r");
					fgets(y,10,archivoRES);
					printf("\t Su clave de 5 letras ordenada es: %s",y);
					fclose(archivoRES);
					printf("\n");
					archivoRES = fopen(nombre_archivoRES,"w");
					fprintf(archivoRES,"%s",N);
					fprintf(archivoRES,"\n");
					char matrix[6][7] = {
		
											{' ',y[0],y[1],y[2],y[3],y[4],' '},
		
											{y[0],'A','B','C','D','E',' '},
		
											{y[1],'F','G','H','I','J','K'},
		
											{y[2],'L','M','N',165,'O','P'},
		
											{y[3],'Q','R','S','T','U',' '},
		
											{y[4],'V','W','X','Y','Z',' '},
		
														};	
											
											for(a=0;a<6;a++)
												{
													for(b=0;b<7;b++)
														{
															fprintf(archivoRES,"%c",matrix[a][b]);
														}
													fprintf(archivoRES,"\n");
												}
					
					fprintf(archivoRES,"\n");	
					fclose(archivoRES);
					while(feof(archivoLEER)==0){
					fgets(Leer,1000,archivoLEER);
					//fscanf(archivoLEER,"%[^;]",Leer);
					strupr(Leer);
					archivoRES = fopen(nombre_archivoRES,"a");
					//mayusLeer[1000] = strupr(Leer);
					for(i=0;i<1000;i++)
						{
							for(j=0;j<28;j++)
							{
								if(Leer[i]==matrizABC[j])
								{
									//printf("%c",matrizABC[j]);
								if(matrizABC[j]=='A')
									{

										printf("%c%c",y[0],y[0]);
										fprintf(archivoRES,"%c%c",y[0],y[0]);
									}
								if(matrizABC[j]=='B')
									{

										printf("%c%c",y[0],y[1]);
									}
								if(matrizABC[j]=='C')
									{

										printf("%c%c",y[0],y[2]);
									}
								if(matrizABC[j]=='D')
									{

										printf("%c%c",y[0],y[3]);
									}
								if(matrizABC[j]=='E')
									{

										printf("%c%c",y[0],y[4]);
									}
							    if(matrizABC[j]=='F')
									{

										printf("%c%c",y[1],y[0]);
									}
								if(matrizABC[j]=='G')
									{

										printf("%c%c",y[1],y[1]);
									}
								if(matrizABC[j]=='H')
									{

										printf("%c%c",y[1],y[2]);
									}
								if(matrizABC[j]=='I')
									{

										printf("%c%c",y[1],y[3]);
									}
								if(matrizABC[j]=='J')
									{

										printf("%c%c",y[1],y[3]);
									}
								if(matrizABC[j]=='K')
									{

										printf("%c%c",y[1],y[4]);
									}
								if(matrizABC[j]=='L')
									{

										printf("%c%c",y[2],y[0]);
									}
								if(matrizABC[j]=='M')
									{

										printf("%c%c",y[2],y[1]);
									}
								if(matrizABC[j]=='N')
									{

										printf("%c%c",y[2],y[2]);
									}
								if(matrizABC[j]==165)
									{

										printf("%c%c",y[2],y[2]);
									}
								if(matrizABC[j]=='O')
									{

										printf("%c%c",y[2],y[3]);
									}
								if(matrizABC[j]=='P')
									{

										printf("%c%c",y[2],y[4]);
									}
								if(matrizABC[j]=='Q')
									{

										printf("%c%c",y[3],y[0]);
									}
								if(matrizABC[j]=='R')
									{

										printf("%c%c",y[3],y[1]);
									}
								if(matrizABC[j]=='S')
									{

										printf("%c%c",y[3],y[2]);
									}
								if(matrizABC[j]=='T')
									{

										printf("%c%c",y[3],y[3]);
									}
								if(matrizABC[j]=='U')
									{

										printf("%c%c",y[3],y[4]);
									}
								if(matrizABC[j]=='V')
									{

										printf("%c%c",y[4],y[0]);
									}
								if(matrizABC[j]=='W')
									{

										printf("%c%c",y[4],y[1]);
									}
								if(matrizABC[j]=='X')
									{

										printf("%c%c",y[4],y[2]);
									}
								if(matrizABC[j]=='Y')
									{

										printf("%c%c",y[4],y[3]);
									}
								if(matrizABC[j]=='Z')
									{

										printf("%c%c",y[4],y[4]);
									}
								
							

								}
								
							}
						}
					}
					fclose(archivoLEER);
					
					
						
					}
					}	
				
									
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
