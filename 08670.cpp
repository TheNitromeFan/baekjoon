#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	int max = 0;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(max < v[i]){
			max = v[i];
		}
		if(max == i){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
