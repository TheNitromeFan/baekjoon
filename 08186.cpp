#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<pair<int, int>, int> num[200000];

void setnum(int rank[200000], int i, int s, int n){
	num[i] = make_pair(make_pair(rank[i], i + s < n ? rank[i + s] : n), i);
}

void renumber(int rank[200000], int n){
	sort(num, num + n);
	rank[num[0].second] = 0;
	for(int i = 1; i < n; ++i){
		rank[num[i].second] = rank[num[i-1].second];
		if(num[i - 1].first != num[i].first){
			++rank[num[i].second];
		}
	}
}

vector<int> kmr(int beads[200000], int n, int r){
	for(int k = 0; k * 2 <= r; (k ? k *= 2 : ++k)){
		for(int i = 0; i < n; ++i){
			setnum(beads, i, k, n);
		}
		renumber(beads, n);
	}
	for(int i = 0; i < n; ++i){
		setnum(beads, i, r, n);
	}
	renumber(beads, n);
	vector<int> ans(beads, beads + n);
	return ans;
}

int main(){
	int n;
	cin >> n;
	int beads[200000];
	for(int i = 0 ; i < n; ++i){
		cin >> beads[i];
	}
	vector<int> ans = kmr(beads, n, 2);
	for(int i = 0; i < n; ++i){
		printf("%d ", ans[i]);
	}
	return 0;
}
