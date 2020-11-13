#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> v(5, 0);
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
			if(s == "X"){
				++v[4];
			}else if(s == "M" || s == "L"){
				++v[0];
			}else if(s == "S"){
				++v[3];
			}else if(stoi(s) >= 12){
				++v[1];
			}else{
				++v[2];
			}
		}
		for(int j = 0; j < 5; ++j){
			cout << v[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
