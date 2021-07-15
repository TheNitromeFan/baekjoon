#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int simulate(vector<int> a, vector<int> b, int m, int n, int p, int q){
	int ret = 1000;
	ret -= a[m];
	b.push_back(a[m]);
	a.erase(a.begin() + m);
	ret += b[n];
	a.push_back(b[n]);
	b.erase(b.begin() + n);
	ret -= a[p];
	b.push_back(a[p]);
	a.erase(a.begin() + p);
	ret += b[q];
	a.push_back(b[q]);
	b.erase(b.begin() + q);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a(10), b(10);
	for(int i = 0; i < 10; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < 10; ++i){
		cin >> b[i];
	}
	unordered_set<int> milk;
	for(int m = 0; m < 10; ++m){
		for(int n = 0; n < 11; ++n){
			for(int p = 0; p < 10; ++p){
				for(int q = 0; q < 11; ++q){
					milk.insert(simulate(a, b, m, n, p, q));
				}
			}
		}
	}
	cout << milk.size() << '\n';
	return 0;
}
