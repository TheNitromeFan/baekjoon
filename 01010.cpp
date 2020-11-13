#include <iostream>

using namespace std;

int comb[30][30];

int solve(int n, int m){
	if(m == 0 || m == n){
		return 1;
	}else if(comb[n][m]){
		return comb[n][m];
	}
	comb[n][m] = solve(n-1, m-1) + solve(n-1, m);
	return comb[n][m];
}

int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		cout << solve(m, n) << '\n';
	}
	return 0;
}
