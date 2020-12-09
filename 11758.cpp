#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p1x, p1y, p2x, p2y, p3x, p3y;
	cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	int cross = (p2x - p1x) * (p3y - p1y) - (p3x - p1x) * (p2y - p1y);
	int orient;
	if(cross > 0){
		orient = 1;
	}else if(cross < 0){
		orient = -1;
	}else{
		orient = 0;
	}
	cout << orient;
	return 0;
}
