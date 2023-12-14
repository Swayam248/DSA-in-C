#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

static struct node* head=NULL;
struct node* tail = NULL;

void display(){
	struct node *temp = head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void add(int dt){
	struct node* newNode= (struct node*)malloc(sizeof(struct node));
	newNode->data=dt;
	newNode->next=NULL;
	
	if(head==NULL){
		head=newNode;
		tail=newNode;
	}
	else{
		tail->next=newNode;
		tail=newNode;
	}
}

void add_part_pos(int dt,int aftrdt){
	struct node *newNode= (struct node*)malloc(sizeof(struct node));
	newNode->data=aftrdt;
	newNode->next=NULL;
	struct node *temp = head;
	if(temp->data==dt){
		newNode->next=temp->next;
		temp->next=newNode;
		
	}
	else{
		while(temp->next->data!=dt){
			temp=temp->next;
		}
		newNode->next=temp->next->next;
		temp->next->next=newNode;
	}
}

void del_part_pos(int pos){
	struct node *temp = head;
	for(int i = 1;i<pos-1;i++){
		temp=temp->next;
	}
	temp->next=temp->next->next;
}


void del_end(){
	struct node *temp = head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	temp->next=NULL;
}

void ins_end(int dt){
	struct node *temp = head;
	struct node *newNode= (struct node*)malloc(sizeof(struct node));
	newNode->data=dt;
	newNode->next=NULL;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
}

void search(struct node *head,int dat){
	if(head->data==dat){
		printf("%d \n", head->data);
	}
	else{
		search(head->next,dat);
	}
}

void rev(struct node *head){
	struct node *temp = head;
	while(temp->next!=NULL){
		temp->next->prev=temp;
		temp=temp->next;
	}
	while(temp->data!=head->data){
		printf("%d ", temp->data);
		temp=temp->prev;
	}
	printf("%d ", temp->data);
	printf("\n");
}

void rem_dup(struct node *head){
	struct node *temp = head;
	struct node *chk=temp;
	static int c;
	while(temp->next!=NULL){
		c++;              //Size of LL
		temp=temp->next;
	}
	while(temp->next!=NULL){
		for(int i=0;i<c;i++){
			if(temp->data==chk->next->data){
				chk->next=chk->next->next;
			}
			chk=chk->next;
		}
		temp=temp->next;
	}
	while(chk->next!=NULL){
		printf("%d ", chk->data);
		chk=chk->next;
	}
	printf("\n");
	
}
int main(){
	add(3);
	add(5);
	add(6);
	add(2);
	add(5);
	display();
	//add_part_pos(3,7);
	//display();
	//del_part_pos(3);
	//display();
	//del_end();
	//display();
	//ins_end(100);
	//display();
	//search(head,100);
	rem_dup(head);
	//rev(head);
	
	return 0;
}
