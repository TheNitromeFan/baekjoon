#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	int x = 0, y = 0;
	int dir = 0;
	int time = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < n; ++i){
		int ti;
		string turn;
		cin >> ti >> turn;
		x += dx[dir] * (ti - time);
		y += dy[dir] * (ti - time);
		time = ti;
		if(turn == "left"){
			dir = (dir + 1) % 4;
		}else if(turn == "right"){
			dir = (dir + 3) % 4;
		}
	}
	x += dx[dir] * (t - time);
	y += dy[dir] * (t - time);
	cout << x << ' ' << y;
	return 0;
}
