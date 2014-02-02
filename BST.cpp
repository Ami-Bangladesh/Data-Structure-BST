#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

typedef struct treeNode
{
     int data;
	 struct treeNode *left;
	 struct treeNode *right;
}treeNode;

treeNode* FindMin(treeNode* node)
{
     if(node==NULL)
		 return NULL;
	 if(node->left)
		 return FindMin(node->left);
	 else
		 return node;
}

treeNode* FindMax(treeNode* node)
{
	if(node==NULL)
		return NULL;
	if(node->right)
		return FindMax(node->right);
	else
		return node;
}

treeNode* Insert(treeNode* node,int data)
{
	if(node==NULL)
	{
		treeNode* temp;
		temp=(treeNode*)malloc(sizeof(treeNode));
		temp->data=data;
		temp->left = temp->right = NULL;
		return temp;
	}
	if(data>node->data)
		node->right=Insert(node->right,data);
	else if(data<node->data)
		node->left=Insert(node->left,data);
		return node;
}

treeNode* Delete(treeNode* node,int data)
{
	treeNode* temp;
	if(node==NULL)
		 cout<<"Element not found ."<<endl;
	else if(data<node->data)
		 node->left=Delete(node->left,data);
	else if(data>node->data)
		 node->right=Delete(node->right,data);
	else if(node->left && node->right)
	{
		temp = FindMin(node->right);
		node->data=temp->data;
		node->right=Delete(node->right,temp->data);
	}
	else
	{
		temp=node;
		if(node->left==NULL)
			    node=node->right;
		else if(node->right==NULL)
			    node=node->left;
		free(temp);
	}
	return node;
}

treeNode* Find(treeNode* node,int data)
{
	if(node==NULL)
		return NULL;
	if(data<node->data)
		return Find(node->left,data);
	else if(data>node->data)
		return Find(node->right,data);
	else
		return node;
}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
			return;
        PrintInorder(node->left);
		cout<<node->data<<" ";
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
        if(node==NULL)
           return;
		cout<<node->data<<" ";
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
           return;
        PrintPostorder(node->left);
        PrintPostorder(node->right);
		cout<<node->data<<" ";
}


int main()
{
	treeNode *root =NULL; treeNode *temp;
	int n;
	while(1)
	{
	   cout<<"1. Insert node ."<<endl;
	   cout<<"2. FindMin node ."<<endl;
	   cout<<"3. FindMax node ."<<endl;
	   cout<<"4. Find node ."<<endl;
	   cout<<"5. Delete node ."<<endl;
	   cout<<"6. Display tree ."<<endl;
	   cin>>n;
	   if(n==1)
	   {
	      int m;
		  cout<<"Num of nodes :"; cin>>m;
		  for(int i=0;i<m;i++)
		  {
		     int a;
			 cin>>a;
			 root=Insert(root,a);
		  }
		  cout<<endl;
	   }
	   if(n==2)
	   {
		  temp=FindMin(root);
		  cout<<"Minimum node :"<<temp->data<<endl;
	   }
	   if(n==3)
	   {
		  temp=FindMax(root);
		  cout<<"Maximum node :"<<temp->data<<endl;
	   }
	   if(n==4)
	   {
		  int b;
		  cout<<"Which elements you wanna looking for : "; cin>>b;
		  temp=Find(root,b);
		  if(temp==NULL)
			 cout<<b<<" is not found ."<<endl;
		  else
			 cout<<b<<" is found ."<<endl;
	   }
	   if(n==5)
	   {
	      int c;
	      cout<<"Which element you wanna delete : "; cin>>c;
	      Delete(root,c);
	      cout<<endl;
	   }
	   if(n==6)
	   {
	      int d;
	      cout<<"Display the tree ."<<endl;
	      cout<<"1. Inorder ."<<endl;
	      cout<<"2. Preorder ."<<endl;
	      cout<<"3. Postorder ."<<endl;
		  cin>>d;
	      if(d==1)
		     PrintInorder(root);
	      if(d==2)
		     PrintPreorder(root);
	      if(d==3)
		     PrintPostorder(root);
	      cout<<endl;
	   }
	}
	return 0;
}
