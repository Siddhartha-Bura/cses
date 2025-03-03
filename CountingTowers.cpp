#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1000005;
 
vector<vector<ll>> dp(N, vector<ll>(2, 0));
 
void solve() {
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 1; i < N; i++) {
		dp[i][0] = (dp[i - 1][1] + (4 * dp[i - 1][0]) + mod) % mod;
		dp[i][1] = (dp[i - 1][0] + (2 * dp[i - 1][1]) + mod) % mod;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	solve();
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n - 1][0] + dp[n - 1][1] + mod) % mod << "\n";
	}
	return 0;
}


// 0 -> has OO kinda ending
// 1 -> has +----+
//          |    |

// To count dp[i][0]
// we consider 
// O    O     O  O    +-+  O     +-+ +-+    O  +-+
// +----+  ,       ,  | | +-+ ,  | | | | , +-+ | |
// |    |     O  O    | | | |    | | | |   | | | |

// dp[i-1][1] + 4 * dp[i-1][0]


// To count dp[i][1]

// +----+      +----+     +----+ 
// |    |      |    |     |    |
// +----+   ,  +----+  ,  |    |
//  O  O       +----+     +----+ 
//             |    |
//             +----+ 

// dp[i-1][0] + 2 * dp[i-1][1]

