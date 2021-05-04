#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> nums;
	for(int x = 1; x <= n; ++x){
		if(x % 10 != k % 10 && x % 10 != 2 * k % 10){
			nums.push_back(x);
		}
	}
	cout << nums.size() << '\n';
	for(int x : nums){
		cout << x << ' ';
	}
	return 0;
}
