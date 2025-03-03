#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n), dp(x + 1, INT_MAX);
	for (int i = 0; i < n; i++) cin >> v[i];
	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		for (auto e : v)
			if (i - e >= 0 && dp[i - e] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - e]);
	}
	cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << "\n";
}
