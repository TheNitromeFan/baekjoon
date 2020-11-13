#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; ++i){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<pair<int, int>> books(m);
		for(int j = 0; j < m; ++j){
			scanf("%d %d", &books[j].first, &books[j].second);
		}
		sort(books.begin(), books.end(), cmp);
		int ans = 0;
		vector<bool> taken(n, false);
		for(int j = 0; j < m; ++j){
			for(int k = books[j].first; k <= books[j].second; ++k){
				if(!taken[k]){
					taken[k] = true;
					++ans;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
