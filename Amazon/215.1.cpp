/*robot moves*/
#include <iostream>
using namespace std;



int main(){
	string moves;
	cin>>moves;

	int x = 0, y = 0;
	int curr_dir=0;
	for(int i = 0; i < moves.length(); ++i){

		if(moves[i] == 'G'){
			switch(curr_dir){
				case 0:
					x++;
					break;
				case 1:
					y++;
					break;
				case 2:
					x--;
					break;
				case 3:
					y--;
					break;
			}
		}else if(moves[i] == 'L'){
			curr_dir = (curr_dir+1)%4;
		}else if(moves[i] == 'R'){
			curr_dir = (curr_dir-1)%4;
		}
		if(curr_dir < 0)
			curr_dir+=4;

		cout<<x<< " " <<y<<" " <<curr_dir<<endl;

	}	

	if(x == 0 && y == 0)
		cout<<"yes\n";
	else cout<<"no\n";

}