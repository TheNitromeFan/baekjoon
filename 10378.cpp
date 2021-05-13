#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, y1, x2, y2, x3, y3, x4, y4, w, h;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> w >> h;
	if((x3 - x1 >= w && y2 - y1 >= h) || (x2 - x4 >= w && y2 - y1 >= h)
	 || (x2 - x1 >= w && y3 - y1 >= h) || (x2 - x1 >= w && y2 - y4 >= h)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}
