// improvement 2
// union by rank
// every element has a rank. Initially, all elements have a zero rank.
// the parent of root of every set tree is the same element
// find operation changes the parent of an element to directly the root of the tree

/*
element i has a parent stored in parent[i]
the root element of the set tree has parent[i]=negative of size
find changes the parent of the element to the root and returns the root of the set tree
union(x,y) changes x's root to the root of y or y's root to the root of x depending upon rank of x and y

*/


void makeSet(int parent[],int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
}

// with this implementation, find takes O(log n)
int find_parent(int parent[], int i)
{
	//also include the condition if i is not in any set if required
	//not included here

    if (parent[i] == i)
        return i;

    return parent[i]=find_parent(parent, parent[i]);
}

// by rank implementation of union()
void Union(int parent[], int x, int y)
{
    int xset=find_parent(parent,x);
    int yset=find_parent(parent,y);

    if(!(xset==yset))
        parent[xset]=yset;

}
