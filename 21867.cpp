#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	for(char c : s){
		if(c != 'J' && c != 'A' && c != 'V'){
			ans += c;
		}
	}
	if(!ans.empty()){
		cout << ans;
	}else{
		cout << "nojava";
	}
	return 0;
}
