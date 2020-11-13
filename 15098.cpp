#include <iostream>
#include <string>
#include <set>

using namespace std;

bool repeats(){
	set<string> s;
	string word;
	while(cin >> word){
		if(s.find(word) == s.end()){
			s.insert(word);
		}else{
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << (repeats() ? "no" : "yes");
	return 0;
}
