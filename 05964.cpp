#include <iostream>
#include <stack>
#define MOD 12345678910LL

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<long long> st;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x){
			long long sum = 0;
			while(!st.empty() && st.top() != 0){
				sum += st.top();
				sum %= MOD;
				st.pop();
			}
			st.pop();
			if(sum == 0){
				st.push(1);
			}else{
				st.push(2 * sum % MOD);
			}
		}else{
			st.push(0);
		}
	}
	long long ans = 0;
	while(!st.empty()){
		ans += st.top();
		ans %= MOD;
		st.pop();
	}
	cout << ans;
	return 0;
}
