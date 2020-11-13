#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, int> cnt;
	int solved = 0, time = 0;
	while(true){
		int m;
		cin >> m;
		if(m == -1){
			break;
		}
		char problem;
		string result;
		cin >> problem >> result;
		if(result == "right"){
			++solved;
			time += m;
			if(cnt.find(problem) != cnt.end()){
				time += 20 * cnt[problem];
			}
		}else{
			if(cnt.find(problem) == cnt.end()){
				cnt[problem] = 1;
			}else{
				++cnt[problem];
			}
		}
	}
	printf("%d %d", solved, time);
	return 0;
}
