#include <iostream>
#include <cmath>

using namespace std;

int square(int x){
	return x * x;
}

bool fit(int h, int w, int r1, int r2){
	return (h >= 2 * r1 + 2 * r2 && w >= 2 * r1 && w >= 2 * r2)
	|| (w >= 2 * r1 + 2 * r2 && h >= 2 * r1 && h >= 2 * r2)
	|| (h >= 2 * r1 && h >= 2 * r2 && w >= 2 * r1 && w >= 2 * r2 && square(h - r1 - r2) + square(w - r1 - r2) >= square(r1 + r2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int h, w, r1, r2;
		cin >> h >> w >> r1 >> r2;
		if(h == 0 && w == 0 && r1 == 0 && r2 == 0){
			break;
		}
		cout << (fit(h, w, r1, r2) ? 'S' : 'N') << '\n';
	}
	return 0;
}
