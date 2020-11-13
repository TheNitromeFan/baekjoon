#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	double x, y;
	cin >> x >> y;
	for(int i = 1; i < n; ++i){
		string dir;
		double d;
		cin >> dir >> d;
		if(dir == "N"){
			y += d;
		}else if(dir == "NE"){
			x += d / sqrt(2);
			y += d / sqrt(2);
		}else if(dir == "E"){
			x += d;
		}else if(dir == "SE"){
			x += d / sqrt(2);
			y -= d / sqrt(2);
		}else if(dir == "S"){
			y -= d;
		}else if(dir == "SW"){
			x -= d / sqrt(2);
			y -= d / sqrt(2);
		}else if(dir == "W"){
			x -= d;
		}else{
			x -= d / sqrt(2);
			y += d / sqrt(2);
		}
	}
	cout << fixed << setprecision(10) << x << ' ' << y;
	return 0;
}
