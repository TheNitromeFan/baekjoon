#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

class Cmp{
	public:
		bool operator()(int x, int y){
			return nums[x] < nums[y] || (nums[x] == nums[y] && x > y);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	nums.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> nums[i];
	}
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		ans[i] = i;
	}
	sort(ans.begin(), ans.end(), Cmp());
	for(int i = 0; i < n; ++i){
		nums[i] = ans[i];
		ans[i] = i;
	}
	sort(ans.begin(), ans.end(), Cmp());
	for(int x : ans){
		cout << x + 1 << " ";
	}
	return 0;
}
