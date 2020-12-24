#include <iostream>
#include <cmath>

using namespace std;

long long pixels(long long r){
	long long ret = 0;
	for(long long x = 0; x <= r; ++x){
		long long y = (long long)sqrt(r * r - x * x);
		if(x * x + y * y == r * r){
			ret += y;
		}else{
			ret += y + 1;
		}
	}
	ret *= 4;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x, y, r;
	while(true){
		cin >> x >> y >> r;
		if(x == 0 && y == 0 && r == 0){
			break;
		}
		cout << pixels(r) << '\n';
	}
	return 0;
}
