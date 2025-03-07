#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll solve(ll l, ll r, vector<ll> &v, vector<vector<ll>>& dp) {
	if (l > r) return 0;
	if (l == r) return dp[l][r] = v[l];
	if (l + 1 == r) return dp[l][r] = max(v[l], v[r]);
	if (dp[l][r] != LLONG_MIN) return dp[l][r];
	dp[l][r] = max(
	               v[l] + min(solve(l + 1, r - 1, v, dp), solve(l + 2, r, v, dp)),
	               v[r] + min(solve(l, r - 2, v, dp), solve(l + 1, r - 1, v, dp))
	           );
	return dp[l][r];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++) cin >> v[i];
	vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, LLONG_MIN));
	cout << solve(0, n - 1, v, dp) << "\n";
	return 0;
}
