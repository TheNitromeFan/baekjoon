#include <iostream>
#define MAX 1001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dp[MAX] = {};
	dp[2] = 1;
	int n;
	cin >> n;
	for(int i = 3; i <= n; ++i){
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
	cout << (dp[n] == 0 ? 2 : 1);
	return 0;
}
