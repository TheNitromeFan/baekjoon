#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#define MAX (100000 + 4)
#define MAX_COLOR 20

using namespace std;

vector<int> adj[MAX];
vector<int> child[MAX];

int dp[MAX][MAX_COLOR + 1];
bool visited[MAX];

int n;

void fill_table(int root){
	if(visited[root]){
		return;
	}
	visited[root] = true;
	for(int c : adj[root]){
		child[root].push_back(c);
		fill_table(c);
	}
	pair<int, int> min1 = make_pair(1 << 29, 100);
	pair<int, int> min2 = make_pair(1 << 30, 100);
	for(int i = 1; i <= MAX_COLOR; ++i){
		int cost = i;
		for(int c : child[root]){
			cost += dp[c][i];
		}
		if(make_pair(cost, i) < min1){
			min2 = min1;
			min1 = make_pair(cost, i);
		}else if(make_pair(cost, i) < min2){
			min2 = make_pair(cost, i);
		}
	}
	for(int i = 0; i <= MAX_COLOR; ++i){
		dp[root][i] = min1.first;
	}
	dp[root][min1.second] = min2.first;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill_table(1);
	printf("%d", dp[1][0]);
	return 0;
}
