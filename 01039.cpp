#include <cstdio>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int k;
	char tmp[10];
	scanf("%s %d", tmp, &k);
	string n = tmp;
	queue<string> q;
	q.push(n);
	
	for(int swp = 0; swp < k; ++swp){
		int sz = q.size();
		set<string> found;
		for(int ind = 0; ind < sz; ++ind){
			string str = q.front();
			q.pop();
			if(found.count(str)){
				continue;
			}
			found.insert(str);
			for(int i = 0; i < str.size(); ++i){
				for(int j = i+1; j < str.size(); ++j){
					if(!(i == 0 && str[j] == '0')){
						swap(str[i], str[j]);
						q.push(str);
						swap(str[j], str[i]);
					}
				}
			}
		}
	}
	
	string ans = "0";
	while(!q.empty()){
		ans = max(ans, q.front());
		q.pop();
	}
	if(ans[0] == '0'){
		printf("-1");
	}else{
		printf("%s", ans.c_str());
	}
	return 0;
}
