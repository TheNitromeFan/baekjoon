#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	map<string, int> cnt;
	int max_so_far = 0;
	vector<string> candidates;
	for(int i = 0; i < n; ++i){
		string title;
		cin >> title;
		if(cnt.find(title) == cnt.end()){
			cnt[title] = 1;
		}else{
			++cnt[title];
		}
		if(max_so_far < cnt[title]){
			max_so_far = cnt[title];
			candidates.clear();
			candidates.push_back(title);
		}else if(max_so_far == cnt[title]){
			candidates.push_back(title);
		}
	}
	sort(candidates.begin(), candidates.end());
	cout << candidates[0];
	return 0;
}
