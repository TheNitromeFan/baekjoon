#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << fixed << setprecision(4);
	for(int i = 0; i < n; ++i){
		double num;
		string unit;
		cin >> num >> unit;
		if(unit == "kg"){
			num *= 2.2046;
			unit = "lb";
		}else if(unit == "lb"){
			num *= 0.4536;
			unit = "kg";
		}else if(unit == "l"){
			num *= 0.2642;
			unit = "g";
		}else if(unit == "g"){
			num *= 3.7854;
			unit = "l";
		}
		cout << round(num * 10000) / 10000 << ' ' << unit << '\n';
	}
	return 0;
}
