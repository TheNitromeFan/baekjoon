#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string nums;
	cin >> nums;
	unsigned ans = 0;
	for(unsigned i = 0; 2 * i + 2 < nums.length(); ++i){
		if(nums[0] != '0' && nums[i + 1] != '0'){
			++ans;
		}
	}
	if(nums.length() % 2 == 0 && nums[0] != '0' && nums[nums.length() / 2] != '0'
	&& nums.substr(0, nums.length() / 2) <= nums.substr(nums.length() / 2, nums.length() / 2)){
		++ans;
	}
	cout << ans;
	return 0;
}
