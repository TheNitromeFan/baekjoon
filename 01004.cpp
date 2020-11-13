#include <iostream>
#include <cmath>


using std::cin;
using std::cout;

static double distance(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

static bool cross(int x1, int y1, int x2, int y2, int cx, int cy, int r){
	return (r - distance(x1, y1, cx, cy)) * (r - distance(x2, y2, cx, cy)) < 0;
}

int main(){
	unsigned tests = 0U;
	cin >> tests;
	for(unsigned t = 0; t < tests; ++t){
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		int n = 0;
		cin >> n;
		int count = 0;
		for(int i = 0; i < n; ++i){
			int cx = 0, cy = 0, r = 0;
			cin >> cx >> cy >> r;
			if(cross(x1, y1, x2, y2, cx, cy, r)){
				++count;
			}
		}
		cout << count << '\n';
	}
	return 0;
}
