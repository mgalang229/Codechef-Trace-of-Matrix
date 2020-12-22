#include <bits/stdc++.h>

using namespace std;

int a[110][110];

int FindTrace(int i, int j, int k) {
	int trace = 0;
	for (int l = 0; l <= k; l++) {
		trace += a[i + l][j + l];
	}
	return trace;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		// brute - force approach
		// i = this is where the row of sub - matrix will start
		// j = this is where the column of the sub - matrix will start
		// k = this will decide the length or height of the sub - matrix
		// FindTrace will skip the values in both the y and x direction to directly add the value in the trace
		// note: a single value is also CONSIDERED as a trace
		int trace = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; i + k < n && j + k < n; k++) {
					trace = max(trace, FindTrace(i, j, k));
				}
			}
		}
		cout << trace << '\n';
	}
	return 0;
}
