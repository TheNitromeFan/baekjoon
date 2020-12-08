#include <iostream>
#define MAX 1000000000

using namespace std;

int build(int a[1001], int n, int k, int pivot){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] - (a[pivot] + k * (i - pivot)) != 0){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int a[1001];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = 1000000000;
	for(int i = 0; i < n; ++i){
		if(a[i] - i * k <= 0){
			continue;
		}
		int cmp = build(a, n, k, i);
		if(ans > cmp){
			ans = cmp;
		}
	}
	cout << ans;
	return 0;
}
