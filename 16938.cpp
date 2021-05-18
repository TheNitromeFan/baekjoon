#include <iostream>
#include <vector>

using namespace std;

int select(vector<int> &a, int n, int left, int right, int x, int cur, int min, int max, int sum, int selected){
	if(cur > n){
		return selected >= 2 && sum >= left && sum <= right && max - min >= x;
	}
	if(sum > right){
		return 0;
	}
	int ret = select(a, n, left, right, x, cur + 1, min, max, sum, selected);
	if(a[cur] < min){
		min = a[cur];
	}
	if(a[cur] > max){
		max = a[cur];
	}
	sum += a[cur];
	++selected;
	ret += select(a, n, left, right, x, cur + 1, min, max, sum, selected);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, left, right, x;
	cin >> n >> left >> right >> x;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	cout << select(a, n, left, right, x, 1, 1000000000, -1000000000, 0, 0);
	return 0;
}
