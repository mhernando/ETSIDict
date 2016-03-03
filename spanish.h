#pragma once

#define MAX_WORD_SIZE 200
class MySpell;
class Spanish
{
	char aux_word[MAX_WORD_SIZE];
	MySpell * pMS;
public:
	Spanish();
	bool check(const char *word);
	bool check(const char *init, int n);
	~Spanish();
};