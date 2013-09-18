#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "rabinFunctions.h"

void help();

int main(int argc, char* argv[]){
  char c;
  FILE* input = NULL;
  FILE* output = NULL;
  Boolean runtime = TRUE, single = FALSE, result;
  unsigned long p = 2;
  int runs = 30, primes = 0, composites = 0, i =0;
  clock_t start, end;
  double elapsed = 0, mid = 0, parcial = 0;

  if(argc < 2){
    help();
  }
  
  while( (c = getopt(argc, argv, "t:f:o:r:y")) != -1){
    switch(c){
    case 'f':
      input = fopen(optarg, "r");
      break;
    case 't':
      p = atoi(optarg);
      single = TRUE;
      break;
    case 'o':
      output = fopen(optarg, "w");
      break;
    case 'y':
      runtime = FALSE;
      break;
    case 'r':
      runs = atoi(optarg);
      break;
    default:
      help();
      break;
    }
  }
  
  if(!single){
    if(input == NULL){
      puts("Unable to open file for reading.");
      help();
    }
    while(fscanf(input, "%lud", &p) != EOF){
      parcial = 0;
      for(i = 0; i < 120; i++){
	start = clock();

	result = millerRabinTest(p, runs);
	
	end = clock();

	mid = (double)(end - start)/CLOCKS_PER_SEC;
     
	parcial += mid;
      }
      
      elapsed += parcial;
      if(result){
	if(!output) fprintf(stdout, "%ld %f\n", p, parcial);
	else fprintf(output, "%ld %f.\n", p, parcial);
	primes++;
      }
      else{
	if(!output) fprintf(stdout, "%ld %f.\n", p, parcial);
	else fprintf(output, "%ld %f.\n", p, parcial);
	composites++;
      }
    }
    
    /*fprintf(stdout, "There were %d composites and %d primes.\n", composites, primes);*/
    if(runtime) fprintf(stdout, "TIME: %f (reading and printing times not included)\n", elapsed);

  }

  else{
    start = clock();
    result = millerRabinTest(p, runs);

    end = clock();

    elapsed = (double)(end - start)/CLOCKS_PER_SEC;

    if(result){
      if(!output) fprintf(stdout, "%ld %f.\n", p, elapsed);
      else fprintf(output, "%ld %f.\n", p, elapsed);
    }
    else{
      if(!output) fprintf(stdout, "%ld is %f.\n", p, elapsed);
      else fprintf(output, "%ld is %f.\n", p, elapsed);
    }

    if(runtime) fprintf(stdout, "TIME: %f (reading and printing times not included)\n", elapsed);

  }

  if(input) fclose(input);
  if(output) fclose(output);

  return 0;
}

void help(){
  fprintf(stdout, "Use -t<number> to test the primality of a single number.\n"
	  "Use -f<input file name> to read the numbers from a file. The output will the STDOUT.\n"
	  "To redirect outuput, use -o<output file name>.\n"
	  "The time consumed is sent to STDOUT. To supress, use -y.\n"
	  "The standard number of runs is 30. Change it using -r<nRuns>.\n"
	  );
  exit(-1);
}
    
  
  
