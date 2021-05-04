#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void partitions(int n, vector<int> &nums){
	if(n == 0){
		for(int x : nums){
			cout << x << ' ';
		}
		cout << '\n';
	}
	if(nums.empty()){
		for(int i = n; i >= 1; --i){
			nums.push_back(i);
			partitions(n - i, nums);
			nums.pop_back();
		}
	}else{
		for(int i = min(nums.back(), n); i >= 1; --i){
			nums.push_back(i);
			partitions(n - i, nums);
			nums.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	partitions(n, v);
	return 0;
}
