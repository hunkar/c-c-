/*Hünkar PURTUL*/
/*hunkarpurtul.blogspot.com*/
/*03.07.2016*/
/*Which character how many times.*/
#include <stdio.h>
#include <conio.h>

int main ()
{
	char cumle[120];		//array which is from user
	char alfabe[63]="ABCDEFGHIJKLMNOPRSTUVYZWXQabcdefghijklmnoprstuvyzwxq0123456789";	//Our template array
	int toplam[63];			//score array
	int i, j;

	for(i=0; i<63; i++)		//set to zero all array
		toplam[i]=0;

	printf("Bir cumle giriniz: ");
	gets(cumle);
	
	for(i=0; cumle[i]!='\0'; i++)			//loop until end of the character array 
	{
         for(j=0; alfabe[j]!='\0'; j++)			//loop till end of the template array
			{
				if(cumle[i]==alfabe[j])			//if template and character equal, then this index increase 1
				toplam[j]=toplam[j]+1;         
			}
	}

	for(i=0; i<63; i++)		
	{
		if(toplam[i]>0)		//print letters if they have value more that zero in score array
			printf("\n%c harfinden %d tane vardir.", alfabe[i], toplam[i]);
	}
		
	getch();
}
