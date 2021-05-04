#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

double norm(double a, double b, double c){
	return sqrt(a * a + b * b + c * c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string star1, star2;
		double x1, y1, z1, x2, y2, z2;
		getline(cin, star1);
		getline(cin, star1);
		cin >> x1 >> y1 >> z1;
		getline(cin, star2);
		getline(cin, star2);
		cin >> x2 >> y2 >> z2;
		cout << star1 << " to " << star2 << ": "
		<< fixed << setprecision(2) << norm(x2 - x1, y2 - y1, z2 - z1) << "\n";
	}
	return 0;
}
