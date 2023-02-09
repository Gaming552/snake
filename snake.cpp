#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

int main()
{
    int gd=DETECT, gm, i, j, x=30, y=30, flag=0, score=0, foodx, foody;
    char ch;
    initgraph(&gd, &gm, "");
    randomize();
    foodx=random(620)+20;
    foody=random(460)+20;
    do
    {
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, GREEN);
        bar(foodx, foody, foodx+10, foody+10);
        if(kbhit())
        {
            ch=getch();
            switch(ch)
            {
                case UP:
                {
                    flag=1;
                    break;
                }
                case DOWN:
                {
                    flag=2;
                    break;
                }
                case LEFT:
                {
                    flag=3;
                    break;
                }
                case RIGHT:
                {
                    flag=4;
                    break;
                }
                case ESC:
                {
                    return 0;
                }
            }
        }
        switch(flag)
        {
            case 1:
            {
                y-=10;
                break;
            }
            case 2:
            {
                y+=10;
                break;
            }
            case 3:
            {
                x-=10;
                break;
            }
            case 4:
            {
                x+=10;
                break;
            }
        }
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, RED);
        bar(x, y, x+10, y+10);
        if((x>=foodx&&x<=foodx+10)&&(y>=foody&&y<=foody+10))
        {
            score+=10;
            foodx=random(620)+20;
            foody=random(460)+20;
        }
        if(x>640||x<0||y>480||y<0)
        {
            break;
        }
        setcolor(WHITE);
        settextstyle(3, 0, 5);
        sprintf(ch, "Score: %d", score);
        outtextxy(10, 10, ch);
        delay(100);
        cleardevice();
    }
    while(1);
    getch();
    closegraph();
    return 0;
}
