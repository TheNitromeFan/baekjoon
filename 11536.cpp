#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> names(n, "");
	for(int i = 0; i < n; ++i){
		cin >> names[i];
	}
	vector<string> c = names;
	if(!prev_permutation(c.begin(), c.end())){
		cout << "INCREASING";
	}else if(!next_permutation(names.begin(), names.end())){
		cout << "DECREASING";
	}else{
		cout << "NEITHER";
	}
	return 0;
}
