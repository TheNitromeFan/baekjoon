#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool intersect(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	int x1 = get<0>(a), y1 = get<1>(a), x2 = get<2>(a), y2 = get<3>(a);
	int x3 = get<0>(b), y3 = get<1>(b), x4 = get<2>(b), y4 = get<3>(b);
	if(x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1){
		return false;
	}else if((x3 > x1 && x4 < x2 && y3 > y1 && y4 < y2) || (x1 > x3 && x2 < x4 && y1 > y3 && y2 < y4)){
		return false;
	}
	return true;
}

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int disjoint_sets(vector<tuple<int, int, int, int>> &rect, int n){
	int comps = n;
	vector<int> parent(n);
	for(int i = 0; i < n; ++i){
		parent[i] = i;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(intersect(rect[j], rect[i]) && find_parent(parent, j) != find_parent(parent, i)){
				unite(parent, i, j);
				--comps;
			}
		}
	}
	return comps;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> rect(n);
	for(int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rect[i] = make_tuple(x1, y1, x2, y2);
	}
	rect.push_back(make_tuple(0, 0, 0, 0));
	cout << disjoint_sets(rect, n + 1) - 1;
	return 0;
}
