#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string msg;
	cin >> msg;
	set<char> letters;
	for(char letter : msg){
		letters.insert(letter);
	}
	unsigned shifts = 26U - letters.size();
	if(shifts > 0){
		cout << shifts;
	}else{
		cout << "impossible";
	}
	return 0;
}
