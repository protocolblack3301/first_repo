#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
	struct BST *parent;
}node;

node *itrsearch(node *root,int key){
while(root!=NULL||root->data!=key){
    if(key<root->data){
        root=root->left;
    }
    else{
        root=root->right;
    }
}
return root;
}

node *recsearch(node *root,int key){
while(root!=NULL||root->data!=key){
    if(key<root->data){
        return recsearch(root->left,key);
    }
    else{
        return recsearch(root->right,key);
    }
}
}


 node *treemin(node *root)
{
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

node *successor(node *key){
    //if key has right subtree
    if(key->right!=NULL){
        key=key->right;
        return successor(treemin(key));
    }

        node *parent=key->parent;
if(parent->parent!=NULL){




    //if key doesnt have right subtree and is left child of its parent
    while(parent!=NULL&&key==parent->left){
        key=parent;
        parent=parent->parent;

    }
    //if key doesnt have right subtree and is right child of its parent
    while(parent!=NULL&&key==parent->right){
        key=parent;
        parent=parent->parent;
    }

}
    return parent;
}



node *treemax(node *root){
while(root->right!=NULL){
    root=root->right;
}
return root;
}

node *create()
{
	node *temp;
	printf("\nEnter data:");
	temp=(node*)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=temp->right=temp->parent=NULL;
	return temp;
}


void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
	printf("\n");
}

void inorder(node *root){
if(root!=NULL){
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
printf("\n");
}


node *insert(node *root,node *temp){
  if(root==NULL){
	root=temp;
	return root;
  }
else{
	if(temp->data<root->data)
	{
		if(root->left!=NULL){
			insert(root->left,temp);
		}


		else{
			root->left=temp;
			temp->parent=root;
		}

	}

	if(temp->data>root->data)
	{
		if(root->right!=NULL){
			insert(root->right,temp);
		}

		else{
			root->right=temp;
		temp->parent=root;
		}
	}
}
return root;
}




int main(int argc, char **argv)
{   node *root=NULL;
	node *newkey=create();
	root=insert(root,newkey);

    newkey=create();
    insert(root,newkey);


	inorder(root);


	return 0;
 }
