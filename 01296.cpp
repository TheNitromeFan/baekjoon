#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculate(int ell, int oh, int v, int e){
	return (((ell + oh) * (ell + v) * (ell + e)) % 100) * (((oh + v) * (oh + e) * (v + e)) % 100) % 100;
}

vector<int> love(string s){
	vector<int> ret(4, 0);
	for(char c : s){
		switch(c){
			case 'L':
				++ret[0];
				break;
			case 'O':
				++ret[1];
				break;
			case 'V':
				++ret[2];
				break;
			case 'E':
				++ret[3];
				break;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string name;
	cin >> name;
	vector<int> val1 = love(name);
	int n;
	cin >> n;
	string ans;
	int max_so_far = -1;
	for(int i = 0; i < n; ++i){
		string girl;
		cin >> girl;
		vector<int> val2 = love(girl);
		int cmp = calculate(val1[0] + val2[0], val1[1] + val2[1], val1[2] + val2[2], val1[3] + val2[3]);
		if(cmp > max_so_far || (cmp == max_so_far && girl < ans)){
			max_so_far = cmp;
			ans = girl;
		}
	}
	cout << ans;
	return 0;
}
