#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long w, h, f, c, x1, y1, x2, y2;
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
	long long painted = 0;
	if(f <= w - f){
		if(x2 <= f){
			painted = (x2 - x1) * (y2 - y1) * (c + 1) * 2;
		}else if(x1 >= f){
			painted = (x2 - x1) * (y2 - y1) * (c + 1);
		}else{
			painted = (f - x1) * (y2 - y1) * (c + 1) * 2 + (x2 - f) * (y2 - y1) * (c + 1);
		}
	}else{
		if(x2 <= w - f){
			painted = (x2 - x1) * (y2 - y1) * (c + 1) * 2;
		}else if(x1 >= w - f){
			painted = (x2 - x1) * (y2 - y1) * (c + 1);
		}else{
			painted = (w - f - x1) * (y2 - y1) * (c + 1) * 2 + (x2 - w + f) * (y2 - y1) * (c + 1);
		}
	}
	cout << w * h - painted;
	return 0;
}
