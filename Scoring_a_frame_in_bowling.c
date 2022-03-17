#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* structure must be declared external to be available in all functions*/
struct frame
{
    char b1,b2;
    int ball1 , ball2 , score;
};
/*generate a random value ,1 through pins*/
int ball_roll(int pins)
{
    return ( rand() % (pins+1) );
}
void fill_frame(struct frame *f)
{
    /*get the first ball*/
    f->ball1=ball_roll(10);/* all 10 pins*/
    /*check for a strike*/
   // printf("test %d", f->ball1);
    if (f->ball1 == 0)
    {
        f->b1=' ';/* the first ball character is blank*/
        f->b2='x';/* the second character is th strike */

        f->ball2=0;/*initialize this value anywaye*/
        f->score=10; /*plus the next two ball*/
    }
    else 
    {
        /* set the first ball s chacter . if zero, the
        '-' is set as the character */
        f->b1=f->ball1 ? f->ball1+'0':'-';
        /*roll th second ball*/
        f->ball2=ball_roll(10-f->ball1);
        /*check for a spoare*/
        if (f-> ball1+f->ball2 ==10)
        f->b2='/'; /*a spare*/
        else 
            f->b2= f->ball2 ? f->ball2+'0':'-';
        f->score = f->ball1+f->ball2;
    }

}
int main ()

{
    struct frame  game   ;
    /*seed randomizer*/
    srand((unsigned)time(NULL));
    fill_frame(&game);
    printf("|%c|%c |\n|  %d]",game.b1,game.b2,game.score );
    getch();
    return 0;
}