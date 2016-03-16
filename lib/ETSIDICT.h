
//Cabecera Publica de ETSIDICT. GENERADA AUTOMATICAMENTE
#ifdef _DEBUG
#pragma comment(lib, "lib/ETSIDICTD.lib")
#else
#pragma comment(lib, "lib/ETSIDICT.lib")
#endif

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