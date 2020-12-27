#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bales(vector<int> &v, int n, int x){
	int low = 1, high = n + 1;
	while(low < high){
		int mid = (low + high) / 2;
		if(v[mid] <= x){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	sort(v.begin() + 1, v.end());
	for(int j = 0; j < q; ++j){
		int a, b;
		cin >> a >> b;
		cout << bales(v, n, b) - bales(v, n, a - 1) << '\n';
	}
	return 0;
}
