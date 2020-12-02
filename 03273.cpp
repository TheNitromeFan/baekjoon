#include <iostream>
#include <vector>
#include <algorithm>

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
	int x;
	cin >> x;
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	int ans = 0;
	while(i < j){
		if(v[i] + v[j] == x){
			int cnt1 = 0, cnt2 = 0;
			int k = i, l = j;
			while(k < n && v[k] + v[j] == x){
				++k;
				++cnt1;
			}
			while(l >= 0 && v[i] + v[l] == x){
				--l;
				++cnt2;
			}
			if(k <= l + 1){
				ans += cnt1 * cnt2;
			}else{
				ans += (k - i) * (k - i - 1) / 2;
			}
			i = k;
			j = l;
		}else if(v[i] + v[j] < x){
			++i;
		}else{
			--j;
		}
	}
	cout << ans;
	return 0;
}
