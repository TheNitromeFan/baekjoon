#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
	}
	vector<int> seen(n + 1, 1);
	for(int j = 0; j < n * k; ++j){
		int x;
		cin >> x;
		cout << seen[x] << ' ';
		++seen[x];
	}
	return 0;
}
