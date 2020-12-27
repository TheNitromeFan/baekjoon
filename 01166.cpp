#include <iostream>
#include <iomanip>

using namespace std;

double a(int n, int l, int w, int h){
	double low = 0.00001, high = 2000000000;
	for(int i = 0; i < 1000; ++i){
		double mid = (low + high) / 2;
		if((long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid) >= n){
			low = mid;
		}else{
			high = mid;
		}
	}
	return low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, w, h;
	cin >> n >> l >> w >> h;
	cout << fixed << setprecision(10) << a(n, l, w, h);
	return 0;
}
