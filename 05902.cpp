#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool fold_at_bead(vector<int> &beads, int n, int idx){
	for(int i = idx - 1, j = idx + 1; i >= 0 && j < n; --i, ++j){
		if(beads[j] - beads[idx] != beads[idx] - beads[i]){
			return false;
		}
	}
	return true;
}

bool fold_at_rope(vector<int> &beads, int n, int idx){
	for(int i = idx, j = idx + 1; i >= 0 && j < n; --i, ++j){
		if(beads[j] - beads[idx + 1] != beads[idx] - beads[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len;
	cin >> n >> len;
	vector<int> beads(n);
	for(int i = 0; i < n; ++i){
		cin >> beads[i];
	}
	sort(beads.begin(), beads.end());
	int cnt = 0;
	for(int i = 1; i < n - 1; ++i){
		if(fold_at_bead(beads, n, i)){
			++cnt;
		}
	}
	for(int i = 0; i < n - 1; ++i){
		if(fold_at_rope(beads, n, i)){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
