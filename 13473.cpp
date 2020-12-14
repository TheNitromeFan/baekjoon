#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, ax, bx, ay, by;
	cin >> w >> h >> ax >> ay >> bx >> by;
	if(ax != bx){
		cout << ax << ' ' << 0 << ' ' << bx << ' ' << h;
	}else{
		cout << 0 << ' ' << ay << ' ' << w << ' ' << by;
	}
	return 0;
}
