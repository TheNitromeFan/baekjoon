#include <iostream>
#include <queue>
#include <string>
#define MAXQUEUES 1000
#define MAXELEMENTS 1000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sc = 0;
	while(true){
		int t;
		cin >> t;
		if(t == 0){
			break;
		}
		++sc;
		queue<int> q[MAXQUEUES];
		int team[MAXELEMENTS];
		for(int j = 0; j < t; ++j){
			int n;
			cin >> n;
			for(int k = 0; k < n; ++k){
				int x;
				cin >> x;
				team[x] = j;
			}
		}
		bool enqueued[MAXQUEUES] = {};
		queue<int> teams;
		cout << "Scenario #" << sc << "\n";
		while(true){
			string command;
			cin >> command;
			if(command == "STOP"){
				break;
			}else if(command == "ENQUEUE"){
				int x;
				cin >> x;
				int p = team[x];
				q[p].push(x);
				if(!enqueued[p]){
					teams.push(p);
					enqueued[p] = true;
				}
			}else{
				int p = teams.front();
				cout << q[p].front() << "\n";
				q[p].pop();
				if(q[p].empty()){
					teams.pop();
					enqueued[p] = false;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
