#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int closest_element(vector<int> &b, int m, int x){
	if(x <= b.front()){
		return b.front();
	}else if(x >= b.back()){
		return b.back();
	}
	int low = 0, high = m - 1;
	int ans = (low + high) / 2;
	while(low <= high){
		int mid = (low + high) / 2;
		if(abs(b[mid] - x) < abs(b[ans] - x) || (abs(b[mid] - x) == abs(b[ans] - x) && mid < ans)){
			ans = mid;
		}
		if(b[mid] == x){
			break;
		}else if(b[mid] > x){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return b[ans];
}

long long c_sum(vector<int> &a, vector<int> &b, int m){
	long long sum = 0;
	for(int x : a){
		sum += closest_element(b, m, x);
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int j = 0; j < m; ++j){
			cin >> b[j];
		}
		sort(b.begin(), b.end());
		cout << c_sum(a, b, m) << '\n';
	}
	return 0;
}
