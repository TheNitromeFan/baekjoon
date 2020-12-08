#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> scores(n);
	for(int i = 0; i < n; ++i){
		cin >> scores[i];
	}
	sort(scores.begin(), scores.end(), greater<int>());
	int ans = k;
	while(ans < n && scores[ans] == scores[k - 1]){
		++ans;
	}
	cout << ans;
	return 0;
}
