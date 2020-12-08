#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

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
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	int ans1 = v[0], ans2 = v[n - 1];
	while(i < j){
		if(abs(ans1 + ans2) > abs(v[i] + v[j])){
			ans1 = v[i];
			ans2 = v[j];
		}
		if(v[i] + v[j] >= 0){
			--j;
		}else{
			++i;
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
