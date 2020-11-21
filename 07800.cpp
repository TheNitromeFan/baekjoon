#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::sort;
using std::find;
using std::greater;

bool cmp(vector<int> a, vector<int> b){
	if(a.size() < b.size()){
		return true;
	}else if(a.size() > b.size()){
		return false;
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	for(unsigned i = 0; i < a.size(); ++i){
		if(a[i] > b[i]){
			return true;
		}else if(a[i] < b[i]){
			return false;
		}
	}
	return false;
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		int s[11][11];
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &s[i][j]);
			}
		}
		vector<int> min_entries(m * m + 1);
		int min_x = 0, min_y = 0;
		for(int x = 1; x + m - 1 <= n; ++x){
			for(int y = 1; y + m - 1 <= n; ++y){
				vector<int> entries;
				for(int i = x; i < x + m; ++i){
					for(int j = y; j < y + m; ++j){
						if(find(entries.begin(), entries.end(), s[i][j]) == entries.end()){
							entries.push_back(s[i][j]);
						}
					}
				}
				if(cmp(entries, min_entries)){
					min_entries = entries;
					min_x = x;
					min_y = y;
				}
			}
		}
		printf("%d %d\n", min_x, min_y);
	}
	return 0;
}
