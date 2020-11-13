#include <iostream>
#include <string>
#include <map>
#define MAX 200000

using namespace std;

int find_parent(int parent[MAX], int x){
	if(x == parent[x]){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

int unite(int parent[MAX], int network[MAX], int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x != y){
		parent[y] = x;
		network[x] += network[y];
	}
	return network[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int f;
		cin >> f;
		int parent[MAX], network[MAX];
		map<string, int> hash;
		int index = 0;
		for(int i = 0; i < 2 * f; ++i){
			parent[i] = i;
			network[i] = 1;
		}
		for(int a1 = 0; a1 < f; ++a1){
			string a, b;
			cin >> a >> b;
			if(hash.find(a) == hash.end()){
				hash[a] = index;
				++index;
			}
			if(hash.find(b) == hash.end()){
				hash[b] = index;
				++index;
			}
			cout << unite(parent, network, hash[a], hash[b]) << '\n';
		}
	}
	return 0;
}
