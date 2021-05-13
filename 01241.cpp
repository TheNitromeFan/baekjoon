#include <iostream>
#define MAX 100001
#define MAXVAL 1000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int cnt[MAXVAL] = {};
	for(int i = 1; i <= n; ++i){
		++cnt[a[i]];
	}
	int bops[MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int d = 1; d * d <= a[i]; ++d){
			if(a[i] % d == 0){
				if(d * d < a[i]){
					bops[i] += cnt[d] + cnt[a[i] / d];
				}else{
					bops[i] += cnt[d];
				}
			}
		}
		--bops[i];
	}
	for(int i = 1; i <= n; ++i){
		cout << bops[i] << '\n';
	}
	return 0;
}
