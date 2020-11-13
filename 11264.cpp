#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string logic;
		double w1, w2, b;
		cin >> logic >> w1 >> w2 >> b;
		vector<bool> v1 = {(b >= 0), (w1 + b >= 0), (w2 + b >= 0), (w1 + w2 + b >= 0)};
		vector<bool> v2 = {false, true, true, true};
		if(logic == "AND"){
			v2[1] = false;
			v2[2] = false;
		}
		cout << (v1 == v2 ? "true" : "false") << '\n';
	}
	return 0;
}
