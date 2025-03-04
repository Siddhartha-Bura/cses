#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int solve(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp) {
	int n1 = s.length(), n2 = t.length();
	if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
	if (idx1 == n1 && idx2 == n2) return dp[idx1][idx2] = 0;
	if (idx1 == n1) return dp[idx1][idx2] = 1 + solve(idx1, idx2 + 1, s, t, dp);
	if (idx2 == n2) return dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2, s, t, dp);
	if (s[idx1] == t[idx2]) return dp[idx1][idx2] = solve(idx1 + 1, idx2 + 1, s, t, dp);
	else
		return dp[idx1][idx2] = min({1 + solve(idx1, idx2 + 1, s, t, dp),
		                             1 + solve(idx1 + 1, idx2, s, t, dp), 1 + solve(idx1 + 1, idx2 + 1, s, t, dp)
		                            });
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	string s, t;
	cin >> s;
	cin >> t;
	int n1 = s.length(), n2 = t.length();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
	cout << solve(0, 0, s, t, dp) << "\n";
	return 0;
}
