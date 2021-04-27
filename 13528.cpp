#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double cost;
	cin >> cost;
	int lawns;
	cin >> lawns;
	double area = 0;
	for(int i = 0; i < lawns; ++i){
		double width, length;
		cin >> width >> length;
		area += width * length;
	}
	cout << fixed << setprecision(12) << cost * area;
	return 0;
}
