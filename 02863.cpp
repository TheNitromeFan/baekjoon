#include <iostream>

using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	double max_val = a / (double)c + b / (double)d;
	double tmp = c / (double) d + a / (double)b;
	if(tmp > max_val){
		max_val = tmp;
		ans = 1;
	}
	tmp = d / (double)b + c / (double)a;
	if(tmp > max_val){
		max_val = tmp;
		ans = 2;
	}
	tmp = b / (double)a + d / (double)c;
	if(tmp > max_val){
		max_val = tmp;
		ans = 3;
	}
	cout << ans;
	return 0;
}
