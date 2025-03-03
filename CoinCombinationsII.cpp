#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	ll dp[x + 1] = {};
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= x; j++) {
			dp[j] = (dp[j] + dp[j - v[i]]) % mod;
		}
	}

	cout << dp[x] << "\n";

}
