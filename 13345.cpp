#include <iostream>

using namespace std;

bool equal_dist(int startx, int starty, int endx1, int endy1, int endx2, int endy2){
	return (startx - endx1) * (startx - endx1) + (starty - endy1) * (starty - endy1)
	== (startx - endx2) * (startx - endx2) + (starty - endy2) * (starty - endy2);
}

int main(){
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int x4, y4;
	if(equal_dist(x1, y1, x2, y2, x3, y3)){
		x4 = x2 + x3 - x1;
		y4 = y2 + y3 - y1;
	}else if(equal_dist(x2, y2, x1, y1, x3, y3)){
		x4 = x1 + x3 - x2;
		y4 = y1 + y3 - y2;	
	}else{
		x4 = x1 + x2 - x3;
		y4 = y1 + y2 - y3;
	}
	cout << x4 << ' ' << y4;
	return 0;
}
