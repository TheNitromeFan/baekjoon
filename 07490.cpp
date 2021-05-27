#include <iostream>
#include <vector>

using namespace std;

void sequence(int n, int reps, int sign, int cur, int sum, vector<char> &ops){
	if(reps == n){
		sum += sign * cur;
		if(sum == 0){
			for(int i = 1; i < n; ++i){
				cout << i << ops[i - 1];
			}
			cout << n << '\n';
		}
		return;
	}
	ops.push_back(' ');
	sequence(n, reps + 1, sign, cur * 10 + reps + 1, sum, ops);
	ops.pop_back();
	ops.push_back('+');
	sequence(n, reps + 1, 1, reps + 1, sum + sign * cur, ops);
	ops.pop_back();
	ops.push_back('-');
	sequence(n, reps + 1, -1, reps + 1, sum + sign * cur, ops);
	ops.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<char> ops;
		sequence(n, 1, 1, 1, 0, ops);
		cout << '\n';
	}
	return 0;
}
