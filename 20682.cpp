#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len;
	cin >> n >> len;
	vector<int> pos(n);
	for(int i = 0; i < n; ++i){
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	int last = pos[0];
	int ans = 0;
	for(int i = 1; i < n; ++i){
		if(pos[i] - last < len){
			++ans;
		}else{
			last = pos[i];
		}
	}
	cout << ans;
	return 0;
}
