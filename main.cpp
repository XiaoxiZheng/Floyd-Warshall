#include <iostream>
#include <vector>
#include <sstream>
#define INF 99999;

using namespace std;

int main(){

    int vertices, edges, queries;
    // Initialize
    //cout<<"Welcome to Floyd-Warshall Program"<<endl;
    //cout<<"Please enter total number of nodes"<<endl;
    cin >> vertices;
    //cout<<"Please enter total number of Edges"<<endl;
    cin >> edges;
   // cout<< "Please enter total number of queries."<<endl;
    cin >> queries;

    int graph[vertices][vertices];
    int next[vertices][vertices];
    //Initialize both vectors to infinity
    for(int i=1; i<=vertices ;i++){
        for(int j =1; j<=vertices; j++){
            //graph[i][j]= NULL;
            next[i-1][j-1] = 999999999;
            graph[i-1][j-1] = 999999999;
        }
    }
    // initialize diagonal as 0
    for(int j=1; j <=vertices; j++){
        graph[j-1][j-1]=0;
    }
    // initialize distances
    //the dist by default is what's passed in from user
    //cout<<"Please enter ABC information"<<endl;
    int a,b,c;
    for(int i=1; i<=edges; i++){
        cin>>a>>b>>c;
        graph[a-1][b-1]=c;
        next[a-1][b-1] = b;
    }
    // Floyd-Warshall
    for(int k = 1; k <=vertices; k++){
        for(int i = 1; i <=vertices; i++){
            for(int j = 1; j <=vertices; j++){
                //if((graph[i-1][k-1]*graph[k-1][j-1]!=0)&&(i != j)){
                    if((graph[i-1][k-1]+graph[k-1][j-1] < graph[i-1][j-1])){
                        //cout<<k<<endl;
                         graph[i-1][j-1]= graph[i-1][k-1]+graph[k-1][j-1];
                         next[i-1][j-1] = next[i-1][k-1];
               // }
                    }
            }
        }
    }
    //Queries
    int num1, num2;
    //cout<<"Please enter your queries"<<endl;
    for(int x = 1; x<=queries; x++){
       // string path; // a temp variable that stores all the string for the path
        cin >> num1;
        cin >> num2;
        //int distance;
        if(num1 ==num2){
            cout<<"cost = 0"<<endl<<num1<<"-"<<num2<<endl;
        }
        else if(next[num1-1][num2-1]>9999999||graph[num1-1][num2-1]>9999999){
            cout<<"NO Path"<<endl;
        }
        else{
            cout<<"cost = "<<graph[num1-1][num2-1]<<endl;
            cout<<num1<<"-";
            while(num1!=num2){
                num1 = next[num1-1][num2-1];
                    if(num1==num2) {
                            cout<<num1<<endl;
                    }
                    else {
                            cout<<num1<<"-";
                    }
            }
        }
    }
return 0;
}
