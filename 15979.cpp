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
	int n, m;
	cin >> n >> m;
	if(n < 0){
		n *= -1;
	}
	if(m < 0){
		m *= -1;
	}
	if(n == 0 && m == 0){
		cout << 0;
	}else if(gcd(n, m) == 1){
		cout << 1;
	}else{
		cout << 2;
	}
	return 0;
}
