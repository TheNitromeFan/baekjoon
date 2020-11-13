#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	queue<int> q;
	map<int, pair<int, bool>> m;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(m.find(x) == m.end()){
			m[x] = make_pair(1, false);
		}else{
			++m[x].first;
		}
		q.push(x);
	}
	vector<pair<int, int>> w;
	for(int i = 0; i < n; ++i){
		int x = q.front();
		q.pop();
		if(!m[x].second){
			w.push_back(make_pair(x, m[x].first));
			m[x].second = true;
		}
	}
	stable_sort(w.begin(), w.end(), cmp);
	for(pair<int, int> a : w){
		for(int j = 0; j < a.second; ++j){
			printf("%d ", a.first);
		}
	}
	return 0;
}
