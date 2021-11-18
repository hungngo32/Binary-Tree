#include"Header.h"
#include<stack>
#include<string.h>
#include<string>
int main() {
	stack <int> a;
	string s;
	int sum = 0;
	getline(cin, s);
	cout << s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		else if (s[i] == '//') {
			int tmp = a.top() - '0';
			a.pop();
			int tmp2 = a.top() - '0';
			a.pop();
			a.push((tmp / tmp2)+'0');
		}
		else if (s[i] == '+') {
			int tmp = a.top() - '0';
			a.pop();
			int tmp2 = a.top() - '0';
			a.pop();
			a.push(tmp + tmp2+'0');
		}
		else if (s[i] == '-') {
			int tmp = a.top() - '0';
			a.pop();
			int tmp2 = a.top() - '0';
			a.pop();
			a.push(tmp - tmp2 +'0');
		} else if (s[i]=='x'){
			int tmp = a.top()-'0';
			a.pop();
			int tmp2 = a.top()-'0';
			a.pop();
			a.push((tmp * tmp2)+'0');
		}
		else {
			a.push(s[i]);
		}
	}
	cout << a.top();
	return 0;
}