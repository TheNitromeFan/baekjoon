#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> occur(50);
		for(int i = 0; i < 6 * n; ++i){
			int x;
			cin >> x;
			++occur[x];
		}
		vector<int> balls(49);
		for(int i = 0; i < 49; ++i){
			balls[i] = i + 1;
		}
		sort(balls.begin(), balls.end(), [&occur](int x, int y){
			return occur[x] > occur[y]
			|| (occur[x] == occur[y] && x == 7)
			|| (occur[x] == occur[y] && x != 7 && y != 7 && x < y);
		});
		sort(balls.begin(), balls.begin() + 6);
		for(int j = 0; j < 6; ++j){
			cout << balls[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
