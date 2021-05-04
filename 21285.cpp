#include <iostream>
#include <string>

using namespace std;

int dist(string &s, string &t){
	int ret = 0;
	for(unsigned idx = 0; idx < s.length(); ++idx){
		if(s[idx] != t[idx]){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string name;
	cin >> name;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		string month;
		cin >> month;
		if(name.length() == month.length() && dist(name, month) <= 1){
			cout << i;
			break;
		}
	}
	return 0;
}
