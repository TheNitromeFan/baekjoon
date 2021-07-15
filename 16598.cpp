#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p;
	cin >> n >> p;
	vector<int> d(n);
	for(int i = 0; i < n; ++i){
		cin >> d[i];
	}
	int i = 0, j = 0;
	int ans = 0;
	while(i < n){
		while(j < n && (d[j] - d[i]) - (j - i) <= p){
			++j;
		}
		ans = max(ans, p + j - i);
		++i;
	}
	cout << ans << '\n';
	return 0;
}
