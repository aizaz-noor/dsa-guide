#include <iostream>
using namespace std;

struct tree{
    int info;
    tree *left;
    tree *right;
};
tree *root = NULL;
void insert(tree *&node, int x) {
    if (node == NULL) {
        node = new tree;
        node->info = x;
        node->left = NULL;
        node->right = NULL;
        cout << "Value " << x << " inserted successfully.\n";
    } 
    else if (x < node->info) {
        insert(node->left, x);
    }
    else if (x > node->info) {
        insert(node->right, x);
    } 
    else {
        cout << "Value " << x << " already exists in the tree.\n";
    }
}
// traversing the tree in order
void in_order(tree *root){
    if(root != NULL){
        in_order(root -> left);
        cout<<root -> info<<" ";
        in_order(root-> right);
    }
}
// traverse the tree pre order
void pre_order(tree *root){
    if(root != NULL){
        cout<<root -> info<<" ";
        pre_order(root -> left);
        pre_order(root-> right);
    }
}
// traverse the tree in the postorder
void post_order(tree *root){
    if(root != NULL){
        post_order(root-> left);
        post_order(root-> right);
        cout<<root -> info << " ";
    }
}
int main(){
    int val;
    int n;
    do{
        cout<<"Menu: \n1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>n;
        switch(n){
            case 1:
                cout<<"enter the value you want to insert: ";
                cin>>val;
                insert(root, val);
                break;
            case 2:
                cout<<"inorder Traversal: ";
                in_order(root);
                cout<<endl;
                break;
            case 3:
                cout<<"preorder Traversal: ";
                pre_order(root);
                cout<<endl;
                break;
            case 4:
                cout<<"postorder Traversal: ";
                post_order(root);
                cout<<endl;
                break;
            case 5:
                cout<<"exiting...\n";
                break;
            default:
                cout<<"invalid choice!\n";
        }
    } while (n != 5);
}