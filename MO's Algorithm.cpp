Mo's algorithm : query square root decomposition

1. The idea of MO’s algorithm is to pre-process all queries
   so that result of one query can be used in next query.
   
 let a[0,... n-1 ] be the array
 
 let q[0.....m-1] be the queries 
 
  * sort queries such that 
    l values from 0 to sqrt(n)-1 are clustered together
    then  from sqrt(n) to 2*sqrt(n)-1 and so on..
    
  * queries are sorted in increasing order of R values
  
  
  *
   Process all queries one by one in a way that every query uses sum computed in the previous query.
   Let ‘sum’ be sum of previous query.
   Remove extra elements of previous query. 
   For example if previous query is [0, 8] and current query is [3, 9], then we subtract a[0],a[1] and a[2] from sum
   Add new elements of current query. 
   In the same example as above, we add a[9] to sum.
   
   #time complexity:  O((m+n) * sqrt(n)) time.
   
   
   #important points:
   	
   	1.all the queries should be known
   	
   	2.mo's algorithm works for queries only. it doesnt allow update queries
   	
   
   
   
   #programme :
   	
   	
   	
   	#include<bits/stdc++.h>
   	using namespace std;
   	int block;
   	struct Query
   	{
   		int L,R;
   	};
   	
  // Function used to sort all queries so that all queries  
// of the same block are arranged together and within a block, 
// queries are sorted in increasing order of R values. 
bool compare(Query x, Query y) 
{ 
    // Different blocks, sort by block. 
    if (x.L/block != y.L/block) 
        return x.L/block < y.L/block; 
  
  
  
  
    // Same block, sort by R value 
    return x.R < y.R; 
} 
	
	void queryResults(int a[], int n, Query q[], int m) 
{ 
    // Find block size 
    block = (int)sqrt(n); 
  
    // Sort all queries so that queries of same blocks 
    // are arranged together. 
    sort(q, q + m, compare); 
  
    // Initialize current L, current R and current sum 
    int currL = 0, currR = 0; 
    int currSum = 0; 
  
    // Traverse through all queries 
    for (int i=0; i<m; i++) 
    { 
        // L and R values of current range 
        int L = q[i].L, R = q[i].R; 
  
        // Remove extra elements of previous range. For 
        // example if previous range is [0, 3] and current 
        // range is [2, 5], then a[0] and a[1] are subtracted 
        while (currL < L) 
        { 
            currSum -= a[currL]; 
            currL++; 
        } 
  
        // Add Elements of current Range 
        while (currL > L) 
        { 
            currSum += a[currL-1]; 
            currL--; 
        } 
        while (currR <= R) 
        { 
            currSum += a[currR]; 
            currR++; 
        } 
  
        // Remove elements of previous range.  For example 
        // when previous range is [0, 10] and current range 
        // is [3, 8], then a[9] and a[10] are subtracted 
        while (currR > R+1) 
        { 
            currSum -= a[currR-1]; 
            currR--; 
        } 
  
        // Print sum of current range 
        cout << "Sum of [" << L << ", " << R 
             << "] is "  << currSum << endl; 
    } 
}
	
	
	
	
	
	
	
	
   	
   	int main()
   	{
   		int n,q;
   		cin>>n>>q;
   		int a[n];
   		for(int i=0;i<n;i++)
   		cin>>a[i];
        query u[q];
   		for(int i=0;i<q;i++)
   		{
   		
   			cin>>u[i].L>>u[i].R;
   			query.push_back({l,r});
	    }
	    
	    queryans(a,n,u,q);
	    return 0;
	   }
   
   


