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

class BST{
    BinaryTreeNode* root;
    public:
        BST(){
            root = NULL;
        }
    private:
        BinaryTreeNode* insertHelper(int data,BinaryTreeNode* node){
            if(node == NULL){
                BinaryTreeNode* newNode = new BinaryTreeNode(data);
                return newNode;
            }
            if(data < node -> data){
                node -> left = insertHelper(data,node -> left);
            }else{
                node -> right = insertHelper(data,node -> right);
            }
            return node;
        }
    public:
        void insert(int data){
            this -> root = insertHelper(data,this -> root);
        }

    private:
        BinaryTreeNode* deleteDataHelper(int data,BinaryTreeNode* node){
            if(node == NULL){
                return NULL;
            }
            if(data < node -> data){
                node -> left = deleteDataHelper(data,node -> left);
                return node;
            }else if(data > node -> data){
                node -> right = deleteDataHelper(data,node -> right);
                return node;
            }else{
                if(node -> left == NULL && node -> right == NULL){
                    delete node;
                    return NULL;
                }else if(node -> left == NULL){
                    BinaryTreeNode* temp = node -> right;
                    node -> right = NULL;
                    delete node;
                    return temp;
                }else if(node -> right == NULL){
                    BinaryTreeNode* temp = node -> left;
                    node -> left = NULL;
                    delete node;
                    return temp;
                }else{
                    BinaryTreeNode* minData = node -> right;
                    while(minData -> left != NULL){
                        minData = minData -> left;
                    }
                    int rightMin = minData -> data;
                    node -> data = rightMin;
                    node -> right = deleteDataHelper(rightMin,node -> right);
                    return node;
                }
            }
        }
    public:
        void deleteData(int data){
            this -> root = deleteDataHelper(data,this -> root);
        }

    private:
        bool hasDataHelper(int data,BinaryTreeNode* node){
            if(node == NULL){
                return false;
            }
            if(node -> data == data){
                return true;
            }else if(data < node -> data){
                return hasDataHelper(data,node -> left);
            }else{
                return hasDataHelper(data,node -> right);
            }
        }

    public:
        bool hasData(int data){
            return hasDataHelper(data,root);
        }

    private:
        void printTreeHelper(BinaryTreeNode* root){
            if(root == NULL){
                return;
            }
            cout << root -> data << ":";
            if(root -> left != NULL){
                cout << "L:" << root -> left -> data;
            }
            if(root -> right != NULL){
                cout << "R:" << root -> right -> data;
            }
            cout << endl;
            printTreeHelper(root -> left);
            printTreeHelper(root -> right);
        }

    public:
        void printTree(){
            printTreeHelper(root);
        }
};

int main(){
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(6);
    b.insert(1);
    b.insert(3);
    b.insert(5);
    b.insert(7);

    b.printTree();

    b.deleteData(4);
    b.printTree();

    return 0;
}
