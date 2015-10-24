#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*zxvuutttrrrpoookiihhgggfdca*/
int main() {
    int T;
    cin>>T;
    while(T--){
    	string str;
    	cin>>str;
    	string str2 = str;
    	stack <char> s1, s3;
    	s1.push(str[str.length()-1]);
    	for(int i = str.length()-2; i >= 0; --i){
    		if(str[i] >= s1.top()){
    			s1.push(str[i]);
    		}
    		if((i == 0 && str[i] < s1.top()) || str[i] < s1.top()){
				char temp = str[i];
    			while(s1.size() > 0 && s1.top() > str[i]){
    				s3.push(s1.top());
    				s1.pop();
    			}
    				
    			if(s3.size() > 0){
    				char replace = s3.top();
	    			str[i] = replace;
	    			s3.pop();
    			}

    			s3.push(temp);

    			while(s1.size() > 0){
    				s3.push(s1.top());
    				s1.pop();
    			}
    			
    			for(int j = i+1; j < str.length() && s3.size() > 0; ++j){
    				str[j] = s3.top();
    				s3.pop();
    			}
    			break;
    		}
    	}
    	if(str == str2)
	    	cout<<"no answer"<<endl;
	    else
	    	cout<<str<<endl;
    }
    return 0;
}
