/*Dynamic Programming | Set 32 (Word Break Problem)*/

#include <bits/stdc++.h>
using namespace std;

bool dictionarycontains(string str){
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
						"icecream","and","go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);

	for(int i = 0; i < size; ++i){
		if(dictionary[i].compare(str) == 0)
			return true;
	}

	return false;
}

bool solve(string inpt){
	if(inpt.size() == 0)
		return true;

	for(int i = 0; i < inpt.size(); ++i){
		if(dictionarycontains(arr, inpt.substr(0,i+1)) && solve(arr, inpt.substr(i+1, inpt.size()-i)))
			return true;
	}
	return false;
}


bool solveusingdp(string inpt){
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
						"icecream","and","go","i","like","ice","cream"};

	int wb[size];

	for(int i = 0; i < size; ++i)
		wb[i] = false;

	for(int i = 0; i < size; ++i){
		if(dictionarycontains(inpt.substr(0,i))){
			/*incomplete*/
		}
	}					


}

int main(){
	string inpt;
	cin>>inpt;

	// recursion method
	if(solve(arr, inpt))
		cout<<"Yes\n";
	else
		cout<<"No\n";

}