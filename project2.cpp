#include<iostream>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;
class Node {
	public:
		char* name;
		int value;
		Node* left;
		Node* right;

	Node(char* n){
		name = n;
		value = strlen(n);
		left = NULL;
		right = NULL;
	}
	void print(){
		if(left!=NULL || right!=NULL){
			cout<<name<<":";
			if(left!=NULL)
				cout<<"L("<<left->name<<") ";
			if(right!=NULL)
				cout<<"R("<<right->name<<") ";
			cout<<endl;				
			if(left!=NULL)
				left->print();
			if(right!=NULL)
				right->print();			

		}
	}
};

class Tree {
	public:
		Node* root;		
	void add(char* name) {
		int val= strlen(name);
		if (root == NULL)
			root = new Node(name);
		else{
			Node* temp = root;
			while(true){
				if(val<=temp->value) {
					if(temp->left == NULL) {
						temp->left = new Node(name);
						break;
					}
					temp = temp->left;
				}
				else {
					if(temp->right == NULL) {
						temp->right = new Node(name);
						break;
					}
					temp = temp->right;
				}
			}
		}
	}
	void print(){
		root->print();
	}
	bool search(int val) {
		Node* temp = root;
		while(temp != NULL) {
			if(temp->value == val)
				return true;
			if(val <= temp->value)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return false;
		
		//algorithm
	}
	int alg(int a, int b){
		int op=0;
		queue<Node*> queueNodes;
		queueNodes.push(root);
		while(!queueNodes.empty()){
			Node* node=queueNodes.front();
			queueNodes.pop();
			op++;
			
			if(node->value<=b)
				if(node->right!=NULL)
					queueNodes.push(node->right);
			
			op++;
			if(node->value>=a)
				if(node->left!=NULL)
				 	queueNodes.push(node->left);
			
			op+=2;
			if(node->value>=a and node->value<=b);
				cout<<node->name<<endl;
		}
		return op;
	}
};
int main(){
	/*Tree* t = new Tree();
	t->add("Anna");
	t->add("Catheline");
	t->add("John");
	t->add("EdmUnd");
	t->add("Frank");
	t->add("Ola");
	t->add("Josephine");
	t->print();
	
	t->alg(3,6);*/
	
	srand(time(NULL));
	ofstream myfile;
	myfile.open("result");
	for (int i=1; i<=100; i++){
		Tree* t=new Tree();
		for(int j=1; j<=i; j++){
			int length=rand()%20+1;
			char* word=new char [length+1];
			for(int k=0; k<length; k++)
				word[k]='a';
			word[length]='\0';
			t->add(word);
		}
		int a=rand()%22;
		int b=rand()%22;
		if(a>b)
			swap(a,b);
		int n = t->alg(a,b);
		myfile<<n<<endl;
	}
	myfile.close();
}
