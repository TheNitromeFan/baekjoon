#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void update_bitwise(vector<int> &bitwise_or, vector<int> &bitwise_and, int x){
	for(int i = 15; i>= 0; --i){
		bitwise_or[i] |= (x & 1);
		bitwise_and[i] &= (x & 1);
		x >>= 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int a, b, c, s;
		cin >> a;
		if(a == 0){
			break;
		}
		cin >> b >> c >> s;
		vector<int> bitwise_or(16), bitwise_and(16, 1);
		update_bitwise(bitwise_or, bitwise_and, s);
		unordered_set<int> vals;
		vals.insert(s);
		while(true){
			s = (a * s + b) % c;
			if(vals.find(s) != vals.end()){
				break;
			}
			update_bitwise(bitwise_or, bitwise_and, s);
			vals.insert(s);
		}
		for(int i = 0; i < 16; ++i){
			if(!bitwise_or[i]){
				cout << 0;
			}else if(bitwise_and[i]){
				cout << 1;
			}else{
				cout << '?';
			}
		}
		cout << '\n';
	}
	return 0;
}
