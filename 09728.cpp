#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		long long m;
		cin >> n >> m;
		vector<long long> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		int i = 0, j = n - 1;
		int ans = 0;
		while(i < j){
			if(v[i] + v[j] == m){
				++ans;
				++i;
				--j;
			}else if(v[i] + v[j] > m){
				--j;
			}else{
				++i;
			}
		}
		cout << "Case #" << a0 << ": " << ans << "\n";
	}
	return 0;
}
