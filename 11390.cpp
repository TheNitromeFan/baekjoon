#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long c[41][41];

void get_combinations(int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= i; ++j){
			if(j == 0 || j == i){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i-1][j-1] + c[i-1][j];
			}
		}
	}
}

int get_rank(int n, long long k){
	get_combinations(n);
	for(int i = 0; i <= n; ++i){
		if(k <= c[n][i]){
			return i;
		}else{
			k -= c[n][i];
		}
	}
	return n;
}

int main(){
	int a, b;
	cin >> a >> b;
	if(a > b){
		swap(a, b);
	}
	int n;
	long long k;
	cin >> n >> k;
	int r = get_rank(n, k);
	double log_size = log(a * b / 2.0);
	for(int i = 0; i < r; ++i){
		log_size += 2*log(a) - log(a*a+b*b);
	}
	for(int i = 0; i < n-r; i++){
		log_size += 2*log(b) - log(a*a+b*b);
	}
	printf("%.16f", log_size);
	return 0;
}
