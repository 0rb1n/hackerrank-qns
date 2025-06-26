#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

// long arrayManipulation(int n, vector<vector<int>> queries) {
//     int m = queries.size(); long result=0;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<m; i++){
//         int a = queries[i][0];
//         int b = queries[i][1];
//         int summoned = queries[i][2];
//         for(int j=a-1; j<b; j++){
//             arr[j] += summoned;
//         } 
//     }
    
//     for(int i=0; i<n; i++){
//         if(result < arr[i]){
//             result = arr[i];
//         }
//     }
    
//     return result;
// }


long arrayManipulation(int n, vector<vector<int>> queries) {
    int m = queries.size(); long result = LONG_MIN;
    vector<long> arr(n+2, 0);
    vector<long> arr2(n+2, 0);

    for(int i = 0; i<m; i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        arr[a] += k;
        arr[b+1] -= k;
    }
  
    for(int i=1; i<n+2; i++){
        arr2[i] = arr2[i-1] + arr[i];
    }

    for(int i=0; i<n+2; i++){
        if(result < arr2[i]){
            result = arr2[i];
        }
    }
    return result;
}
int main(){
    ofstream fout("output.txt");
    
    int m, n;
    cin >> n >> m;
    
    vector<vector<int>> queries(m, vector<int>(3));
    for(int i = 0; i<m; i++){
        cin >> queries[i][0]
            >> queries[i][1]
            >> queries[i][2]; 
    }
    long result = arrayManipulation(n, queries);
    fout << result <<endl;
    
    fout.close();
    return 0;
}


