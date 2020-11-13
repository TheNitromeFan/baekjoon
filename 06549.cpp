#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		vector<int> heights(n, 0);
		for(int i = 0; i < n; ++i){
			scanf("%d", &heights[i]);
		}
		long long area = 0;
		stack<int> st;
		for(int i = 0; i < n; ++i){
			while(!st.empty() && heights[st.top()] > heights[i]){
				long long height = heights[st.top()];
				st.pop();
				int width;
				if(st.empty()){
					width = i;
				}else{
					width = i - st.top() - 1;
				}
				if(area < width * height){
					area = width * height;
				}
			}
			st.push(i);
		}
		while(!st.empty()){
			long long height = heights[st.top()];
			st.pop();
			int width;
			if(st.empty()){
				width = n;
			}else{
				width = n - st.top() - 1;
			}
			if(area < width * height){
				area = width * height;
			}
		}
		printf("%lld\n", area);
	}
	return 0;
}
