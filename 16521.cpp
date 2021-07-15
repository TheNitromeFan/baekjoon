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
	int r1, r2;
	char c;
	cin >> r1 >> c >> r2;
	cout << 36000 / gcd(36000, 100 * r1 + r2) << '\n';
	return 0;
}
