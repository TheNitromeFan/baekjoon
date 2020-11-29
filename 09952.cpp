#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <deque>
#include <algorithm>
#include <cctype>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<string, int> a, pair<string, int> b){
			if(a.second != b.second){
				return a.second > b.second;
			}
			for(unsigned i = 0; i < 3; ++i){
				if(tolower(a.first[i]) != tolower(b.first[i])){
					return tolower(a.first[i]) < tolower(b.first[i]);
				}
			}
			return false;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<pair<string, int>> cans(n);
		for(int i = 0; i < n; ++i){
			cin >> cans[i].first >> cans[i].second;
		}
		sort(cans.begin(), cans.end(), Cmp());
		deque<string> d;
		for(int i = 0; i < n; ++i){
			if(i % 2 == 0){
				d.push_back(cans[i].first);
			}else{
				d.push_front(cans[i].first);
			}
		}
		while(!d.empty()){
			cout << d.front() << " ";
			d.pop_front();
		}
		cout << "\n";
	}
	return 0;
}
