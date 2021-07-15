#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	a.push_back(1000000001);
	b.push_back(1000000001);
	int milk = n * x;
	int ans = milk;
	int i = 0, j = 0;
	while(i < n){
		if(i == n || a[i] > b[j]){
			milk += z - y;
			++j;
		}else{
			milk += y - x;
			++i;
		}
		ans = max(ans, milk);
	}
	cout << ans << '\n';
	return 0;
}
