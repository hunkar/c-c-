/* Hünkar PURTUL */
/* 02.07.2015    */
/* EUCLID OBEB ALGORITHM */

#include <iostream>
using namespace std;


int main()
{
    
    int a,b, temp;
    
    cout<<"a: ";
    cin>>a; 
    
    cout<<"b: ";
    cin>>b;    

	//a need to be bigger one
    if(a < b)
    {
		temp = a;
		a = b;
		b = temp;     
    }        
    
    //a equal to a-b until a==b
    while(a != b)
    {
            a = a-b;
            if(a < b)
            {
                 temp = a;
                 a = b;
                 b = temp;     
            }        
    }
    
    cout<<"obeb: "<< a;
    
    system("pause");
    return 0;    
}
