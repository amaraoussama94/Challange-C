 # include<stdio.h>
 # include<stdlib.h>
 # include<time.h>
 #define PSIZE 20
 #define RSIZE 15
 int main()
 {
     char*playlist[PSIZE]=
     {"Like a Rolling Stone","satisfaction","imagine","what's going on","respect","good vibrations","johnny n. goode","hey jude","what'd i say","smells like teen spirit","my generation",
     "yesterday","blowin in the wind","purple haze","londion calling","i want to hol your hand","maybellene","hound dog","let it be","a change is gonna come"
     };
     int frequency [PSIZE];
     int recent[RSIZE];
     int x,r,count,found;
     /*initialize*/
     srand((unsigned)time(NULL));
     for (x=0;x<PSIZE;x++)
     frequency[x]=0;
     for(x=0;x<RSIZE;x++)
     recent[x]=-1 ;/*because no element is -1*/
     /* run through the playlist randomly*/
     puts("Playlist");
     count=0;
     while(count<100)
     {
         /* does r appear in recent[]?*/
         found=1;/* assume it does */
         while(found)
         {
             r=rand()%PSIZE; /*random value*/
             found= 0;
             for(x=0; x<RSIZE;x++)
             {
                 if(r==recent[x])
                 found=1;
             }
         }
         recent[count%RSIZE]=r; /*play the song*/
         printf("%3d : Now playing %s\n",count+1,playlist[r]);
         frequency[r]++;
         count++;


     }
     printf("songs frequency  :\n");

     for(int n=0 ;n<PSIZE;n++)
    printf(" %s : %d \n" ,playlist[n], frequency[n]); 
    getch();
    return 0;

 }