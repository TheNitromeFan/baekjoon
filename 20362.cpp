#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string user;
	cin >> n >> user;
	vector<pair<string, string>> chat(n);
	int k = -1;
	for(int i = 0; i < n; ++i){
		cin >> chat[i].first >> chat[i].second;
		if(chat[i].first == user){
			k = i;
		}
	}
	int ans = 0;
	for(int i = 0; i < k; ++i){
		if(chat[i].second == chat[k].second){
			++ans;
		}
	}
	cout << ans;
	return 0;
}
