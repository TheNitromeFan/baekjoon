#include <iostream>
#include <vector>

using namespace std;

int num(char c){
	if(c == 'A'){
		return 0;
	}else if(c == 'B'){
		return 2;
	}else if(c == 'C'){
		return 3;
	}else if(c == 'D'){
		return 5;
	}else if(c == 'E'){
		return 7;
	}else if(c == 'F'){
		return 8;
	}else if(c == 'G'){
		return 10;
	}
	return -1;
}

char note(int x){
	if(x == 0){
		return 'A';
	}else if(x == 2){
		return 'B';
	}else if(x == 3){
		return 'C';
	}else if(x == 5){
		return 'D';
	}else if(x == 7){
		return 'E';
	}else if(x == 8){
		return 'F';
	}else if(x == 10){
		return 'G';
	}
	return ' ';
}

bool transcribe(vector<int> &interv, int n, char start, char &end){
	int x = num(start);
	for(int i = 0; i < n; ++i){
		x = (x + 24 + interv[i]) % 12;
		if(note(x) == ' '){
			return false;
		}
	}
	end = note(x);
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> intervals(n);
	for(int i = 0; i < n; ++i){
		cin >> intervals[i];
	}
	char end = ' ';
	for(char start = 'A'; start <= 'G'; ++start){
		if(transcribe(intervals, n, start, end)){
			cout << start << ' ' << end << '\n';
		}
	}
	return 0;
}
