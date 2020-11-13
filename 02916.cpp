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
	int n, k;
	cin >> n >> k;
	int g = 360;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		g = gcd(g, x);
	}
	for(int j = 0; j < k; ++j){
		int a;
		cin >> a;
		if(a % g == 0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
