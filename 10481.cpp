#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> ternary;
		while(n > 0){
			ternary.push_back(n % 3);
			n /= 3;
		}
		ternary.push_back(0);
		for(unsigned i = 0; i + 1 < ternary.size(); ++i){
			if(ternary[i] >= 2){
				ternary[i] -= 3;
				++ternary[i + 1];
			}
		}
		vector<long long> left, right;
		long long weight = 1;
		for(unsigned i = 0; i < ternary.size(); ++i, weight *= 3){
			if(ternary[i] == -1){
				left.push_back(weight);
			}else if(ternary[i] == 1){
				right.push_back(weight);
			}
		}
		reverse(left.begin(), left.end());
		reverse(right.begin(), right.end());
		cout << "left pan:";
		for(long long x : left){
			cout << ' ' << x;
		}
		cout << '\n';
		cout << "right pan:";
		for(long long x : right){
			cout << ' ' << x;
		}
		cout << '\n';
		cout << '\n';
	}
	return 0;
}
