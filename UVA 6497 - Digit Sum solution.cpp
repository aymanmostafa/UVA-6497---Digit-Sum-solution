//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 6497 - Digit Sum
	int n;
	long long x, y, res;
	vector<int> v;
	while (cin >> n && n) {
		v.clear();
		while (n--) {
			cin >> x;
			v.push_back(x);
		}
		sort(all(v));
		res = 1e9;
		for (int i = 0; i < (1 << v.size()); i++) {
			string f = "", s = "";
			x = 0, y = 0;
			for (int k = 0; k < v.size(); k++) {
				if ((i >> k) & 1)
					f += (v[k] + 48);
				else
					s += (v[k] + 48);
			}
			for (int i = 0; i < f.size(); i++) {
				if (f[i] != '0') {
					swap(f[0], f[i]);
					break;
				}
			}
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != '0') {
					swap(s[0], s[i]);
					break;
				}
			}
			stringstream(f) >> x;
			stringstream(s) >> y;
			stringstream ff, ss;
			ff << x, ss << y;
			f = ff.str(), s = ss.str();
			if (f.size() + s.size() == v.size())
				if (x + y < res)
					res = x + y;
		}
		cout << res << endl;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
