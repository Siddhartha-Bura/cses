#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int> (n, 0));
	vector<vector<int>> dp(n, vector<int> (n, 0));

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			if (temp[j] == '*') grid[i][j] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (grid[i][0] == 1) break;
		dp[i][0] = 1;
	}

	for (int j = 0; j < n; j++) {
		if (grid[0][j] == 1) break;
		dp[0][j] = 1;
	}


	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] != 1) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}
  
	cout << dp[n - 1][n - 1] << "\n";

}
