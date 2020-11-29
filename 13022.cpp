#include <iostream>
#include <string>

using namespace std;

bool good_word(string &wolf){
	unsigned idx = 0;
	while(idx < wolf.length()){
		int w = 0, o = 0, l = 0, f = 0;
		while(idx < wolf.length() && wolf[idx] == 'w'){
			++w;
			++idx;
		}
		while(idx < wolf.length() && wolf[idx] == 'o'){
			++o;
			++idx;
		}
		while(idx < wolf.length() && wolf[idx] == 'l'){
			++l;
			++idx;
		}
		while(idx < wolf.length() && wolf[idx] == 'f'){
			++f;
			++idx;
		}
		if(!(w == o && o == l && l == f)){
			return false;
		}
	}
	return idx == wolf.length();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string wolf;
	cin >> wolf;
	cout << good_word(wolf);
	return 0;
}
