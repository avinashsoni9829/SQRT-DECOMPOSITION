common query optimization technique

1. helps in the reduction of time complexity by a factor of sqrt(N)

2. it decomposes the array into chunks of size sqrt(N)

3. array on n elements is decomposed into sqrt(n) blocks,
where each block contains sqrt(n) elements (assuming size of array is perfect square).



->you need to answer certain queries asking you the answer for the elements in range l to r
(l and r are starting and ending indices of the array) in the original n sized array.


 #1	
 precomputed the answer for all individual chunks and
 now we need to answer the queries in range l to r.
 #2
 we are jumping sqrt(n) steps at a time instead of jumping 1 step at a time as done in naive approach
 
 
 range sum queries : Q L R
 
 point update queries : U idx val
 
 
 
 let us consider the array of 9 elements
 
 A[]= { 1,5,2,4,6,1,3,5,7}
 
 
 no of blocks = sqrt(9)=3
 
 block 1= {1,5,2}=1+5+2=8
 
 block2={4,6,1}=4+6+1=11
 
 block3={3,5,7}=3+5+7=15
 
 queries:
 	
 	1.when the queries are on block boundaries:
 		
 		for ex l=3, r=8
 		       #---------# 
 		{0,1,2,3,4,5,6,7,8}
 		{1,5,2,4,6,1,3,5,7}
 		
 		so this query covers the block 2 and 3 and the ans will be 11+15=26
 		
 	time complexity: O(sqrt(n)) in the worst case	
 	
	 
	2.when given range is not on the block boundaries
	
	for ex l=1 , r=6
	
	
	       #---------#
		{0,1,2,3,4,5,6,7,8}
 		{1,5,2,4,6,1,3,5,7}
	
	
	 5+2+block-2+3= 7+11+3=21 ans 
	 
	 
	 
	 time  complextiy will also be O(sqrt(n)).
	 
	 
	 
	 
	 
	 
	 3.update queries : In this query we simply find the block in which the given index lies,
	  then subtract its previous value and add the new updated value as per the point update query.
	  
	  time complexity for this is O(1).
	  
	  
	  
	  
	 #programme :
	 
	 
	 
	 
	 #include<bits/stdc++.h>
	 using namespace std;
	 const max=1e5+5;
	 const bsize=sqrt(max);
	 int arr[max];
	 int blk[bsize];
	 int size;
	 
	 void update(int indx,int val)
	 {
	 	int num=indx/size;
	 	blk[num]+=val-arr[indx];
	 	arr[indx]=val;
	 }
	 
	 int query(int l,int r)
	 {
	 	int sum=0;
	 	while(l<r and l%size!=0 and l!=0)
	 	{
	 		sum+=arr[i];
	 		l++;
		 }
		 
		 while(l+size<=r)
		 {
		 	sum+=blk[l/size];
		 	l+=size;
		 }
		 while(l<=r)
		 {
		 	sum+=arr[i];
		 	l++;
		 }
		 
		 return sum;
	 }
	 
	 
	 void preprocess(int a[],int n)
	 {
	 	int idx=-1;
	 	
	    size=sqrt(n);
	 	
	 	for(int i=0;i<n;i++)
	 	{
	 		arr[i]=a[i];
	 		if(i%size==0)
	 		idx++;
	 		blk[idx]+=arr[i];  // here we need to add the elements ,if we want to find xor values then blk[idx]^=arr[i];
		 }
	 }
	 
	 int main()
	 {
	 	int n,q;
	 	cin>>n>>q;
	 	
	 	int a[n];
	 	
	 	for(int i=0;i<n;i++)
	 	cin>>a[i];
	 	
	 	preprocess(a,n);
	 	
	 	while(q--)
	 	{
	 		int l,r;
	 		cin>>l>>r;
	 		cout<<query(l,r)<<endl;
	 		
	 		
	 		update(8,0);
	 		
	 		
		 }
	 	
	}	return 0;
