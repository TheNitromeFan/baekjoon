#include <iostream>
#include <vector>
#include <queue>
#define MAX 50010

using namespace std;

int minimum_unreachable(vector<int> &nums, int n, int uses){
	queue<int> q;
	vector<int> reached(MAX, -1);
	q.push(0);
	reached[0] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(reached[x] == uses){
			continue;
		}
		for(int num : nums){
			int y = x + num;
			if(reached[y] == -1){
				q.push(y);
				reached[y] = reached[x] + 1;
			}
		}
	}
	for(int i = 0; i < MAX; ++i){
		if(reached[i] == -1){
			return i;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i){
		cin >> nums[i];
	}
	int uses;
	cin >> uses;
	int ans = minimum_unreachable(nums, n, uses);
	cout << (ans % 2 == 0 ? "holsoon" : "jjaksoon") << " win at " << ans;
	return 0;
}
