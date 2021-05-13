#include <iostream>
#include <vector>

using namespace std;

void setup(vector<vector<int>> &adj){
	for(int i = 1; i <= 54; ++i){
		if(i != 7 && i != 16 && i != 27 && i != 38 && i != 47 && i != 54){
			adj[i].push_back(i + 1);
		}
	}
	for(int i = 1; i <= 54; ++i){
		if(i != 1 && i != 8 && i != 17 && i != 28 && i != 39 && i != 48){
			adj[i].push_back(i - 1);
		}
	}
	for(int i = 1; i <= 7; ++i){
		if(i % 2 == 1){
			adj[i].push_back(i + 8);
		}
	}
	for(int i = 8; i <= 16; ++i){
		if(i % 2 == 0){
			adj[i].push_back(i + 10);
		}else{
			adj[i].push_back(i - 8);
		}
	}
	for(int i = 17; i <= 27; ++i){
		if(i % 2 == 1){
			adj[i].push_back(i + 11);
		}else{
			adj[i].push_back(i - 10);
		}
	}
	for(int i = 28; i <= 38; ++i){
		if(i % 2 == 1){
			adj[i].push_back(i + 10);
		}else{
			adj[i].push_back(i - 11);
		}
	}
	for(int i = 39; i <= 47; ++i){
		if(i % 2 == 0){
			adj[i].push_back(i + 8);
		}else{
			adj[i].push_back(i - 10);
		}
	}
	for(int i = 48; i <= 54; ++i){
		if(i % 2 == 0){
			adj[i].push_back(i - 8);
		}
	}
}

bool trapped(vector<vector<int>> &adj, vector<int> &occupied, int pos){
	if(occupied[pos] != 2){
		return false;
	}
	for(int x : adj[pos]){
		if(occupied[x] == 0){
			return false;
		}
	}
	return true;
}

bool can_trap(vector<vector<int>> &adj, vector<int> &occupied){
	for(int i = 1; i <= 54; ++i){
		if(occupied[i] != 1){
			continue;
		}
		for(int x : adj[i]){
			if(occupied[x] == 0){
				occupied[x] = 1;
				occupied[i] = 0;
				for(int y : adj[x]){
					if(trapped(adj, occupied, y)){
						return true;
					}
				}
				occupied[i] = 1;
				occupied[x] = 0;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> adj(55);
	setup(adj);
	int t = 0;
	while(true){
		vector<int> occupied(55);
		int x;
		cin >> x;
		if(x == 0){
			break;
		}
		++t;
		occupied[x] = 1;
		for(int i = 1; i < 6; ++i){
			cin >> x;
			occupied[x] = 1;
		}
		for(int i = 0; i < 6; ++i){
			cin >> x;
			occupied[x] = 2;
		}
		cout << t << ". " << (can_trap(adj, occupied) ? "TRAPPED" : "FREE") << "\n";
	}
	return 0;
}
