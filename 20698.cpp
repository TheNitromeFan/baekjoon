#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int max_x = -10000000, min_x = 10000000, max_y = -10000000, min_y = 10000000;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		if(max_x < x){
			max_x = x;
		}
		if(min_x > x){
			min_x = x;
		}
		if(max_y < y){
			max_y = y;
		}
		if(min_y > y){
			min_y = y;
		}
	}
	cout << (max_x - min_x + 1) / 2 << ' ' << (max_y - min_y + 1) / 2;
	return 0;
}
