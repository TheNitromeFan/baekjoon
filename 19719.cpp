#include <iostream>
#include <vector>

using namespace std;

bool cash_gap(int s, vector<int> &deductions, vector<int> &payments, int m){
	for(int day = 1; day <= m; ++day){
		s += deductions[day];
		if(s < 0){
			return true;
		}
		s += payments[day];
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, s;
	cin >> n >> m >> s;
	vector<int> deductions(m + 1), payments(m + 1);
	for(int i = 0; i < n; ++i){
		int cnt, from, to;
		cin >> cnt >> from >> to;
		if(cnt > 0){
			payments[to] += cnt;
		}else{
			deductions[from] += cnt;
		}
	}
	cout << (cash_gap(s, deductions, payments, m) ? "YES" : "NO");
	return 0;
}
