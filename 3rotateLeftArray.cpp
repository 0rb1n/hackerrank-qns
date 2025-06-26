#include <iostream>
#include <vector>
#include <algorithm> // for std::rotate

using namespace std;

// std::vector<int> rotateLeft(int d, std::vector<int> arr) {
//     int arrSize=arr.size();
//     for(int i=0; i<d; i++){
//         int temp=arr[0]; int j=0;//1,
//         while(j<arrSize-1){
//             arr[j]=arr[j+1];
//             j++;//1 2 3 5  
//         }
//         arr[arrSize-1]=temp;
//     }
//     return arr;
// }

vector<int> rotateLeft(int d, vector<int> arr) {
    rotate(arr.begin(), arr.begin() + d, arr.end());
    return arr;
}



int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int d = 4;

    std::vector<int> rotated = rotateLeft(d, arr);

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Rotated array: ";
    for (int num : rotated) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
