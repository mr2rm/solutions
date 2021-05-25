#include <iostream>
#include <string>

using namespace std;

string str, s;
int res;

bool IsDig (int in)
{
	return (str[in] >= '0' && str[in] <= '9');
}
bool IsChar (int in)
{
	return ((str[in] >= 'a' && str[in] <= 'z') || (str[in] >= 'A' && str[in] <= 'Z'));
}
bool IsIden (int in)
{
	return (str[in] == '_' || IsChar(in) || IsDig(in));
}
bool IsHex (int in)
{
	return (in < str.length() && 
				(
				 IsDig(in) || 
				(str[in] >= 'a' && str[in] <= 'f') || 
				(str[in] >= 'A' && str[in] <= 'F')
				)
		   );
}
bool IsCons (int in)
{
	return (str[in] == '\'' || IsDig(in) || (str[in] == '$' && IsHex (in+1)));
}
bool IsCom (int in)
{
	return (str[in] == '{' || (str[in] == '(' && in < str.length()-1 && str[in+1] == '*'));
}
int Op (int in)
{
	switch (str[in])
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case '@':
		case '^':
			return in;
		case '<':
			if (in < str.length()-1 && (str[in+1] == '=' || str[in+1] == '>'))
				return in + 1;
			else	return in;
		case '>':
			if (in < str.length()-1 && str[in+1] == '=')
				return in + 1;
			else	return in;
		case ':':
			if (in < str.length()-1 && str[in+1] == '=')
				return in + 1;
		default:
			return 0;
	}
}
int cons (int in)
{
	int t = in + 1;
	if (str[in] == '\'')
	{
		for (; t < str.length(); t++)
			if (str[t] == '\'')
				if (t != str.length()-1 && str[t+1] == '\'')
					t++;
				else
					break;
	}
	else if (str[in] == '$')
	{
		for (t++; t < str.length() && IsHex(t); t++);
		t--;
	}
	else
	{
		bool dot = false;
		for (; t < str.length() && (IsDig(t) || (!dot && str[t] == '.')); t++)
			if (str[t] == '.')
				dot = true;
		if (t < str.length() && (str[t] == 'E' || str[t] == 'e'))
		{
			t++;
			for (; t < str.length() && str[t] == ' '; t++);
			if (t < str.length() && (str[t] == '+' || str[t] == '-'))
				t++;
			for (; t < str.length() && str[t] == ' '; t++);
			for (; t < str.length() && IsDig(t); t++);
		}
		t--;
		/*
		for (; t < str.length() && IsDig(t); t++);
		if (t < str.length() && str[t] == '.')
			t++;
		for (; t < str.length() && IsDig(t); t++);
		if (t < str.length() && (str[t] == 'e' || str[t] == 'E'))
		{
			for (t++; t < str.length() && str[t] == ' '; t++);
			if (t < str.length() && (str[t] == '+' || str[t] == '-'))
				t++;
			for (; t < str.length() && str[t] == ' '; t++);
			for (; t < str.length() && IsDig(t); t++);
		}
		t--;
		*/
	}
	return t;
}
int iden (int in)
{
	int i;
	for (i = in + 1; i < str.length() && IsIden(i); i++);
	i--;
	return i;
}
int com (int in)
{
	int t;
	if (str[in] == '(')
		t = in + 2;
	else
		t = in + 1;
	bool b = false;
	do
	{
		for (; t < str.length() && !b; t++)
			if (str[t] == '}')
			{
				b = true;
				t--;
			}
			else if (str[t] == '*' && t < str.length()-1 && str[t+1] == ')')
				b = true;
		if (!b)
			t = 0;
	}while (!b && getline(cin, str));
	return t;
}

int main ()
{
	res = 0;
	while (getline(cin, str))
	{
		if (str.length() > 1 && str[0] == '~' && str[1] == '~')
		{
			str = string (str.begin()+2, str.end());
			cout << "Program by " << str << " contains " << res << " units." << endl;
			res = 0;
		}
		else
		{
			for (int i = 0; i < str.length(); i++)
			{
				if(IsCons(i))
				{
					i = cons(i);
					res++;
				}
				else if (Op(i))
				{
					i = Op(i);
					res++;
				}
				else if (IsIden(i))
				{
					i = iden(i);
					res++;
				}
				else if (IsCom(i))
					i = com(i);
				else if (str[i] == '(' || str[i] == '[')
					res++;
			}
		}
	}
	return 0;
}