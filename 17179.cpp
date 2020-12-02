#include <iostream>
#include <vector>

using namespace std;

bool can_cut(vector<int> &cuts, int m, int c, int length){
	int cnt = 0, last = 0;
	for(int i = 1; i <= m + 1; ++i){
		if(cuts[i] - cuts[last] >= length){
			last = i;
			++cnt;
		}
	}
	return cnt > c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> cuts(m + 2);
	for(int i = 1; i <= m; ++i){
		cin >> cuts[i];
	}
	cuts[m + 1] = l;
	for(int j = 0; j < n; ++j){
		int q;
		cin >> q;
		int low = 1, high = l;
		while(low < high){
			int mid = (low + high) / 2;
			if(can_cut(cuts, m, q, mid)){
				low = mid + 1;
			}else{
				high = mid;
			}
		}
		cout << low - 1 << '\n';
	}
	return 0;
}
