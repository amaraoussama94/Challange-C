#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int GSIZE = 8;
struct loc
{
     int   col  ,row;
};
/*output the game grid*/
void output (int t, struct loc k)
{
int row ,col;
if (t == 0)
puts("Start:");
else   printf("Turn %d:\n",t);
/*grid*/

for(row = 0; row<GSIZE;row++)
{
    for(col = 0; col<GSIZE;col++)
    {  // printf("%d",col);
        if ((row == k.row )&& (col == k.col))
            printf("k");
        else
            printf(".");
        
    }   
    putchar('\n');
    //printf("%d",row);
}
}


int move(void)
{int r;
r=(rand()% 3)-1;
return(r);
}
int escaped(struct loc k)
{   
    enum{FALSE=0,TRUE};

    printf("this is test in escape func %d   %d\n",k.col ,k.row);
    if(k.row<0)
    {
    printf("Test1 is detected \n");
    return(TRUE);
    }
    
    if (k.row >=GSIZE)
    {
    printf("Test2\n");
    return(TRUE);
    }
    if(k.col<0)
    {
    printf("Test3 \n");
    return (TRUE);
    }
    if (k.col >=GSIZE)
    {
    printf("Test4 \n");
    return(TRUE);
    }
    printf("Test G\n");
    return(FALSE);

}
int main()
{
    int turn = 0;
    struct loc king={3,4};/*fourth row, fifth colum*/
    printf("1st location %d   %d",king.col ,king.row);
    /*seed randomizer*/
    srand((unsigned)time(NULL));
    /* the loop terminates when the king wanders out*/
    output(turn,king);
    while(1)
    { 
    turn ++;
    /*move the king*/
    king.row+=move();
    printf("%d\n",king.row);
    king.col+=move();
    printf("%d\n",king.col);
    output(turn,king);
    int b = escaped(king);
    printf("this is test main  %d   %d \n",king.col ,king.row);
    printf(" escaped :%d",b);
    if (b==1)
    {   
        printf ("the king wandered off the grid after %d turn",turn);
        break;
    }
     
     
    }
getch();
return(0);
}