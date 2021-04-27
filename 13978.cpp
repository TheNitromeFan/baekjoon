#include <iostream>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, r;
	cin >> n >> k >> r;
	bool cam[MAX] = {};
	for(int i = 0; i < k; ++i){
		int x;
		cin >> x;
		cam[x] = true;
	}
	int cnt = 0;
	for(int j = 1; j <= r; ++j){
		if(cam[j]){
			++cnt;
		}
	}
	int ans = 0;
	if(cnt == 0){
		cam[r - 1] = true;
		cam[r] = true;
		cnt = 2;
		ans = 2;
	}else if(cnt == 1 && cam[r]){
		cam[r - 1] = true;
		cnt = 2;
		ans = 1;
	}else if(cnt == 1){
		cam[r] = true;
		cnt = 2;
		ans = 1;
	}
	int i = 1, j = r;
	while(j < n){
		if(cam[j + 1]){
			++cnt;
		}
		++j;
		if(cam[i]){
			--cnt;
		}
		++i;
		if(cnt == 1){
			cam[j] = true;
			cnt = 2;
			++ans;
		}
	}
	cout << ans;
	return 0;
}
