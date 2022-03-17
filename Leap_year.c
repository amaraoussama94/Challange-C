#include<stdio.h>
int leapyear(int y )
{
    if (y%4 == 0)
    return (1);
    if (y%100 == 0)
    return 0;
    if(y%400 == 0)
    return (1);
    return (0);
}
int main()
{
  int y;
  for (y=1582;y<2102;y++)
  {
      if(leapyear(y))
      printf("%d \n",y);
  }
getch();
return 0;

}
