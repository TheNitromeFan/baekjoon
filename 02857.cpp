#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool fbi(string s){
	for(unsigned j = 0; j + 2 < s.length(); ++j){
		if(s[j] == 'F' && s[j + 1] == 'B' && s[j + 2] == 'I'){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> ans;
	for(int i = 1; i <= 5; ++i){
		string s;
		cin >> s;
		if(fbi(s)){
			ans.push_back(i);
		}
	}
	if(ans.empty()){
		cout << "HE GOT AWAY!";
		return 0;
	}
	for(int a : ans){
		cout << a << ' ';
	}
	return 0;
}
