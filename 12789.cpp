#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	stack<int> st;
	int next = 1;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		st.push(x);
		while(!st.empty() && st.top() == next){
			st.pop();
			++next;
		}
	}
	printf("%s", (next == n + 1) ? "Nice" : "Sad");
	return 0;
}
