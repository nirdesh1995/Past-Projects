

/* ####################################################################################################### */

Draft 1 

//Nirdesh Bhandari 
//lab 1 x by x array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
int main () {

   int row,column;
   int i,j;

   i = j = 0;

   char array[row][column]; 

   puts(" Input number of row" ); 
   scanf( "%d" , &row);

   puts(" Input number of row" ); 
   scanf("%d" , &column);




// FOR Row major 
   
   for ( i= 0; i < row ; i++) {
   	array[i][j] = abs(rand()% 1000 );

      for ( j= 0; j < column; j++ ) {
      array[i][j] = abs(rand()% 1000 );
         
        printf("[%d][%d] = %d \t", i,j, array[i][j] ); 
      }
      j = 0; 
      printf(" Next row \n");
      
   }
   


   // For column major 

 for ( i= 0; i < column ; i++) {
   	array[i][j] = abs(rand()% 1000 );

      for ( j= 0; j < row; j++ ) {
      array[i][j] = abs(rand()% 1000 );
         
        printf("[%d][%d] = %d \t", i,j, array[i][j] ); 
      }
      j = 0; 
      printf(" Next row \n");
      
   }

   return 0;
}


/* ####################################################################################################### */


DRAFT 2 

stack size              (kbytes, -s) 8192
//Nirdesh Bhandari 
//lab 1 x by x array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
 
int main () {

   int dimension;
   

   int row,column;
   clock_t start_time, run_time;
   double time_per_sec;
   int temp;
    

   

   puts(" Input dimension of array" ); 
   scanf( " %d" , &dimension);

  char array[dimension][dimension];
  char array_2[dimension][dimension]; 


// FOR Row macolumnor 
   
   printf(" -------- ROW MAcolumnOR------\n\n");
start_time = clock();
   
    
    

   for ( row= 0; row < dimension ; row++) 
   	{
   	array[row][column] = rand()% 1000 ;

      for ( column= 0; column < dimension; column++ ) {
      array[row][column] = rand()% 1000 ;
         
        printf("[%d][%d] = %d \t", row,column, array[row][column] ); 
      }
     
      printf(" \n Next row \n");
      
   }
   run_time = clock() - start_time;
   time_per_sec = ((double)run_time)/CLOCKS_PER_SEC; 

   printf(" \n\n Time for ROW MAJOR %lf ", time_per_sec);

printf(" \n\n -------- COLUMN MAcolumnOR------\n\n");
   // For column macolumnor 



start_time = clock();
    
    

 for ( column= 0; column < dimension ; column++) {
   	array[row][column] = rand()% 1000 ;

      for ( row= 0; row < dimension; row++ ) {
      array[row][column] = rand()% 1000 ;
         
        //printf("[%d][%d] = %d \t", row,column, array[row][column] ); 
      }
           // printf(" \n Next row \n");
      
   }
   
   run_time = clock() - start_time;
   time_per_sec = ((double)run_time)/ CLOCKS_PER_SEC; 
   printf(" \n\n Time for column major %lf \n \n ", time_per_sec);

   return 0;
}


/* ####################################################################################################### */


//printf("[%d][%d] = %c \t", row,column, array_2[row][column] ); 

//Nirdesh Bhandari 
//lab 1 x by x array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
 
 // Prototying the functions so that C knows they exist. 

void create_array_row( int dimension);
void create_array_column( int dimension);

// Global Varivles go here 
int row,column;

int main () {

   
   
   double diff_t;
   int dim;
    

   puts(" Input dimension of array" ); 
   scanf( " %d" , &dim);
    clock_t start_t = clock();
    create_array_column(dim);
    diff_t  = (double)(clock() - start_t)/ (double)CLOCKS_PER_SEC ;

  printf(" \n\n Time for ROW MAJOR %f ", diff_t);
  
  //char array_2[dimension][dimension]; 




   return 0;
}

void create_array_row(int dimension){

   
   printf(" -------- ROW MAJOR CREATED ------\n\n");
  
   char array[dimension][dimension];
   

  
   for ( row= 0; row < dimension ; row++) {

      for ( column= 0; column < dimension; column++ ) {
        array[row][column] = 'A' ;
         
        printf("[%d][%d] = %c \t", row,column, array[row][column] ); 
      }
     
      printf(" \n Next row \n") ;
      
   }
   
   printf(" \n\n THE VOID RAN !!! ");
   return;
}

void create_array_column( int dimension) {
printf(" -------- COLUMN MAJOR CREATED ------\n\n");
  
   char array_2[dimension][dimension];
   

  
   for ( column= 0; column < dimension ; column++) {

      for ( row= 0; row < dimension; row++ ) {
        
         array_2[row][column] = 'B' ;
         
        printf("[%d][%d] = %c \t", row,column, array_2[row][column] ); 
      }
     
      printf(" \n Next row \n") ;
      
   }
   
   printf(" \n\n THE VOID RAN !!! ");
   return;

}



/* ####################################################################################################### */

Draft 4 cleaned up and debug lines removed, code made easier to read. 


//Nirdesh Bhandari 
//lab 1 x by x array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
 
 // Prototying the functions so that C knows they exist. 

void create_array_row( int dimension);
void create_array_column( int dimension);


// Global Varivles go here.
int row,column;



int main () 
{

   double diff_t;
   int dim,i;
   float avg_row_maj, avg_row_min;
    

   puts(" Input dimension of array" ); 
   scanf( " %d" , &dim);
   
   for(i = 0; i <3 ; i++ )
   {

      clock_t start_t = clock();
      create_array_row(dim);
      diff_t  = (double)(clock() - start_t)/ (double)CLOCKS_PER_SEC ;
      printf(" {MAJOR}Run no %d::: %lf s\n",i, diff_t);
         avg_row_maj += diff_t;

   } 
   printf(" \n AVERAGE for row MAJOR ::: %lf s\n\n", avg_row_maj/3);


   for(i = 0; i <3 ; i++ )
   {
   
      clock_t start_t = clock();
      create_array_column(dim);
      diff_t  = (double)(clock() - start_t)/ (double)CLOCKS_PER_SEC ;
      printf(" {MINOR}Run no %d::: %lf s\n",i, diff_t);
         avg_row_min += diff_t;
   }
   printf(" \n AVERAGE for row MINOR::: %lf s \n", avg_row_min/3);


   return 0;
}



void create_array_row(int dimension)
{

   char array[dimension][dimension];
   
   for ( row= 0; row < dimension ; row++) 
   {
      for ( column= 0; column < dimension; column++ )
      {
         array[row][column] = 'A' ;
      }   
      
   }
   
   return;

}


void create_array_column( int dimension)
{

   char array_2[dimension][dimension];
  
   for ( column= 0; column < dimension ; column++) 
   {
      for ( row= 0; row < dimension; row++ )
      {
         array_2[row][column] = 'B' ;
      } 
   }
   
   return;

}


/* ####################################################################################################### */
//Nirdesh Bhandari 
//lab 1 x by x array 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
 

void create_array_row( int dimension);
void create_array_column( int dimension);
void time_individual_row( int dimension);
void time_individual_column( int dimension);

 
int row,column;
clock_t start_ind;
double diff_ind, sum_ind;


/*--------------------------------------------MAIN-----------------------------------------------*/

int main () 
{

   double diff_t, bogomips;
   int dim,i,j,x;
   float avg_row_maj, avg_row_min;
   int dim_test[] = {100, 1000, 2000} ; 
   char hostname[1024];
   double bogomips_store[] = {1.0,5599.2};


   for (x=0 ; x<2 ; x++)
   { 

      char *time_type;
      printf("\n\n");
      
      if (x == 0){ 
         time_type = "Raw \0";
         bogomips = bogomips_store[x];

      } else {
         time_type = "Normalized \0";
         bogomips = bogomips_store[x];
      }

      gethostname(hostname, 1024);
      printf("\t \t %s --  %s \n", hostname,time_type );
      printf("\t \t %dX%d \t %dX%d \t %dX%d \n", dim_test[0],dim_test[0],
                                                dim_test[1],dim_test[1],
                                                dim_test[2],dim_test[2]);
      printf(" x -> y");


      for(j = 0; j <3 ; j++ )
      {
         
         dim = dim_test[j];
         for(i = 0; i <3 ; i++ )
         {

            clock_t start_t = clock();
            create_array_row(dim);
               diff_t  = (double)(clock() - start_t)/CLOCKS_PER_SEC ;
               avg_row_maj += diff_t;
         } 
         printf(" \t %.5lf ms", (avg_row_maj*1000)/(3*bogomips));

      }

      printf(" \n y -> x ");

      for(j = 0; j <3 ; j++ )
      {
         dim = dim_test[j];
         for(i = 0; i <3 ; i++ )
         {
            clock_t start_t = clock();
            create_array_column(dim);
               diff_t  = (double)(clock() - start_t)/ CLOCKS_PER_SEC;
               avg_row_min += diff_t;
         }
         
         printf(" \t %.5lf ms ", (avg_row_min *1000) /(3* bogomips));
      }

   }

   time_individual_row(dim);
   time_individual_column(dim);

   return 0;
}


/*------------------------------------------- ROW TRAVERSAL ------------------------------------------------*/

void create_array_row(int dimension)
{
   char array[dimension][dimension];
   
   for ( row= 0; row < dimension ; row++) 
   {
      for ( column= 0; column < dimension; column++ ){ array[row][column] = 'A' ; }    
   }
   return;
}




/*------------------------------------------ COLUMN TRAVERSAL -------------------------------------------------*/

void create_array_column( int dimension)
{
   char array_2[dimension][dimension];
  
   for ( column= 0; column < dimension ; column++) 
   {
      for ( row= 0; row < dimension; row++ ) { array_2[row][column] = 'B' ; } 
   } 
   return;
}



/*------------------------------------------ROW <INDIVIDUAL> -------------------------------------------------*/

void time_individual_row( int dimension)
{

   char array[dimension][dimension];

   for ( row= 0; row < dimension ; row++) 
   {
      for ( column= 0; column < dimension; column++ )
      { 
         start_ind= clock();
         array[row][column] = 'A' ; 
         diff_ind  = (double)(clock() - start_ind)/ CLOCKS_PER_SEC ;
            sum_ind += diff_ind;
      }    
   }
   printf("\n\nINDIVIDUAL SUM_MAJOR (%dX%d) :: %.5lf ms", dimension,dimension, (sum_ind*1000)/dimension);
   return;

}




/*-------------------------------------------COLUMN <INDIVIDUAL---------------------------------------*/

void time_individual_column( int dimension)
{

  char array_2[dimension][dimension];
  
   for ( column= 0; column < dimension ; column++) 
   {
      for ( row= 0; row < dimension; row++ ) 
    { 
      start_ind= clock();
      array_2[row][column] = 'B' ; 
      diff_ind  = (double)(clock() - start_ind)/CLOCKS_PER_SEC ;
         sum_ind += diff_ind;
     } 
   } 
   printf("\nINDIVIDUAL SUM_MINOR (%dX%d) :: %.5lf ms\n", dimension,dimension, (sum_ind*1000)/dimension );
   return;

}

/*-------------------------------------------------------------------------------------------*/