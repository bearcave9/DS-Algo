// Greedy Algorithm
// Activity selection problem
//
// Greedy choice property- From a local optimum, we can reach a global optimum
// without having to reconsider the decisions already taken
//
//Optimal substructure property- The optimal solution to a problem can be
// determined from the optimal solution to its subproblem
//--------------------------------------------------------------------------
//
// The key is to sort the finishing time, then 1st activity will always be
// selected. Select the first activity which takes the least amount of time and
// then continuing the problem for the remaining activities.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void print_max_activities(int s[], int f[], int n){
	int i,j; //j denotes the last activity selected

	i=0; 
	cout<<i<<endl; //First activity is always selecteds
	for(j=1;j<n;j++){
		if(s[j]>=f[i]) //we can select activity i only if last selected activity has finished
		{
            cout<<j<<endl;
            i=j;    //Activity i now becomes the last activity selected
		}
	}
}

int main(){
	int s[]= {1,3,0,5,8,5};
	int f[]= {2,4,6,7,9,9}; //already sorted

	int n= sizeof(s)/sizeof(s[0]);

	print_max_activities(s,f,n);

	return 0;
}