#include <iostream>

using namespace std;

int phi[25] = {0, 1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8, 8, 16, 6, 18, 8, 12, 10, 22, 8};

long long pow(long long base, int exp){
	if(exp == 1){
		return base;
	}else if(exp % 2 == 0){
		return pow(base * base, exp/2);
	}else{
		return pow(base * base, exp/2) * base;
	}
}

long long necklaces(int n){
	long long tmp = 0;
	for(int d = 1; d <= n; ++d){
		if(n % d == 0){
			tmp += phi[d] * pow(3, n/d);
		}
	}
	return tmp / n;
}

long long bracelets(int n){
	long long neck = necklaces(n);
	if(n % 2 == 0){
		return neck/2 + pow(3, n/2);
	}else{
		return (neck + pow(3, (n+1)/2))/2;
	}
}

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == -1){
			break;
		}else if(n == 0){
			cout << 0 << '\n';
			continue;
		}
		cout << bracelets(n) << '\n';
	}
	return 0;
}
