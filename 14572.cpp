#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d;
	cin >> n >> k >> d;
	vector<pair<int, int>> students(n);
	for(int i = 0; i < n; ++i){
		int m;
		cin >> m >> students[i].first;
		for(int j = 0; j < m; ++j){
			int x;
			cin >> x;
			students[i].second |= 1 << (x - 1);
		}
	}
	sort(students.begin(), students.end());
	int left = 0, right = 0;
	int cnt[30] = {};
	int ans = 0;
	while(right < n){
		while(students[right].first - students[left].first > d){
			for(int i = 0; i < k; ++i){
				if(students[left].second & (1 << i)){
					--cnt[i];
				}
			}
			++left;
		}
		for(int i = 0; i < k; ++i){
			if(students[right].second & (1 << i)){
				++cnt[i];
			}
		}
		int c = 0;
		for(int i = 0; i < k; ++i){
			if(cnt[i] > 0 && cnt[i] < right - left + 1){
				++c;
			}
		}
		ans = max(ans, c * (right - left + 1));
		++right;
	}
	cout << ans << '\n';
	return 0;
}
