#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	deque<string> d;
	string names;
	for(int i = 0; i < t; ++i){
		d.clear();
		int n;
		cin >> n;
		int change = 0;
		int max_len = 0;
		names = "";
		for(int j = 0; j < n; ++j){
			string name;
			int amount;
			cin >> name >> amount;
			if(amount == 15){
				++change;
			}else{
				d.push_back(name);
			}
			while(change > 0 && !d.empty()){
				d.pop_front();
				--change;
			}
			if(d.size() > max_len){
				max_len = d.size();
				names = d[0];
				for(int i = 1; i < d.size(); ++i){
					names += " " + d[i];
				}
			}
		}
		if(max_len == 0){
			cout << "Line B stayed empty.";
		}else{
			cout << names;
		}
		cout << '\n';
	}
	return 0;
}
