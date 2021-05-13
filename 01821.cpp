#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int comb[11][11] = {};
	for(int n = 0; n <= 10; ++n){
		comb[n][0] = 1;
		comb[n][n] = 1;
	}
	for(int n = 2; n <= 10; ++n){
		for(int k = 1; k < n; ++k){
			comb[n][k] = comb[n - 1][k - 1] + comb[n - 1][k];
		}
	}
	int n, f;
	cin >> n >> f;
	vector<int> c(n);
	for(int i = 0; i < n; ++i){
		c[i] = i + 1;
	}
	do{
		int sum = 0;
		for(int i = 0; i < n; ++i){
			sum += c[i] * comb[n - 1][i];
		}
		if(sum == f){
			break;
		}
	}while(next_permutation(c.begin(), c.end()));
	for(int x : c){
		cout << x << ' ';
	}
	return 0;
}
