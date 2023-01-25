#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(struct node* root,int val)
{
    struct node* nw=(struct node*)malloc(sizeof(struct node));
    nw->data=val;
    nw->right=NULL;
    nw->left=NULL;

    return nw;
}
int countNodes(struct node* root)
{
    if(root==NULL)
    return 0;
    else
    return countNodes(root->left) + countNodes(root->right) +1;
}

int countDegree_0(struct node* root)
{
    static int count=0;
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    count++;

    countDegree_0(root->left);
    countDegree_0(root->right);

    return count;

}

int countDegree_1(struct node* root)
{
    static int count=0;
    if(root==NULL)
    return 0;

    if(root->left==0 && root->right!=0 || root->left!=0 && root->right==0)
    count++;

    countDegree_1(root->left);
    countDegree_1(root->right);

    return count;

}

int countDegree_2(struct node* root)
{
    static int count=0;
    if(root==NULL)
    return 0;

    if(root->left!=0 && root->right!=0)
    count++;

    countDegree_2(root->left);
    countDegree_2(root->right);

    return count;

}
int main()
{
    struct node* root=createNode(root,1);
    root->left=createNode(root,2);
    root->right=createNode(root,3);
    root->left->left=createNode(root,4);
    root->left->right=createNode(root,5);
    root->right->left=createNode(root,6);
    root->right->right=createNode(root,7);

  int ans= countDegree_2(root);
  printf("%d",ans);
  return 0;
}