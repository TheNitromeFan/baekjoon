#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

bool power_of_2(int x){
	while(x > 1){
		if(x % 2 == 1){
			return false;
		}
		x /= 2;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	for(int i = 0; i < 5; ++i){
		int c, d;
		cin >> c >> d;
		if(a == b && c == d){
			cout << 'Y';
		}else if((long long)(b - a) * (d - c) <= 0){
			cout << 'N';
		}else{
			int x = abs(b - a), y = abs(d - c);
			x /= gcd(x, y);
			cout << (power_of_2(x) ? 'Y' : 'N');
		}
		cout << '\n';
	}
	return 0;
}
