#include <iostream>
#include<string>
using namespace std ;

class node{
public:
    string info;
    node *leftchild;
    node *rightchild;

    //cons buat node class
    node(string i,node *l,node *r)
    {
        info = i;
        leftchild=l;
        rightchild=r;
    }
};

class binarytree{
    public:
    node *root;

    binarytree()
    {
        root = NULL; 
    }

    void insert (string element)
    {
        node *newnode = new node (element,NULL,NULL);

        newnode ->info=element;
        newnode ->leftchild= NULL;
        newnode ->rightchild = NULL;

        node *parent = NULL;
        node *currentnode = NULL;

        search(element, parent, currentnode);

        if (parent == NULL)
        {
            root = newnode;
            return;
        }
         if (element < parent->info)
        {
            parent->leftchild = newnode;
        }
        else if (element > parent->info)
        {
            parent->rightchild = newnode;
        }
    }

    // This function searches the current node of the specified node
    // as well as the current node of its parent
    void search(string element, node *&parent, node *&currentNode)
    {
        currentNode = root;
        parent = NULL;

        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;

            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(node *ptr)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(node *ptr)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        } 
    }
     void postorder(node *ptr)
    {
         if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }  
    }
};

int main()
{
    
}