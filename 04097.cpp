#include <iostream>
#include <algorithm>
#define MIN -1000000000000000000LL

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		long long best_sum = MIN;
		long long current_sum = 0;
		for(int i = 0; i < n; ++i){
			long long x;
			cin >> x;
			current_sum = max(x, current_sum + x);
			best_sum = max(best_sum, current_sum);
		}
		cout << best_sum << '\n';
	}
	return 0;
}
