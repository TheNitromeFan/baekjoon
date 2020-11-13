#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::min;

static int distance(int x, int y, int w, int h){
	return min({x, w-x, y, h-y});
}

int main(){
	int x = 0, y = 0, w = 0, h = 0;
	cin >> x >> y >> w >> h;
	cout << distance(x, y, w, h);
	return 0;
}
