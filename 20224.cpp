#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		int cnt = 0;
		for(int i = 0; i + 3 < n; ++i){
			if(v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 2 && v[i + 3] == 0){
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
