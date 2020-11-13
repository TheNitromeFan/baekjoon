#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int main(){
	int n, m;
	scanf("%d %d ", &n, &m);
	vector<int> points(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d ", &points[i]);
	}
	vector<pair<int, int>> testers;
	testers.resize(m);
	for(int j = 0; j < m; ++j){
		scanf("%d ", &testers[j].first);
		testers[j].second = 0;
		for(int i = 0; i < n; ++i){
			char correct;
			scanf("%c ", &correct);
			if(correct == 'O'){
				testers[j].second += points[i];
			}
		}
	}
	sort(testers.begin(), testers.end(), cmp);
	printf("%d %d", testers[0].first, testers[0].second);
	return 0;
}
