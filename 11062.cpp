#include <cstdio>
#include <cstring>

int computer(int dp[][1001], int cards[1001], int n, int front, int back);
int alice(int dp[][1001], int cards[1001], int n, int front, int back);

int computer(int dp[][1001], int cards[1001], int n, int front, int back){
	if(front > back){
		return 0;
	}
	int ret1 = alice(dp, cards, n, front + 1, back), ret2 = alice(dp, cards, n, front, back - 1);
	return (ret1 < ret2) ? ret1 : ret2;
}

int alice(int dp[][1001], int cards[1001], int n, int front, int back){
	if(front > back){
		return 0;
	}
	if(dp[front][back] != -1){
		return dp[front][back];
	}
	int ret1 = cards[front] + computer(dp, cards, n, front + 1, back);
	int ret2 = cards[back] + computer(dp, cards, n, front, back - 1);
	dp[front][back] = (ret1 > ret2) ? ret1 : ret2;
	return dp[front][back];
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int cards[1001];
		for(int i = 0; i < n; ++i){
			scanf("%d", &cards[i]);
		}
		int dp[1001][1001];
		memset(dp, -1, sizeof(dp));
		printf("%d\n", alice(dp, cards, n, 0, n - 1));
	}
	return 0;
}
