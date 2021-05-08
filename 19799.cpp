#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	unordered_set<double> apples;
	apples.insert(n);
	for(int i = 0; i < k; ++i){
		unordered_set<double> left;
		for(double apple : apples){
			if(apple > 0){
				left.insert(apple - 0.5);
			}
			if(apple == (int)apple){
				left.insert(apple / 2);
			}
		}
		apples = left;
	}
	vector<double> v;
	for(double apple : apples){
		v.push_back(apple);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(double apple : v){
		cout << fixed << setprecision(1) << apple << ' ';
	}
	return 0;
}
