#include <bits/stdc++.h>
using namespace std;
int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		vector<int> fv(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> fv[i];
		}
		int n2;
		cin >> n2;
		vector<int> sv(n2 + 1);
		for (int i = 0; i < n2; i++)
		{
			cin >> sv[i];
		}
		fv[n] = 20000;
		sv[n2] = 20000;
		int fc = 0, sc = 0;
		int res = 0;
		int actf = 0;
		int acts = 0;
		int count = 0;
		while (fc < n + 1 || sc < n2 + 1)
		{
			//printf("i%d\t%d\t%d\t%d\n",fc,sc,fv[fc],sv[sc]);
			fc = min(fc, n);
			sc = min(sc, n2);

			if (fv[fc] == sv[sc])
			{
				res += max(actf, acts) + fv[fc];
				fc++;
				sc++;
				actf = 0;
				acts = 0;
			}
			else if (fv[fc] < sv[sc])
			{
				actf += fv[fc++];
			}
			else
			{
				acts += sv[sc++];
			}
			//printf("f%d\t%d\t%d\t%d\n",fc,sc,fv[fc],sv[sc]);
		}
		cout << res - 20000 << endl;
	}
	return 0;
}