#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int j, r;
	cin >> j >> r;
	int winner = j;
	vector<int> points(j + 1);
	for(int i = 0; i < r; ++i){
		for(int player = 1; player <= j; ++player){
			int x;
			cin >> x;
			points[player] += x;
			if(points[player] >= points[winner]){
				winner = player;
			}
		}
	}
	cout << winner << '\n';
	return 0;
}
