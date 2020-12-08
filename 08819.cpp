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
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int n;
		cin >> n;
		for(int j = 1; j <= n; ++j){
			if(gcd(n, j) == 1){
				cout << j << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
