#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if((x2 - x1) * (y4 - y3) != (x4 - x3) * (y2 - y1)){
			double x = (y2 - y1) * (x4 - x3) + (y4 - y3) * (x2 - x1) + (double)(y3 - y1) * (x4 - x3) * (x2 - x1);
			double y;
			if(x1 != x2){
				y = (y2 - y1) / (double)(x2 - x1) * (x - x1) + y1;
			}else{
				y = (y4 - y3) / (double)(x4 - x3) * (x - x3) + y3;
			}
			cout << setprecision(2) << fixed << "POINT " << x << " " << y << "\n";
		}else if((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1)){
			cout << "LINE\n";
		}else{
			cout << "NONE\n";
		}
	}
	return 0;
}
