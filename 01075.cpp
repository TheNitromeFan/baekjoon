#include <iostream>

using namespace std;

int main(){
	int n, f;
	cin >> n >> f;
	int significand = n / 100;
	for(int mantissa = 0; mantissa < 100; ++mantissa){
		if((significand * 100 + mantissa) % f == 0){
			if(mantissa < 10){
				cout << '0';
			}
			cout << mantissa << endl;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
