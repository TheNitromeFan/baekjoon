#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		long long w, h;
		cin >> w >> h;
		if(w == 0 && h == 0){
			break;
		}
		long long g = gcd(w, h);
		cout << (w / g) * (h / g) << '\n';
	}
	return 0;
}
