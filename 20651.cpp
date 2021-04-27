#include <iostream>
#define MAX 101

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p[MAX], psum[MAX] = {};
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> p[i];
		psum[i] = psum[i - 1] + p[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			int sum = psum[j] - psum[i - 1];
			int len = j - i + 1;
			if(sum % len != 0){
				continue;
			}
			int avg = sum / len;
			for(int k = i; k <= j; ++k){
				if(p[k] == avg){
					++cnt;
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
