#include <cstdio>
#include <algorithm>
#include <vector>

int players[10001];

bool cmp(int a, int b){
	return players[a] > players[b] || (players[a] == players[b] && a < b);
}

int main(){
	while(true){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		for(int p = 0; p <= 10000; ++p){
			players[p] = 0;
		}
		std::vector<int> v;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				int player;
				scanf("%d", &player);
				if(players[player] == 0){
					v.push_back(player);
				}
				++players[player];
			}
		}
		std::sort(v.begin(), v.end(), cmp);
		int index = 1;
		while(players[v[index]] == players[v[1]]){
			printf("%d ", v[index]);
			++index;
		}
		printf("\n");
	}
	return 0;
}
