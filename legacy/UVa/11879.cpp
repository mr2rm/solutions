#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string dif (string str)
{
	int x = 5*(str[str.length()-1]-'0');
	int num, I;
	str.erase (str.end()-1);
	for (int J = str.length()-1; x; J--)
	{
		num = x % 10;
		x /= 10;
		if (str[J]-'0' >= num)
			str[J] = '0'+ (str[J]-'0'-num);
		else
		{
			for (I = J-1; I >= 0 && str[I] == '0'; I--);
			str[I]--;
			for (I++; I < J; I++)
				str[I] = '9';
			str[J] = '0'+(str[J]-'0'+10-num);
		}
	}
	return str;
}

int myfunc (string str)
{
	if (str.length() <= 19)
	{
		stringstream ss (str);
		unsigned long long x;
		ss >> x;
		return (x % 17);
	}
	return myfunc (dif(str));
}

int main ()
{
	string str;
	while (cin >> str && str != "0")
		if (myfunc (str))
			cout << 0 << endl;
		else
			cout << 1 << endl;
	return 0;
}