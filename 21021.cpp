#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; ++i){
		cin >> c[i];
	}
	if(n == 1){
		cout << (c[0] > 0);
		return 0;
	}
	vector<bool> prize(n);
	if(c[0] > 0 && !prize[0]){
		--c[0];
		prize[0] = true;
	}
	if(c[0] > 0 && !prize[1]){
		--c[0];
		prize[1] = true;
	}
	for(int i = 1; i < n - 1; ++i){
		if(c[i] > 0 && !prize[i - 1]){
			--c[i];
			prize[i - 1] = true;
		}
		if(c[i] > 0 && !prize[i]){
			--c[i];
			prize[i] = true;
		}
		if(c[i] > 0 && !prize[i + 1]){
			--c[i];
			prize[i + 1] = true;
		}
	}
	if(c[n - 1] > 0 && !prize[n - 2]){
		--c[n - 1];
		prize[n - 2] = true;
	}
	if(c[n - 1] > 0 && !prize[n - 1]){
		--c[n - 1];
		prize[n - 1] = true;
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(prize[i]){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
