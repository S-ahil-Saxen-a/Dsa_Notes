#include <iostream>
using namespace std;

// WARSHALL'S ALGORITHM for calculation path matrix

// P [i][j] = P [i][j] || ( P [i][j] && P [k][j] )
//  k         k-1           k-1         k-1

void warshall(int[][4], int[][4]);

int main(){
    int adj[4][4],path[4][4];
    int i,j;
    
    // taking user input for adjacency matrix (2d array)
    for(i = 0; i < 4; i++){ 
        for(j = 0; j < 4; j++){
            cout << "Is there is a direct path from V["<<i+1<<"] to V["<<j+1<<"] ? (Yes-1,NO-0):";
            cin >> adj[i][j];
        }
    }

    // i/o = 0 0 0 1 1 0 1 1 1 0 0 1 0 0 1 0

    warshall(adj, path);

    cout << endl << endl << "Following is the path matix of the graph:" << endl;

    // displaying the upated final path matrix of the given graph
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void warshall(int adj[][4], int path[][4]){
    int i,j,k;

    // copying the adjacency matrix to the intial path martrix (Po)
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            path[i][j] = adj[i][j];
        }
    }

    for(k = 0; k < 4; k++){ // this loop is to find P1,P2,P3,P4 (four times)

        // these loops is to update the current path martrix with the P1,P2,P3 and P4 value
        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }

    }

}