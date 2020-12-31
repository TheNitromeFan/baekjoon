#include <iostream>
#include <algorithm>
#define MAX 201

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		int moves[MAX] = {};
		for(int i = 0; i < n; ++i){
			int a, b;
			cin >> a >> b;
			if(a > b){
				swap(a, b);
			}
			for(int j = (a + 1) / 2; j <= (b + 1) / 2; ++j){
				++moves[j];
			}
		}
		int time = 0;
		for(int k = 1; k < MAX; ++k){
			time = max(time, 10 * moves[k]);
		}
		cout << time << '\n';
	}
	return 0;
}
