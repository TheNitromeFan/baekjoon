#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dist(int n, int x, int y){
	if(x > y){
		swap(x, y);
	}
	return min(y - x, x + n - y);
}

bool close_combination(int n, int a1, int a2, int a3, int b1, int b2, int b3, int x1, int x2, int x3){
	return (dist(n, a1, x1) <= 2 && dist(n, a2, x2) <= 2 && dist(n, a3, x3) <= 2) ||
	(dist(n, b1, x1) <= 2 && dist(n, b2, x2) <= 2 && dist(n, b3, x3) <= 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a1, a2, a3, b1, b2, b3;
	cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				if(close_combination(n, a1, a2, a3, b1, b2, b3, i, j, k)){
					++cnt;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
