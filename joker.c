#include<stdio.h>
#include<stdlib.h>
//functionto create a node
struct node {
	int data;
	struct node *link;
}*head=NULL;
//create a head pointing to null
//creating a simple variable
//typedef node = struct node *;
// function to allocate memory
struct node *getnode(){
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	return temp;
}
//function to insert at start
void insrt(int x){
	struct node *t=head;
	t = getnode();
	t->data=x;
	if(head==NULL)
	{	
		t->link=NULL;
		head=t;
	}
	else 
	{
		t->link=head;
		head=t;
	}
}
//function to insert at end
void ine(int y){
	struct node *t= head;
	t=getnode();
	t->data=y;
	if (head==NULL)
	{	
		t->link=NULL;
		head=t;
	}
	else
	{
		struct node *temp =head;
        // We do need to have last node at temp.
        // we should not get down the train
		while(temp->link)
		{
			temp=temp->link;
		}
        // written this line after the while loop as we need to do this only once	
        temp->link=t;
	}
}
//function to at between
void inb(int z,int a)
{
	struct node *t= head;
	t=getnode();
	t->data=z;
	if(head==NULL)
	{
		t->link=NULL;
		head=t;
	}
	else{
		struct node *temp=head;
		while(temp->data!=a)
		{
			temp=temp->link;
		}
        // removed these two lines from the while loop and written then outside for loop
        t->link=temp->link;
        temp->link=t;
	}
}
//function to display
void display(){
	if(head==NULL)
		printf("List is empty");
	else{ 
		struct node *temp=head;
			printf("\nList elements are: ");
		while(temp){
			printf("%d\t",temp->data);
			temp=temp->link;
		}
        // removed this line    printf("%d\t->NULL",temp->data);
	}
}
int main(){
		int a,b,c,l1,l2;
	while(1){
		printf("*****MENU*****\n1.Insert\n2.Display\n3.Exit\n");
		scanf("%d",&a);
		switch(a){
			case 1: printf("Enter the value to insert");
					scanf("%d",&b);
				//while(1){
					printf("Where you want to insert the element: \n1.At start\n2.At end\n3.At btw");
					scanf("%d",&c);
					switch(c){
						case 1: insrt(b);
							break;
						case 2: ine(b);
							break;
						case 3: printf("Enter two values where you want to insert: ");
								scanf("%d",&l1);
								inb(b,l1);
							break;
						default : (0);
					}
				break;
			case 2: display();
				break;
			case 3: exit(0);
				break;
			}
		}
}