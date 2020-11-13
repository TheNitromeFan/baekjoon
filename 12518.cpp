#include <iostream>
#include <string>

using namespace std;

string ruler(string name){
	string ret;
	switch(name[name.length() - 1]){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			ret = "a queen";
			break;
		case 'Y':
		case 'y':
			ret = "nobody";
			break;
		default:
			ret = "a king";
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		string name;
		cin >> name;
		cout << "Case #" << i << ": " << name << " is ruled by " << ruler(name) << ".\n";
	}
	return 0;
}
