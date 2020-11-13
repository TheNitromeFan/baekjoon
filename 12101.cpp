#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> v;

int main(){
	int n, k;
	cin >> n >> k;
	vector<string> tmp;
	v.push_back(tmp);
	tmp.clear();
	tmp.push_back("1");
	v.push_back(tmp);
	tmp.clear();
	tmp.push_back("1+1");
	tmp.push_back("2");
	v.push_back(tmp);
	tmp.clear();
	tmp.push_back("1+1+1");
	tmp.push_back("1+2");
	tmp.push_back("2+1");
	tmp.push_back("3");
	v.push_back(tmp);
	for(int i = 4; i <= n; ++i){
		tmp.clear();
		for(int j = 1; j <= 3; ++j){
			for(string s : v[i-j]){
				tmp.push_back(to_string(j) + "+" + s);
			}
		}
		v.push_back(tmp);
	}
	if(v[n].size() < k){
		cout << -1;
	}else{
		cout << v[n][k-1];
	}
	return 0;
}
