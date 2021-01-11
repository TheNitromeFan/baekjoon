#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int first_disagreement(vector<int> &aIdx, vector<int> &bIdx, int n){
	for(int i = 0; i < n; ++i){
		if(aIdx[i] != bIdx[i]){
			return i + 1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	int n;
	while(cin >> n){
		++t;
		vector<int> a(n), b(n);
		for(int &ai : a){
			cin >> ai;
		}
		for(int &bi : b){
			cin >> bi;
		}
		vector<int> aIdx(n), bIdx(n);
		for(int i = 0; i < n; ++i){
			aIdx[i] = i;
			bIdx[i] = i;
		}
		sort(aIdx.begin(), aIdx.end(), [&a](int x, int y){
			return a[x] > a[y];
		});
		sort(bIdx.begin(), bIdx.end(), [&b](int x, int y){
			return b[x] > b[y];
		});
		int ans = first_disagreement(aIdx, bIdx, n);
		cout << "Case " << t << ": ";
		if(ans == -1){
			cout << "agree\n";
		}else{
			cout << ans << "\n";
		}
	}
	return 0;
}
