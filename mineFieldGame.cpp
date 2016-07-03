/*Hünkar PURTUL*/
/*hunkarpurtul.blogspot.com*/
/*03.07.2016*/
/*Minefield game in console. Create minefield and get x-y positions from console*/

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>



int main(){
    int size=1, mayinSayisi=1, x=0, y=0;
    int sayac1, sayac2;
    int enbuyuk;
    
    FILE *maxpuan;
    
    
	do{
		maxpuan = fopen("rekor.txt","r");		//get max score from file
		fscanf(maxpuan, "%d", &enbuyuk);
		fclose(maxpuan);
		printf("Mayin tarlanizin boyutunu giriniz: ");		//get size of field which have to be smaller than 20. 
		scanf("%d", &size);
	} while(size<0||size>20);

    int mayinTarlasi[size][size];

	do{
		printf("Kac mayin olsun: ");                           
		scanf("%d", &mayinSayisi);						//get mine size 
	} while(mayinSayisi>size*size || mayinSayisi<0);
    
    for(sayac1=0; sayac1<size; sayac1++)
        for(sayac2=0; sayac2<size; sayac2++)
           mayinTarlasi[sayac1][sayac2]=0;
 
 
	srand(time(NULL));
 
	for(sayac1=0; sayac1<mayinSayisi; sayac1++)		//we put mines to field randomly. we put 100 to index which has mine 
	{
		x=rand()%size;
		y=rand()%size;
    
		if(mayinTarlasi[x][y]!=100)
			mayinTarlasi[x][y]=100; 
		else sayac1--;
     }
 
	for(sayac1=0; sayac1<size; sayac1++)			//we decrease 1 neighbours of mines
        for(sayac2=0; sayac2<size; sayac2++)
        {
            if(mayinTarlasi[sayac1][sayac2]>=100)
            {
                  if(sayac1-1>=0) mayinTarlasi[sayac1-1][sayac2]++;
                  if(sayac2-1>=0) mayinTarlasi[sayac1][sayac2-1]++;
                  if(sayac1+1<size) mayinTarlasi[sayac1+1][sayac2]++;
                  if(sayac2+1<size) mayinTarlasi[sayac1][sayac2+1]++;
            }
        }     


	int puan=0;
	char matrisimiz[size][size];
	int xkoordinati, ykoordinati;    
    
    for(sayac1=0; sayac1<size; sayac1++)
        for(sayac2=0; sayac2<size; sayac2++)			//We set all matrix to 177. It is square on the ASCII table
           {
                      matrisimiz[sayac1][sayac2]=177;
           }
	
	xkoordinati=0; ykoordinati=0;

	while(1)
	{
     system("CLS");
     printf("\n\n");
         
     for(sayac1=0; sayac1<size; sayac1++)			//We print all matrix to screen
        {
			for(sayac2=0; sayac2<size; sayac2++) 
			{
						if(sayac1==0&&sayac2==0)
						{
						  printf("    ");
						  
						  for(int sayac3=0; sayac3<size; sayac3++) 
							printf("%3d", sayac3+1); printf("\n\n");
						}
					
						if(sayac2==0)
						{
							printf("%3d ", sayac1+1);
						}
						
						printf("%c%c%c", 177, 177, matrisimiz[sayac1][sayac2]);
			}
			
			printf("\n");
         }
	do{													//get coordinates from user
		printf("\nX Koordinatini giriniz: ");         
		scanf("%d", &xkoordinati);
		printf("\nY Koordinatini giriniz: ");
		scanf("%d", &ykoordinati);
	}
	while(xkoordinati>size || xkoordinati<1 || ykoordinati>size || ykoordinati<1);
  
     
     switch(mayinTarlasi[xkoordinati-1][ykoordinati-1])
     {
		case 0: matrisimiz[xkoordinati-1][ykoordinati-1] = '0'; break;
			case 1: matrisimiz[xkoordinati-1][ykoordinati-1] = '1'; break;
				case 2: matrisimiz[xkoordinati-1][ykoordinati-1] = '2'; break;
					case 3: matrisimiz[xkoordinati-1][ykoordinati-1] = '3'; break;
						case 4: matrisimiz[xkoordinati-1][ykoordinati-1] = '4'; break;
     }
     

     if(mayinTarlasi[xkoordinati-1][ykoordinati-1]>=5)    		//game over if user find bomb
        {
			printf("\nBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOMMMMMMM!!!!!!!!!");
			printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
			printf("\nMayina Bastin Oldun!!!\nPUANIN: %d", puan);
			
			if(puan>enbuyuk)		//print if user did high score
			{
				enbuyuk=puan;
				maxpuan=fopen("rekor.txt","w"); 
				fprintf(maxpuan, "%d", enbuyuk); 
				printf("\nEn yuksek puan senin!");
				fclose(maxpuan);
			}
			
			printf("\n\nREKOR=%d", enbuyuk);
			getch();
			system("CLS");
			break;
         }
     else
     {
          puan=puan+mayinTarlasi[xkoordinati-1][ykoordinati-1]+2;		//score calculate
     }
         
   }
         

     
     
     system("CLS");							//Clear screen and print new version of matrix again
     for(sayac1=0; sayac1<size; sayac1++)
     {
        for(sayac2=0; sayac2<size; sayac2++)
        {
           if(sayac1==0&&sayac2==0)
           {
			   printf("    ");
			   for(int sayac3=0; sayac3<size; sayac3++) 
					printf("%3d", sayac3+1); printf("\n\n");
			}
               
            if(sayac2==0)
            {
				printf("%3d ", sayac1+1);
			}
           
           if(mayinTarlasi[sayac1][sayac2]>=100)
           {printf("%3s", "M");}
           else {printf("%3d", mayinTarlasi[sayac1][sayac2]);}
        
        }
        printf("\n");
     }


	printf("\n\nYeniden baslamak icin E tusuna basin?");

	char tercih;
	tercih=getch();

	if(tercih=='e'||tercih=='E')
	{
		system("CLS"); main();			//Call main function as a recursive if user want to continue. 
	}
	else return 0; 
}
