#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int b, d;
		cin >> b >> d;
		int g = gcd(b, d);
		cout << (b - 1) / (d / g) << '\n';
	}
	return 0;
}
