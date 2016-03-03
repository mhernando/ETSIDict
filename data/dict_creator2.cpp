#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../mock_file.h"
#define MAX_LINE 500
#define LINE_END "\\r\\n"
void printvar(FILE *fin, FILE *fout, const char *prefix, const char *name)
{
 fprintf(fout,"\nconst char *%s_%s_strings[]={",prefix,name);
  //   
  char buf[255];
  bool first=true;
  int count=0;
  while(fgets(buf,254,fin)) {
	  int tam=strlen(buf);
	  if((tam>0)&&(buf[tam-1]=='\n'))buf[tam-1]='\0';
	  count++;
	  if(!first)fprintf(fout,",\n");
	  fprintf(fout, "\"%s\"",buf);
	  first=false;
  }
  fprintf(fout,"\"\n};\n\n");
  fprintf(fout, "MockFile %s_%s_file = {%s_%s_strings, %d, 0};\n",prefix,name,prefix,name,count);
}

void printvar2(FILE *fin, FILE *fout, const char *prefix, const char *name)
{
 fprintf(fout,"\nconst char *%s_%s_strings[]={",prefix,name);
  //   
  char buf[255];
  char buff2[2000];
  bool first=true,init=true;
  int count=0; //cuenta el numero de lineas
  int numstrings=0; //cuenta el numero de cadenas
  int stringlen=0;
  while(fgets(buf,254,fin)) {
	  int tam=strlen(buf);
	  if((tam>0)&&(buf[tam-1]=='\n'))buf[tam-1]='\0';
	  stringlen+=tam;
	  count++;
	  if(stringlen<MAX_LINE){
	      if(init){
			  if(!first)fprintf(fout,",\n");
			  fprintf(fout,"\"");
			  init=false;
			  first=false;
		  }
		  fprintf(fout, "%s\\n",buf);
	  }
	  else
	  {
		 fprintf(fout, "%s\"",buf);
		 init=true;	 
		 stringlen=0;
		 numstrings++;
	  }

	 
	  
  }
  fprintf(fout,"\"\n};\n\n");
  fprintf(fout, "MockFile %s_%s_file = {%s_%s_strings, %d, 0, 0};\n",prefix,name,prefix,name,numstrings);
}
//a simple main to create de header file with the mock of a afxfile and dict file
int 
main(int argc, char** argv)
{


    FILE* fdic;
	FILE* faff;
	FILE* fout;

  /* first parse the command line options */
  /* arg1 - affix file, arg2 dictionary file, arg3 - file of words to check */
  if(argc<4) printf("ERROR you have to include: affix_file dict_file output_file");

  if((faff = fopen(argv[1],"r"))==0){
	  printf("ERROR: could not open aff file: %s", argv[1]);
	  exit(1);
  }
  if((fdic = fopen(argv[2],"r"))==0){
	  printf("ERROR: could not open dic file: %s", argv[2]);
	  fclose(faff);
	  exit(1);
  }
  char fname[100];
  sprintf(fname,"%s.h",argv[3]);
  if((fout = fopen(fname,"w"))==0){
	  printf("ERROR: could not open output file: %s", fname);
	  fclose(faff); 
	  fclose(fdic);
	  exit(1);
  }
  //afvar
  printvar2(faff,fout,"aff", argv[3]);
  printvar2(fdic,fout,"dic", argv[3]);
  fclose(faff);
  fclose(fdic);
  fclose(fout);

}