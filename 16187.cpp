#include <iostream>
#define MAX 5001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dp[MAX] = {};
	dp[2] = 1;
	for(int i = 3; i <= 5000; ++i){
		bool check[16] = {};
		for(int j = 0; j <= i - 2; ++j){
			check[dp[j] ^ dp[i - 2 - j]] = true;
		}
		for(int k = 0; k < 16; ++k){
			if(!check[k]){
				dp[i] = k;
				break;
			}
		}
	}
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		cout << (dp[n] == 0 ? "Second\n" : "First\n");
	}
	return 0;
}
