#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main ()
{
    int t, res;
    string str;
    int reg[10];
	bool b;
    for (cin >> t, cin.ignore(), cin.ignore(); t != 0; t--)
    {
		vector <string> ram (1000, "000");
        memset (reg, 0, sizeof reg);
        for (int i = 0; getline (cin, str) && str.length();i++)
            ram[i] = str;
		res = 0;
		b = true;
        for (int i = 0; b; i++, res++)
		{
            switch (ram[i][0])
            {
            case '2':
				{
                reg[ram[i][1]-'0'] = ram[i][2]-'0';
				reg[ram[i][1]-'0'] %= 1000;
				}
				break;
            case '3':
				{
                reg[ram[i][1]-'0'] += ram[i][2]-'0';
				reg[ram[i][1]-'0'] %= 1000;
				}
                break;
            case '4':
				{
                reg[ram[i][1]-'0'] *= ram[i][2]-'0';
				reg[ram[i][1]-'0'] %= 1000;
				}
                break;
            case '5':
				{
                reg[ram[i][1]-'0'] = reg[ram[i][2]-'0'];
				reg[ram[i][1]-'0'] %= 1000;
				}
                break;
            case '6':
				{
                reg[ram[i][1]-'0'] += reg[ram[i][2]-'0'];
				reg[ram[i][1]-'0'] %= 1000;
				}
                break;
            case '7':
				{
                reg[ram[i][1]-'0'] *= reg[ram[i][2]-'0'];
				reg[ram[i][1]-'0'] %= 1000;
				}
                break;
            case '8':
				{
                stringstream ss (ram[reg[ram[i][2]-'0']]);
                ss >> reg[ram[i][1]-'0'];
				}
				break;
            case '9':
				{
                stringstream ss;
                ss << reg[ram[i][1]-'0'];
				if (ss.str().length() == 1)	ss.str() = "0" + ss.str();
				if (ss.str().length() == 2)	ss.str() = "0" + ss.str();
                ram[reg[ram[i][2]-'0']] = ss.str();
				}
				break;
			case '0':
                if (reg[ram[i][2]-'0'])
                    i = reg[ram[i][1]-'0']-1;
				break;
			default:
				if (ram[i] == "100")
					b = false;
            }
		}
        cout << res << endl;
        if (t > 1)
            cout << endl;
    }
    return 0;
}

