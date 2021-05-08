#include <iostream>
#include <unordered_map>

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
		unordered_map<int, int> m;
		int max = 0;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			++m[x];
			if(max < m[x]){
				max = m[x];
			}
		}
		cout << max << '\n';
	}
	return 0;
}
