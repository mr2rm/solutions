#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, x, sum, strong, weak;
	vector <int> s, g;
	for (int t = 1; cin >> n && n; t++)
	{
		s.clear();
		for (int I = 0; I < n && cin >> x; I++)
			s.push_back(x);
		cout << "Game " << t << ":" << endl;
		while (1)
		{
			g.clear();
			sum = 0;
			for (int I = 0; I < n && cin >> x; I++)
			{
				g.push_back(x);
				sum += x;
			}
			if (!sum)	break;
			strong = weak = 0;
			vector <int> markstrong (n, 0);
			vector <int> markweak (n, 0);
			for (int I = 0; I < n; I++)
				if (g[I] == s[I])
				{
					strong++;
					markstrong[I] = 1;
				}
			for (int I = 0; I < n; I++)
				if (!markstrong[I])
					for (int J = 0; J < n; J++)
						if (!markstrong[J] && !markweak[J] && g[I] == s[J])
						{
							weak++;
							markweak[J] = 1;
							break;
						}
			cout << "    (" << strong << "," << weak << ")" << endl;
		}
	}
	return 0;
}