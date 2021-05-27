#include <iostream>
#define MAX 1000005

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int a0 = 0; a0 < z; ++a0){
		int n;
		cin >> n;
		int a[MAX] = {};
		long long p[MAX] = {};
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			++p[a[i]];
		}
		for(int i = 0; i < 20; ++i){
			for(int j = 0; j < MAX; ++j){
				if(j & (1 << i)){
					p[j] += p[j ^ (1 << i)];
				}
			}
		}
		long long ans = 0;
		for(int i = 0; i < n; ++i){
			ans += p[a[i]];
		}
		cout << ans << '\n';
	}
	return 0;
}
