#include<stdio.h>
#include<time.h>


int main ()
{
    int monday;
    monday=(1-today->tm_wday);
    if(monday<1)
        monday+= 7+today->tm_mday;
    else 
        monday+= today->tm_mday;
    /*check to see if the nex monday is in the next month*/
    mflag =today->tm_mon;
    if (monday> monthw[today->tm_mon])
    {
        monday-= months[today->tm_mon]
        mflag++;
        mflag%=12

    }
    printf("the next monday will be th %d %s of %s\n",monday)

    


}