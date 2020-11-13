#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	map<string, unsigned> order;
	for(unsigned i = 0; i < n; ++i){
		string plate;
		cin >> plate;
		order[plate] = i;
	}
	stack<string> tunnel;
	for(unsigned i = 0; i < n; ++i){
		string plate;
		cin >> plate;
		tunnel.push(plate);
	}
	int ans = 0;
	unsigned next = n;
	while(!tunnel.empty()){
		string car = tunnel.top();
		tunnel.pop();
		unsigned i = order[car];
		if(i <= next){
			next = min((unsigned)tunnel.size(), i);
		}else{
			++ans;
		}
	}
	cout << ans;
	return 0;
}
