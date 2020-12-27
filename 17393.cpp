#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int paint(vector<long long> &b, int n, long long x, int i){
	int low = i + 1, high = n + 1;
	while(low < high){
		int mid = (low + high) / 2;
		if(b[mid] <= x){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - i - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	for(int i = 1; i <= n; ++i){
		cout << paint(b, n, a[i], i) << ' ';
	}
	return 0;
}
