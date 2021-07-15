#include <iostream>
#include <vector>

using namespace std;

int find_cashier(vector<int> &cashier, int n){
	int ret = 0;
	int min_cashier = 100000000;
	for(int i = 1; i <= n; ++i){
		if(cashier[i] < min_cashier){
			ret = i;
			min_cashier = cashier[i];
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	vector<int> cashier(n + 1);
	for(int j = 0; j < c; ++j){
		int t;
		cin >> t;
		int idx = find_cashier(cashier, n);
		int x = cashier[idx];
		for(int i = 1; i <= n; ++i){
			cashier[i] -= x;
		}
		cashier[idx] = t;
		cout << idx << ' ';
	}
	return 0;
}
