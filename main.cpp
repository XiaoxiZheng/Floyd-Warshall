#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

int main(){

    int vertices, edges, queries;
    // Initialize
    cout<<"Welcome to Floyd-Warshall Program"<<endl;
    cout<<"Please enter total number of nodes"<<endl;
    cin >> vertices;
    cout<<"Please enter total number of Edges"<<endl;
    cin >> edges;
    cout<< "Please enter total number of queries."<<endl;
    cin >> queries;

    std::vector<std::vector<int> > graph(
                                    edges,
                                    std::vector<int>(edges));

    // initialize distances
    cout<<"Please enter ABC information"<<endl;
    int a,b,c;
    for(int i=0; i< edges; i++){
        cin>>a;
        cin>>b;
        cin>>c;
        graph[a][b]=c;
    }
    // Floyd-Warshall
    // Add nodes between (first 1 then 2, 3 till n) and look if
    // distance is shorter
    for(int k = 0; k < vertices; k++){
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
               // if((graph[i][k]*graph[k][j]!=0)&& (i!=j)){
                    if(graph[i][k]+graph[k][j]< graph[i][j]){
                        graph[i][j]= graph[i][k]+graph[k][j];
                    }
                 //}
            }
        }
    }

    // initialize diagonal as 0
    for(int j=0; j < vertices; j++){
        graph[j][j]=0;
    }


    int num1, num2;
    cout<<"Please enter your queries"<<endl;
    for(int x = 0; x< queries; x++){
        cin >> num1;
        cin >> num2;
        cout<< "cost = "<< graph[num1-1][num2-1] <<endl; // account for incrementing errors.
    }

    // Print out final distance matrix
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
