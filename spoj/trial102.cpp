#include<iostream>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;


    node(int x)
    {
        value = x;
        //left = NULL;
        //right = NULL;
    }
};

void insert(node* tre, int value){
    if(tre == NULL){
        cout<<"null\n";
		tre= new node(value);
		
    }
    else if(tre->value < value){
        cout<<"right\n";
         insert( tre->right , value);
    }
    else{
        cout<<"left\n";
           insert(tre->left, value);
		}
}

int main(){
    cout<<"making new tree\n";
    node* tre=NULL;
    //node* tree = new node(2);
    insert(tre, 2);
     cout<<(tre==NULL);
	cout<<(*tre).value;
    insert(tre, 1);
    //cout<<(*tree).left->value;
}
