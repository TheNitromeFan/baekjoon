#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int range_gcd(int a[MAX], int start, int end){
	int ret = 0;
	for(int i = start; i < end; ++i){
		ret = gcd(ret, a[i]);
	}
	return ret;
}

int sum_gcd(int a[MAX], int start, int end){
	int n = end - start;
	if(n == 1){
		return a[start];
	}
	int mid = start + n / 2;
	return max(range_gcd(a, start, mid) + sum_gcd(a, mid, end), range_gcd(a, mid, end) + sum_gcd(a, start, mid));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	cout << sum_gcd(a, 0, n);
	return 0;
}
