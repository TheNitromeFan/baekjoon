#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> b(n + 1), psum(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
		psum[i] = psum[i - 1] + b[i];
	}
	for(int j = 1; j <= q; ++j){
		int t;
		cin >> t;
		int low = 1, high = n;
		while(low < high){
			int mid = (low + high) / 2;
			if(psum[mid] <= t){
				low = mid + 1;
			}else{
				high = mid;
			}
		}
		cout << low << '\n';
	}
	return 0;
}
