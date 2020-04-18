/**************************************************************************************
C Program to Implement Johnson Trotter algorithm to generate permutations.
**************************************************************************************/

#include <stdio.h>
#include <conio.h>

int NN, i, count=0;
int p[100], pi[100];      
int dir[100];             

void PrintPerm()
{
   int i;
   
   count = count + 1;
   printf( "[%2d] ", count );
   
   for (i=1; i <= NN; ++i)
      printf( "%d", p[i] );
} 

void PrintTrans( int x, int y )
{
   printf( " (%d %d)", x, y );
   printf( "\n" );
} 

void Move( int x, int d )
{
   int z;
   PrintTrans( pi[x], pi[x]+d );
   z = p[pi[x]+d];
   p[pi[x]] = z;
   p[pi[x]+d] = x;
   pi[z] = pi[x];
   pi[x] = pi[x]+d;
}

void Perm ( int n )
{
   int i;
   if (n > NN)
      PrintPerm();
   else
   {
      Perm( n+1 );
      for (i=1; i<=n-1; ++i)
      {
         Move( n, dir[n] );
         Perm( n+1 );
      }
      dir[n] = -dir[n];
   } 
} 

int main()
{
   printf( "Enter the Value of n : " );
   scanf( "%d", &NN );
   printf( "\n" );
   for (i=1; i<=NN; ++i)
   {
      dir[i] = -1; p[i] = i;
      pi[i] = i;
   }
   Perm ( 1 );
   printf( "\n" );
   return 0;
} 

/**********************************************************
Output:

Enter the Value of n : 4                                                                                                        
                                                                                                                                
[ 1] 1234 (4 3)                                                                                                                 
[ 2] 1243 (3 2)                                                                                                                 
[ 3] 1423 (2 1)                                                                                                                 
[ 4] 4123 (4 3)                                                                                                                 
[ 5] 4132 (1 2)                                                                                                                 
[ 6] 1432 (2 3)                                                                                                                 
[ 7] 1342 (3 4)                                                                                                                 
[ 8] 1324 (2 1)                                                                                                                 
[ 9] 3124 (4 3)                                                                                                                 
[10] 3142 (3 2)                                                                                                                 
[11] 3412 (2 1)                                                                                                                 
[12] 4312 (4 3)                                                                                                                 
[13] 4321 (1 2)                                                                                                                 
[14] 3421 (2 3)                                                                                                                 
[15] 3241 (3 4)                                                                                                                 
[16] 3214 (1 2)                                                                                                                 
[17] 2314 (4 3)                                                                                                                 
[18] 2341 (3 2)                                                                                                                 
[19] 2431 (2 1)                                                                                                                 
[20] 4231 (3 4)                                                                                                                 
[21] 4213 (1 2)                                                                                                                 
[22] 2413 (2 3)                                                                                                                 
[23] 2143 (3 4)                                                                                                                 
[24] 2134
**********************************************************/
