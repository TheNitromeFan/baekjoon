#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

bool allCoprime(int a[1000], int n, int i){
	for(int j = 0; j < n; ++j){
		if(j == i){
			continue;
		}
		if(gcd(a[j], a[i]) > 1){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		int a[1000];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n, greater<int>());
		for(int i = 0; i < n; ++i){
			if(allCoprime(a, n, i)){
				printf("%d\n", a[i]);
				break;
			}
		}
	}
	return 0;
}
