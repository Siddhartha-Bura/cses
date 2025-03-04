#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
void solve() {
	int n, tot = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		tot += v[i];
	}
	vector<bool> t(tot + 1, false);
	for (int i = 0; i < n; i++) {
		int ele = v[i];
		vector<int> to_mark;
		for (int j = 0; j <= tot; j++) {
			if (t[j] && j + ele <= tot) to_mark.push_back(j + ele);
		}
		for (auto &x : to_mark) t[x] = true;
		t[ele] = true;
	}
	int cnt = 0;
	for (int j = 0; j <= tot; j++) if (t[j]) ++cnt;
	cout << cnt << "\n";
	for (int j = 0; j <= tot; j++)
		if (t[j]) cout << j << " ";
	cout << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
