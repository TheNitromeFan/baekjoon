#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int score = 0;
	for(int i = 0; i < n; ++i){
		int ai;
		cin >> ai;
		if(ai == 0){
			++score;
		}
	}
	for(int j = 0; j < m; ++j){
		int bj;
		cin >> bj;
		if(bj == 1){
			--score;
		}
	}
	cout << abs(score);
	return 0;
}
