#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int collatz(int randomNumber)
{
   int steps = 0;
   while(randomNumber != 1)
   {
      if(randomNumber % 2 == 0)
      {
         randomNumber = randomNumber / 2;
      }
      else if(randomNumber % 2 == 1)
      {
         randomNumber = (randomNumber * 3) + 1;
      }

      steps++;
   }
   return steps;
}

typedef struct{
   int key;
   int value;
} cache_entry_t;



int main(int argc, char *argv[]) {

   int nTerms = 0;
   int min = 0;
   int max = 0;

   sscanf(argv[1], "%d", &nTerms); // scan for input
   sscanf(argv[2], "%d", &min);
   sscanf(argv[3], "%d", &max);

   srand(time(NULL));
   FILE *file = fopen("test.csv", "w"); 

   clock_t meanTimeStart = clock();

   for (int i = 0; i < nTerms; i++)
   {

      clock_t start = clock();
 

      int randomNumber = (rand() % (max- min + 1)) + min;
      int collatzSteps = collatz(randomNumber);



      clock_t finish = clock();
      double runTime = (double)(finish - start) / CLOCKS_PER_SEC; 

      fprintf(file, "%d,%d,%f\n", randomNumber, collatzSteps, runTime);



   }


   
   clock_t meanTimeFinish = clock();
   double meanRunTime = (double)(meanTimeFinish - meanTimeStart) / CLOCKS_PER_SEC; 
   double officialMeanTime = meanRunTime / nTerms;

   fprintf(file, "\nMean time: %f\n", officialMeanTime);

   fclose(file);
   return 0;



}