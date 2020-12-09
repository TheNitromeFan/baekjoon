#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double area(double a, double b, double c){
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double ha, hb, hc;
	cin >> ha >> hb >> hc;
	double low = 0, high = 10000;
	double a, b, c;
	for(int i = 0; i < 1000; ++i){
		a = (low + high) / 2;
		b = ha / hb * a;
		c = ha / hc * a;
		if(area(a, b, c) >= a * ha / 2){
			high = a;
		}else{
			low = a;
		}
	}
	a = low;
	b = ha / hb * a;
	c = ha / hc * a;
	cout << setprecision(11) << fixed << area(a, b, c);
	return 0;
}
