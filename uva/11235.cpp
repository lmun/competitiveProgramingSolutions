#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
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

class SegmentTree { // the OOP Segment Tree implementation, like Heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
	int n;
	int left (int p) { return  p << 1; }    // same as binary heap operations
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {                           // O(n log n)
		if (L == R)                            // as L == R, either one is fine
			st[p] = L;                                         // store the index
		else {                                // recursively compute the values
			build(left(p) , L          , (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R      );
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
		if (i >  R || j <  L) return -1; // current segment outside query range
		if (L >= i && R <= j) return st[p];               // inside query range
		// compute the min position in the left and right part of the interval
		int p1 = rmq(left(p) , L        , (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R      , i, j);
		if (p1 == -1) return p2;   // if we try to access segment outside query
		if (p2 == -1) return p1;                               // same as above
		return (A[p1] >= A[p2]) ? p1 : p2;
	}          // as as in build routine

	int update(int p, int L, int R, int idx, int new_value) {
		int i = idx, j = idx;                   // for point update i = j = idx
		// if the current interval does not intersect the update interval,
		if (i > R || j < L) return st[p];         // return this st node value!
		// if the current interval is included in the update range,
		if (L == i && R == j) {
			A[i] = new_value;                      // update the underlying array
			return st[p] = L;                                       // this index
		}
		// compute the minimum position in the left/right part of the interval
		int p1, p2;
		p1 = update(left(p) , L        , (L + R) / 2, idx, new_value);
		p2 = update(right(p), (L + R) / 2 + 1, R    , idx, new_value);
		// return the position where the overall minimum is
		return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
	}

public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();              // copy content for local usage
		st.assign(4 * n, 0);            // create large enough vector of zeroes
		build(1, 0, n - 1);                                  // recursive build
	}
	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading
	int update(int i, int v) {                                // point update
		return update(1, 0, n - 1, i, v);
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	int n, q;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cin >> q;
		vi nums(n, 0);
		vi start(n, 0);
		int nu, ulti = -10000000, ini;
		vi parase(0);
		int j = -1;
		for (int i = 0; i < n; ++i)
		{
			cin >> nu;
			if (nu > ulti) {
				j++;
				if (i) {
					parase.push_back(i - ini);
					//cout << i << ' ' << ini << ' ' << i - ini << endl;
				}
				ini = i;
				ulti = nu;
			}
			nums[i] = j;
			start[i] = ini;
		}
		parase.push_back(n - ini);
/*
		for (int k : nums) {
			cout << k << ' ';
		}
		cout << endl;

		for (int k : start) {
			cout << k << ' ';
		}
		cout << endl;
*/
		SegmentTree tree(parase);
		for (int i = 0; i < q; ++i)
		{
			int le, ri;
			cin >> le >> ri;
			le--, ri--;
			if (nums[le] == nums[ri])
			{
				cout << ri - le + 1 << endl;
				continue;
			}
			// int posi1 = parase[nums[le]] - (le - start[le]);
			// int posi2 = ri - start[ri] + 1;
			int posi = max(ri - start[ri] + 1, parase[nums[le]] - (le - start[le]));
			if (nums[le] + 1 == nums[ri])
			{
				cout << posi << endl;
				continue;
			}
			//cout << parase[tree.rmq(nums[le]+1, nums[ri]-1)] << ' ' << parase[tree.rmq(le, ri)] << endl;
			cout << max(posi, parase[tree.rmq(nums[le]+1, nums[ri]-1)]) << endl;
		}
	}

	return 0;
}
