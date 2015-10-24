#include <bits/stdc++.h>
using namespace std;


class pairs{
public:
	int index;
	string word;
};

bool compare(pairs one, pairs two){
	return (one.word.append(two.word) < two.word.append(one.word));
}

int main(){

	// char str[] = "prashant,prashatn,jdvkfn,njvdnkjnkn,jknvdkfjn,nkvjdfk";
	char str[] = "this,is,me,prashant,calling,apoorva,isth,si,me,parsahnt,llingca,avroopa,prashatn,lund";
	
	vector<string> v;
	int len = strlen(str), i=0;
	string word="";
	while(i<len){
		if(str[i]!=','){
			word += str[i];
		}else{
			v.push_back(word);
			word = "";
		}
		++i;
	}
	
	v.push_back(word);
	int v_size = v.size();
	pairs ps[v_size];
	for(int i = 0; i < v_size; ++i){
		ps[i].index = i;
		ps[i].word = v[i];
		sort(ps[i].word.begin(), ps[i].word.end());
	}

	sort(ps,ps+v_size,compare);
	
	bool flag = false;
	for(int i = 0; i < v_size; ++i){

		int j = i+1;
		
		while(j < v_size && ps[j].word == ps[i].word){
			cout<<v[ps[i].index]<<" "<<v[ps[j].index]<<endl;
			j++;	
			flag = true;
		}
		if(flag==false)
		{
			printf("-1\n");
			break;
		}
		
	}

}