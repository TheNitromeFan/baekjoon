#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> bulbs(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> bulbs[i];
	}
	for(int j = 0; j < m; ++j){
		int a;
		cin >> a;
		if(a == 1){
			int i, x;
			cin >> i >> x;
			bulbs[i] = x;
		}else if(a == 2){
			int left, right;
			cin >> left >> right;
			for(int i = left; i <= right; ++i){
				bulbs[i] = !bulbs[i];
			}
		}else if(a == 3){
			int left, right;
			cin >> left >> right;
			for(int i = left; i <= right; ++i){
				bulbs[i] = 0;
			}
		}else{
			int left, right;
			cin >> left >> right;
			for(int i = left; i <= right; ++i){
				bulbs[i] = 1;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << bulbs[i] << ' ';
	}
	return 0;
}
