#include <iostream>
#define MAX 1234567
#define MIL 1000000

using namespace std;

long long f(long long arr[MAX], long long k){
	long long ret = 0;
	for(long long i = 1; i * i <= k; ++i){
		ret += arr[i] * k / (i * i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long arr[MAX] = {};
	arr[1] = 1;
	for(long long i = 1; i <= MIL; ++i){
		for(long long j = 2 * i; j <= MIL; j += i){
			arr[j] -= arr[i];
		}
	}
	long long k;
	cin >> k;
	long long start = 0, end = 100000000000LL;
	while(start + 1 < end){
		long long mid = (start + end) / 2;
		if(mid - f(arr, mid) < k){
			start = mid;
		}else{
			end = mid;
		}
	}
	cout << end;
	return 0;
}
