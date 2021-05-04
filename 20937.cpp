#include <iostream>
#define MAX 50001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt[MAX] = {};
	int max = 0;
	for(int i = 0; i < n; ++i){
		int ci;
		cin >> ci;
		++cnt[ci];
		if(cnt[ci] > max){
			max = cnt[ci];
		}
	}
	cout << max;
	return 0;
}
