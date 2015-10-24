#include <iostream>
#include <vector>
using namespace std;

int main(){

	string good[10] = { "1111110", "0110000" , "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
	int T;
	cin>>T;
	for(int smallt = 0; smallt < T; smallt++){
		int	t;
		cin>>t;

		vector<char> v2[t];
		for(int t2 = 0; t2 < t; ++t2){
			string s;
			cin>>s;
			cout<<s<<endl;

			for(int k = 0; k < 10; ++k){
				bool flag = true;
				for(int i = 0; i < 7; ++i){
					if(s[i] == '1' && good[k][i] == '0'){
						flag = false;
						break;
					}

				}
				if(flag)
					v2[t2].push_back(k);
			}

		}

		/*for(int i = 0; i < t; ++i){
			for(int k = 0; k < v2[i].size(); ++k){
				cout<<(int)v2[i][k]<<" ";
			}
			cout<<endl;
		}*/

		int bar[10];
		for (int i = 0; i < 10; ++i)
			bar[i] = 0;

		for(int i = 0; i < t; ++i){
			for(int k = 0; k < v2[i].size(); ++k){
				++bar[(int)v2[i][k]-i];
			}
		}

		int max = -1;
		bool bigo = false;
		
		for(int i = 0; i < 10; ++i){
			cout<<bar[i]<<" "
;		}
cout<<endl;
int index = 0;
		for (int i = 0; i < 10; ++i)
		{
			if(max < bar[i]){
				max = bar[i];
				index = i;
			}
			else if(max > bar[i])
				continue;
			else if(max == bar[i]){
				bigo = true;
			}

		}
		cout<<index-t<<endl;
		if(bigo)
			cout<<"Case  #"<<smallt+1<<": "<<good[index-t-1]<<endl;
		else
			cout<<"Case  #"<<smallt+1<<": "<<"ERROR!"<<endl;



	}	
}