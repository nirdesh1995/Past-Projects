
#include <stdio.h>     			

int main(void)                        //Main function
{ 

int x=0,y=1,counter=0,n,z;                    //variable declarations 

printf("Enter Non Negative integer number ::\n");	//prompt user to input integer 
scanf("%d", &n);                                 //store input in n 


while(counter <= n)         
	{

		printf("F%d = %d\n",counter, x);          //Print counter and sequence  

		z = x +y ;                          //set z to sum of x and y
		x = y ;
		y = z ;        
		counter++;                                //increment counter

	}
 printf("Thank you for running this program\n\n");
}