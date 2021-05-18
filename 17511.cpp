#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<bool> capital(n + 1, true);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		capital[b] = false;
	}
	vector<int> s;
	for(int v = 1; v <= n; ++v){
		if(capital[v]){
			s.push_back(v);
		}
	}
	cout << s.size() << '\n';
	for(int v : s){
		cout << v << ' ';
	}
	return 0;
}
