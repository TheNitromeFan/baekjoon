#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int ans = 0, cnt = 0;
	for(int i = 0; i < n; ++i){
		if(v[i]){
			++cnt;
			if(ans < cnt){
				ans = cnt;
			}
		}else{
			cnt = 0;
		}
	}
	if(ans < cnt){
		ans = cnt;
	}
	cout << ans;
	return 0;
}
