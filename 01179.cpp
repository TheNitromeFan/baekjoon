#include <iostream>

using namespace std;

long long josephus(long long n, int k){
	if(n == 1){
		return 0LL;
	}
	if(k == 1){
		return n-1;
	}
	if(n < k){
		return (josephus(n-1, k) + k) % n;
	}
	long long cnt = n/k;
	long long res = josephus(n - cnt, k);
	res -= n % k;
	if(res < 0){
		res += n;
	}else{
		res += res / (k-1);
	}
	return res;
}

int main(){
	long long n;
	int k;
	cin >> n >> k;
	cout << josephus(n, k) + 1;
	return 0;
}
