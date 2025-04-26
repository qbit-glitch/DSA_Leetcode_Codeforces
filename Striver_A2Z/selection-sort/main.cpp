/*
Given an array arr, use selection sort to sort arr[] in increasing order.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: Maintain sorted (in bold) and unsorted subarrays. Select 1. Array becomes 1 4 3 9 7. Select 3. Array becomes 1 3 4 9 7. Select 4. Array becomes 1 3 4 9 7. Select 7. Array becomes 1 3 4 7 9. Select 9. Array becomes 1 3 4 7 9.
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Input: arr[] = [38, 31, 20, 14, 30]
Output: [14, 20, 30, 31, 38]
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 106

*/

// Dirver Code as per geeksforgeeks
#include <bits/stdc++.h>

using namespace std;

class Array{
    public:
    template <class T>
    static void input(vector<T> &A, int n){
        for(int i=0; i<n; i++)
            scanf("%d", &A[i]);
    }

    template <class T>
    static void print(vector<T> &A){
        for(int i=0; i<A.size(); i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

class Solution{
    public:
    // Function to perform Selection Sort
    void selection_sort(vector<int> &arr){
        // Code here
        int n = arr.size();
        for(int i=0; i <= n-2; i++){
            int mini = i;
            for(int j=i; j <= n-1; j++){
                if(arr[j] < arr[mini])
                    mini = j;
            }
            int temp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = temp;
        }
    }

    
};


// Driver Code starts
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number){
            a.push_back(number);
        }

        Solution obj;
        obj.selection_sort(a);

        Array::print(a);
        cout << "~" << endl;
    }
}

