#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int solve(int a, int b, vector<vector<int>> & dp) {
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i == j) dp[i][j] = 0;
			else {
				for (int k = 1; k < j; k++)
					dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
				for (int k = 1; k < i; k++)
					dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
			}
		}
	}
	return dp[a][b];
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a + 1, vector<int> (b + 1, 1e9));
	cout << solve(a, b, dp) << "\n";
	return 0;
}

// Greedy doesn't work kek!
