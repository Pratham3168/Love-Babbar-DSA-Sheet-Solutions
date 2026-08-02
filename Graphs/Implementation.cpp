//IMPLEMENTATION OF GRAPH USING ADJACENCY LIST
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){

        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void print(){

        for (auto i: adj){
            cout<<i.first<<"->";
            for(int j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }

    }

};

int main(){
    int n;
    int m;

    cout<<"Enter the number of nodes : ";
    cin>>n;

    cout<<"\nEnter the number of edges : ";
    cin>>m;


    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }


    g.print();
    return 0;


}





//====================================ATTENTION==============================================//

//THIS IS THE SIMILAR IMPLEMENTATION OF THE ABOVE CODE BUT HERE U AND V ARE ALREADY GIVEN USING EDGES VECTOR
//AND WE HAVE TO PRINT THE ADJACENCY LIST OF THE GRAPH
//THIS CODE IS TAKEN FROM A QUESTION ON CODING NINJA PLATFORM
// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     // Write your code here.
//     vector<int> ans[n];

//     for(int i=0;i<m;i++){
//         int u=edges[i][0];
//         int v=edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }

//     vector<vector<int>> adj(n);
//     for(int i=0;i<n;i++){
//         adj[i].push_back(i);
//         for(int j=0;j<ans[i].size();j++){
//             adj[i].push_back(ans[i][j]);
//         }
//     }
//     return adj;

// }