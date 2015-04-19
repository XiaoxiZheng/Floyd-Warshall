#include <iostream>
#include <vector>
#include <sstream>
#define INF INT_MAX/2 -1;

using namespace std;

int main(){

    int vertices, edges, queries;
    // Initialize
    cout<<"Welcome to Floyd-Warshall Program"<<endl;
    cout<<"Please enter total number of nodes"<<endl;
    cin >> vertices;
    vertices++;
    cout<<"Please enter total number of Edges"<<endl;
    cin >> edges;
    cout<< "Please enter total number of queries."<<endl;
    cin >> queries;

    std::vector<std::vector<int> > graph(
                                    vertices+1,
                                    std::vector<int>(vertices+1));
    std::vector<std::vector<string> > dist(
                                    vertices+1,
                                    std::vector<string>(vertices+1));
/*
//Initialize both vectors to null
    for(int i=0; i<vertices ;i++){
        for(int j =0; j<vertices; j++){
            graph[i][j]= NULL;
            dist[i][j] = "";
        }
    }
*/
    // initialize distances
    //the dist by default is what's passed in from user
    cout<<"Please enter ABC information"<<endl;
    int a,b,c;
    for(int i=1; i<=edges; i++){
        stringstream ss;
        cin>>a>>b>>c;
        ss<<a<<"-"<<b;
        graph[a][b]=c;
        dist[a][b] = ss.str();
    }
    // Floyd-Warshall
    // Add nodes between (first 1 then 2, 3 till n) and look if
    // distance is shorter
    for(int k = 1; k <=vertices; k++){
        for(int i = 1; i <=vertices; i++){
            for(int j = 1; j <=vertices; j++){
                if((graph[i][k]*graph[k][j]!=0)&&(i != j)){
                    if((graph[i][k]+graph[k][j] < graph[i][j])||(graph[i][j]==0)){
                        //cout<<k<<endl;
                         graph[i][j]= graph[i][k]+graph[k][j];
                        //cout<<"Dist["<<i<<"]["<<j<<"]"<<"Path--"<<i<<" "<<k<<" "<<j<<endl;
                         stringstream intToString;
                         if(!dist[i+1][j].empty() && (dist[i][k].length()==3)){
                             intToString<< i <<"-"<<dist[i+1][j];
                         }
                         else if(!dist[i][k].empty()){
                            intToString << dist[i][k]<<"-"<<j;
                         }
                         else{
                            intToString <<i<<"-"<<k<<"-"<<j;
                         }
                         dist[i][j] = intToString.str();
                    }
                }
            }
        }
    }

    // initialize diagonal as 0
    for(int j=1; j <=vertices; j++){
        stringstream ss;
        ss<<j<<"-"<<j;
        graph[j][j]=0;
        dist[j][j] = ss.str();
    }

    //Queries
    int num1, num2;
    cout<<"Please enter your queries"<<endl;
    for(int x = 0; x< queries; x++){
        cin >> num1;
        cin >> num2;
        //int distance;
        if(dist[num1][num2].empty()){
            cout<<"NO Path"<<endl;
        }
        //else if(graph[num1][num2]== 0){
            //cout<< "cost = 0 "<<endl<<dist[num1][num2]<<endl;
        //}
        else{
            cout<< "cost = "<< graph[num1][num2]<<endl<<dist[num1][num2]<<endl;
        }
    }

    cout<<"Path matrix"<<endl;
    for(int i = 1; i <vertices; i++){
        for(int j = 1; j <vertices; j++){
                if(dist[i][j].empty()) cout<<"NONE"<<"\t\t\t";
                else cout<< dist[i][j]<<"\t\t\t";
        }
        cout << endl;
    }
    // Print out final distance matrix
    cout<<"Cost matrix"<<endl;
    for(int i = 1; i <vertices; i++){
        for(int j = 1; j<vertices; j++){
                cout << graph[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}
