#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int triangles = 0, right = 0, acute = 0, obtuse = 0;
	while(true){
		vector<int> s(3);
		for(int i = 0; i < 3; ++i){
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		if(s[0] <= 0 || s[2] >= s[0] + s[1]){
			break;
		}
		++triangles;
		if(s[2] * s[2] == s[0] * s[0] + s[1] * s[1]){
			++right;
		}else if(s[2] * s[2] < s[0] * s[0] + s[1] * s[1]){
			++acute;
		}else{
			++obtuse;
		}
	}
	cout << triangles << ' ' << right << ' ' << acute << ' ' << obtuse;
	return 0;
}
