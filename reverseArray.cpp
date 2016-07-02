/*Hünkar PURTUL*/
/*hunkarpurtul.blogspot.com*/
/*02.07.2016*/
/*Reverse of array which has max 10 elements*/
#include <stdio.h>
#include <conio.h>


int main()
{
	int duz[10], ters[10], *p, i;
	
	for(i=0; i<10; i++)
	{
		printf("10 Sayilik dizinin %d. sayisini girin: ", i+1);
		scanf("%d", &duz[i]);
	}    

	printf("\nGirilen dizi: \n");

	for(i=0; i<10; i++)
	{
		printf("%d  ", duz[i]);         
	}
	
	p=&duz[9];

	for(i=0; i<10; i++) 		//p is pointer to last index of normal array and decrease step by step to first elements address
	{							
		ters[i] = *p; 			
		p--;         
	}

	printf("\nGirilen dizinin tersten yazilisi: \n");

	for(i=0; i<10; i++)
	{
		printf("%d  ", ters[i]);         
	}
    
	getch();    
}
