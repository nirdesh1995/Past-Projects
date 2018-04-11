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




/*-------------------------------------------COLUMN <INDIVIDUAL> ------------------------------------------------*/

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