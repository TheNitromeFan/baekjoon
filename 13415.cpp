#include <cstdio>
#include <deque>
#include <algorithm>
#include <utility>
#define MAX (100000 + 1)

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int k;
	scanf("%d", &k);
	deque<pair<int, bool>> d;
	for(int j = 0; j < k; ++j){
		int up, down;
		scanf("%d %d", &up, &down);
		while(!d.empty() && d.back().first <= up){
			d.pop_back();
		}
		if(up > 1){
			d.push_back(make_pair(up, true));
		}
		while(!d.empty() && d.back().first <= down){
			d.pop_back();
		}
		if(down > 1){
			d.push_back(make_pair(down, false));
		}
	}
	d.push_back(make_pair(0, true));
	int result[MAX];
	auto item = d.front();
	d.pop_front();
	int end = item.first;
	int max_idx = end;
	bool up = item.second;
	int asc_idx = end, desc_idx = 1;
	sort(a + 1, a + max_idx + 1);
	while(!d.empty()){
		item = d.front();
		d.pop_front();
		int start = item.first;
		if(up){
			for(int i = end; i > start; --i){
				result[i] = a[asc_idx];
				--asc_idx;
			}
		}else{
			for(int i = end; i > start; --i){
				result[i] = a[desc_idx];
				++desc_idx;
			}
		}
		up = item.second;
		end = start;
	}
	for(int i = 1; i <= max_idx; ++i){
		printf("%d ", result[i]);
	}
	for(int i = max_idx + 1; i <= n; ++i){
		printf("%d ", a[i]);
	}
	return 0;
}
