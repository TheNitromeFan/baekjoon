#include <iostream>
#include <string>

using namespace std;

void floyd_warshall(bool adj[26][26]){
	for(int k = 0; k < 26; ++k){
		for(int i = 0; i < 26; ++i){
			for(int j = 0; j < 26; ++j){
				if(adj[i][k] && adj[k][j]){
					adj[i][j] = true;
				}
			}
		}
	}
}

bool decipher(string &s1, string &s2, bool adj[26][26]){
	if(s1.length() != s2.length()){
		return false;
	}
	for(unsigned i = 0; i < s1.length(); ++i){
		char c1 = s1[i], c2 = s2[i];
		if(!adj[c1 - 'a'][c2 - 'a']){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	bool adj[26][26] = {};
	for(int i = 0; i < 26; ++i){
		adj[i][i] = true;
	}
	for(int a0 = 0; a0 < m; ++a0){
		char u, v;
		cin >> u >> v;
		adj[u - 'a'][v - 'a'] = true;
	}
	floyd_warshall(adj);
	for(int a1 = 0; a1 < n; ++a1){
		string s1, s2;
		cin >> s1 >> s2;
		cout << (decipher(s1, s2, adj) ? "yes" : "no") << '\n';
	}
	return 0;
}
