#include <cstdio>
#include <utility>
#include <algorithm>
#define MAX (100 + 1)

using namespace std;

int n;
char str[MAX];
int match[MAX][MAX];
pair<int, int> dp[MAX][MAX];

pair<int, int> f(int s, int e){
	if(s > e){
		return make_pair(0, 0);
	}
	if(dp[s][e].first != -1){
		return dp[s][e];
	}
	dp[s][e].first = 0;
	int val = 1e9 + 7, h = 0;
	for(int k = s + 1; k <= e; k += 2){
		if(str[s] != str[k]){
			auto a = f(s + 1, k - 1);
			auto b = f(k + 1, e);
			int dist = k - s;
			if(val > a.first + b.first + dist + (a.second + 1) * 2){
				val = a.first + b.first + dist + (a.second + 1) * 2;
				h = max(a.second + 1, b.second);
				match[s][e] = k;
			}
		}
	}
	dp[s][e] = make_pair(val, h);
	return dp[s][e];
}

void trace(int s, int e){
	if(s > e){
		return;
	}
	int k = match[s][e];
	printf("%d %d\n", s + 1, k + 1);
	trace(s + 1, k - 1);
	trace(k + 1, e);
}

int main(){
	scanf("%d", &n);
	scanf("%s", str);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			dp[i][j].first = -1;
		}
	}
	printf("%d\n", f(0, n - 1).first);
	trace(0, n - 1);
	return 0;
}
