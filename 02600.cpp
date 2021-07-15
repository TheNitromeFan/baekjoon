#include <iostream>
#include <cstring>
#define MAX (500 + 1)

using namespace std;

int cache[MAX][MAX];
int b1, b2, b3;

int dp(int k1, int k2){
	if(cache[k1][k2] != -1){
		return cache[k1][k2];
	}
	cache[k1][k2] = 0;
	if(k1 >= b1 && !dp(k1 - b1, k2)){
		cache[k1][k2] = 1;
		return 1;
	}
	if(k1 >= b2 && !dp(k1 - b2, k2)){
		cache[k1][k2] = 1;
		return 1;
	}
	if(k1 >= b3 && !dp(k1 - b3, k2)){
		cache[k1][k2] = 1;
		return 1;
	}
	if(k2 >= b1 && !dp(k1, k2 - b1)){
		cache[k1][k2] = 1;
		return 1;
	}
	if(k2 >= b2 && !dp(k1, k2 - b2)){
		cache[k1][k2] = 1;
		return 1;
	}
	if(k2 >= b3 && !dp(k1, k2 - b3)){
		cache[k1][k2] = 1;
		return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> b1 >> b2 >> b3;
	memset(cache, -1, sizeof(cache));
	for(int i = 0; i < 5; ++i){
		int k1, k2;
		cin >> k1 >> k2;
		cout << (dp(k1, k2) ? 'A' : 'B') << '\n';
	}
	return 0;
}
