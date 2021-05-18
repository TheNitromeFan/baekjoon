#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double a, double b, double c, double x){
	return a * x + b * sin(x) - c;
}

double df(double a, double b, double x){
	return a + b * cos(x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double a, b, c;
	cin >> a >> b >> c;
	double x = (c - b) / a;
	for(int i = 0; i < 500; ++i){
		x -= f(a, b, c, x) / df(a, b, x);
	}
	cout << fixed << setprecision(6) << x;
	return 0;
}
