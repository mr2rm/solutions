#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
	string str;
	vector <int> v;
	vector <int> sorted;
	int n;
	while (getline(cin, str))
	{
		stringstream ss(str);
		v.clear();
		while (ss >> n)
			v.push_back(n);
		reverse (v.begin(), v.end());
		sorted = vector <int> (v.begin(), v.end());
		sort (sorted.begin(), sorted.end());
		reverse (sorted.begin(), sorted.end());
		n = v.size();
		cout << str << endl;
		for (int I = 0; I < n-1; I++)
			if (sorted[I] != v[I])
			{
				if (sorted[I] != v[n-1])
					for (int J = I + 1; J < n-1; J++)
						if (v[J] == sorted[I])
						{
							reverse (v.begin()+J, v.end());
							cout << J+1 << " ";
							break;
						}
				reverse (v.begin()+I, v.end());
				cout << I+1 << " ";
			}
		cout << "0" << endl;
	}
	return 0;
}
