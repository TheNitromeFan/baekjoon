#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> small(a), big(b);
	for(int i = 0; i < a; ++i){
		cin >> small[i];
	}
	for(int j = 0; j < b; ++j){
		cin >> big[j];
	}
	sort(small.begin(), small.end(), greater<int>());
	sort(big.begin(), big.end(), greater<int>());
	int i = 0, j = 0;
	int ans = 0;
	if(n % 2 == 1){
		ans += small[i];
		++i;
		--n;
	}
	for(int k = 0; k < n; k += 2){
		if(i + 2 <= a && small[i] + small[i + 1] > big[j]){
			ans += small[i] + small[i + 1];
			i += 2;
		}else{
			ans += big[j];
			++j;
		}
	}
	cout << ans << '\n';
	return 0;
}
