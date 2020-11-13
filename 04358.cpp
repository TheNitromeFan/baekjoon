#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> species;
	map<string, int> cnt;
	string tree;
	int total = 0;
	while(getline(cin, tree)){
		if(cnt.find(tree) == cnt.end()){
			species.push_back(tree);
			cnt[tree] = 1;
		}else{
			++cnt[tree];
		}
		++total;
	}
	sort(species.begin(), species.end());
	for(string tree : species){
		cout << tree << ' ' << fixed << setprecision(4) << (cnt[tree] * 100.0) / total << '\n';
	}
	return 0;
}
