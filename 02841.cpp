#include <cstdio>
#include <stack>
#define MAX (6 + 1)

using std::stack;

int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	static stack<int> s[MAX];
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int string, fret;
		scanf("%d %d", &string, &fret);
		while(!s[string].empty() && s[string].top() > fret){
			s[string].pop();
			++cnt;
		}
		if(s[string].empty() || s[string].top() < fret){
			s[string].push(fret);
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
