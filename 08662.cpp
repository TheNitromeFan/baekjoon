#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		if(v[i] < i + 1){
			cout << -1;
			return 0;
		}
	}
	int cnt = 0;
	for(int i = n - 2; i >= 0; --i){
		if(v[i] >= v[i + 1]){
			++cnt;
			v[i] = v[i + 1] - 1;
		}
	}
	cout << cnt;
	return 0;
}
