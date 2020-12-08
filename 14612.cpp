#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> notes;
	for(int j = 0; j < n; ++j){
		string type;
		cin >> type;
		if(type == "order"){
			int n, t;
			cin >> n >> t;
			notes.push_back(make_pair(t, n));
		}else if(type == "complete"){
			int n;
			cin >> n;
			for(vector<pair<int, int>>::iterator it = notes.begin(); it != notes.end(); ++it){
				if((*it).second == n){
					notes.erase(it);
					break;
				}
			}
		}else{
			sort(notes.begin(), notes.end());
		}
		if(!notes.empty()){
			for(pair<int, int> p : notes){
				cout << p.second << " ";
			}
		}else{
			cout << "sleep";
		}
		cout << "\n";
	}
	return 0;
}
