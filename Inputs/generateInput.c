#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>
#include <unistd.h>

#define ARG_ERROR -1
#define TRUE 1
#define FALSE 0

void help();

int main(int argc, char* argv[]){
  FILE *out;
  int i = 0, seed = 0, n = 1000;
  int randomize = FALSE;
  char c;
  char* name;

  if(argc < 2){
    help();
    exit(ARG_ERROR);
  }
  
  while((c = getopt(argc, argv, "f:n:s:r")) != -1){
    switch(c){
    case 'f':
      name = optarg;
      break;
    case 'n':
      n = atoi(optarg);
      break;
    case 's':
      seed = atoi(optarg);
      break;
    case 'r':
      randomize = TRUE;
      break;
    }
  }

  out = fopen(name, "w");
  
  if(out == NULL){
    puts("Unable to open file for writing.");
    help();
    exit(-2);
  }
	
  if (!randomize) {
    for (i = 0; i<n; i++) {
      fprintf(out,"%d ", i);
    }
  }
  else {
    if(seed != 0)
      srand(seed);
    else srand(time(NULL));
    for(i = 0; i < n; i++){
      int randomInt = rand();
      fprintf(out, "%d ", randomInt);
    }
  }
  fclose(out);
  return 0;
}

void help(){
  fprintf(stdout, "Use -f<file name> to inform the name pf the file you wish to print the output of the program on.\n"
	  "Use -n<size> to inform the size of the outpu. The standard size is 1000.\n"
	  "Use -r if you wish to generate a random output. If you wish to use a seed, use -s<seed>. The standard is sequential.\n"
	  );
}
	  
	  
