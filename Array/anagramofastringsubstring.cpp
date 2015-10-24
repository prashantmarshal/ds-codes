#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void swap(string &str, int a, int b){
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}
void findallpermutations(string str, int k, string str1){
	int n = str.length();
	if(k == n)
		return;
	for(int i = k; i < n; ++i){
		swap(str, i, k);

		int pos = str1.find(str);
		if(pos == -1)
		else if(pos >= 0){
			cout<<"Yes";
			return;
		}
		findallpermutations(str, k+1, str1);
		swap(str, i, k);	
	}
	

}

int main(){
	string str1 = "amazon", str2 = "amzo";
	// cin>>str1;
	// cin>>str2;
	int a[26] = {0};

	

	for(int i = 0; i < str1.length(); ++i)
		a[str1[i]-'a']++;
	bool flag = true;
	for(int i = 0; i < str2.length(); ++i){
		a[str2[i]-'a']--;
		if(a[str2[i]-'a'] < 0){
			flag = false;
			break;
		}
	}
	if(!flag){

		cout<<"No";
	}
	else{
		findallpermutations(str2, 0, str1);		
	}
	
}