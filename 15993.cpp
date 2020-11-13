#include <cstdio>
#include <utility>
#define MAX 100001
#define MOD 1000000009

using namespace std;

pair<int, int> ways(int number){
	static int a[MAX][2] = {}; // a[n][m % 2]
	a[1][1] = 1;
	a[2][0] = 1;
	a[2][1] = 1;
	a[3][0] = 2;
	a[3][1] = 2;
	for(int n = 4; n <= number; ++n){
		a[n][0] = ((a[n-1][1] + a[n-2][1]) % MOD + a[n-3][1]) % MOD;
		a[n][1] = ((a[n-1][0] + a[n-2][0]) % MOD + a[n-3][0]) % MOD;
	}
	return make_pair(a[number][1], a[number][0]);
}
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);
		pair<int, int> ans = ways(n);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
