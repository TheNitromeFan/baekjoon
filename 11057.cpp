#include <iostream>

using namespace std;

int main(){
	int mod = 10007;
	int n;
	cin >> n;
	int ascending[1001][10]; // [number_of_digits][final_digit]
	for(int j = 0; j <= 9; ++j){
		ascending[1][j] = 1;
	}
	for(int i = 2; i <= n; ++i){
		for(int j = 0; j <= 9; ++j){
			ascending[i][j] = 0;
			for(int k = 0; k <= j; ++k){
				ascending[i][j] = (ascending[i][j] + ascending[i-1][k]) % mod;
			}
		}
	}
	int answer = 0;
	for(int j = 0; j <= 9; ++j){
		answer = (answer + ascending[n][j]) % mod;
	}
	cout << answer << endl;
	return 0;
}
