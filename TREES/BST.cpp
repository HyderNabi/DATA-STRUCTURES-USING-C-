#include<iostream>
using namespace std;

//defining class for Binary Search Tree

class node
{
                int data;
                node *left;
                node *right;
public:

        // Procedure to insert node in the Tree
        node *insert(node *root,int val)
        {

                if(root == NULL)
                {

                        node *temp = new node();
                        temp->data = val;
                        temp->left = NULL;
                        temp->right = NULL;
                        root = temp;



                }
                else
                {


                        if(val < root->data)
                        {
                                insert(root->left,val);


                        }
                        else{

                                insert(root->right,val);
                        }

                }


                cout<<root->data<<endl;
              return root;

        }

        //Procedure to display the nodes of the tree
        //inorder traversal is used to traverse the tree for display

        void display(node *root)
        {
              cout<<root->data<<endl;
              root = root->left;
              cout<<root->data<<endl;

        }


};
int main()
{
        node *root = NULL;
        node ob;

        root = ob.insert(root,80);
        cout<<endl;
        root = ob.insert(root,55);
        cout<<endl;
       root = ob.insert(root,40);
    //    cout<<endl;
      //  root = ob.insert(root,12);

//       ob.display(root);



}
