#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int cards[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &cards[i][j]);
		}
		sort(cards[i], cards[i] + m, greater<int>());
	}
	int points[101] = {};
	for(int j = 0; j < m; ++j){
		int max_val = 0;
		for(int i = 0; i < n; ++i){
			if(cards[i][j] > max_val){
				max_val = cards[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			if(cards[i][j] == max_val){
				++points[i + 1];
			}
		}
	}
	int max_score = 0;
	for(int i = 1; i <= n; ++i){
		if(points[i] > max_score){
			max_score = points[i];
		}
	}
	for(int i = 1; i <= n; ++i){
		if(points[i] == max_score){
			printf("%d ", i);
		}
	}
	return 0;
}
