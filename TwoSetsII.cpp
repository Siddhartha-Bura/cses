#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;


void solve() {
	ll n;
	cin >> n;
	ll tot = n * (n + 1) / 2;
	if (tot & 1) {
		cout << "0\n";
		return;
	}
	ll hs = tot >> 1;
	vector<ll> v(n), prev(hs + 1, 0);
	for (ll i = 0; i < n; i++) v[i] = i + 1;
	prev[0] = 1;
	for (ll i = 1; i < n; i++) {
		vector<ll> curr = prev;
		for (ll j = 0; j <= hs; j++) {
			if (j - i >= 0) {
				curr[j] = (curr[j] + prev[j - i]) % mod;
			}
		}
		prev = curr;
	}
	cout << prev[hs] << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
