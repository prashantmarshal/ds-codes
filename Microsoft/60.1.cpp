#include <bits/stdc++.h>
using namespace std;

#define For(i,s,l) for (int i = s; i < l; ++i)
#define si(i) scanf("%d", &i)
#define sl(i) scanf("%ld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%ld", i);
#define scan(arr,l) for(int i = 0; i < l; ++i) si(arr[i])
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

const int rows=5,cols=4;

class point{
public:
	int x;
	int y;
	point(int i, int j){
		x = i;
		y = j;
	}
};

int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};

bool issafe(int arr[rows][cols], point front, int index, bool visited[rows][cols])
{	
	if(arr[front.x+x[index]][front.y+y[index]] && !visited[front.x+x[index]][front.y+y[index]] && front.x+x[index] >= 0 && front.x+x[index]<rows && front.y+y[index] >= 0 && front.y+y[index] < cols)
		return true;
	else return false;
}

void solve(int arr[rows][cols], bool visited[rows][cols]){

	queue<point>q;
	point source(4,2);
	q.push(source);
	visited[4][2] = true;

	int count2 = 1;
	int count=0;
	while(!q.empty()){
		int qsize = q.size();
		bool flag = false;
		while(qsize--){
			point front = q.front();
			q.pop();
			For(i,0,4){
				if(issafe(arr, front, i, visited)){
					// cout<<front.x+x[i]<<" " <<front.y+y[i]<< " Indexattackedbyrotten"<< " "<<count<< "\n";
					flag = true;
					point temp(front.x+x[i], front.y+y[i]);
					q.push(temp);
					count2++;
					visited[front.x+x[i]][front.y+y[i]] = true;
				}	
			}

		}
		if(flag)
			count++;		
	}
	For(i,0,rows)
	For(j,0,cols)
	if(arr[i][j] == 1)
		count2--;
	if(!count2)
		pi(count);
	else 
		pi(-1);

}

int main(int argc, char const *argv[])
{
	int arr[5][4] = {
		{0,0,0,1},
		{1,1,1,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,1,1,1}
	};
	bool visited[rows][cols];
	memset(visited,0,rows*cols);
	solve(arr, visited);
	return 0;
}