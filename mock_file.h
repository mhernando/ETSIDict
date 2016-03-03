#include <cstring>
#pragma once
typedef struct {
  const char **lines;
  int num; //number of lines
  int count; //current reading line
  int ccount; //current reading char
}MockFile;

int inline fgets(char *ts, int n, MockFile *file)
{
	if(file->count<file->num){
		
		int i=0;
		while(i<n){
			ts[i]=file->lines[file->count][(file->ccount)++];
			if(ts[i]=='\0'){
				(file->count)++;
				file->ccount=0;
				return 1;
			}
			if(ts[i]=='\n'){
				ts[i]='\0';
				return 1;
			}
			i++;
		}

	return 1;
	}
	return 0;
}
void inline fclose(MockFile *file)
{
	file->count=0;
	file->ccount=0;
}
MockFile inline *fopen(MockFile *file, const char *mode)
{
	file->count=0;
	file->ccount=0;
	return file;
}
