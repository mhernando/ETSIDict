
#include "spanish.h"
#include "myspell.h"
#include "mock_file.h"
#include "ES_dict.h"
#include <iostream>
Spanish::Spanish(){
	pMS = new MySpell(&aff_ES_dict_file,&dic_ES_dict_file);
	if(0){
	for(int i=0;i<aff_ES_dict_file.num;i++)
		std::cout<<aff_ES_dict_file.lines[i];
	for(int i=0;i<dic_ES_dict_file.num;i++)
		std::cout<<dic_ES_dict_file.lines[i];
	}
}
Spanish::~Spanish()
{
	delete pMS;
}
bool Spanish::check(const char *word){
	int dp = pMS->spell(word);
    if (dp) return true;
	return false;
}
bool Spanish::check(const char *init, int n)
{
	if(n>=MAX_WORD_SIZE)return false;
	strncpy(aux_word,init,n);
	aux_word[n]='\0';
	return check(aux_word);
}
