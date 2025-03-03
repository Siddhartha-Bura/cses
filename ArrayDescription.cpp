#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

	function<bool(int)> cg = [&](int x) {
		if (x >= 1 && x <= m) return true;
		return false;
	};

	for (int i = 1; i <= n; i++) {
		if (v[i - 1] == 0) {
			if (i == 1)
				for (int j = 1; j <= m; j++) dp[i][j] = 1;
			else
				for (int j = 1; j <= m; j++) {
					int a = j - 1;
					int b = j;
					int c = j + 1;
					if (cg(a)) dp[i][j] = (dp[i][j] + dp[i - 1][a]) % mod;
					if (cg(b)) dp[i][j] = (dp[i][j] + dp[i - 1][b]) % mod;
					if (cg(c)) dp[i][j] = (dp[i][j] + dp[i - 1][c]) % mod;
				}
		}
		else {
			if (i == 1) dp[i][v[i - 1]] = 1;
			else {
				int a = v[i - 1] - 1;
				int b = v[i - 1];
				int c = v[i - 1] + 1;
				if (cg(a)) dp[i][v[i - 1]] = (dp[i][v[i - 1]] + dp[i - 1][a]) % mod;
				if (cg(b)) dp[i][v[i - 1]] = (dp[i][v[i - 1]] + dp[i - 1][b]) % mod;
				if (cg(c)) dp[i][v[i - 1]] = (dp[i][v[i - 1]] + dp[i - 1][c]) % mod;
			}
		}
	}

	ll res = 0;
	for (int i = 1; i <= m; i++) res = (res + dp[n][i]) % mod;

	cout << res << "\n";

}
