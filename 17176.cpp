#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	string s1(n, 'K'), s2;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x == 0){
			s1[i] = ' ';
		}else if(x <= 26){
			s1[i] = x - 1 + 'A';
		}else{
			s1[i] = x - 27 + 'a';
		}
	}
	getline(cin, line);
	sort(s1.begin(), s1.end());
	getline(cin, s2);
	sort(s2.begin(), s2.end());
	cout << ((s1 == s2) ? 'y' : 'n');
	return 0;
}
