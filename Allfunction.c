#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void add(ST **node) {
	char ch;
   do{	
    ST *newnode = (ST *)malloc(sizeof(ST));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
   if(*node==NULL){
	   newnode->roll=101;
   }
   else
   {
	   ST* temp=(*node);
	   while(temp->next!=NULL)
	   {
		   temp=temp->next;
	   }
	   newnode->roll=temp->roll+1;
   }

    printf("Enter Roll:%d\n",newnode->roll);
    printf("Enter Name: ");
    scanf("%s", newnode->name);
    printf("Enter Mark: ");
    scanf("%f", &newnode->mark);
    newnode->next = NULL;

    if (*node == NULL) {
        (*node) = newnode;
    } else {
        ST *temp = (*node);
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Student record added successfully!\n");
   printf("Do You Want To Another record(Y/N):");
   scanf(" %c",&ch);
  }while(ch=='Y'||ch=='y');
}

// 2(Display function)
void display(ST *node) {
    if (node== NULL) {
        printf("No student records found!\n");
        return;
    }
    
    ST *temp = node;
    printf("\n--- Student Records ---\n");

        printf("%-6s | %-15s | %s","Roll","Name","Mark\n");
	printf("-----------------------------------------------\n");
    while (temp != NULL) {

        printf("%-6d | %-15s | %.2f\t\t\n", temp->roll, temp->name, temp->mark);
        temp = temp->next;
    }
}

//3(Modify function)
void modify(ST **node) {
    if (*node == NULL) {
        printf("No records to modify!\n");
        return;
    }
    
    int r,choice,n=0;
    float Mark;
    char ch[50],c;
    printf("[1]Roll Number\n[2]Name\n[3]mark\nEnter your choice:");
    scanf("%d",&choice);

    ST *temp = *node;
label:
    switch(choice)
    {
    case 1:printf("Enter the Roll Number:");
		       scanf("%d",&r);
		       temp=(*node);
		       while(temp!=NULL)
		       {
			       if(temp->roll==r)
			       {
				       printf("-----------------------------------------\n");
				       printf("%d\t\t%s\t\t%.2f\n",temp->roll,temp->name,temp->mark);
				       printf("-----------------------------------------\n");
				       printf("Confrom if you modify the record:y/n\n");
				       scanf(" %c",&c);
				       if(('Y'==c)||('y'==c))
				       { 
				       printf("Enter the Name:");
				       scanf(" %[^\n]",temp->name);
				       printf("Enter the Mark:");
				       scanf("%f",&temp->mark);
				       printf("succesfully modified....\n");}
				       return;
			       }
			       temp=temp->next;
		       }
		       printf("No Record found....\n");
		       break;
		case 2:printf("Enter the Name:");
		       scanf(" %[^\n]",ch);
		       temp=(*node);
		       while(temp!=NULL)
		       {
			       if(strcmp(temp->name,ch)==0)
			       {
				       printf("-----------------------------------------\n");
				       printf("%d\t\t%s\t\t%.2f\n",temp->roll,temp->name,temp->mark);
				       printf("-----------------------------------------\n");
				       n++;
			       }
			       temp=temp->next;
		       }
		       if(n==0){
		       printf("No Record found.....\n");
		       return;}
		       else if(n==1)
		       {
			       temp=(*node);
			       while(temp!=NULL)
			       {
				       if(strcmp(temp->name,ch)==0)
				       {
					       printf("Confrom if you modify the record(y/n):");
				       	       scanf(" %c",&c);
				               if(('Y'==c)||('y'==c))
					       {
					       printf("ENTER NAME:");
					       scanf(" %[^\n]",temp->name);
					       printf("ENTER MARK:");
					       scanf("%f",&temp->mark);
					       printf("SUCCESSFULLY MODIFIED\n");}
					       return;
				       }
				       temp=temp->next;
			       }
		       }
		       else{
			       choice=1;
			       goto label;
		       }
		       break;
		case 3:printf("Enter the Mark:");
		       scanf("%f",&Mark);
		       temp=(*node);
		       while(temp!=NULL)
		       {
			       if(temp->mark==Mark)
			       {
				       printf("-----------------------------------------\n");
				       printf("%d\t\t%s\t\t%.2f\n",temp->roll,temp->name,temp->mark);
				       printf("-----------------------------------------\n");
				       n++;
			       }
			       temp=temp->next;
		       }
		       if(n==0){
		       printf("No Record found.....\n");
		       return;}
		       else if(n==1)
		       {
			       temp=(*node);
			       while(temp!=NULL)
			       {
				       if(temp->mark==Mark)
				       {
					       printf("Confrom if you modify the record:y/n\n");
				       	       scanf(" %c",&c);
				               if(('Y'==c)||('y'==c))
					       {
					       printf("ENTER NAME:");
					       scanf(" %[^\n]",temp->name);
					       printf("ENTER MARK:");
					       scanf("%f",&temp->mark);
					       printf("SUCCESSFULLY MODIFIED\n");}
					       return;
				       }
				       temp=temp->next;
			       }
		       }
		       else{
			       choice=1;
			       goto label;
		       }

	}

}

// 4(Delete function)
void delete(ST **node) {
    if (*node == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    
    int r,n=0;
    char ch[20],c;
    int choice;
	printf("[1]Delete using Roll Number\n[2]Delete using Name\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	ST*temp=(*node);
	ST*prev=NULL;
label:
        switch(choice)
	{
	case 1:printf("Enter Roll No:");
	       scanf("%d",&r);
	       temp=(*node);
	       while(temp!=NULL)
	       {
	        if(r==temp->roll)
		{
                    
		    printf("Roll:%d\tName:%s\tMark:%.2f\n",temp->roll,temp->name,temp->mark);
		    printf("Conform if you want to delete y/n:");
		    scanf(" %c",&c);
	            if(('Y'==c)||('y'==c))
		    {
	              if(temp==(*node))
		      {
  		       (*node)=temp->next;
		      }
     	              else
		      {
		       prev->next=temp->next;
		      }
	              free(temp);
                      printf("successfully deleted....\n");
		    }
		   return;
	         }
	        else
		{
	        prev=temp;
		temp=temp->next;
	        }
            }
	    printf("No Record found.....\n");
	    break;
		       
      case 2:printf("Enter The Name:");
	     scanf(" %[^\n]",ch);
             while(temp!=NULL)
	       {
		if(strcmp(ch,temp->name)==0)
           	   {
		       printf("Roll:%d\tName:%s\tMark:%.2f\n",temp->roll,temp->name,temp->mark);
			 n++;
	           }
	        temp=temp->next;
	       }
	       if(n>0)
	       {
		 choice=1;
          	 goto label;
	       }
	       else
	       {
		 printf("No Record Found.......\n");
		 break;
	       }
	}
}

// 5.(Sort by Roll Number)
void sort(ST**node,ST*p){
    if (*node == NULL || (*node)->next == NULL) 
    {
        printf("Not enough records to sort!\n");
        return;
    }
    
    int swapped,choice;
    int mark,r,n=0;
    char Name[20],c;
    ST *ptr1=(*node);
    ST *temp1,*prev;

        printf("[1]Sort by Name\n[2]Sort by Mark\n");
	printf("Enter your choice:");
	scanf("%d",&choice);

            while(ptr1!=NULL)
	    {
		n++;
		ptr1=ptr1->next;
	    }
	switch(choice)
	{
	   case 1:while(n!=0)
		   {
		       temp1=(*node);
		       prev=(*node)->next;
		       while(prev!=NULL)
		       {
	                  if(strcmp(temp1->name,prev->name)>0)
		          {
			       mark=temp1->mark;
			       temp1->mark=prev->mark;
			       prev->mark=mark;
			       r=temp1->roll;
			       temp1->roll=prev->roll;
			       prev->roll=r;

		               strcpy(Name,temp1->name);
			       strcpy(temp1->name,prev->name);
			       strcpy(prev->name,Name);
			  }
			  temp1=temp1->next;
			  prev=prev->next;
		       }
		       n--;
		   }
		  printf("sort done\n");
		  display(p);
		  printf("if you want to save in file :y/n\n");
		  scanf(" %c",&c);
		  if(('y'==c)||('Y'==c))
		      save(p);
		  return;
	   case 2:while(n!=0)
		  {
			  temp1=(*node);
			  prev=(*node)->next;
			  while(prev!=NULL)
			  {
				  if((temp1->mark)>(prev->mark))
				  {
					  mark=temp1->mark;
					  temp1->mark=prev->mark;
					  prev->mark=mark;

					  r=temp1->roll;
					  temp1->roll=prev->roll;
					  prev->roll=r;

				          strcpy(Name,temp1->name);
				          strcpy(temp1->name,prev->name);
			   		  strcpy(prev->name,Name);
		   		  }
				  temp1=temp1->next;
				  prev=prev->next;
			  }
			  n--;
		  }
		  printf("sort done\n");
		  display(p);
		  printf("if you want to save in file :y/n\n");
		  scanf(" %c",&c);
		  if(('y'==c)||('Y'==c))
			  save(p);
		  return;
	}
}

// 6.(Save to File)
void save(ST *node) {
    if(node==NULL)
    {
	    fprintf(stderr,"No Record....\n");
		return;
    }

    FILE*fs=fopen("student","w");
    fprintf(fs,"--------------------------------------------------\n");
    fprintf(fs,"%-10s %-20s %-5s","Roll","Name","Mark\n");
    fprintf(fs,"--------------------------------------------------\n");

    while(node!=NULL)
	{
		fprintf(fs,"%-10d %-20s %-5.2f\n",node->roll,node->name,node->mark);
		node=node->next;
	}
	fclose(fs);
	printf("successfully saved...\n");
}

//7.(Exit Function)
void ex(ST*p)
{
	int choice;
	printf("[1]Save and Exit\n[2]Exit Without Saving\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:save(p);return;
		case 2:return;
	}
}
