#include <iostream>
#include <cstring>
#define MAX 1000001

using namespace std;

int cache[MAX];

int dp(int n){
	if(n == 0){
		return 0;
	}
	if(cache[n] != -1){
		return cache[n];
	}
	cache[n] = 0;
	for(int x = 1; x * x <= n; ++x){
		if(!dp(n - x * x)){
			cache[n] = 1;
			break;
		}
	}
	return cache[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		cout << (dp(n) ? "koosaga" : "cubelover") << '\n';
	}
	return 0;
}
