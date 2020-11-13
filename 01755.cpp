#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string word(int n){
	string ret = "";
	while(n){
		ret = " " + words[n % 10] + ret;
		n /= 10;
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &m, &n);
	vector<pair<string, int>> nums;
	for(int i = m; i <= n; ++i){
		nums.push_back(make_pair(word(i), i));
	}
	sort(nums.begin(), nums.end());
	for(unsigned idx = 0; idx < nums.size(); ++idx){
		printf("%d ", nums[idx].second);
		if(idx % 10 == 9){
			printf("\n");
		}
	}
	return 0;
}
