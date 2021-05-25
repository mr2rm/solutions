using namespace std;
 
int main ()
{
	int t, n, x;
	int sum, res;
	int bn[100];
	cin >> t;
	for (int I = 0; I < t && cin >> n >> x; I++)
	{
		sum = 0;
		for (int J = 0; J < n; J++)
		{
			cin >> bn[J];
			sum += bn[J];
		}
		res = sum / x;
		for (int J = 0; J < n; J++)
			if ((sum - bn[J])/x == res)
			{
				res = -1;
				break;
			}
		cout << res << endl;
	}
	return 0;
}