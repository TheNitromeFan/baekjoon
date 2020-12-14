#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int assign(vector<tuple<char, int, int>> &adj, int n, int k, int cow, int pos, vector<int> &assigned){
	if(cow > n){
		return 1;
	}
	vector<bool> possible(3, true);
	while(pos < k && get<2>(adj[pos]) == cow){
		if(get<0>(adj[pos]) == 'S'){
			for(int i = 0; i < 3; ++i){
				if(i != assigned[get<1>(adj[pos])]){
					possible[i] = false;
				}
			}
		}else{
			possible[assigned[get<1>(adj[pos])]] = false;
		}
		++pos;
	}
	int ret = 0;
	for(int i = 0; i < 3; ++i){
		if(possible[i]){
			assigned.push_back(i);
			ret += assign(adj, n, k, cow + 1, pos, assigned);
			assigned.pop_back();
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<tuple<char, int, int>> adj(k);
	for(int i = 0; i < k; ++i){
		char rel;
		int a, b;
		cin >> rel >> a >> b;
		if(a > b){
			swap(a, b);
		}
		adj[i] = make_tuple(rel, a, b);
	}
	sort(adj.begin(), adj.end(), [](tuple<char, int, int> a, tuple<char, int, int> b){
		return get<2>(a) < get<2>(b) || (get<2>(a) == get<2>(b) && get<1>(a) < get<1>(b));
	});
	vector<int> assigned = {0};
	cout << assign(adj, n, k, 1, 0, assigned);
	return 0;
}
