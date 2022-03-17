#include<stdio.h>
#include<stdlib.h>
#include<time.h>



struct matrix
{
int rows;
int cols;
char *cells;
};

void fill_matrix()
{

}
void fill_matrix()
{
    
}
int main ()
{
    struct matrix grid[3]={
        {8,3,NULL},
        {5,5,NULL},
        {4,6,NULL}
    } ;
    int x;
    /*initialize the randomizer*/
    srand((unsigned)time(NULL) ); 
    /*allocate storafe for the grids*/
    for(x=0;x<3;x++)   
    {
        grid[x].cells= (char*)malloc(sizeof(char)*grid[x].rows*grid[x].cols);
        if(grid[x].cells== NULL)
        {
            fprintf(stderr,"Memory allocatio error on the grid #%d\n",x);
            exit(1);
        }
    
    } 
    for(x=0;x<3;x++) 
    {
        fill_matrix(grid[x]);
        printf("original matrix %d: \n",x+1);
        output_matrix(grid[x]);
        rotate_matrixe(&grid[x]);
        printf("rotated matrix : %d :\n",x+1);
        output_matrix(grid[x]);
    } 
    return(0);
}