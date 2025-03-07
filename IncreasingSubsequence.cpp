#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;


void solve() {
	ll n;
	cin >> n;
	vector<ll> sq;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ll idx = lower_bound(sq.begin(), sq.end(), x) - sq.begin();
		if (idx == sq.size()) sq.push_back(x);
		else sq[idx] = x;
	}
	cout << sq.size() << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
