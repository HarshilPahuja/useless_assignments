#include <stdio.h>

void Input(int a[10][10],int m,int n){
    int i,j;
    printf("Enter the elements of sparse Matrix:\n-----------------\n");
     for (i = 0; i < m; i++) {  
      for (j = 0; j < n; j++) {  
         scanf("%d", &a[i][j]);  
      }  
   }  
}
void Display(int a[10][10],int m,int n){
    int i,j;
    printf("SPARSE MATRIX:\n-----------------\n");
     for (i = 0; i < m; i++) {  
      for (j = 0; j < n; j++) {  
         printf("%d\t", a[i][j]);  
      }
         printf("\n");
   }  
}
void sparse_to_compact(int a[10][10],int b[10][3], int m,int n){
    int i,j,count=1;
    b[0][0]=m;
    b[0][1]=n;
    for(i=0;i<m;i++)
        {
            for (j=0;j<n;j++ )
                {
                    if (a[i][j]!=0)
                        {
                            b[count][0]=i;
                            b[count][1]=j;
                            b[count][2]=a[i][j];
                            count=count+1;
                        }

                }
            b[0][2]= count-1;
        }

}
void print_compact(int b[10][3],int n)
{
    int i;
    n = b[0][2];
    printf("\n-----------------\nCOMPACT FORM\n-----------------\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}
void transpose(int b[10][3],int c[10][3]){
    int i,j,count,t;
    c[0][0]=b[0][1];
    c[0][1]=b[0][0];
    c[0][2]=b[0][2];
    count=1;
    t=b[0][2];
    for(i=0;i<b[0][1];i++){
        for(j=0;j<=t;j++){
            if (i==b[j][1]) {
                c[count][0]=i;
                c[count][1]=b[j][0];
                c[count][2]=b[j][2];
                count=count+1;
             }
        }
    }
}
void print_transpose(int c[10][3],int n)
{
    int i;
    n = c[0][2];
    printf("\n-----------------\nTRANSPOSE MATRIX\n-----------------\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", c[i][0], c[i][1], c[i][2]);
    }
}
void fast(int b[50][3],int d[50][3]) //function definition for fast transposing the matrix
{ int i,m,n,pos[50]={0},count[50]={0};
for (i=1; i<b[0][2];i++) //calculate terms of 0,1,2,3..
{ m=b[i][1];
count[m]++;
}
pos[0]=1; //Default Position
for (i=1;i<b[0][1];i++) //calculate position
{ pos[i]=pos[i-1]+count[i-1];
}
for (i=1;i<=b[0][2];i++)
{ m=b[i][1];
n=pos[m];
pos[m]++;
d[n][0]=b[i][1];
d[n][1]=b[i][0];
d[n][2]=b[i][2];
}
d[0][0]=b[0][0];
d[0][1]=b[0][1];
d[0][2]=b[0][2];
} // end of fast ()

void print_fast(int d[10][3],int n)
{
    int i;
    n = d[0][2];
    printf("\n-----------------\n FAST TRANSPOSE MATRIX\n-----------------\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", d[i][0], d[i][1], d[i][2]);
    }
}

int main(){
    int a[10][10],b[10][3],c[10][3], d[10][3],m,n;
    printf("Enter no. of rows :\n");
    scanf("%d",&m);
    printf("Enter no. of columns :\n");
    scanf("%d",&n);

    Input( a, m, n);
    Display(a, m, n);
    sparse_to_compact(a, b, m, n);
    print_compact(b,n);
    transpose(b, c);
    print_transpose(c,n);
    fast (b,d);
    print_fast (d,n);


    return 0;

}