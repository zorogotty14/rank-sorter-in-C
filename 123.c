#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct tnode
{
  int rank;
  int rn;
  struct tnode *left;
  struct tnode *right;
};
void inorder(struct tnode*);
void rinsert(struct tnode **, int ,int);

int main()
{
    int b;
    struct tnode *root;
    char num[20];
    FILE *f1;
    f1=fopen("pro1.txt","r+");
    
   while(!feof(f1))
   {   fgets(num,50,f1);
    
        char *rn = strtok(num," ");
        char *rank  = strtok(NULL," ");
        
        
        int a = atoi(rn);
        int b = atoi(rank);
      // printf("%d %d",a,b);
       rinsert(&root,a,b);
   }

    fclose(f1);
    printf("Enter Your RollNo");
    scanf("&d",b);
    
    inorder(root);
}  


   void  rinsert(struct tnode **t, int x,int y)
   {
      struct tnode *temp,*curr,*prev;
     
       temp=(struct tnode*)malloc(sizeof(struct tnode));
       temp->rn=x;
       temp->rank=y;
       temp->left=temp->right=NULL;
       
     if(*t==NULL)
          *t=temp;
     
     else{
         curr=*t;
         prev=NULL;
         while(curr!=NULL)
         {
           prev=curr;
             if(x<curr->rn)
                 curr=curr->left;
             else
                 curr=curr->right;
         }
         if(x<prev->rn)
             prev->left=temp;
         else
             prev->right=temp;
     }
   }


  
   void inorder(struct tnode *t)
   {
    if(t!=NULL)
      {
         inorder(t->left);
         printf("Rank%d  ",t->rank);
         printf("Roll no%d\n",t->rn);
         inorder(t->right);
      }
    }


