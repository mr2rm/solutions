#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main ()
{
	string words = "HELLO HALLO BONJOUR CIAO ZDRAVSTVUJTE HOLA";
	string langs = "ENGLISH GERMAN FRENCH ITALIAN RUSSIAN SPANISH";
	stringstream ss1(words);
	stringstream ss2(langs);
	string str, s1, s2;
	map <string, string> mp;
	while (ss1 >> s1 && ss2 >> s2)
		mp[s1] = s2;
	for (int I = 1; cin >> str && str != "#"; I++)
	{
		cout << "Case " << I << ": ";
		if (mp[str] == "")
			cout << "UNKNOWN" << endl;
		else
			cout << mp[str] << endl;
	}
	return 0;
}