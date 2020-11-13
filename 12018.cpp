#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> mileages;
	for(int i = 0; i < n; ++i){
		int p, ell;
		scanf("%d %d", &p, &ell);
		vector<int> invested;
		for(int j = 0; j < p; ++j){
			int x;
			scanf("%d", &x);
			invested.push_back(x);
		}
		if(ell > p){
			mileages.push_back(1);
			continue;
		}
		sort(invested.begin(), invested.end(), greater<int>());
		mileages.push_back(invested[ell - 1]);
	}
	sort(mileages.begin(), mileages.end());
	int ans = 0;
	int idx = 0;
	while(idx < n && m >= mileages[idx]){
		m -= mileages[idx];
		++ans;
		++idx;
	}
	printf("%d", ans);
	return 0;
}
