#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> w(2 * n);
	for(int i = 0; i < 2 * n; ++i){
		cin >> w[i];
	}
	sort(w.begin(), w.end());
	int sm = 300000;
	for(int i = 0, j = 2 * n - 1; i < j; ++i, --j){
		if(sm > w[i] + w[j]){
			sm = w[i] + w[j];
		}
	}
	cout << sm;
	return 0;
}
