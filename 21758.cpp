#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX], psum[MAX] = {};
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 2; i < n; ++i){
		ans = max(ans, psum[n - 1] - psum[1] + a[i]);
	}
	for(int i = 2; i < n; ++i){
		ans = max(ans, psum[n] - psum[1] + psum[n] - psum[i] - a[i]);
	}
	for(int i = 2; i < n; ++i){
		ans = max(ans, psum[n - 1] + psum[i - 1] - a[i]);
	}
	cout << ans;
	return 0;
}
