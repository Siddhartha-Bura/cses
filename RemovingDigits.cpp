#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, cnt = 0;
	cin >> n;

	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp) {
			int rem = temp % 10;
			dp[i] = min(dp[i], 1 + dp[i - rem]);
			temp = temp / 10;
		}
	}

	cout << dp[n] << "\n";

}
