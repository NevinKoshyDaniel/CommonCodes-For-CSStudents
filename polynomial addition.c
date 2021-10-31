struct node{
    int power;
    int value;
    struct node* next;
};
int i;
typedef struct node linkedlist;
/* Declare PTR 1 to Ptr 4 ,as well as head 1-4*/;
createnode()
{
    linkedlist *node=malloc(sizeof(node));
    return node;
}
addnode(*head)
{
    if (head==NULL)
    {
        node=createnode();
        node->power=powers;
        node->value=values;
        node->link=NULL;
        head=node;
    }
    else
     {  
         ptr=head;
         prev=ptr;
         while (ptr!=NULL)
         {
             if(ptr->power >powers)
             {
                prev=ptr;
                ptr=ptr->link;
             }
             else if(ptr->power == powers)
             {
                 ptr->value+=values;
                 break;
             }
            else
            {
                node=createnode();
                node->power=powers;
                node->value=values;
                prev->link=node;
                node->link=ptr
             }
       }
    }
}

sumofnodes()
{   
    ptr1=head1;
    ptr2=head2;

    while(ptr1!=NULL && ptr2!=NULL)
    {
    if (ptr1->power < ptr2->power)
    {
        while(ptr2 != NULL)
        {
            ptr2=ptr2->link;
        }
            if (ptr2 == NULL)
               { node= createnode()
                 node->power=ptr2->power;
                 node->value=ptr2->value;
                 node->link=ptr3;
               } 
        }
    }
    else if (ptr1->power > ptr2->power)
    {
        node=createnode()
        node->power=ptr1->power;
        node->value=ptr1->value+ptr2->value;
        node->link=ptr3;
        ptr3=node;
    }
    else
    {
        node=createnode()
        node->power=ptr1->power;
        node->value=ptr1->value+ptr2->value;
        node->link=ptr3;
        ptr3=node;
    }
    }
}

productofnodes()
{   
    int power,value;
     while(ptr1!=NULL)
     {  
         while(ptr2!=NULL)
        {
            power= ptr1->power * ptr2->power;
            if (ptr4 == NULL)
               { 
                 node= createnode()
                 node->power=power;
                 node->value=ptr1->value*ptr2->value;
                 node->link= NULL;
               }
           
            while(ptr4 != NULL)
            {  
                 prev=ptr4;
                if(ptr4->power == power )
                   { 
                    ptr4->value=ptr1->value*ptr2->value;
                    break;
                   }
                else if(ptr4->power > power)
                    {
                        prev=ptr4;
                        ptr4=ptr4->link;
                        }
                else
                {
                        node= createnode()
                        node->power=power;
                        node->value=ptr1->value*ptr2->value;
                        node->link= prev->link;
                        prev->link= node;
                        break;
                    } 
            }
             
        }
    }
}

void display(h1)
{
    printf("The node goes like this \n \n");
    ptr=h1;
    while(ptr!=NULL)
    {
        printf("%d | %d | %d  \t", ptr->power ,ptr->value ,ptr->link );
        ptr=ptr->link;
    }
    printf("\n");
}

void main()
{
int choice,c1,c2,powers,values;
do
{
printf("\n \t \t Menu");
printf("\n 1. Create / Add to node 1");
printf("\n 2. Create / Add to node 2");
printf("\n 3. Sum up the nodes");
printf("\n 4. Display the nodes  ");
printf("\n 5. Exit");
printf("\n Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
    case 1:
        printf("\n Enter the first element's power and value :");
        scanf("%d %d",&powers, &value);
        addnode(&head1,powers,values);
        break;
    
    case 2:
        printf("\n Enter the second element's power and value :");
        scanf("%d %d",&powers, &value);
        addnode(&head2,powers,values);
        break;
    
    case 3:
        sumofnodes(&head1,&head2);
        break;

    case 4:
    {       printf("\n \t \t Menu");
        printf("\n 1. Show Node 1");
        printf("\n 2. Show node 2");
        printf("\n 3. Show the Summed up nodes");
        printf("\n Enter your choice:");
        scanf("%d",&c1);

        switch(c1)
        {
            case 1:
            display(head1);
            break;
            case 2:
            display(head2);
            break;
            case 3:
            display(head3);
            break;
            default:
            printf("Invalid Choice, please enter a valid one");
        }
        break;
    }
    case 5:
        return;
    
    default:
        printf("Invalid Choice, please enter a valid one");

}
printf("\n Do you want to continue (1/0):")
scanf("%d",&c2);
}while(c2!=0);
}