#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int sum_of_team(int s[][20], vector<int> members){
	int ret = 0;
	for(int i = 0; i < members.size(); ++i){
		for(int j = 0; j < i; ++j){
			ret += s[members[i]][members[j]] + s[members[j]][members[i]];
		}
	}
	return ret;
}

int diff(int s[][20], int n, string bitmask){
	vector<int> a, b;
	for(int i = 0; i < n; ++i){
		if(bitmask[i]){
			a.push_back(i);
		}else{
			b.push_back(i);
		}
	}
	return abs(sum_of_team(s, a) - sum_of_team(s, b));
}

int main(){
	int n;
	scanf("%d", &n);
	int s[20][20];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &s[i][j]);
		}
	}
	string bitmask(n/2, 1);
	bitmask.resize(n, 0);
	int mn = 10000;
	do{
		int tmp = diff(s, n, bitmask);
		if(tmp < mn){
			mn = tmp;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", mn);
	return 0;
}
