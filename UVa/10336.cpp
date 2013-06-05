#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int h, w, t;
vector <string> mat;
vector < vector <int> > mark;
map <char, int> mp;
vector < pair <int, char> > res;
string str;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool cmp (pair <int, char> p1, pair <int, char> p2)
{
	if (p1.first != p2.first)
		return p1.first > p2.first;
	return p1.second < p2.second;
}

void dfs (int x, int y)
{
	mark[x][y] = 1;
	for (int I = 0; I < 4; I++)
	{
		int tx = dir[I][0] + x;
		int ty = dir[I][1] + y;
		if (tx >= 0 && tx < h && ty >= 0 && ty < w && !mark[tx][ty] && mat[tx][ty] == mat[x][y])
			dfs (tx, ty);
	}
}

int main ()
{	
	cin >> t;
	for (int I = 1; I <= t && cin >> h >> w; I++)
	{
		mat.clear();
		mp.clear();
		res.clear();
		mark = vector < vector <int> > (h, vector <int> (w, 0));
		for (int J = 0; J < h && cin >> str; J++)
			mat.push_back (str);
		for (int J = 0; J < h; J++)
			for (int K = 0; K < w; K++)
				if (!mark[J][K])
				{
					mp[mat[J][K]]++;
					dfs (J, K);
				}
		for (map <char, int>::iterator mit = mp.begin(); mit != mp.end(); mit++)
			res.push_back (make_pair((*mit).second, (*mit).first));
		sort (res.begin(), res.end(), cmp);
		cout << "World #" << I << endl;
		for (int J = 0; J < (int)res.size(); J++)
			cout << res[J].second << ": " << res[J].first << endl;
	}
	return 0;
}