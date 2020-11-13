#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> ignore = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
	string word;
	string ans;
	int idx = 0;
	while(cin >> word){
		if(idx == 0 || ignore.find(word) == ignore.end()){
			ans += (char)(word[0] - 'a' + 'A');
		}
		++idx;
	}
	cout << ans;
	return 0;
}
