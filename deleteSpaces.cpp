/*Hünkar PURTUL*/
/*hunkarpurtul.blogspot.com*/
/*02.07.2016*/
/*Delete spaces in the char array*/

#include <stdio.h>
#include <conio.h>



int main()
{
	char dizgi[100];	//Char array with 100 limit.
	int i, j;
	
	printf("Enter the array: \n");
	gets(dizgi);

	for(i=0; dizgi[i]!='\0'; i++)		//first loop till the end of char array
	{
		if(dizgi[i]==' ')
		for(j=i; dizgi[j]!='\0'; j++)	
			dizgi[j]=dizgi[j+1];		//all elements which are after the space swap to before one index
	}
	
	puts(dizgi);		//Show output array
	getch();
	return 0;    
}
