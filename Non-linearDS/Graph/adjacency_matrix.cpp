#include <iostream>
using namespace std;

int main(){
    int adj[4][4];
    int i,j;
    
    // taking user input for adjacency matrix (2d array)
    for(i = 0; i < 4; i++){ 
        for(j = 0; j < 4; j++){
            cout << "Is there is a direct path from V["<<i+1<<"] to V["<<j+1<<"] ? (Yes-1,NO-0):";
            cin >> adj[i][j];
        }
    }

    // i/o = 0 0 0 1 1 0 1 1 1 0 0 1 0 0 1 0

    cout << endl << endl << "Following is the adjaceny matix of the graph:" << endl;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}