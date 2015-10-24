#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

bool checkall(std::map<char, int> cmi, std::map<char, int> cma)
{
	map<char, int>::iterator iti=cmi.begin();
	map<char, int>::iterator ita=cma.begin();

	if(cma.size() != cmi.size())
		return false;

	for(; iti!=cmi.end(),ita!=cma.end(); ++iti, ++ita){
		if(iti->second != ita->second)
			return false;
	}

	return true;
}

int solve(string str, string str2)
{
	string substr="";

	std::map<char, int> cmi;
	std::map<char, int> cma;

	For(i,0,str2.length())
		cmi[str2[i]]++;

	int i=0;
	while(!checkall(cmi,cma)){
		substr+=str[i];
		if(cmi.count(str[i])>0)
			cma[str[i]]++;
		++i;
	}

	int j = 0, mincount = i;

	for(;i<str.length();++i){
	
		substr+=str[i];
	
		if(cmi.count(str[i])>0)
			cma[str[i]]++;

		if(substr[substr.length()-1] == substr[j]){
			while(1){
				if(cmi.count(substr[j])==0 || cma[substr[j]]>cmi[substr[j]]){
					j++;
					cma[substr[i]]--;
				}
				else break;
			}

			mincount = min(mincount, i-j+1);
			
		}
	}

	return mincount;

}

int main(int argc, char const *argv[])
{
	const char *str = "acffdeaca";
	const char *str2= "aca";
	cout<<solve(str,str2);
	return 0;
}