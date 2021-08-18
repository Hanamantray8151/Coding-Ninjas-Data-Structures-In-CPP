/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is 
separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication
whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task. 
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
	public:
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data){
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
};

void pairSumHelper(BinaryTreeNode* root,vector<int> &output){
    if(root == NULL){
        return;
    }
    output.push_back(root -> data);
    pairSumHelper(root -> left,output);
    pairSumHelper(root -> right,output);
}

void pairSum(BinaryTreeNode* root,int sum){
    vector<int> output;
    pairSumHelper(root,output);
    sort(output.begin(),output.end());

    int i = 0;
    int j = output.size() - 1;

    while(i < j){
        if(output[i] + output[j] > sum){
            j--;
        }else if(output[i] + output[j] < sum){
            i++;
        }else{
            cout << output[i] << " " << output[j] << endl;
            i++;
            j--;
        }
    }
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root -> left = new BinaryTreeNode(2);
    root -> right = new BinaryTreeNode(3);
    root -> left -> left = new BinaryTreeNode(4);
    root -> left -> right = new BinaryTreeNode(5);
    root -> right -> left = new BinaryTreeNode(6);
    root -> right -> right = new BinaryTreeNode(7);

    int sum;
    cin >> sum;
    pairSum(root,sum);

    return 0;
}
