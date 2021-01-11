#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int idx(vector<int> &a, int n, int x){
	int low = 0, high = n - 1;
	while(low < high){
		int mid = (low + high) / 2;
		if(a[mid] >= x){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	if(a[low] == x){
		return low;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int &ai : a){
		cin >> ai;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < m; ++i){
		int x;
		cin >> x;
		cout << idx(a, n, x) << '\n';
	}
	return 0;
}
