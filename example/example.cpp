#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "lib/ETSIDICT.h"
const char *test[]={
"escucha",
"Escuchando",
"Escucha.",
"estudiando",
"dear",
"yuyuyu",
"desvo",
"desbo"
};
const char *test2="estopruebadepalabrasencadenadas";
int main(int argc, char** argv)
{
    FILE* fin;

	Spanish diccionario;
	for(int i=0;i<8;i++){
		if(diccionario.check(test[i]))printf("%s es correcto\n", test[i]);
		else printf("%s NO es correcto\n", test[i]);
	}
	for(int i=0;i<8;i++){
		if(diccionario.check(test2+i,6))printf("En %s empieza una palabra de 6 letras\n", test2+i);
		
	}
/*
  if(argc<2) {printf("ERROR you have to include a file with words to check");
  exit(1);}

 
  // open the words to check list 
  fin = fopen(argv[1],"r");
  if (!fin) {
    fprintf(stderr,"Error - could not open file of words to check\n");
    exit(1);
  }

   

    int k;
    bool dp;
    char buf[101];

    while(fgets(buf,100,fin)) {
      k = strlen(buf);
      *(buf + k - 1) = '\0';
       dp = diccionario.check(buf);
       if (dp) {
          fprintf(stdout,"\"%s\" is okay\n",buf);
          fprintf(stdout,"\n");
       } else {
          fprintf(stdout,"\"%s\" is incorrect!\n",buf);
  
       }
    }

    
    fclose(fin);
	*/
    return 0;
}

