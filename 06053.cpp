#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; ++i){
		cin >> h[i];
	}
	int idx = 0;
	int maxWidth = 0;
	while(idx < n){
		int start = idx;
		while(idx + 1 < n && h[idx + 1] >= h[idx]){
			++idx;
		}
		while(idx + 1 < n && h[idx + 1] <= h[idx]){
			++idx;
		}
		int width = idx - start + 1;
		if(maxWidth < width){
			maxWidth = width;
		}
		if(idx == n - 1){
			break;
		}
		while(idx - 1 >= 0 && h[idx - 1] == h[idx]){
			--idx;
		}
	}
	cout << maxWidth;
	return 0;
}
