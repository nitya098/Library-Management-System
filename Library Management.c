//Library Management System

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure definition for book
struct library
{
    int id,type;
    char name[100],author[100];
    struct library *next,*prev;
};

//Bnode defining
typedef struct library bnode;

//Start node for new book entry
bnode *bstart=NULL;

//Member structure definition
struct member
{
    int id;
    char name[100];
    long long phone;
    int book;
    struct member *next,*prev;
};

//Mnode defining
typedef struct member mnode;

//Start node for new member entry
mnode *mstart=NULL;

//Structure definition for available books
struct available
{
    int id;
    char name[100];
    struct available *next,*prev;
};

//Anode defining
typedef struct available anode;

//Start node defining for book available list
anode *astart=NULL;

//Structure definition for issued books
struct issued
{
    int id,no;
    struct issued *next,*prev;
};

//Inode defining
typedef struct issued inode;

//Start node defining for book issued list
inode *istart=NULL;

//Structure definition for issued books database
struct save
{
    int bid,mid;
    char name[100];
    struct save *next,*prev;
};

//Snode defining
typedef struct save snode;

//Start node defining for book issued database
snode *sstart=NULL;

//Create function for new library book
bnode *create_book()
{
    bnode *new;
    new=(bnode *)malloc(sizeof(bnode));
    new->next=new->prev=NULL;
    return new;
}

//Function to create a member node
mnode *create_member()
{
    mnode *newn;
    newn=(mnode *)malloc(sizeof(mnode));
    newn->next=newn->prev=NULL;
    return newn;
}

//Function to create a available book node
anode *create_aval_book()
{
    anode *newn;
    newn=(anode *)malloc(sizeof(anode));
    newn->next=newn->prev=NULL;
    return newn;
}

//Function to create a issued book node
inode *create_issued_book()
{
    inode *newn;
    newn=(inode *)malloc(sizeof(inode));
    newn->next=newn->prev=NULL;
    return newn;
}

//Function to create a issued book record node
snode *create_issue_record()
{
    snode *newn;
    newn=(snode *)malloc(sizeof(snode));
    newn->next=newn->prev=NULL;
    return newn;
}

//Function to put book type variables
void put_var(int a,int b,int c,int d,int e)
{
    FILE *file=fopen("Book Type variables.txt","w");
    if(file==NULL)
        exit(1);
    fprintf(file,"%d %d %d %d %d",a,b,c,d,e);
    fclose(file);
}

//Function to put member variable
void put_mem_var(int m)
{
    FILE *file=fopen("Member variable.txt","w");
    if(file==NULL)
        exit(1);
    fprintf(file,"%d",m);
    fclose(file);
    return;
}

//Function to put book data into file Book Database
void put_book()
{
    bnode *cur;
    FILE *file=fopen("Book Database.txt","w");
    if(file==NULL)
        exit(1);
    cur=bstart;
    do
    {
        fprintf(file,"%d %d %s %s\n",cur->id,cur->type,cur->name,cur->author);
        cur=cur->next;
    }while(cur!=bstart);
    fclose(file);
}

//Function to get book data from file Book Database
void get_book()
{
    FILE *file=fopen("Book Database.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int id,type;
    char nam[100],aut[100],line[1000];
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(sscanf(line,"%d %d %s %s",&id,&type,nam,aut)==4)
        {
            bnode *cur=create_book();
            strcpy(cur->name,nam);
            strcpy(cur->author,aut);
            cur->id=id;
            cur->type=type;
            if(bstart==NULL)
            {
                bstart=cur;
                bstart->prev=bstart->next=bstart;
            }
            else
            {
                bnode *t=bstart;
                while(t->next!=bstart)
                    t=t->next;
                cur->prev=t;
                cur->next=bstart;
                t->next=cur;
            }
        }
    }
    fclose(file);
}

//Function to put member data into file Book Database
void put_member()
{
    mnode *cur;
    FILE *file=fopen("Member Database.txt","w");
    if(file==NULL)
        exit(1);
    cur=mstart;
    do
    {
        fprintf(file,"%d %s %lld %d\n",cur->id,cur->name,cur->phone,cur->book);
        cur=cur->next;
    }while(cur!=mstart);
    fclose(file);
}
//Function to get member data from file Book Database
void get_member()
{
    FILE *file=fopen("Member Database.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int i,b;
    char nam[100],line[1000];
    long long ph;
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(sscanf(line,"%d %s %lld %d",&i,nam,&ph,&b)==4)
        {
            mnode *cur=create_member();
            cur->id=i;
            strcpy(cur->name,nam);
            cur->phone=ph;
            cur->book=b;
            if(mstart==NULL)
            {
                mstart=cur;
                mstart->prev=mstart->next=mstart;
            }
            else
            {
                mnode *t=mstart;
                while(t->next!=mstart)
                    t=t->next;
                cur->prev=t;
                cur->next=mstart;
                t->next=cur;
            }
        }
    }
    fclose(file);
}
//Function to put available book data into file Book Database
void put_aval_book()
{
    anode *cur;
    FILE *file=fopen("Available Book Database.txt","w");
    if(file==NULL)
        exit(1);
    cur=astart;
    do
    {
        fprintf(file,"%d %s\n",cur->id,cur->name);
        cur=cur->next;
    }while(cur!=astart);
    fclose(file);
}
//Function to get available book data from file Book Database
void get_aval_book()
{
    FILE *file=fopen("Available Book Database.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int i;
    char nam[100],line[1000];
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(sscanf(line,"%d %s",&i,nam)==2)
        {
            anode *cur=create_aval_book();
            strcpy(cur->name,nam);
            cur->id=i;
            if(astart==NULL)
            {
                astart=cur;
                astart->prev=astart->next=astart;
            }
            else
            {
                anode *t=astart;
                while(t->next!=astart)
                    t=t->next;
                cur->prev=t;
                cur->next=astart;
                t->next=cur;
            }
        }
    }
    fclose(file);
}
//Function to put currently issued book data into file Book Database
void put_issued_book()
{
    inode *cur;
    FILE *file=fopen("Issued Book Database.txt","w");
    if(file==NULL)
        exit(1);
    cur=istart;
    do
    {
        fprintf(file,"%d %d\n",cur->id,cur->no);
        cur=cur->next;
    }while(cur!=istart);
    fclose(file);
}
//Function to get currently issued book data from file Book Database
void get_issued_book()
{
    FILE *file=fopen("Issued Book Database.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int i,num;
    char line[1000];
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(sscanf(line,"%d %d",&i,&num)==2)
        {
            inode *cur=create_issued_book();
            cur->id=i;
            cur->no=num;
            if(istart==NULL)
            {
                istart=cur;
                istart->prev=istart->next=istart;
            }
            else
            {
                inode *t=istart;
                while(t->next!=istart)
                    t=t->next;
                cur->prev=t;
                cur->next=istart;
                t->next=cur;
            }
        }
    }
    fclose(file);
}
//Function to put all issued book data into file Book Database
void put_issued_record()
{
    snode *cur;
    FILE *file=fopen("Issue History Database.txt","w");
    if(file==NULL)
        exit(1);
    cur=sstart;
    do
    {
        fprintf(file,"%d %d %s\n",cur->bid,cur->mid,cur->name);
        cur=cur->next;
    }while(cur!=sstart);
    fclose(file);
}
//Function to get all issued book data from file Book Database
void get_issue_record()
{
    FILE *file=fopen("Issue History Database.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int m,b;
    char nam[100],line[1000];
    long long ph;
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        if(sscanf(line,"%d %d %s",&b,&m,nam)==3)
        {
            snode *cur=create_issue_record();
            cur->bid=b;
            strcpy(cur->name,nam);
            cur->mid=m;
            if(sstart==NULL)
            {
                sstart=cur;
                sstart->prev=sstart->next=sstart;
            }
            else
            {
                snode *t=sstart;
                while(t->next!=sstart)
                    t=t->next;
                cur->prev=t;
                cur->next=sstart;
                t->next=cur;
            }
        }
    }
    fclose(file);
}

//Function to issue book number
int book_no(int n,int a,int b,int c,int d,int e)
{
    if(n==1)
    {
        a++;
        put_var(a,b,c,d,e);
        return((n*1000)+a);
    }
    if(n==2)
    {
        b++;
        put_var(a,b,c,d,e);
        return((n*1000)+b);
    }
    if(n==3)
    {
        c++;
        put_var(a,b,c,d,e);
        return((n*1000)+c);
    }
    if(n==4)
    {
        d++;
        put_var(a,b,c,d,e);
        return((n*1000)+d);
    }
    if(n==5)
    {
        e++;
        put_var(a,b,c,d,e);
        return((n*1000)+e);
    }

}

//Function to issue member ID
int mem_id(int m)
{
    m++;
    put_mem_var(m);
    return(1000+m);
}

//Function to add a new book to available list
void insert_available_book(int Id)
{
    anode *new1;
    new1=(anode*)malloc(sizeof(anode));
    new1->id=Id;
    bnode *tempb=bstart;
    do
    {
        if(tempb->id==new1->id)
        {
            strcpy(new1->name,tempb->name);
            break;
        }
        tempb=tempb->next;
    }while(tempb!=bstart);
    if(astart==NULL)
    {
        astart=new1;
        new1->next=astart;
        new1->prev=astart;
        //put_aval_book();
        return;
    }
    if(astart->next==astart)
    {
        if(astart->id>new1->id)
        {
            new1->next=new1->prev=astart;
            astart->prev=astart->next=new1;
            astart=astart->prev;
            //put_aval_book();
            return;
        }
        else
        {
            new1->next=astart;
            new1->prev=astart;
            astart->next=new1;
            astart->prev=new1;
            //put_aval_book();
            return;
        }
    }
    anode *temp=astart;
    do
    {
        if((temp->id)<(new1->id))
        {
            if(temp->next!=astart)
                temp=temp->next;
            else
            {
                new1->next=astart;
                new1->prev=temp;
                temp->next=new1;
                astart->prev=new1;
                //put_aval_book();
                return;
            }
        }
        else
        {
            if(temp==astart)
            {
                new1->next=astart;
                new1->prev=astart->prev;
                astart->prev->next=new1;
                astart->prev=new1;
                astart=astart->prev;
                //put_aval_book();
                return;
            }
            else
            {
                new1->prev=temp->prev;
                new1->next=temp;
                temp->prev->next=new1;
                temp->prev=new1;
                //put_aval_book();
                return;
            }
        }
    }
    while(temp!=astart);
    printf("Book %d added",Id);
}

//Function to remove a book from available list
void delete_available_book(int Id)
{
    int n=Id,f=0;
    anode *temp=astart;
    if(astart==NULL)
    {
        printf("No book available in library\n");
        return;
    }
    do
    {
        if(temp->id==n)
        {
            f++;
            break;
        }
        else
            temp=temp->next;
    }
    while(temp!=astart);
    temp=astart;
    if(f>0)
    {
        if(astart->id==n)
        {
            if(astart->next==astart)
            {
                astart=NULL;
                return;
            }
            astart->prev->next=astart->next;
            astart->next->prev=astart->prev;
            astart=astart->next;
            free(temp);
            return;
        }
        temp=astart->next;
        while(temp!=astart)
        {
            if(temp->id<n)
                temp=temp->next;
            else
                break;
        }

        anode *temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
    else
        printf("\nInvalid book number\n");

}

//Function to display all books available in library
void display_book_available()
{
    anode *temp=astart;
    if(astart==NULL)
    {
        printf("There are no books available in library\n");
        return;
    }
    printf("Book ID\t\tBook Name\n---------------------------\n");
    do
    {
        printf("%d\t\t%s\n",temp->id,temp->name);
        temp=temp->next;
    }while(temp!=astart);
    printf("\n");
}

//Function to add a new book to issued list
void insert_issued_book(int No,int Id)
{
    inode *new1;
    new1=(inode*)malloc(sizeof(inode));
    new1->no=No;
    new1->id=Id;
        if(istart==NULL)
    {
        istart=new1;
        new1->next=istart;
        new1->prev=istart;
        //put_issued_book();
        return;
    }
    if(istart->next==istart)
    {
        if(istart->id>new1->id)
        {
            new1->next=new1->prev=istart;
            istart->prev=istart->next=new1;
            istart=istart->prev;
            //put_issued_book();
            return;
        }
        else
        {
            new1->next=istart;
            new1->prev=istart;
            istart->next=new1;
            istart->prev=new1;
            //put_issued_book();
            return;
        }
    }
    inode *temp=istart;
    do
    {
        if((temp->id)<(new1->id))
        {
            if(temp->next!=istart)
                temp=temp->next;
            else
            {
                new1->next=istart;
                new1->prev=temp;
                temp->next=new1;
                istart->prev=new1;
                //put_issued_book();
                return;
            }
        }
        else
        {
            if(temp==istart)
            {
                new1->next=istart;
                new1->prev=istart->prev;
                istart->prev->next=new1;
                istart->prev=new1;
                istart=istart->prev;
                //put_issued_book();
                return;
            }
            else
            {
                new1->prev=temp->prev;
                new1->next=temp;
                temp->prev->next=new1;
                temp->prev=new1;
                //put_issued_book();
                return;
            }
        }
    }
    while(temp!=istart);
}

//Function to remove a book from issued list
void delete_issued_book(int Id)
{
    int n=Id,f=0;
    inode *temp=istart;
    if(istart==NULL)
    {
        printf("No book issued from library\n");
        return;
    }
    do
    {
        if(temp->id==n)
        {
            f++;
            break;
        }
        else
            temp=temp->next;
    }
    while(temp!=istart);
    temp=istart;
    if(f>0)
    {
        mnode *del=mstart;
        do
        {
            if(del->id==n)
            {
                del->book=0;
                break;
            }
            del=del->next;
        }while(del!=mstart);
        if(istart->id==n)
        {
            if(istart->next==istart)
            {
                istart=NULL;
                return;
            }
            istart->prev->next=istart->next;
            istart->next->prev=istart->prev;
            istart=istart->next;
            free(temp);
            return;
        }
        temp=istart->next;
        while(temp!=istart)
        {
            if(temp->id<n)
                temp=temp->next;
            else
                break;
        }
        inode *temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
    }
    else
        printf("\nInvalid book number\n");
}

//Function to display list of Issued books
void display_book_issued()
{
    printf("\n-------------------------------------------------ISSUED BOOK DISPLAY MENU-----------------------------------------------\n");
    inode *temp=istart;
    if(istart==NULL)
    {
        printf("There are no books issued from library\n");
        return;
    }
    printf("\nMember ID\t\tBook No\n------------------------------\n");
    do
    {
        printf("%d\t\t\t%d\n",temp->id,temp->no);
        temp=temp->next;
    }while(temp!=istart);
}

//Function to insert a new book
void insert_book(int a,int b,int c,int d,int e)
{
    printf("\n--------------------------------------------------NEW BOOK ENTRY MENU--------------------------------------------------\n");
    int n;
    bnode *new1=create_book(),*temp=bstart;
    printf("Enter book type:\n1.Educational\n2.Novels\n3.Short Stories\n4.Poems\n5.Non Fiction\n");
    printf("\nType number : ");
    scanf("%d",&new1->type);
    printf("\nEnter book name: ");
    scanf("%s",new1->name);
    printf("\nEnter author's name: ");
    scanf("%s",new1->author);
    n=new1->type;
    new1->id=book_no(n,a,b,c,d,e);
    printf("\nThe issued book number is %d\n",new1->id);
    if(bstart==NULL)
    {
        bstart=new1;
        new1->next=bstart;
        new1->prev=bstart;
        insert_available_book(new1->id);
        //put_book();
        return;
    }
    if(bstart->next==bstart)
    {
        if(bstart->id>new1->id)
        {
            new1->next=new1->prev=bstart;
            bstart->prev=bstart->next=new1;
            bstart=bstart->prev;
            insert_available_book(new1->id);
            //put_book();
            return;
        }
        else
        {
            new1->next=bstart;
            new1->prev=bstart;
            bstart->next=new1;
            bstart->prev=new1;
            insert_available_book(new1->id);
            //put_book();
            return;
        }
    }
    temp=bstart;
    do
    {
        if((temp->id)<(new1->id))
        {
            if(temp->next!=bstart)
                temp=temp->next;
            else
            {
                new1->next=bstart;
                new1->prev=temp;
                temp->next=new1;
                bstart->prev=new1;
                insert_available_book(new1->id);
                //put_book();
                return;
            }
        }
        else
        {
            if(temp==bstart)
            {
                new1->next=bstart;
                new1->prev=bstart->prev;
                bstart->prev->next=new1;
                bstart->prev=new1;
                bstart=bstart->prev;
                insert_available_book(new1->id);
                //put_book();
                return;
            }
            else
            {
                new1->prev=temp->prev;
                new1->next=temp;
                temp->prev->next=new1;
                temp->prev=new1;
                insert_available_book(new1->id);
                //put_book();
                return;
            }
        }
    }
    while(temp!=bstart);
}

//Function to insert a new member
void insert_member(int m)
{
    printf("\n-------------------------------------------------NEW MEMBER ENTRY MENU-------------------------------------------------\n");
    mnode *n=create_member();
    printf("Enter new member's name: ");
    scanf("%s",n->name);
    printf("Enter phone number: ");
    scanf("%lld",&n->phone);
    n->book=0;
    n->id=mem_id(m);
    printf("The issued member ID is: %d",n->id);
    if(mstart==NULL)
    {
        mstart=n;
        n->next=n->prev=mstart;
        //put_member();
        return;
    }
    mnode *temp=mstart;
    if(temp->next==mstart)
    {
        n->next=mstart;
        n->prev=temp;
        temp->next=n;
        mstart->prev=n;
        //put_member();
        return;
    }
    while(temp->next!=mstart)
        temp=temp->next;
    n->next=mstart;
    n->prev=temp;
    temp->next=n;
    mstart->prev=n;
    //put_member();
}

//Function to delete a book
void delete_book()
{
    printf("\n-------------------------------------------------BOOK DELETION MENU-------------------------------------------------\n");
    int n,f=0;
    bnode *temp=bstart;
    if(bstart==NULL)
    {
        printf("The database is empty\n");
        return;
    }
    printf("Book ID: ");
    scanf("%d",&n);
    do
    {
        if(temp->id==n)
        {
            f++;
            break;
        }
        else
            temp=temp->next;
    }
    while(temp!=bstart);
    temp=bstart;
    if(f>0)
    {
        if(bstart->id==n)
        {
            if(bstart->next==bstart)
            {
                printf("\nBook with ID %d deleted\n",n);
                delete_available_book(n);
                bstart=NULL;
                return;
            }
            bstart->prev->next=bstart->next;
            bstart->next->prev=bstart->prev;
            bstart=bstart->next;
            free(temp);
            printf("\nBook with ID %d deleted\n",n);
            delete_available_book(n);
            return;
        }
        temp=bstart->next;
        while(temp!=bstart)
        {
            if(temp->id<n)
                temp=temp->next;
            else
                break;
        }
        bnode *temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        temp=NULL;
        free(temp);
        printf("\nBook with ID %d deleted\n",n);
        delete_available_book(n);
        return;
    }
    else
        printf("\nInvalid book number\n");
}

//Function to delete a member
void delete_member()
{
    printf("\n-------------------------------------------------MEMBER DELETION MENU-------------------------------------------------\n");
    int n,f=0;
    mnode *temp=mstart;
    if(mstart==NULL)
    {
        printf("The database is empty\n");
        return;
    }
    printf("Member ID: ");
    scanf("%d",&n);
    do
    {
        if(temp->id==n)
        {
            f++;
            break;
        }
        else
            temp=temp->next;
    }
    while(temp!=mstart);
    temp=mstart->next;
    if(f>0)
    {
            if(mstart->id==n)
        {
            if(mstart->next==mstart)
            {
                printf("\nMember with ID %d deleted\n",n);
                mstart=NULL;
                return;
            }
            printf("\nMember with ID %d deleted\n",n);
            mstart->prev->next=mstart->next;
            mstart=mstart->next;
            mstart->prev=temp->prev;
            temp=NULL;
            free(temp);
            return;
        }
        while(temp!=mstart)
        {
            if(temp->id<n)
                temp=temp->next;
            else
                break;
        }
        mnode *temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        temp=NULL;
        free(temp);
        printf("\nMember with ID %d deleted\n",n);
    }
    else
        printf("\nInvalid Member ID\n");
}

//Function to display database
void display_all_books()
{
  printf("\n----------------------------------------------BOOK COLLECTION DISPLAY MENU----------------------------------------------\n");
    bnode *temp=bstart;
    if(bstart==NULL)
    {
        printf("The database is empty\n");
        return;
    }
    printf("\nBook ID\t\t\tName\t\t\t\tAuthor\t\t\t\tType\n----------------------------------------------------------------------------------------------------------\n");
    do
    {
        printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\n",temp->id,temp->name,temp->author,temp->type);
        temp=temp->next;
    }
    while(temp!=bstart);
}

//Function to display member details
void display_member_details()
{
    printf("\n-------------------------------------------------MEMBER DETAILS DISPLAY MENU-------------------------------------------------\n");
    mnode *temp=mstart;
    if(mstart==NULL)
    {
        printf("The database is empty\n");
        return;
    }
    printf("Member ID\t\tName\t\t\tPhone\t\tBooks Borrowed\n------------------------------------------------------------------------------\n");
    do
    {
        printf("%d\t\t%s\t\t%lld\t\t%d\n",temp->id,temp->name,temp->phone,temp->book);
        temp=temp->next;
    }
    while(temp!=mstart);
}

//Function to add data to book issue database
void insert_database(int m,int b)
{
    snode *newn;
    newn=(snode*)malloc(sizeof(snode));
    newn->next=newn->prev=NULL;
    newn->mid=m;
    newn->bid=b;
    bnode *tempc=bstart;
    do
    {
        if(tempc->id==b)
        {
            strcpy(newn->name,tempc->name);
            break;
        }
        tempc=tempc->next;
    }while(tempc!=bstart);
    if(sstart==NULL)
    {
        sstart=newn;
        newn->next=newn->prev=sstart;
        //put_issued_record();
        return;
    }
    snode *temp=sstart;
    if(temp->next==sstart)
    {
        if (temp->mid==m||temp->mid<m)
        {
            newn->next=temp;
            newn->prev=temp;
            temp->next=newn;
            temp->prev=newn;
            //put_issued_record();
            return;
        }
        else
        {
            newn->next=temp;
            newn->prev=temp;
            temp->next=newn;
            temp->prev=newn;
            sstart=newn;
            //put_issued_record();
            return;
        }
    }
    temp=sstart;
    do
    {
        if((temp->mid)<(newn->mid))
        {
            if(temp->next!=sstart)
                temp=temp->next;
            else
            {
                newn->next=sstart;
                newn->prev=temp;
                temp->next=newn;
                sstart->prev=newn;
                //put_issued_record();
                return;
            }
        }
        else if(temp->mid==newn->mid)
        {
            if(temp->next==sstart)
            {
                newn->next=sstart;
                newn->prev=sstart->prev;
                sstart->prev->next=newn;
                sstart->prev=newn;
                sstart=sstart->prev;
                //put_issued_record();
                return;
            }
            else if(temp->next->mid>newn->mid)
            {
                newn->next=temp->next;
                newn->prev=temp;
                temp->next->prev=newn;
                temp->next=newn;
                //put_issued_record();
                return;
            }
            else
                temp=temp->next;
        }
        else
        {
            if(temp==sstart)
            {
                newn->next=sstart;
                newn->prev=sstart->prev;
                sstart->prev->next=newn;
                sstart->prev=newn;
                sstart=sstart->prev;
                //put_issued_record();
                return;
            }
            else
            {
                newn->prev=temp->prev;
                newn->next=temp;
                temp->prev->next=newn;
                temp->prev=newn;
                //put_issued_record();
                return;
            }
        }
    }
    while(temp!=sstart);
    printf("\nDone!!\n");
}

//Function to display the issue database
void display_issue_database()
{
    snode *temp=sstart;
    if(sstart==NULL)
    {
        printf("\nIssue database is empty\n");
        return;
    }
    printf("Member ID\tBook ID\t\tBook title\n-----------------------------------------------------------------------------------------\n");
    do
    {
        printf("%d\t\t%d\t\t%s\n",temp->mid,temp->bid,temp->name);
        temp=temp->next;
    }while(temp!=sstart);
}

//Function to issue a book to a member
void issue_book()
{
    printf("\n----------------------------------------------------BOOK ISSUE MENU----------------------------------------------------\n");
    int n,m=0,f=0,b;
    printf("Books currently available in library:\n\n");
    display_book_available();
    printf("\nEnter the member ID of borrower: ");
    scanf("%d",&n);
    mnode *temp=mstart;
    if(mstart==NULL)
    {
        printf("\nMember not found\n");
        return;
    }
    do
    {
       if(temp->id==n)
       {
           m++;
           if(temp->book==0)
            {
                printf("\nEnter book ID of the book being borrowed: ");
                scanf("%d",&b);
                anode *find=astart;
                do
                {
                    if(find->id==b)
                    {
                        temp->book=b;
                        insert_issued_book(temp->book,temp->id);
                        delete_available_book(temp->book);
                        insert_database(temp->id,temp->book);
                        printf("\nBook issue recorded!\n");
                        f++;
                        return;
                    }
                    find=find->next;
                }while(find!=astart);
            }
            else
            {
                printf("\nThe member already has a book with ID %d.Book cannot be issued\n",temp->book);
                m++;
                return;
            }
       }
       temp=temp->next;
    }while(temp!=mstart);
    if(m==0)
    {
        printf("Member ID not found\n");
        return;
    }
    if(f==0)
        printf("\nBook is currently not available in library!\n");
}

//Function to return a book
void return_book()
{
    printf("\n---------------------------------------------------BOOK RETURN MENU---------------------------------------------------\n");
    int n,num=0;
    printf("\nList of member IDs which have borrowed books: ");
    inode *tempi=istart;
    do
    {
        printf("%d ",tempi->id);
        tempi=tempi->next;
        if(tempi!=istart)
            printf(", ");
    }while(tempi!=istart);
    printf("\n\nEnter the member ID under which the book was borrowed : ");
    scanf("%d",&n);
    inode *temp=istart;
    do
    {
        if(n==temp->id)
        {
           num=temp->no;
           break;
        }
        temp=temp->next;
    }while(temp!=istart);
    if(num>0)
    {
        printf("\nThe returned book number is : %d\n",num);
        delete_issued_book(n);
        insert_available_book(num);
    }
    else
        printf("\nIncorrect member ID!!The member has not borrowed any book\n");
}

//Function to Update Book details
void update_book()
{
    int n,p=0,ch;
    printf("\nEnter the book ID of the book to be updated: ");
    scanf("%d",&n);
    bnode *temp=bstart;
    do
    {
        if(temp->id==n)
        {
            p++;
            break;
        }
        temp=temp->next;
    }while(temp!=bstart);
    if(p>0)
    {
        anode *update=astart;
        bnode *dum=bstart;
        do
        {
            if(dum->id==n)
            {
                printf("Book Name: %s\nBook Author: %s\n",dum->name,dum->author);
                printf("\n1.Update Book Name\n2.Update Book Author\n3.Cancel\n\nChoice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:printf("Enter new Book Name: ");
                            scanf("%s",dum->name);
                            do
                            {
                                if(update->id==n)
                                {
                                    strcpy(update->name,dum->name);
                                    break;
                                }
                                update=update->next;
                            }while(update!=astart);
                            printf("\n\nDetails updated\n");
                            break;
                    case 2:printf("Enter new Author Name: ");
                            scanf("%s",dum->author);
                            printf("\n\nDetails updated\n");
                            break;
                    case 3:break;
                }
            }
            dum=dum->next;
        }while(dum!=bstart);
    }
    else
        printf("Book ID not found!");
}

//Function to Update Member details
void update_member()
{
     int n,p=0,ch;
    printf("\nEnter the member ID to be updated: ");
    scanf("%d",&n);
    mnode *temp=mstart;
    do
    {
        if(temp->id==n)
        {
            p++;
            break;
        }
        temp=temp->next;
    }while(temp!=mstart);
    if(p>0)
    {
        mnode *dum=mstart;
        do
        {
            if(dum->id==n)
            {
                printf("\nMember Name: %s\nPhone Number: %ld\n",dum->name,dum->phone);
                printf("\n1.Update Member Name\n2.Update Phone Number\n3.Cancel\n\nChoice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:printf("Enter new Name: ");
                            scanf("%s",dum->name);
                            printf("\n\nDetails updated\n");
                            break;
                    case 2:printf("Enter new Phone Number: ");
                            scanf("%ld",dum->phone);
                            printf("\n\nDetails updated\n");
                            break;
                    case 3:break;
                }
            }
            dum=dum->next;
        }while(dum!=mstart);
    }
    else
        printf("Member ID not found!");
}

//Function to get book type variables
void get_var()
{
    FILE *file=fopen("Book Type variables.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int a,b,c,d,e;
    fscanf(file,"%d %d %d %d %d",&a,&b,&c,&d,&e);
    insert_book(a,b,c,d,e);
    fclose(file);
}

//Function to get member variable
void get_mem_var()
{
     FILE *file=fopen("Member variable.txt","r");
    if(file==NULL)
    {
        printf("File fetch failed");
        exit(0);
    }
    int m;
    fscanf(file,"%d",&m);
    insert_member(m);
    fclose(file);
}

//Function to search for a book
void search_book()
{
    printf("\n----------------------------------------------------BOOK SEARCH MENU----------------------------------------------------\n");
    if(bstart==NULL)
    {
        printf("\nDatabase empty!\n");
        return;
    }
    char bn[100];
    printf("\nEnter book name : ");
    scanf("%s",bn);
    bnode *temp=bstart;
    int b=0;
    do
    {
        if(!strcmp(temp->name,bn))
        {
            printf("\nThe book ID is %d\n",temp->id);
            b++;
            anode *find=astart;
            int f=0;
            do
            {
                if(temp->id==find->id)
                {
                    printf("\nBook is currently available in the library!\n");
                    f++;
                    break;
                }
                find=find->next;
            }while(find!=astart);
            if(f==0)
                printf("\nBook currently not available in the library\n");
            break;
        }
        temp=temp->next;
    }while(temp!=bstart);
    if(b==0)
        printf("\nBook not found!\n");
}

//Function to search for a member
void search_member()
{
    printf("\n--------------------------------------------------MEMBER SEARCH MENU----------------------------------------------------\n");
    if(mstart==NULL)
    {
        printf("\nDatabase is empty!\n");
        return;
    }
    char mn[100];
    printf("Enter member name: ");
    scanf("%s",mn);
    mnode *temp=mstart;
    int m=0;
    do
    {
        if(!strcmp(temp->name,mn))
        {
            printf("\nThe member ID is %d\n",temp->id);
            m++;
            break;
        }
        temp=temp->next;
    }while(temp!=mstart);
    if(m==0)
        printf("\nMember not found!\n");
}

//Main function
void main()
{
      get_book();
      get_member();
      get_aval_book();
      get_issued_book();
      get_issue_record();
    printf("\n------------------------------------------WELCOME TO LIBRARY MANAGEMENT SYSTEM------------------------------------------");
    int mch,ch1,ch2,ch3,ch4,ch5,ch;
    for(;;)
    {
        printf("\n------------------------------------------------------------------------------------------------------------------------\n1.Open Main Menu\n2.Exit\n\nChoice: ");
        scanf("%d",&ch);
        system("cls");
        switch(ch)
        {
            case 1: printf("\n-------------------------------------------------------MAIN MENU-------------------------------------------------------\n");
                    printf("1.New Entry menu\n2.Delete menu\n3.Display menu\n4.Update Menu\n5.Search Menu\n6.Exit\n");
                    printf("\nChoice: ");
                    scanf("%d",&mch);
                    system("cls");
                    switch(mch)
                    {
                        case 1:printf("\n-------------------------------------------------------ENTRY MENU-------------------------------------------------------\n1.New book\n2.New member\n3.Book issue\n4.Book return\n5.Back\n\nChoice: ");
                                scanf("%d",&ch1);
                                system("cls");
                                switch(ch1)
                                {
                                    case 1:get_var();break;
                                    case 2:get_mem_var();break;
                                    case 3:issue_book();break;
                                    case 4:return_book();break;
                                    case 5:break;
                                    default:("Invalid choice\n");break;
                                }
                                break;
                        case 2:printf("\n-----------------------------------------------------DELETION MENU-----------------------------------------------------\n1.Delete book\n2.Delete member\n3.Back\n\nChoice: ");
                                scanf("%d",&ch2);
                                system("cls");
                                switch(ch2)
                                {
                                    case 1:delete_book();break;
                                    case 2:delete_member();break;
                                    case 3:break;
                                    default:("Invalid choice\n");break;
                                }
                                break;
                        case 3:printf("\n------------------------------------------------------DISPLAY MENU------------------------------------------------------\n1.List of book collection\n2.List of books currently avalilable\n3.List of issued books\n4.List of members\n5.Issue Database\n6.Back\n\nChoice: ");
                                scanf("%d",&ch3);
                                system("cls");
                                switch(ch3)
                                {
                                    case 1:display_all_books();break;
                                    case 2:printf("\n----------------------------------------------BOOK AVAILABLE DISPLAY MENU----------------------------------------------\n");display_book_available();break;
                                    case 3:display_book_issued();break;
                                    case 4:display_member_details();break;
                                    case 5:display_issue_database();break;
                                    case 6:break;
                                    default:("Invalid choice\n");break;
                                }
                                break;
                        case 4:printf("\n-----------------------------------------------------UPDATE MENU-----------------------------------------------------\n1.Update Book Details\n2.Update Member Details\n3.Back\n\nChoice: ");
                                scanf("%d",&ch4);
                                system("cls");
                                switch(ch4)
                                {
                                    case 1:update_book();break;
                                    case 2:update_member();break;
                                    case 3:break;
                                    default:("Invalid choice\n");break;
                                }
                                break;
                        case 5:printf("\n-----------------------------------------------------SEARCH MENU-----------------------------------------------------\n1.Book Search\n2.Member Search\n3.Back\n\nChoice: ");
                                scanf("%d",&ch5);
                                system("cls");
                                switch(ch5)
                                {
                                    case 1:search_book();break;
                                    case 2:search_member();break;
                                    case 3:break;
                                    default:("Invalid choice\n");break;
                                }
                                break;
                        case 6:put_book();put_aval_book();put_member();put_issued_book();put_issued_record();exit(0);
                        default:printf("Invalid choice!!Try again\n");break;
                    }
                    break;
                case 2:put_book();put_aval_book();put_member();put_issued_book();put_issued_record();exit(0);
                default:printf("\nInvalid choice!Try again\n");break;
            }

    }
}
