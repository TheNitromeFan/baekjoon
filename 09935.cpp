#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string original, explode;
	cin >> original >> explode;
	deque<char> ans;
	for(unsigned i = 0; i < original.length(); ++i){
		ans.push_back(original[i]);
		while(!ans.empty() && ans.back() == explode[explode.length() - 1]){
			unsigned j;
			for(j = 1; j <= explode.length() && j <= ans.size(); ++j){
				if(ans[ans.size() - j] != explode[explode.length() - j]){
					break;
				}
			}
			if(j > explode.length()){
				for(unsigned k = 0; k < explode.length(); ++k){
					ans.pop_back();
				}
			}else{
				break;
			}
		}
	}
	if(ans.empty()){
		cout << "FRULA";
		return 0;
	}
	while(!ans.empty()){
		cout << ans.front();
		ans.pop_front();
	}
	return 0;
}
