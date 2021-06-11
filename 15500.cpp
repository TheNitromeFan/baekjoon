#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<int> s1, s2;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		s1.push(x);
	}
	cout << n * (n + 1) / 2 << '\n';
	for(int k = n; k > 0; --k){
		if(k % 2 == n % 2){
			while(!s1.empty()){
				if(s1.top() == k){
					cout << 1 << ' ' << 3 << '\n';
				}else{
					cout << 1 << ' ' << 2 << '\n';
					s2.push(s1.top());
				}
				s1.pop();
			}
		}else{
			while(!s2.empty()){
				if(s2.top() == k){
					cout << 2 << ' ' << 3 << '\n';
				}else{
					cout << 2 << ' ' << 1 << '\n';
					s1.push(s2.top());
				}
				s2.pop();
			}
		}
	}
	return 0;
}
