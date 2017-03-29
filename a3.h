#ifndef A3_H
#define A3_H
#include <string>
using namespace std;
class SpellCheck{

public:
	SpellCheck(string data[],int sz);
	void addWord(const string& newWord);
	bool lookup(const string& word) const;
	int suggest(const string& partialWord, string suggestions[]) const;
	~SpellCheck();	
};
#endif