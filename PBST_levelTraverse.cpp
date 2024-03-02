// C++ implementation to check if the given array 
// can represent Level Order Traversal of Binary 
// Search Tree
#include <bits/stdc++.h>
 
using namespace std;
 
// to store details of a node like
// node's data, 'min' and 'max' to obtain the
// range of values where node's left and 
// right child's should lie
struct nodeInfo
{
    nodeInfo(int a, int b, int c){
      data = a;
      min = b;
      max = c;
    }
    int data;
    int min;
    int max;
};
 
// function to check if the given array 
// can represent Level Order Traversal 
// of Binary Search Tree
bool isBST(int arr[], int n)
{
    // if tree is empty
    if (n == 0)
        return true;
     
    // queue to store NodeDetails
    queue<NodeInfo*> q;
     
    // index variable to access array elements
    int i=0;
     
    // root node
    auto newNode = new NodeInfo(arr[i], INT_MIN, INT_MAX);
    newNode->data = arr[i];
    i++;
    newNode->min = INT_MIN;
    newNode->max = INT_MAX;
    q.push(newNode);
     
    // loop through all the node
    //    1
    //  5   8
    // 3 6
    // in queue 1,5,8,3,6 
    while (i != n && !q.empty())        
    {
        auto temp = q.front();
        q.pop();
         
        // check if i is left child
        if (i < n && (arr[i] < temp.data && 
                     arr[i] > temp.min))
        {
            newNode.data = arr[i++];
            newNode.min = temp.min;
            newNode.max = temp.data;
            q.push(newNode);                
        }
         
        // check whether there are more elements 
        // in the arr[] and arr[i] can be right child 
        // of 'temp.data' or not 
        if (i < n && (arr[i] > temp.data && 
                      arr[i] < temp.max))
        {
            // Create NodeDetails for newNode 
            /// and add it to the queue
            newNode.data = arr[i++];
            newNode.min = temp.data;
            newNode.max = temp.max;
            q.push(newNode);            
        }        
    }
     
    // given array represents level
    // order traversal of BST
    if (i == n)
        return true;
         
    // given array do not represent 
    // level order traversal of BST    
    return false;        
}
 
// Driver program to test above
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};    
    int n = sizeof(arr) / sizeof(arr[0]);    
    if (levelOrderIsOfBST(arr, n))
        cout << "Yes";
    else
        cout << "No";        
    return 0;    
} 
