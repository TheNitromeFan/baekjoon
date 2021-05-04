#include <iostream>
#include <vector>
#include <set>

using namespace std;

void insert_sum(set<int> &sums, vector<int> &s, int n, int pos, int cur_sum){
	if(pos == n){
		sums.insert(cur_sum);
		return;
	}
	insert_sum(sums, s, n, pos + 1, cur_sum);
	insert_sum(sums, s, n, pos + 1, cur_sum + s[pos]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	set<int> sums;
	insert_sum(sums, s, n, 0, 0);
	for(int cand = 1; ; ++cand){
		if(sums.find(cand) == sums.end()){
			cout << cand;
			break;
		}
	}
	return 0;
}
