#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int dist(int x1, int y1, int x2, int y2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int xs, ys, xe, ye, dx, dy;
	cin >> xs >> ys >> xe >> ye >> dx >> dy;
	int g = gcd(abs(dx), abs(dy));
	dx /= g;
	dy /= g;
	int xjump = xe, yjump = ye, distjump = dist(xe, ye, xs, ys);
	while(xe >= -200 && xe <= 200 && ye >= -200 && ye <= 200){
		xe += dx;
		ye += dy;
		int cmp = dist(xe, ye, xs, ys);
		if(cmp < distjump){
			xjump = xe;
			yjump = ye;
			distjump = cmp;
		}
	}
	cout << xjump << ' ' << yjump;
	return 0;
}
