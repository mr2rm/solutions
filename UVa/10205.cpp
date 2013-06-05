#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main ()
{
	int T, n, x;
	string str;
	int shuf[110][53];
	vector <int> deck(53);
	vector <int> ndeck(53);
	string suit[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	string value[4] = {"Jack", "Queen", "King", "Ace"};
	cin >> T;
	for (int t = 0; t < T && cin >> n; t++)
	{
		for (int I = 1; I <= n; I++)
			for (int J = 1; J <= 52; J++)
			{
				cin >> x;
				shuf[I][J] = x;
			}

		for (int I = 1; I <= 52; I++)
			deck[I] = I;

		cin.ignore();
		while (getline(cin, str) && str != "")
		{
			stringstream ss (str);
			ss >> x;
			for (int I = 1; I <= 52; I++)
				ndeck[I] = deck[shuf[x][I]];
			deck = ndeck;
		}

		if (t)
			cout << endl;
		for (int I = 1; I <= 52; I++)
		{
			x = (deck[I] - 1) % 13;
			if (x < 9)
				cout << x + 2;
			else
				cout << value[x % 9];
			cout << " of ";
			x = (deck[I] - 1) / 13;
			cout << suit[x] << endl;
		}
	}
	return 0;
}