//program to find the optimal values for both min player and max player
//given the leaves of the game tree and branching factor 
#include<iostream>
#include<cmath>
using namespace std; 
 
// depth is current depth in game tree. 
// nodeIndex is index of current node in scores[]. 
// isMax is true if current move is 
// of maximizer, else false 
// scores[] stores leaves of Game tree. 
// h is maximum height of Game tree 
int minimax(int depth, int nodeIndex, bool isMax, 
			int scores[], int h, int b, int n ) 
{ 
	// Terminating condition. i.e 
	// leaf node is reached 
	if (depth == h) 
		return scores[nodeIndex]; 
 
	int x=0,y,j,m=n;
	//n=n/b;
	// If current move is max player, this gets max value
	if (isMax) {
		for(j=0;j<b;j++){
			y= minimax(depth+1, nodeIndex*b + j, false, scores, h, b, n);
			if(x<y)
				x=y;
		}
	}
	// Else If current move is Min player, this gets min value
	else{
		x=100000;
		for(j=0;j<b;j++){
			y= minimax(depth+1, nodeIndex*b + j, true, scores, h, b,n);
			if(x>y)
				x=y;
		}	
	}
	return x;
} 

// A function to find Log n to the base b
int logb(int n, int b) 
{ 
	if(n==1)
		return 0;
	else
		return 1 + logb(n/b, b); 
} 

// Driver code 
int main() 
{  
	int scores[100]; 
	int n ,b;// b is branching factor and n is no. of nodes(leaves)
	cout<<"Enter branching factor:\n";
	cin>>b;
	cout<<"Enter no. of nodes(must be of the form "<<b<<"^i):\n";
	cin>>n;
	cout<<"Enter values at nodes from left to right\n";
	for(int i=0; i<n; i++){
		cin>>scores[i];
	} 
	int h = logb(n,b); 
	int res;
	//if(h%2==0){
		res = minimax(0, 0, true, scores, h, b, n);
		cout << "The optimal value (for max player) is : " << res << endl;
	//}
	//else {
		res = minimax(0, 0, false, scores, h, b, n);
		cout << "The optimal value (for min player) is : " << res << endl; 
	//}
	return 0; 
} 

