#include <bits/stc++.h>
using namespace std;
long long matrix[100][100];// 0 means empty box(can visit)
                           // and -1 means filled box(cant visit)
long long start_x,start_y,end_x,end_y;//start and end coordinates that is taken as input from user.
long long distanceMatrix[100][100]; // each cell stores the shortest path from start cell to itself.
									// initially all elements will have distance infinity from start point.

void recur(int s_x,int s_y,int dist){
	if((s_x>=1&&s_x<=n)&&(s_y>=1&&s_y<=m))//if the current cell is withn limits of the matrix
	{
		if(matrix[s_x][s_y]!=-1)//if the cell is empty
		distanceMatrix[i][j] = min(distanceMatrix[i][j],dist);//the distance equals minimum ( current distance , distance traversed in this recursion call )

		else return;
		//recurse to all 4 sides of the cell by increasing the dist value by 1
		recur(s_x-1,s_y,dist+1);
		recur(s_x+1,s_y,dist+1);
		recur(s_x,s_y-1,dist+1);
		recur(s_x,s_y+1,dist+1);

	}

	else return;

}

int main() {
	int i,j,m,n;
	cin>>n>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>matrix[i][j];
			distanceMatrix[i][j] = 1000000;
		}
	}
	//get input of start and end coordinates
	cin>>start_x>>start_y;
	cin>>end_x>>end_y;
	//call to recursive function..
    //passing only the start coordinates to it and distance to itself (0);
	recur(start_x,start_y,0);
	//print the minimum distance from start point to end
	cout<<distanceMatrix[end_x][end_y]<<endl;
	return 0;
}
