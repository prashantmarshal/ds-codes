/*evaluation of post fix*/

#include <bits/stdc++.h>
using namespace std;

int solve(string expr){
	stack<int>s;
	int l = expr.length();
	int i=0;
	int res=0;;
	while(i<l){
		if(expr[i] == '*' || expr[i] == '+' || expr[i] == '-' || expr[i] == '/')
		{
			if(s.size()<2)
				return -1;
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			
			switch(expr[i]){
				case '*':
					res=a*b;
					break;
				case '+':
					res=a+b;
					break;
				case '-':
					res=b-a;
					break;
				case '/':
					res=b/a;
					break;
			}
			s.push(res);
		}else{
			s.push(expr[i]-'0');
		}
		++i;
	}
	if(s.size()>0)	{
		return s.top();
	}
}

int main(int argc, char const *argv[])
{
	string expr = "132+-156-+654-+541+-+++";
	printf("%d ",solve(expr));
	return 0;
}