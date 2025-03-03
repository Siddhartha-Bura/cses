#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7; // use const, save time

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	ll dp[x + 1] = {};
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i - v[j] >= 0)
				dp[i] = (dp[i] + dp[i - v[j]]) % mod;
		}
	}
	cout << dp[x] << "\n";

}
