#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int prev;
	cin >> prev;
	int empty = 0, missed = 0;
	for(int i = 1; i < n; ++i){
		int cur;
		cin >> cur;
		if(prev > cur){
			empty += prev - cur;
		}else if(prev < cur){
			missed += cur - prev;
		}
		prev = cur;
	}
	cout << empty << ' ' << missed;
	return 0;
}
