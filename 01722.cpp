#include <iostream>
#include <vector>
#include <deque>

using namespace std;

long long factorial[21];

int main(){
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(1);
	factorial[1] = 1;
	for(int i = 2; i <= n; ++i){
		v.push_back(i);
		factorial[i] = factorial[i-1] * i;
	}
	int option;
	cin >> option;
	if(option == 1){
		long long k;
		cin >> k;
		k -= 1;
		deque<int> d;
		for(int i = 1; i <= n; ++i){
			d.push_front(k % i);
			k /= i;
		}
		for(int i = 1; i < n; ++i){
			cout << v[d.front()] << " ";
			v.erase(v.begin() + d.front());
			d.pop_front();
		}
		cout << v[0];
	}else{
		deque<int> d;
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			for(int j = 0; j < v.size(); ++j){
				if(v[j] == x){
					d.push_back(j);
					v.erase(v.begin() + j);
					break;
				}
			}
		}
		long long ans = 0;
		for(int i = n-1; i > 0; --i){
			ans = (ans + d.front()) * i;
			d.pop_front();
		}
		cout << ans + 1;
	}
	return 0;
}
