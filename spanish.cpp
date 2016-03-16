
#include "spanish.h"
#include "myspell.h"
#include "mock_file.h"
#include "ES_dict.h"
#include <iostream>
#include <string>
using std::string;
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
	char aux_word[2000];
	if(n>=2000)return false;
	strncpy(aux_word,init,n);
	aux_word[n]='\0';
	return check(aux_word);
}

bool Spanish::check(const string &word)
{
	return check(word.c_str());
}

bool Spanish::check(const string &line, int ini, int num)
{
	return check(line.substr(ini,num).c_str());
}