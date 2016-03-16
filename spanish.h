#pragma once

#include <string>
using std::string;
class MySpell;

class Spanish
{
	
	MySpell * pMS;
public:
	Spanish();
	bool check(const char *word);
	bool check(const char *init, int n);
	bool check(const string &word);
	bool check(const string &line, int ini, int num);
	~Spanish();
};