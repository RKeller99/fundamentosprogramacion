#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char N[50];
char opc,resp,x[5],y[6],Leer[1000],mayusLeer[1000],z[1000];
char letras[5],clave[5];
char ordenado[5];
char matrix[6][7];
char matrizABC[28] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',165,'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char enie = 164, ENIE = 165;
char archCopiado[1000];
int selec;


//PARA ARCHIVO RESULTANTE
FILE *archivoRES;
char nombre_archivoRES[50];
//PARA ARCHIVO DE LECTURA
FILE *archivoLEER;
char nombre_archivoLEER[50];
//PARA ARCHIVO DESENCRIPTACION
FILE *archivoDES;
char nombre_archivoDES[50];
FILE *archivoDES2;
char nombre_textoENCRIPTADO[50];
int i,j,k,a,b;	
int main()
	{
		system("color 01");
		printf("\n\t\t\t\t\t ~ Basile Alvarez Andr%cs Jos%c\n\t\t\t\t\t ~ Guzm%cn Mercado Sergio Francisco\n\t\t\t\t\t ~ Keller Ascencio Rodolfo Andr%cs\n\t\t\t\t\t ~ Pardo Reyna Anelissa Allizon\n\t\t\t\t\t ~ Pulido Rodr%cguez Aramis de Jes%cs",130,130,160,130,161,163);
		printf("\n\n\t\t\t\t\tFundamentos de Programaci%cn\n\n\t\t\t\t\t\tGrupo: 1101\n\n\t\t\t\t\tM.C. Cintia Quezada Reyes",162); 
		printf("\n\n\t\tIngresa tu nombre: ");	//El usuario ingresa su nombre
		scanf(" %[^\n]",&N);
		resp='s';
		toupper(resp);
		while((resp=='s')||(resp=='S'))
			{
				printf("\nSELECCIONA UNA OPCI%cN: ",162);
				printf("\n\n\t [A] MODIFICACION%cN DE UN TEXTO ",162);
				printf("\n\n\t [B] OBTENCI%cN DEL TEXTO ORIGINAL \n\n\t",162);
				printf(" [C] SALIR DEL PROGRAMA \n\n\t\t\t\t");
				printf("Respuesta: ");
				scanf("%s",&opc);			
				system("cls");
				opc=toupper(opc);
				if(opc=='A')
				{
					system("color 0c"); 
					printf("\n\n\t\t\t\t %c MODIFICACI%cN DE UN TEXTO %c",174,162,175);
					printf("\n\n\t~~ Proporciona 5 letras del alfabeto [ UNA TRAS OTRA, SIN ESPACIOS ENTRE CADA UNA ] ~~\n\n\t");
					printf("Tus letras: ");
					scanf("%s",&letras);
							
					
					if(strlen(letras)!=5)
						printf("\n\n\t\t *Solamente se pueden ingresar 5 letras*");
					else
					{
						printf("\n\n\t Ingrese el nombre del archivo de donde se va a leer el texto (presionar enter al finalizar): ");
						scanf(" %[^\n]",&nombre_archivoLEER);
						archivoLEER = fopen(nombre_archivoLEER,"r");
						if(archivoLEER==NULL)
						{
							printf("\n\n\n\t\t\t *ERROR, no existe ese archivo*");
						}
						else
						{
						
						printf("\n\n\t %c Ingrese el nombre del archivo resultante. Presione enter al finalizar: ",175);
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
					fgets(y,6,archivoRES);
					system("cls");
					printf("\n\n\t\t\t\t %c MODIFICACI%cN DE UN TEXTO %c",174,162,175);
					printf("\n\n ~ Su clave de 5 letras ordenadas es: %s",y);
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
					printf("\n\n ~ Su texto encriptado es: ");	
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
										fprintf(archivoRES,"%c%c",y[0],y[1]);
									}
								if(matrizABC[j]=='C')
									{

										printf("%c%c",y[0],y[2]);
										fprintf(archivoRES,"%c%c",y[0],y[2]);
									}
								if(matrizABC[j]=='D')
									{

										printf("%c%c",y[0],y[3]);
										fprintf(archivoRES,"%c%c",y[0],y[3]);
									}
								if(matrizABC[j]=='E')
									{

										printf("%c%c",y[0],y[4]);
										fprintf(archivoRES,"%c%c",y[0],y[4]);
									}
							    if(matrizABC[j]=='F')
									{

										printf("%c%c",y[1],y[0]);
										fprintf(archivoRES,"%c%c",y[1],y[0]);
									}
								if(matrizABC[j]=='G')
									{

										printf("%c%c",y[1],y[1]);
										fprintf(archivoRES,"%c%c",y[1],y[1]);
									}
								if(matrizABC[j]=='H')
									{

										printf("%c%c",y[1],y[2]);
										fprintf(archivoRES,"%c%c",y[1],y[2]);
									}
								if(matrizABC[j]=='I')
									{

										printf("%c%c",y[1],y[3]);
										fprintf(archivoRES,"%c%c",y[1],y[3]);
									}
								if(matrizABC[j]=='J')
									{

										printf("%c%c",y[1],y[3]);
										fprintf(archivoRES,"%c%c",y[1],y[3]);
									}
								if(matrizABC[j]=='K')
									{

										printf("%c%c",y[1],y[4]);
										fprintf(archivoRES,"%c%c",y[1],y[4]);
									}
								if(matrizABC[j]=='L')
									{

										printf("%c%c",y[2],y[0]);
										fprintf(archivoRES,"%c%c",y[2],y[0]);
									}
								if(matrizABC[j]=='M')
									{

										printf("%c%c",y[2],y[1]);
										fprintf(archivoRES,"%c%c",y[2],y[1]);
									}
								if(matrizABC[j]=='N')
									{

										printf("%c%c",y[2],y[2]);
										fprintf(archivoRES,"%c%c",y[2],y[2]);
									}
								if(matrizABC[j]==165)
									{

										printf("%c%c",y[2],y[2]);
										fprintf(archivoRES,"%c%c",y[2],y[2]);
									}
								if(matrizABC[j]=='O')
									{

										printf("%c%c",y[2],y[3]);
										fprintf(archivoRES,"%c%c",y[2],y[3]);
									}
								if(matrizABC[j]=='P')
									{

										printf("%c%c",y[2],y[4]);
										fprintf(archivoRES,"%c%c",y[2],y[4]);
									}
								if(matrizABC[j]=='Q')
									{

										printf("%c%c",y[3],y[0]);
										fprintf(archivoRES,"%c%c",y[3],y[0]);
									}
								if(matrizABC[j]=='R')
									{

										printf("%c%c",y[3],y[1]);
										fprintf(archivoRES,"%c%c",y[3],y[1]);
									}
								if(matrizABC[j]=='S')
									{

										printf("%c%c",y[3],y[2]);
										fprintf(archivoRES,"%c%c",y[3],y[2]);
									}
								if(matrizABC[j]=='T')
									{

										printf("%c%c",y[3],y[3]);
										fprintf(archivoRES,"%c%c",y[3],y[3]);
									}
								if(matrizABC[j]=='U')
									{

										printf("%c%c",y[3],y[4]);
										fprintf(archivoRES,"%c%c",y[3],y[4]);
									}
								if(matrizABC[j]=='V')
									{

										printf("%c%c",y[4],y[0]);
										fprintf(archivoRES,"%c%c",y[4],y[0]);
									}
								if(matrizABC[j]=='W')
									{

										printf("%c%c",y[4],y[1]);
										fprintf(archivoRES,"%c%c",y[4],y[1]);
									}
								if(matrizABC[j]=='X')
									{

										printf("%c%c",y[4],y[2]);
										fprintf(archivoRES,"%c%c",y[4],y[2]);
									}
								if(matrizABC[j]=='Y')
									{

										printf("%c%c",y[4],y[3]);
										fprintf(archivoRES,"%c%c",y[4],y[3]);
									}
								if(matrizABC[j]=='Z')
									{

										printf("%c%c",y[4],y[4]);
										fprintf(archivoRES,"%c%c",y[4],y[4]);
									}
								
							

								}
								
							}
						}
					}
					fclose(archivoLEER);
					fclose(archivoRES);
					
						
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
						system("color 0B");
						printf("\n\n\t\t\t\t %c OBTENCI%cN DEL TEXTO ORIGINAL %c",174,162,175);
						printf("\n\n\tSi desea desencriptar a partir del archivo resultante de la opci%cn [A], oprima A. \n\n\tSi desea desencriptar a partir de una cadena encriptada que se encuentre en cualquier otro archivo, oprima B. ",162);
						printf("\n\n\n\t *Si oprime A, la desencriptaci%cn se guarda en el archivo resultante ya existente. Si selecciona B, la desencriptaci%cn se sobreescribe en el archivo en el que se encuentra su cadena encriptada* ",162,162);
						printf("\n\n\t ~ Respuesta: ");
						scanf("%s",&selec);
						selec = toupper(selec);
						if(selec == 'A')
						{
						
						system("cls");
						printf("\n\n\t\t\t\t %c OBTENCI%cN DEL TEXTO ORIGINAL %c",174,162,175);
						printf("\n\n\t Ingrese el nombre del archivo de donde se va a leer el texto (presionar enter al finalizar): ");
						scanf(" %[^\n]",&nombre_archivoRES);
						archivoRES = fopen(nombre_archivoRES,"r");	
						int contador = 0;
					    char linea[1000];
					    //VALIDA QUE EL ARCHIVO CONTENGA UN TEXTO
					    if(archivoRES == NULL)
					    {
					        printf("\n\n\t*Error, el archivo no se pudo abrir correctamente*");
					        break;
					    }
					    while(!feof(archivoRES))
						    {
					        fgets(linea, 1000, archivoRES);
					        for( i = 0; i <= strlen(linea); i++)
					        {
					            if(linea[i] == '\0')
					            contador++;
					        }
					        if(contador == 9)
					        break;
					    }
					    printf("\n\t Linea : %s", linea);
						fclose(archivoRES);
					
						printf("\n\n\tProporciona 5 letras del alfabeto (su clave para modificar texto) una tras otra, sin espacios entre cada una. Presione enter.\n\t");
						printf("\n\n\t Tus letras: ");
						
						scanf(" %[^\n]",&letras);
						for(i=0;i<78;i++)
						{
							printf("%c",196);
						}
						
						if(strlen(letras)!=5)
							{
								printf("\n\n\t\t *Se deben ingresar 5 letras, BYE* \n\n");
								for(i=0;i<78;i++)
								{
									printf("%c",196);
								}
								break;
							}
						else
							{
							strupr(letras); //Pasamos a mayus
							for(k=0;k<5;k++)
								{
									if(enie == letras[k] || ENIE == letras[k])
										{
											letras[k] = 165;
										}
								}
							strcpy(ordenado,letras); //Copiamos letras en clave para realizar el ordenamiento alfabetico
							//printf("%s",ordenado);
							archivoDES = fopen("ClaveOrdenada","w");
							for(j=0;j<28;j++)
								{
									for(i=0;i<5;i++)
										{
											if(ordenado[i]==matrizABC[j])
												{
													fprintf(archivoDES,"%c",ordenado[i]);	
												}
												
										}
									
								}
							fclose(archivoDES);
							archivoDES = fopen("ClaveOrdenada","r");
							fscanf(archivoDES,"%s",&clave);
							fclose(archivoDES);
								
							}
						archivoRES = fopen(nombre_archivoRES,"a");
						fprintf(archivoRES,"\n");
							
					    printf("\n\n Texto Original: ");
					    fprintf(archivoRES,"\nTexto Original: ");
								char matrix[6][7] = {
		
											{' ',clave[0],clave[1],clave[2],clave[3],clave[4],' '},
		
											{clave[0],'A','B','C','D','E',' '},
		
											{clave[1],'F','G','H','I','J','K'},
		
											{clave[2],'L','M','N',165,'O','P'},
		
											{clave[3],'Q','R','S','T','U',' '},
		
											{clave[4],'V','W','X','Y','Z',' '},
		
														};	
						
						for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoRES,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoRES,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoRES,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoRES,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoRES,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoRES,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoRES,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoRES,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'I');
												fprintf(archivoRES,"%c",'I');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoRES,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoRES,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoRES,"%c",'M');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'N');
												fprintf(archivoRES,"%c",'N');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoRES,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoRES,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoRES,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoRES,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoRES,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoRES,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoRES,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoRES,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoRES,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoRES,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoRES,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoRES,"%c",'Z');
											}
								
								
							}
							
							
							printf("\n\n Texto Original 2: ");
							fprintf(archivoRES,"\nTexto Original 2: ");
							
							for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoRES,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoRES,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoRES,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoRES,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoRES,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoRES,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoRES,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoRES,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'J');
												fprintf(archivoRES,"%c",'J');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoRES,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoRES,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoRES,"%c",'M');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'N');
												fprintf(archivoRES,"%c",'N');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoRES,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoRES,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoRES,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoRES,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoRES,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoRES,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoRES,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoRES,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoRES,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoRES,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoRES,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoRES,"%c",'Z');
											}
							
								
							}
							
								printf("\n\n Texto Original 3: ");
								fprintf(archivoRES,"\nTexto Original 3: ");
							
							for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoRES,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoRES,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoRES,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoRES,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoRES,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoRES,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoRES,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoRES,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'I');
												fprintf(archivoRES,"%c",'I');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoRES,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoRES,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoRES,"%c",'M');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",165);
												fprintf(archivoRES,"%c",165);
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoRES,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoRES,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoRES,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoRES,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoRES,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoRES,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoRES,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoRES,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoRES,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoRES,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoRES,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoRES,"%c",'Z');
											}
							}
								printf("\n\n Texto Original 4: ");
								fprintf(archivoRES,"\nTexto Original 4: ");
							
							for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoRES,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoRES,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoRES,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoRES,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoRES,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoRES,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoRES,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoRES,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'J');
												fprintf(archivoRES,"%c",'J');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoRES,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoRES,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoRES,"%c",'M');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",165);
												fprintf(archivoRES,"%c",165);
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoRES,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoRES,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoRES,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoRES,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoRES,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoRES,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoRES,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoRES,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoRES,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoRES,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoRES,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoRES,"%c",'Z');
											}
							}
							fclose(archivoRES);
							
							printf("\n\n");
							for(i=0;i<78;i++)
								{
									printf("%c",196);
								}
					
							
						}
						
						
						
						
						
					else
						{
							if(selec == 'B')
								{
									system("cls");
									printf("\n\n\t\t\t\t %c OBTENCI%cN DEL TEXTO ORIGINAL %c",174,162,175);
									printf("\n\n\t Ingrese el nombre del archivo donde se encuentra su cadena encriptada: ");
									scanf(" %[^\n]",&nombre_textoENCRIPTADO);
									archivoDES2 = fopen(nombre_textoENCRIPTADO,"r");
									if(archivoDES2 == NULL)
									    {
									        printf("\n\n\t\t\t*Error, el archivo no se pudo abrir correctamente*");
									        break;
									    }
									else
										{
											printf("\n\n\t ~ Proporcione 5 letras del alfabeto (su clave para modificar texto) una tras otra, sin espacios entre cada una. [Presione enter].\n\t");
											printf("\n\n\t Tu clave: ");
											scanf(" %[^\n]",&letras);
											printf("\n");
											for(i=0;i<78;i++)
											{
												printf("%c",196);
											}
											if(strlen(letras)!=5)
												{
													printf("\n\n\t\t *Se deben ingresar 5 letras, BYE* \n\n");
													for(i=0;i<78;i++)
													{
														printf("%c",196);
													}
													break;
												}
											else
												{
												strupr(letras); //Pasamos a mayus
												for(k=0;k<5;k++)
													{
														if(enie == letras[k] || ENIE == letras[k])
															{
																letras[k] = 165;
															}
													}
												strcpy(ordenado,letras); //Copiamos letras en clave para realizar el ordenamiento alfabetico
												//printf("%s",ordenado);
												archivoDES = fopen("ClaveOrdenada","w");
												for(j=0;j<28;j++)
													{
														for(i=0;i<5;i++)
															{
																if(ordenado[i]==matrizABC[j])
																	{
																		fprintf(archivoDES,"%c",ordenado[i]);	
																	}
																	
															}
														
													}
												fclose(archivoDES);
												archivoDES = fopen("ClaveOrdenada","r");
												fscanf(archivoDES,"%s",&clave);
												fclose(archivoDES);
													
												}
										char linea[1000];
										fscanf(archivoDES2,"%s",&linea);
										fclose(archivoDES2);
										
						
										}
								archivoDES2 = fopen(nombre_textoENCRIPTADO,"w");
								fprintf(archivoDES2,"%s\n",N);
										
								printf("\n\n Texto Original: ");
								
								char matrix[6][7] = {
		
											{' ',clave[0],clave[1],clave[2],clave[3],clave[4],' '},
		
											{clave[0],'A','B','C','D','E',' '},
		
											{clave[1],'F','G','H','I','J','K'},
		
											{clave[2],'L','M','N',165,'O','P'},
		
											{clave[3],'Q','R','S','T','U',' '},
		
											{clave[4],'V','W','X','Y','Z',' '},
		
														};	
												for(a=0;a<6;a++)
												{
													for(b=0;b<7;b++)
														{
															fprintf(archivoDES2,"%c",matrix[a][b]);
														}
													fprintf(archivoDES2,"\n");
												}
						fprintf(archivoDES2,"\nTexto Original: ");							
						char linea[1000];
						for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoDES2,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoDES2,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoDES2,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoDES2,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoDES2,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoDES2,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoDES2,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoDES2,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'I');
												fprintf(archivoDES2,"%c",'I');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoDES2,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoDES2,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoDES2,"%c",'M');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'N');
												fprintf(archivoDES2,"%c",'N');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoDES2,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoDES2,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoDES2,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoDES2,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoDES2,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoDES2,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoDES2,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoDES2,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoDES2,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoDES2,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoDES2,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoDES2,"%c",'Z');
											}								
							}
							printf("\n\n Texto Original 2: ");
							fprintf(archivoDES2,"\nTexto Original 2: ");
							for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoDES2,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoDES2,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoDES2,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoDES2,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoDES2,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoDES2,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoDES2,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoDES2,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'J');
												fprintf(archivoDES2,"%c",'J');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoDES2,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoDES2,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoDES2,"%c",'M');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'N');
												fprintf(archivoDES2,"%c",'N');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoDES2,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoDES2,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoDES2,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoDES2,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoDES2,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoDES2,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoDES2,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoDES2,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoDES2,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoDES2,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoDES2,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoDES2,"%c",'Z');
											}
							
								
							}
							
								printf("\n\n Texto Original 3: ");
								fprintf(archivoDES2,"\nTexto Original 3: ");
							
							for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoDES2,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoDES2,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoDES2,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoDES2,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoDES2,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoDES2,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoDES2,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoDES2,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'I');
												fprintf(archivoDES2,"%c",'I');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoDES2,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoDES2,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoDES2,"%c",'M');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",165);
												fprintf(archivoDES2,"%c",165);
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoDES2,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoDES2,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoDES2,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoDES2,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoDES2,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoDES2,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoDES2,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoDES2,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoDES2,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoDES2,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoDES2,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoDES2,"%c",'Z');
											}
							}
								printf("\n\n Texto Original 4: ");
								fprintf(archivoDES2,"\nTexto Original 4: ");
							
							for(i=0;i<1000;i+=2)
							{
								if((linea[i]==clave[0])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'A');
												fprintf(archivoDES2,"%c",'A');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'B');
												fprintf(archivoDES2,"%c",'B');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'C');
												fprintf(archivoDES2,"%c",'C');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'D');
												fprintf(archivoDES2,"%c",'D');
											}
								if((linea[i]==clave[0])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'E');
												fprintf(archivoDES2,"%c",'E');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'F');
												fprintf(archivoDES2,"%c",'F');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'G');
												fprintf(archivoDES2,"%c",'G');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'H');
												fprintf(archivoDES2,"%c",'H');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'J');
												fprintf(archivoDES2,"%c",'J');
											}
								if((linea[i]==clave[1])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'K');
												fprintf(archivoDES2,"%c",'K');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'L');
												fprintf(archivoDES2,"%c",'L');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'M');
												fprintf(archivoDES2,"%c",'M');
											}
								
								if((linea[i]==clave[2])&&(linea[i+1]==clave[2]))
											{
												printf("%c",165);
												fprintf(archivoDES2,"%c",165);
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'O');
												fprintf(archivoDES2,"%c",'O');
											}
								if((linea[i]==clave[2])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'P');
												fprintf(archivoDES2,"%c",'P');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'Q');
												fprintf(archivoDES2,"%c",'Q');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'R');
												fprintf(archivoDES2,"%c",'R');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'S');
												fprintf(archivoDES2,"%c",'S');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'T');
												fprintf(archivoDES2,"%c",'T');
											}
								if((linea[i]==clave[3])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'U');
												fprintf(archivoDES2,"%c",'U');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[0]))
											{
												printf("%c",'V');
												fprintf(archivoDES2,"%c",'V');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[1]))
											{
												printf("%c",'W');
												fprintf(archivoDES2,"%c",'W');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[2]))
											{
												printf("%c",'X');
												fprintf(archivoDES2,"%c",'X');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[3]))
											{
												printf("%c",'Y');
												fprintf(archivoDES2,"%c",'Y');
											}
								if((linea[i]==clave[4])&&(linea[i+1]==clave[4]))
											{
												printf("%c",'Z');
												fprintf(archivoDES2,"%c",'Z');
											}
								
								}
								fclose(archivoDES2);
								printf("\n\n");
								for(i=0;i<78;i++)
								{
									printf("%c",196);
								}
								
								
						}
						else
								
						{
							if((selec!='A')||(selec!='B'))
							printf("\n\n\t* No hay otra opci%cn *",162);
						}
							
					printf("\n\n\n\tPara regresar al men%c, oprima una S: ",163);
					scanf("%s", &resp);
					system("cls");
				 }}
				 
				 
				 
				 
				 
				 
					else
					{
					if(opc=='C')
						{
						return 0;
						}
						else
							{
							printf("\n\n\t\tOPCI%cN NO V%cLIDA, DEBES SELECCIONAR UNA OPCI%cN",162,160,162); 
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


