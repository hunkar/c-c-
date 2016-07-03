#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void sansTopu(void);
void sayisalLoto(void);
void superLoto(void);

int main()
{
    
    char ctercih;
    
    tercihYap:
    
    printf("Lutfen Hangi Oyunu Oynayacaginizi seciniz: \n");			//Show option to user
    printf("1) Sans Topu\n2) Sayisal Loto\n3) Super Loto\n");
    
    ctercih = getch();
    
    system("CLS");
    
    switch(ctercih)
    {
            case '1': sansTopu();
                 break;
            case '2': sayisalLoto();
                 break;
            case '3': superLoto();
                 break;
            default: printf("Yanlis Tercih Yaptiniz\n");
                     system("CLS");
                     goto tercihYap;
                     break;
    }
    
    printf("Yeni Tahmin Istiyorsaniz 1'e Basin");						//for new options screen
    ctercih = getch();
    
    
    if(ctercih == '1')
    {
              system("CLS");
              goto tercihYap;
    }

	return 0;
}

void sansTopu()								//This game choose 5 + 1 random number. We can create estimates more than 1.
{
	srand(time(NULL));
	int kolon = 0, tut[6];
	printf("Kac kolon olsun: ");
               
	scanf("%d", &kolon);		//size of esimates 
               
	for(int sayac=0; sayac<kolon; sayac++)
	{
		for(int sayici=0; sayici<5; sayici++)
		{ 
			tut[sayici] =  rand()%34+1; 
            
            for(int say = 0; say < sayici; say++)
            
            if(tut[sayici] == tut[say])
            {
				sayici--;
				continue;               
            } 
            
            tut[5] = rand()%14+1;

		}
                       
                
               
		printf("%2d - %2d - %2d - %2d - %2d + %2d\n", tut[0], tut[1], tut[2], tut[3], tut[4], tut[5]);
     }
}
     
void sayisalLoto()								//This game choose 6 random number. We can create estimates more than 1.
{
	srand(time(NULL));
	int kolon = 0, tut[6];
	printf("Kac kolon olsun: ");
               
	scanf("%d", &kolon);
               
	for(int sayac=0; sayac<kolon; sayac++)
	{
		for(int sayici=0; sayici<6; sayici++)
		{ 
			tut[sayici] =  rand()%49+1; 
			
			for(int say = 0; say < sayici; say++)
			if(tut[sayici] == tut[say])
			{
				sayici--;
				continue;               
			} 
		}
        
        printf("%2d - %2d - %2d - %2d - %2d - %2d\n", tut[0], tut[1], tut[2], tut[3], tut[4], tut[5]);
               
	}
}
                  
     

void superLoto()								//This game choose 6 random number. We can create estimates more than 1.
{
	srand(time(NULL));
	int kolon = 0, tut[6];
	printf("Kac kolon olsun: ");
               
	scanf("%d", &kolon);
               
	for(int sayac=0; sayac<kolon; sayac++)
	{
		for(int sayici=0; sayici<6; sayici++)
		{ 
			tut[sayici] =  rand()%54+1; 
                              
			for(int say = 0; say < sayici; say++)
				if(tut[sayici] == tut[say])
				{
					sayici--;
					continue;               
				} 
		}
                       
		printf("%2d - %2d - %2d - %2d - %2d - %2d\n", tut[0], tut[1], tut[2], tut[3], tut[4], tut[5]);
	}
}
