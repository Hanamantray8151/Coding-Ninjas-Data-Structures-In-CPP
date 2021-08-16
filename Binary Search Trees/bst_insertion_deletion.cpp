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
    private:
        BinaryTreeNode* root;

        bool hasData(int data,BinaryTreeNode* node){
            if(root == NULL){
                return false;
            }

            if(data == node -> data){
                return true;
            }else if(data < node -> data){
                return hasData(data,node -> left);
            }else{
                return hasData(data,node -> right);
            }
        }

        BinaryTreeNode* insertData(int data,BinaryTreeNode* node){
            if(node == NULL){
                BinaryTreeNode* newNode = new BinaryTreeNode(data);
                return newNode;
            }

            if(data < node -> data){
                node -> left = insertData(data,node -> left);
            }else{
                node -> right = insertData(data,node -> right);
            }
            return node;
        }

        BinaryTreeNode* deleteData(int data,BinaryTreeNode* node){
            if(node == NULL){
                return NULL;
            }

            if(data < node -> data){
                node -> left = deleteData(data,node -> left);
                return node;
            }else if(data > node -> data){
                node -> right =  deleteData(data,node -> right);
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
                    BinaryTreeNode* minNode = node -> right;
                    while(minNode -> left != NULL){
                        minNode = minNode -> left;
                    }
                    int rightMin = minNode -> data;
                    node -> data = rightMin;
                    node -> right = deleteData(rightMin,node -> right);
                    return node;
                }
            }
        }

        void printTree(BinaryTreeNode* node){
            if(node == NULL){
                return;
            }
            cout << node -> data << ":";
            if(node -> left != NULL){
                cout << "L:" << node -> left -> data;
            }
            if(node -> right != NULL){
                cout << "R:" << node -> right -> data;
            }
            cout << endl;

            printTree(node -> left);
            printTree(node -> right);
        }

    public:
        BST(){
            this -> root = NULL;
        }

        bool hasData(int data){
            return hasData(data,root);
        }

        void insertData(int data){
            root = insertData(data,root);
        }

        void deleteData(int data){
            root = deleteData(data,root);
        }

        void printTree(){
            printTree(root);
        }
};

int main(){
    BST b;
    b.insertData(4);
    b.insertData(2);
    b.insertData(6);
    b.insertData(1);
    b.insertData(3);
    b.insertData(5);
    b.insertData(7);

    b.printTree();

    b.deleteData(4);
    b.printTree();

    return 0;
}
