#include <iostream>

using namespace std;

bool prime(int n){
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int steps = 0;
	while(n > 3){
		++steps;
		if(prime(n - 2)){
			n -= 4;
			continue;
		}
		for(int p = 3; 2 * p <= n; p += 2){
			if(prime(p) && prime(n - p)){
				n -= 2 * p;
				break;
			}
		}
	}
	cout << steps;
	return 0;
}
