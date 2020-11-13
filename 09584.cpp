#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool match(string &code, string &plate){
	for(unsigned i = 0; i < code.length(); ++i){
		if(code[i] != '*' && code[i] != plate[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string code;
	cin >> code;
	int n;
	cin >> n;
	vector<string> ans;
	for(int i = 0; i < n; ++i){
		string plate;
		cin >> plate;
		if(match(code, plate)){
			ans.push_back(plate);
		}
	}
	cout << ans.size();
	for(string a : ans){
		cout << '\n' << a;
	}
	return 0;
}
