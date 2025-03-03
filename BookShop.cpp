#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> prices(n), pages(n);

	for (int i = 0; i < n; i++) cin >> prices[i];
	for (int i = 0; i < n; i++) cin >> pages[i];

	vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - prices[i - 1] >= 0)
				dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - prices[i - 1]]);
		}
	}

	cout << dp[n][x] << "\n";
}
