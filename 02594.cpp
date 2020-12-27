#include <iostream>
#define MAX 2000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool unrest[MAX] = {};
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int start, end;
		cin >> start >> end;
		int sh = start / 100, sm = start % 100, eh = end / 100, em = end % 100;
		for(int j = sh * 60 + sm; j < eh * 60 + em; ++j){
			unrest[j] = true;
		}
	}
	int ans = 0, cnt = 0;
	for(int j = 10 * 60 - 10; j < 22 * 60 + 10; ++j){
		if(unrest[j]){
			if(ans < cnt - 20){
				ans = cnt - 20;
			}
			cnt = 0;
		}else{
			++cnt;
		}
	}
	if(ans < cnt - 20){
		ans = cnt - 20;
	}
	cout << ans;
	return 0;
}
