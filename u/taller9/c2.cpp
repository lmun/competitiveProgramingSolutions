#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
struct Pair {
	int to, energy;
	Pair(int first, int second) : to(first), energy(second){}
};

int main() {
	int n, value, leave,
		next, current, isFinal, isCyclic, total,
		i, j;

	while (cin >> n && n != -1) {
		isFinal = false;
		isCyclic = false;
		
		vector<Pair> *adjList = new vector<Pair>[n + 1];
		int* energy = new int[n + 1];
		int* r = new int[n + 1];
		bool* inQueue = new bool[n + 1];

		bool transitive[101][101];
		memset(transitive, false, sizeof(transitive));

		for (i = 1; i <= n; i++) {
			energy[i] = (int)-1e9;
			r[i] = 0;
			inQueue[i] = false;
			adjList[i].clear();
		}
		for (i = 1; i <= n; i++) {
			cin >> value >> leave;
			if (leave)
				for (j = 0; j < leave; j++) {
					cin >> next;
					adjList[i].push_back({ next, value });
				}
		}

		queue<int> Q;
		for (i = 1; i <= n; i++) {
			Q.push(i);
			while (!Q.empty()) {
				next = Q.front();
				Q.pop();

				if (transitive[i][next])
					continue;
				else
					transitive[i][next] = true;

				for (j = 0; j < (int)adjList[next].size(); j++)
					Q.push(adjList[next][j].to);
			}
		}
		queue<int> q;
		q.push(1);
		energy[1] = 100;

		while (!q.empty()) {
			current = q.front();
			q.pop();
			inQueue[current] = false;

			if (current == n) {
				isFinal = true;
				break;
			} else if (r[current] >= n) {
				if (transitive[current][n]) {
					isCyclic = true;
					break;
				} else
					energy[current] = (int)1e9;
				continue;
			}

			for (i = 0; i < (int)adjList[current].size(); i++) {
				next = adjList[current][i].to;
				total = energy[current] + adjList[current][i].energy;
				if (total > 0 && total > energy[next]) {
					energy[next] = total;
					r[next] = r[current] + 1;
					if (!inQueue[next]) {
						q.push(next);
						inQueue[next] = true;
					}
				}
			}
		}
		
		if (isFinal || isCyclic)
			cout << "winnable\n";
		else if (energy[n] > 0)
			cout << "winnable\n";
		else
			cout << "hopeless\n";
		delete[] adjList;
		delete[] inQueue;
		delete[] r;
		delete[] energy;
	}

	return 0;
}