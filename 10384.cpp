#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 1; i <= n; ++i){
		vector<int> v(26, 0);
		getline(cin, line);
		for(char c : line){
			if(c >= 'A' && c <= 'Z'){
				++v[c - 'A'];
			}else if(c >= 'a' && c <= 'z'){
				++v[c - 'a'];
			}
		}
		cout << "Case " << i << ": ";
		switch(*min_element(v.begin(), v.end())){
			case 0:
				cout << "Not a pangram";
				break;
			case 1:
				cout << "Pangram!";
				break;
			case 2:
				cout << "Double pangram!!";
				break;
			default:
				cout << "Triple pangram!!!";
				break;
		}
		cout << '\n';
	}
	return 0;
}
