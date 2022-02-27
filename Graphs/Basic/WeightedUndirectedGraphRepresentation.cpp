#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return 0;
}

/*

we will be using a adjacency matrix as an array of vectors with array size of (n+1)/(n)
here each index represents each vertex of the graph
now we will enter all the vertices connected to the edges of the vertex in the graph
and do the vice versa also
so now the space complexity will be n+∑degree(each vertex) = N+2*E
since will add every time weights too we will be having extra N+4*E as space complexity
 
*/