#include <iostream>
#include <string>

using namespace std;

int main(){
	string honi = "HONI";
	string word;
	cin >> word;
	int ans = 0;
	int idx = 0;
	for(char c : word){
		if(c == honi[idx]){
			idx = (idx + 1) % 4;
			if(idx == 0){
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
