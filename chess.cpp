int j = 0, a = 100, b = 400, cnt = 0, utemp1 = 0, utemp2 = 0;
int posarr[2] = {0, 0}, x, y, z = 1, cl;
#include &lt; string.h & gt;
#include &lt; stdlib.h & gt;
#include &lt; iostream.h & gt;
#include &lt; graphics.h & gt;
#include &lt; stdio.h & gt;
#include &lt; conio.h & gt;
#include &lt; dos.h & gt;
#include &lt; process.h & gt;
#include &lt; time.h & gt;
#include &lt; math.h & gt;
union REGS in, out;
void changepos(void);

void undo();
/////////////////////////////////////////////////////////
/////////////////
void intro()
{
    int i, j;

    for (i = 0; i & lt; 2; i++)
    { //Function to display the intro
        screen for (j = 1; j & lt; 15; j++)
        {
            setcolor(j);
            settextstyle(1, HORIZ_DIR, 10);
            if (j == 3 || j == 7 || j == 9 || j == 11 || j == 12 || j == 13 || j == 14 || j == 15)
            {
                outtextxy(110, 110, &quot; CHESS & quot;);
                outtextxy(50, 105, &quot; **&quot;);
                line(100, 250, 470, 250);
            }
            delay(100);
        }
    }
    setcolor(RED);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(250, 350, &quot; Press any key to continue & quot;);

    getch();

    setcolor(YELLOW);
    cleardevice();

    settextstyle(8, HORIZ_DIR, 5);

    outtextxy(40, 40, &quot; GAME DESIGNED BY
              : -&quot;);

    settextstyle(2, HORIZ_DIR, 6);
    circle(80, 200, 50);
    outtextxy(40, 190, &quot; SAICHARAN & quot;);

    delay(500);

    circle(170, 350, 50);
    outtextxy(138, 340, &quot; APOORVA & quot;);

    delay(500);

    circle(260, 200, 50);
    outtextxy(237, 190, &quot; ARYAN & quot;);

    delay(500);

    circle(350, 350, 50);
    outtextxy(312, 340, &quot; ABHISHEK & quot;);

    delay(500);

    outtextxy(360, 200, &quot; #Students of class XI A & quot;);

    delay(500);

    setcolor(RED);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(300, 420, &quot; Press any key to continue & quot;);

    setcolor(YELLOW);
    getch();
    cleardevice();
}

/////////////////////////////////////////////////////////
///////////////////////
int mousehide()
{
    in.x.ax = 2; //Function to hide the mouse icon
    int86(51, &amp; in, &amp; out);
    return 1;
}
/////////////////////////////////////////////////////////
///////////////////////
void mainmenu(); //Function to display the main
menu struct xycord
{
    int x;
    int y;
    int player; //structure to hold the x,y coordinates
    and the piece present in a perticular square char piece[3];
} sqrpos[65];
/////////////////////////////////////////////////////////
//////////////////////
int pos1, pos2;
void assignpos(void)
{
    int k = 0;
    for (int m = 0; m & lt; 8; m++)
        for (int l = 0; l & lt; 8; l++)

        { //Function to assign the initial
            positions of the pieces

                sqrpos[k]
                    .x = 150 + (m * 40);
            sqrpos[k].y = 150 + (l * 40);

            //To arrange the chess board

            sqrpos[k].piece[0] = &#39;
            \0 & #39;
            ;
            sqrpos[k].player = 0;
            k++;
        }

    strcpy(sqrpos[0].piece, &quot; R & quot;);
    strcpy(sqrpos[1].piece, &quot; N & quot;);
    strcpy(sqrpos[2].piece, &quot; B & quot;);
    strcpy(sqrpos[3].piece, &quot; K & quot;);
    strcpy(sqrpos[4].piece, &quot; Q & quot;);
    strcpy(sqrpos[5].piece, &quot; B & quot;);
    strcpy(sqrpos[6].piece, &quot; N & quot;);
    strcpy(sqrpos[7].piece, &quot; R & quot;);
    strcpy(sqrpos[8].piece, &quot; P & quot;);

    strcpy(sqrpos[9].piece, &quot; P & quot;);
    strcpy(sqrpos[10].piece, &quot; P & quot;);
    strcpy(sqrpos[11].piece, &quot; P & quot;);
    strcpy(sqrpos[12].piece, &quot; P & quot;);
    strcpy(sqrpos[13].piece, &quot; P & quot;);
    strcpy(sqrpos[14].piece, &quot; P & quot;);
    strcpy(sqrpos[15].piece, &quot; P & quot;);
    strcpy(sqrpos[48].piece, &quot; P & quot;);
    strcpy(sqrpos[49].piece, &quot; P & quot;);
    strcpy(sqrpos[50].piece, &quot; P & quot;);
    strcpy(sqrpos[51].piece, &quot; P & quot;);
    strcpy(sqrpos[52].piece, &quot; P & quot;);
    strcpy(sqrpos[53].piece, &quot; P & quot;);
    strcpy(sqrpos[54].piece, &quot; P & quot;);
    strcpy(sqrpos[55].piece, &quot; P & quot;);
    strcpy(sqrpos[56].piece, &quot; R & quot;);
    strcpy(sqrpos[57].piece, &quot; N & quot;);
    strcpy(sqrpos[58].piece, &quot; B & quot;);
    strcpy(sqrpos[59].piece, &quot; K & quot;);
    strcpy(sqrpos[60].piece, &quot; Q & quot;);

    strcpy(sqrpos[61].piece, &quot; B & quot;);
    strcpy(sqrpos[62].piece, &quot; N & quot;);
    strcpy(sqrpos[63].piece, &quot; R & quot;);

    for (int h = 0; h & lt; 16; h++)
    {
        sqrpos[h].player = 1;
        sqrpos[63 - h].player = 2;
    }
}
/////////////////////////////////////////////////////////
///////////////////////
void display()
{

    int i, j, k;
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(440, 100, &quot; Other Inputs & quot;);
    line(440, 140, 650, 140);

    line(440, 145, 650, 145); //To display the
    main screen during the game
        settextstyle(2, HORIZ_DIR, 5);
    outtextxy(440, 150, &quot; 1000 - Queen side castle.& quot;);
    outtextxy(440, 170, &quot; 2000 - King side castle.& quot;);
    outtextxy(440, 190, &quot; 5000 - Reset & quot;);
    outtextxy(440, 210, &quot; 999 - Exit & quot;);
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, BROWN);
    for (i = 100; i & lt; 460; i = i + 40)
    {
        for (j = 100; j & lt; 460; j = j + 40)
        {
            if (cnt == 0)
            {
                line(i, i, i, j);
                delay(5);
                line(i, j, j, j);
                delay(5);
                line(j, j, j, i);
                delay(5);

                line(j, i, i, i);
                delay(5);
            }
            else
            {
                line(i, i, i, j);
                line(i, j, j, j);
                line(j, j, j, i);
                line(j, i, i, i);
            }
        }
    }

    settextstyle(2, HORIZ_DIR, 3);
    for (i = 100; i & lt; 420; i = i + 80)
        for (j = 100; j & lt; 420; j = j + 80)
            if (cnt == 0)
            {
                floodfill(i + 20, j + 20, YELLOW);
                delay(25);
            }
            else
                floodfill(i + 20, j + 20, YELLOW);

    for (i = 140; i & lt; 420; i = i + 80)
        for (j = 140; j & lt; 420; j = j + 80)
            if (cnt == 0)
            {
                floodfill(i + 20, j + 20, YELLOW);
                delay(25);
            }
            else
                floodfill(i + 20, j + 20, YELLOW);

    setcolor(YELLOW);
    j = 0, k = 0;
    for (i = 1; i & lt; 65; i++)
    {

        char str[10];

        itoa(i, str, 10);
        settextstyle(2, HORIZ_DIR, 4);
        outtextxy(102 + j, 102 + k, str);
        if (sqrpos[i - 1].player == 1)
            setcolor(WHITE);
        if (sqrpos[i - 1].player == 2)
            setcolor(CYAN);
        settextstyle(0, HORIZ_DIR, 2);
        if (cnt == 0)
        {
            outtextxy(97 + j, 115 + k, sqrpos[i - 1].piece);
            delay(10);
        }
        else
            outtextxy(97 + j, 115 + k, sqrpos[i - 1].piece);
        j = j + 40;
        if (i % 8 == 0)
        {
            k = k + 40;
            j = 0;
        }
        for (int l = 0; l & lt; 10; l++)
            str[l] = &#39;
        \0 & #39;
        ;
        setcolor(YELLOW);
    }

    rectangle(95, 95, 425, 425);
    cnt++;
}
/////////////////////////////////////////////////////////
///////////////
void promo()
{
    for (int r = 0; r & lt; 8; r++)
    {
        if (strcmp(sqrpos[r].piece, &quot; P & quot;) == 0) //To
            promote a pawn to a queen when it reaches the last rank

                strcpy(sqrpos[r].piece, &quot; Q & quot;);
        if (strcmp(sqrpos[r].piece, &quot; P & quot;) == 0)
            strcpy(sqrpos[63 - r].piece, &quot; Q & quot;);
    }
}
int validpawn()
{

    if ((pos1 != pos2) & amp; &amp; pos1 &gt; = 1 & amp; &amp; pos1 &lt; = 64 & amp; &amp; pos2 &gt; = 1 & amp; &amp; pos2 &lt; = 64 & amp; &amp; s
                                                                                                                                                      qrpos[pos2 - 1]
                                                                                                                                                          .player != z)
    {
        int diff, i, flag = 0;
        diff = pos2 - pos1;
        if (z == 1)
        { //To check the

            validity of the pawn

                if ((diff == 7 || diff == 9) & amp; &amp; sqrpos[pos2 -

                                                                 1]
                                                                  .player != z &
                                                          amp;
                    &amp; sqrpos[pos2 - 1].player != 0)

                    return 1;
            else if (diff == 16 & amp; &amp; ((pos1 - 1 &gt; = 8 & amp; &amp; pos1 - 1 &lt; = 15) || (pos1 -

                                                                                                          1 &gt;
                                                                                                      = 47 & amp; &amp; pos1 - 1 &lt; = 55))) return 1;
            else if (diff == 8) if (sqrpos[pos2 - 1].piece[0] != &#39;\0 & #39;) return 0;
            else return 1;
        }

        else if (z == 2)
        {
            if ((diff == -7 || diff == -9) & amp; &amp; sqrpos[pos2 -

                                                               1]
                                                                .player != z &
                                                        amp;
                &amp; sqrpos[pos2 - 1].player != 0)

                return 1;
            else if (diff == -16 & amp; &amp; (pos1 - 1 &gt; = 47 & amp; &amp; pos1 - 1 &lt; = 55))
                return 1;
            else if (diff == -8)
                if (sqrpos[pos2 - 1].piece[0] != &#39;\0 & #39;)
                    return 0;
                else
                    return 1;
        }
    }
    else
        return 0;
}
int validrook()
{

    int flag = 0, i, diff;

    if ((pos1 != pos2) & amp; &amp; pos1 &gt; = 1 & amp; &amp; pos1 &lt; = 64 & amp; &amp; pos2 &gt; = 1 & amp; &amp; pos2 &lt; = 64 & amp; &amp; s
                                                                                                                                                      qrpos[pos2 - 1]
                                                                                                                                                          .player != z)
    {

        diff = abs(pos1 - pos2); //To check

        validity of the rook if (diff % 8 == 0)
        {
            for (i = pos1 + 8; i & lt; pos2; i += 8)

                if (sqrpos[i - 1].piece[0] != &#39;\0 & #39;)
                {
                    flag = 1;
                    break;
                }
            if (flag == 1)
                return 0;
            else
                return 1;
        }
        else if ((pos1 - 1) / 8 == (pos2 - 1) / 8)
        {
            if (pos1 & lt; pos2)
            {
                for (i = pos1; i & lt; pos2 - 1; i++)
                    if (sqrpos[i].piece[0] != &#39;\0 & #39;)
                    {
                        flag = 1;
                        break;
                    }
                if (flag == 1)
                    return 0;
                else
                    return 1;
            }
            else if (pos1 & gt; pos2)
            {

                for (i = pos1 - 2; i & gt; pos2; i--)
                    if (sqrpos[i].piece[0] != &#39;\0 & #39;)

                    {
                        flag = 1;
                        break;
                    }
                if (flag == 1)
                    return 0;
                else
                    return 1;
            }
        }
    }
    else
        return 0;
}
int validking()
{

    if ((pos1 != pos2) & amp; &amp; pos1 &gt; = 1 & amp; &amp; pos1 &lt; = 64 & amp; &amp; pos2 &gt; = 1 & amp; &amp; pos2 &lt; = 64 & amp; &amp; s
                                                                                                                                                      qrpos[pos2 - 1]
                                                                                                                                                          .player != z)
    {

        int diff, i, flag = 0;
        diff = abs(pos1 - pos2);
        if (diff == 8 || diff == 7 || diff == 9 || diff == 1) //To

            check validity of the king

                if (sqrpos[pos2 - 1].player != z) return 1;
        else
            return 0;
    }
    else
        return 0;
}
int castle()
{
    if (pos1 == 1000)
    {
        if (z == 2)
        {

            if (sqrpos[62].piece[0] == &#39;\0 & #39; &amp; &amp; sqrpos[61].piece[0] == &#39;\0 & #39; &amp; &amp; sqr
                                                                                                                        pos[60]
                                                                                                                            .piece[0] == &#39;\0 & #39;)
                return 1;
            else
                return 0; //To check the validity

            of castle
        }
        else if (z == 1)
        {

            if (sqrpos[6].piece[0] == &#39;\0 & #39; &amp; &amp; sqrpos[5].piece[0] == &#39;\0 & #39; &amp; &amp; sqrpo
                                                                                                                      s[4]
                                                                                                                          .piece[0] == &#39;\0 & #39;)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else if (pos1 == 2000)

    {
        if (z == 2)
        {

            if (sqrpos[57].piece[0] == &#39;\0 & #39; &amp; &amp; sqrpos[58].piece[0] == &#39;\0 & #39;)
                return 1;
            else
                return 0;
        }
        else if (z == 1)
        {

            if (sqrpos[1].piece[0] == &#39;\0 & #39; &amp; &amp; sqrpos[2].piece[0] == &#39;\0 & #39;)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else

        return 0;
}
////////////////////////////////////////
int validknight()
{

    if ((pos1 != pos2) & amp; &amp; pos1 &gt; = 1 & amp; &amp; pos1 &lt; = 64 & amp; &amp; pos2 &gt; = 1 & amp; &amp; pos2 &lt; = 64 & amp; &amp; s
                                                                                                                                                      qrpos[pos2 - 1]
                                                                                                                                                          .player != z)
    {
        int diff; //To check the validity

        of the knight

            diff = abs(pos1 - pos2);
        if (diff == 1)
            return 0;
        if (diff == 15 || diff == 17 || diff == 10 || diff == 6)
            return 1;
    }
    return 0;
}
int validbishop()
{

    if ((pos1 != pos2) & amp; &amp; pos1 &gt; = 1 & amp; &amp; pos1 &lt; = 64 & amp; &amp; pos2 &gt; = 1 & amp; &amp; pos2 &lt; = 64 & amp; &amp; s
                                                                                                                                                      qrpos[pos2 - 1]
                                                                                                                                                          .player != z)
    {
        int i, diff, flag = 1;
        diff = abs(pos1 - pos2); //To check the validity of

        the bishop

            if (diff == 7 || diff == 9) return 1;
        else if (diff % 7 == 0)
        {
            flag = 0;
            for (i = pos1 + 7; i & lt; pos2; i += 7)
            {
                if (sqrpos[i - 1].piece[0] != &#39;\0 & #39;)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                return 0;

            else
                return 1;
        }
        else if (diff % 9 == 0)
        {
            flag = 0;

            for (i = pos1 + 9; i & lt; pos2; i += 9)
            {
                if (sqrpos[i - 1].piece[0] != &#39;\0 & #39;)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1)
            return 0;
        return 1;
    }
    else
        return 0;
}
int validqueen()
{
    int x;
    x = validbishop(); //To check validity of the king
    if (x == 1)
        return x;
    else
        x = validrook();
    return x;
}
/////////////////////////////////////////////////////////
///////////////
/////////////////////////////////////////////////////////
///////////////

int validplayer()
{
    if (sqrpos[pos1 - 1].player == z) //To check if the move is
        entered by the right player

            return 1;
    else
        return 0;
}

int valid()
{
    int temp = 0;
    char ch[3]; //To call the valid
    functions
        strcpy(ch, sqrpos[pos1 - 1].piece);
    if (pos1 != pos2)
        switch (ch[1])
        {
        case &#39; R & #39;:
            temp = validrook();
            break;

        case &#39; N & #39;:
            temp = validknight();

            break;

        case &#39; B & #39;:
            temp = validbishop();

            break;

        case &#39; K & #39;:
            temp = validking();
            ;
            break;

        case &#39; Q & #39;:
            temp = validqueen();
            break;
        case &#39; P & #39;:
            temp = validpawn();
            break;
        }
    return temp;
}

void reset()
{
    assignpos(); //To reset the board
    z = 1;
}

void getmove(void)

{
    char as; //To take input from the user
    int ll;
    cout &lt;
    &lt;
    &quot;
    PLAYER &quot;
    &lt;
    &lt;
    z &lt;
    &lt;
    &quot;
    \n &quot;
    ;
    cout &lt;
    &lt;
    &quot;
    Enter initial piece position \n &quot;
    ;
    cin &gt;
    &gt;
    pos1;
    if (pos1 == 999)
        exit(0);
    else if (pos1 == 1000 || pos1 == 2000)
    {
        ll = castle();
        if (ll == 1)
            changepos();
    }
    else if (pos1 == 5000)
        reset();

    cout &lt;
    &lt;
    &quot;
    Enter final piece position \n &quot;
    ;
    cin &gt;
    &gt;
    pos2;
}

void changepos(void)
{
    if (pos1 == 1000) //To move the pieces
    {
        if (z == 1)
        {
            strcpy(sqrpos[5].piece, sqrpos[3].piece);
            strcpy(sqrpos[3].piece, &quot; &quot;);
            sqrpos[5].player = sqrpos[3].player;
            sqrpos[3].player = 0;
            strcpy(sqrpos[4].piece, sqrpos[7].piece);
            strcpy(sqrpos[7].piece, &quot; &quot;);
            sqrpos[4].player = sqrpos[7].player;
            sqrpos[7].player = 0;
            z++;
        }
        else if (z == 2)
        {
            strcpy(sqrpos[61].piece, sqrpos[59].piece);
            strcpy(sqrpos[59].piece, &quot; &quot;);
            sqrpos[61].player = sqrpos[59].player;
            sqrpos[59].player = 0;
            strcpy(sqrpos[60].piece, sqrpos[63].piece);
            strcpy(sqrpos[63].piece, &quot; &quot;);
            sqrpos[60].player = sqrpos[63].player;
            sqrpos[63].player = 0;
            z--;
        }
    }
    else if (pos1 == 2000)
    {
        if (z == 1)
        {

            strcpy(sqrpos[1].piece, sqrpos[3].piece);
            strcpy(sqrpos[3].piece, &quot; &quot;);
            sqrpos[1].player = sqrpos[3].player;
            sqrpos[3].player = 0;
            strcpy(sqrpos[2].piece, sqrpos[0].piece);
            strcpy(sqrpos[0].piece, &quot; &quot;);
            sqrpos[2].player = sqrpos[0].player;
            sqrpos[0].player = 0;
            z++;
        }
        else if (z == 2)
        {
            strcpy(sqrpos[57].piece, sqrpos[59].piece);
            strcpy(sqrpos[59].piece, &quot; &quot;);
            sqrpos[57].player = sqrpos[59].player;
            sqrpos[59].player = 0;
            strcpy(sqrpos[58].piece, sqrpos[56].piece);
            strcpy(sqrpos[56].piece, &quot; &quot;);
            sqrpos[58].player = sqrpos[56].player;

            sqrpos[56].player = 0;
            z--;
        }
    }
    else
    {
        strcpy(sqrpos[pos2 - 1].piece, sqrpos[pos1 - 1].piece);
        strcpy(sqrpos[pos1 - 1].piece, &quot; &quot;);
        sqrpos[pos2 - 1].player = sqrpos[pos1 - 1].player;
        sqrpos[pos1 - 1].player = 0;
    }
}

/////////////////////////////////////////////////////////
///////////////////////
/*void undo()
{

if(utemp1!=0&amp;&amp;utemp2!=0)
{
pos1=utemp2;
pos2=utemp1;
if(z==2)
z--;
else
z++;
changepos();
}
} For later purposes*/
/////////////////////////////////////////////////////////
///////////////////////
int check(xycord a[])
{ //To check for checkmate
    int flag1 = 0, flag2 = 0;
    for (int c = 0; c & lt; 64; c++)
        if (strcmp(a[c].piece, &quot; K & quot;) == 0 & amp; &amp; a[c].player == 1)
            flag1 = 1;
    for (int i = 0; i & lt; 64; i++)

        if (strcmp(a[i].piece, &quot; K & quot;) == 0 & amp; &amp; a[i].player == 2)
            flag2 = 1;
    if (flag1 == 0)
        return 2;
    else if (flag2 == 0)
        return 1;
    else
        return 0;
}
/////////////////////////////////////////////////////////
///////////////////////
int callmouse()
{
    in.x.ax = 1; //To display the mouse
    int86(51, &amp; in, &amp; out);
    return 1;
}
/////////////////////////////////////////////////////////
///////////////////////
void restrictmouseptr(int x1, int y1, int x2, int y2)
{

    in.x.ax = 7;
    in.x.cx = x1; //To restrict the mouse

    pointer &#39;
    s movement within the rectangle

        in.x.dx = x2;
    int86(51, &amp; in, &amp; out);
    in.x.ax = 8;
    in.x.cx = y1;
    in.x.dx = y2;
    int86(51, &amp; in, &amp; out);
}
/////////////////////////////////////////////////////////
///////////////////////
void mouseposi(int x[], int &amp; xpos, int &amp; ypos, int &amp; click)
{
    in.x.ax = 3; //To return the x and y
    coordinates of the mouse
        int86(51, &amp; in, &amp; out);
    click = out.x.bx;
    xpos = out.x.cx;
    ypos = out.x.dx;
    if (!click)
        j = 1;

    if (click & amp; &amp; j == 1)
    {
        x[0] = xpos;
        x[1] = ypos;
    }
}
/////////////////////////////////////////////////////////
/////////////////////////
void setposi(int &amp; xpos, int &amp; ypos)
{
    in.x.ax = 4;
    in.x.cx = xpos;
    in.x.dx = ypos;
    int86(51, &amp; in, &amp; out);
}
/////////////////////////////////////////////////////////
///////////////////////
void rules()
{
    mousehide();
    cleardevice();

    settextstyle(4, HORIZ_DIR, 6); //To

    display the rules

        setcolor(CYAN);
    outtextxy(230, 20, &quot; RULES & quot;);
    rectangle(10, 10, 620, 450);
    rectangle(15, 15, 615, 445);
    restrictmouseptr(15, 15, 615, 445);
    settextstyle(0, HORIZ_DIR, 4);
    outtextxy(577, 25, &quot; X & quot;);
    settextstyle(0, HORIZ_DIR, 1);
    outtextxy(50, 90, &quot; 1. Each of the 6 different kinds

                                 of pieces moves differently.&
                             quot;);

    outtextxy(50, 100, &quot; Pieces cannot move through

                                  other pieces and
                              can never move onto a & quot;);

    outtextxy(50, 110, &quot; square with one of their own

                                  pieces.&
                              quot;);

    outtextxy(50, 130, &quot; 2. Pawns can only move forward

                                  one square at a time,
                              except & quot;);

outtextxy(50,140,&quot; for their very first move

where they can move forward two squares.&quot;);

outtextxy(50, 150, &quot; Pawns can only capture one

                              square diagonally in front of them.&
                          quot;);

outtextxy(50, 160, &quot; They can never move or

                          capture backwards & quot;);

outtextxy(50, 180, &quot; 3. The rook may move as far as

                          it wants,
                          but only forward, &quot;);

outtextxy(50, 190, &quot; backward, and to the sides.& quot;);
outtextxy(50, 210, &quot; 4. The bishop may move as far

                              as it wants,
                          but only diagonally.& quot;);

outtextxy(50, 230, &quot; 5. Knights move in a very

                              different way from the other pieces &
                          quot;);

outtextxy(50, 240, &quot; going two squares in one

                              direction,
                          and then one more move at a & quot;);

outtextxy(50, 250, &quot; 90 degree angle, just like the

                                                   shape of an \&
                                               quot;
          L\& quot;.& quot;);

outtextxy(50, 270, &quot; 6. The queen can move in any

                                  one straight direction -
                              forward,
                          &quot;);

outtextxy(50, 280, &quot; backward, sideways, or

                                                  diagonally - as far as possible as long as &quot;);

outtextxy(50, 290, &quot; she does not move through

                              any of her own pieces.&
                          quot;);

outtextxy(50, 310, &quot; 7. The king can only move one

                                  square in any direction -
                              up,
                          down, &quot;);

outtextxy(50, 320, &quot; to the sides, and diagonally.& quot;);

outtextxy(50, 340, &quot; 8. To move the pieces, enter

                                                         the number of the box of the initial &
                                                     quot;);

outtextxy(50, 350, &quot; position and the number of

                                               the box of the final position.&
                                           quot;);

outtextxy(50,370,&quot;9. Enter 1000 for queen side

castle. &quot;);

outtextxy(50,390,&quot;10. Enter 2000 for king side

castle.&quot;);

outtextxy(50, 410, &quot; 11. Enter 999 to end the game & quot;);
outtextxy(50, 430, &quot; 12. Enter 5000 to reset the

                              board &
                          quot;);

rectangle(615, 15, 565, 60);
rectangle(610, 20, 570, 55);
int m = 0;
setposi(a, b);
callmouse();
while (m == 0)
{
    mouseposi(posarr, x, y, cl);
    gotoxy(1, 2);

    if (posarr[0] &gt; = 550 & amp; &amp; posarr[0] &lt; = 615 & amp; &amp; posarr[1] &lt; = 60 & amp; &amp; posarr[1] &gt; = 15)

    {
        cleardevice();
        mainmenu();
        m = 1;
    }
}
mousehide();
}
/////////////////////////////////////////////////////////
///////////////////////
void main1()
{
    int x = 0, v = 0, vp = 0;
    assignpos();

    //To control the flow of the program

    while (x == 0)
    {

        cleardevice();
        display();
        if (z == 1)
        {

            getmove();
            vp = validplayer();
            if (pos1 != 1000 & amp; &amp; pos1 != 2000)
            {
                if (vp == 1)
                    v = valid();
                if (v == 1)
                {
                    changepos();
                    z++;
                }
            }
        }
        x = check(sqrpos);
        promo();

        v = 0;
        vp = 0;
        if (x != 0)
        {
            cleardevice();
            display();
            delay(50);
            cout &lt;
            &lt;
            &quot;
            Player &quot;
            &lt;
            &lt;
            x &lt;
            &lt;
            &quot;
            Wins &quot;
            ;
            getch();
            reset();
        }
        clrscr();
        cleardevice();
        display();
        if (z == 2)
        {

            getmove();
            vp = validplayer();
            if (pos1 != 1000 & amp; &amp; pos2 != 2000)

            {
                if (vp == 1)
                    v = valid();
                if (v == 1)
                {
                    changepos();
                    z--;
                }
            }
        }
        x = check(sqrpos);
        promo();
        v = 0;
        vp = 0;
        if (x != 0)
        {
            cleardevice();
            display();
            delay(50);
            cout &lt;
            &lt;
            &quot;
            Player &quot;
            &lt;
            &lt;
            x &lt;
            &lt;
            &quot;
            Wins &quot;
            ;

            getch();
            reset();
        }
        clrscr();
    }
    cleardevice();
    cout &lt;
    &lt;
    &quot;
    PLAYER &quot;
    &lt;
    &lt;
    x &lt;
    &lt;
    &quot;
    WINS &quot;
    ;
}
/////////////////////////////////////////////////////////
///////////////////////
void mainmenu()
{
    mousehide();
    cleardevice();
    callmouse(); //To display the main menu
    int k = 0;
    setcolor(RED);
    callmouse();
    settextstyle(4, HORIZ_DIR, 6);

    outtextxy(230, 20, &quot; CHESS & quot;);
    rectangle(10, 10, 620, 450);
    rectangle(15, 15, 615, 445);
    restrictmouseptr(15, 15, 615, 445);

    setposi(a, b);
    callmouse();
    do
    {
        settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
        mouseposi(posarr, x, y, cl);
        gotoxy(1, 2);
        setcolor(LIGHTRED);
        rectangle(150, 150, 475, 200);
        rectangle(155, 155, 470, 195);
        setcolor(YELLOW);
        outtextxy(270, 150, &quot; PLAY & quot;);
        setcolor(LIGHTRED);
        rectangle(150, 250, 475, 300);

        rectangle(155, 255, 470, 295);
        setcolor(YELLOW);
        outtextxy(260, 255, &quot; RULES & quot;);
        setcolor(LIGHTRED);
        rectangle(150, 355, 475, 400);
        rectangle(155, 360, 470, 395);
        setcolor(YELLOW);
        outtextxy(270, 355, &quot; QUIT & quot;);

        if (posarr[0] &gt; = 150 & amp; &amp; posarr[0] &lt; = 475 & amp; &amp; posarr[1] &gt; = 350 & amp; &amp; posarr
                [1] &lt;
            = 400)

            k = 1;

        if (posarr[0] &gt; = 150 & amp; &amp; posarr[0] &lt; = 475 & amp; &amp; posarr[1] &lt; = 300 & amp; &amp; posarr
                [1] &gt;
            = 250)
        {
            rules();
            cleardevice();
        }

        if (posarr[0] &gt; = 150 & amp; &amp; posarr[0] &lt; = 475 & amp; &amp; posarr[1] &gt; = 150 & amp; &amp; posarr
                [1] &lt;
            = 200)
        {
            mousehide();
            cleardevice();
            main1();
        }

    } while (k == 0);

    mousehide();
}
/////////////////////////////////////////////////////////
///////////////////////
void main()
{
    int k = 0;

    int gd = DETECT, gm;
    initgraph(&amp; gd, &amp; gm, &quot; C
              :\\TurboC3\\BGI & quot;);
    intro();
    if (k == 0)
    {
        mainmenu();
        k++;
    }