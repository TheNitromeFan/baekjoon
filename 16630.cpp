#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	int len = 1;
	for(char c : s){
		if(c == 'R'){
			v.push_back(len);
			len = 1;
		}else{
			++len;
		}
	}
	v.push_back(len);
	int m = 1;
	for(int x : v){
		for(int y = m + x - 1; y >= m; --y){
			cout << y << '\n';
		}
		m += x;
	}
	return 0;
}
