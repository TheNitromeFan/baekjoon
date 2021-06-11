#include <iostream>

using namespace std;

int dist(int x1, int y1, int x2, int y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool inside_rink(int w, int h, int x, int y, int xi, int yi){
	if(xi >= x && xi <= x + w && yi >= y && yi <= y + h){
		return true;
	}
	int r = h / 2;
	if(dist(x, y + r, xi, yi) <= r * r || dist(x + w, y + r, xi, yi) <= r * r){
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	int cnt = 0;
	for(int i = 0; i < p; ++i){
		int xi, yi;
		cin >> xi >> yi;
		if(inside_rink(w, h, x, y, xi, yi)){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
