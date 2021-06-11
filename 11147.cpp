#include <iostream>
#include <vector>
#define MAX 200

using namespace std;

void floyd_warshall(int c[][MAX], int n){
	for(int k = 0; k < n; ++k){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(c[i][k] != -1 && c[k][j] != -1 && (c[i][j] == -1 || c[i][j] > c[i][k] + c[k][j])){
					c[i][j] = c[i][k] + c[k][j];
				}
			}
		}
	}
}

int tour_cost(vector<int> &tour, int c[][MAX], int n){
	floyd_warshall(c, n);
	tour.push_back(tour[0]);
	int ret = 0;
	for(int i = 0; i < n; ++i){
		int cur = tour[i], next = tour[i + 1];
		if(c[cur][next] == -1){
			return -1;
		}
		ret += c[cur][next];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> tour(n);
		for(int i = 0; i < n; ++i){
			cin >> tour[i];
		}
		int c[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> c[i][j];
			}
		}
		int ans = tour_cost(tour, c, n);
		if(ans != -1){
			cout << ans << '\n';
		}else{
			cout << "impossible\n";
		}
	}
	return 0;
}
