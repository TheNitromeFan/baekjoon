#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a[MAX], psum[MAX] = {};
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	int max_so_far = 0, min_ending_here = 0;
	for(int i = m; i <= n; ++i){
		min_ending_here = min(min_ending_here, psum[i - m]);
		max_so_far = max(max_so_far, psum[i] - min_ending_here);
	}
	cout << max_so_far;
	return 0;
}
