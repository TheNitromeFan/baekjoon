#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<unsigned> left, right;
	for(unsigned i = 0; i + 1 < s.length(); ++i){
		if(s[i] == '(' && s[i + 1] == '('){
			left.push_back(i);
		}else if(s[i] == ')' && s[i + 1] == ')'){
			right.push_back(i);
		}
	}
	unsigned cnt = 0;
	unsigned i1 = 0, i2 = 0;
	while(i1 < left.size() || i2 < right.size()){
		if(i2 == right.size() || (i1 < left.size() && left[i1] < right[i2])){
			cnt += right.size() - i2;
			++i1;
		}else{
			++i2;
		}
	}
	cout << cnt;
	return 0;
}
