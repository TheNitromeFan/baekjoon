#include <iostream>
#include <string>
#include <queue>
#define MAX 10000000

using namespace std;

int string_to_int(string s){
	int ret = 0;
	for(char c : s){
		ret *= 2;
		if(c == '1'){
			++ret;
		}
	}
	return ret;
}

string int_to_string(int n){
	string ret;
	while(n){
		if(n % 2){
			ret = "1" + ret;
		}else{
			ret = "0" + ret;
		}
		n /= 2;
	}
	return ret;
}

int bfs(int start, int end){
	queue<int> q;
	q.push(start);
	int visited[MAX] = {};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == end){
			return visited[x];
		}
		int nx;
		nx = x + 1;
		if(nx != start && !visited[nx]){
			visited[nx] = visited[x] + 1;
			q.push(nx);
		}
		if(x > 0){
			nx = x - 1;
			if(nx != start && !visited[nx]){
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
		}
		string s = int_to_string(x);
		for(unsigned idx = 1; idx < s.length(); ++idx){
			string t = s;
			if(t[idx] == '0'){
				t[idx] = '1';
			}else{
				t[idx] = '0';
			}
			nx = string_to_int(t);
			if(nx != start && !visited[nx]){
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
		}
	}
	return -1;
}

int main(){
	string src, dest;
	cin >> src >> dest;
	cout << bfs(string_to_int(src), string_to_int(dest));
	return 0;
}
