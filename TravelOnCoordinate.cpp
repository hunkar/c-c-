/*Hünkar PURTUL*/
/*hunkarpurtul.blogspot.com*/
/*02.07.2016*/
/*Travelling on coordinate system with w,a,s,d keys*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int x=0, y=0; 
	char secim;
	printf("x=%d  y=%d\n", x, y);

	do
	{
		secim=getch();		//We get route in this line
		switch(secim)
		{ 
			case 'w':			//W can move to y+ route on the coordinate
			case 'W': ++y;
			break;
			
			case 'a':			//A can move to x- route on the coordinate
			case 'A': --x;   
			break;

			case 's':			//S can move to y- route on the coordinate
			case 'S': --y;
			break;

			case 'd':			//D can move to x+ route on the coordinate
			case 'D': ++x;
			break;

			default: 	x=x; 	//Ignore another entrance
						y=y;
		}

		system("CLS");						//Clear window
		printf("x=%d  y=%d\n", x, y);		//Write new coordinate    
	}
	while(1);		//Do it infinitive


	getch();
	return 0;
}
