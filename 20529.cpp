#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int dist(string &s1, string &s2){
	int ret = 0;
	for(unsigned i = 0; i < s1.length(); ++i){
		if(s1[i] != s2[i]){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		unordered_map<string, int> cntr;
		vector<string> v;
		for(int a1 = 0; a1 < n; ++a1){
			string mbti;
			cin >> mbti;
			if(cntr[mbti] < 3){
				v.push_back(mbti);
				++cntr[mbti];
			}
		}
		vector<int> bitmask(3, 1);
		bitmask.resize(v.size(), 0);
		int ans = 10000;
		do{
			vector<string> choice;
			for(unsigned i = 0; i < v.size(); ++i){
				if(bitmask[i]){
					choice.push_back(v[i]);
				}
			}
			ans = min(ans, dist(choice[0], choice[1]) + dist(choice[1], choice[2]) + dist(choice[2], choice[0]));
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
		cout << ans << '\n';
	}
	return 0;
}
