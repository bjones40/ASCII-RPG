#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
    public:
        Player(WINDOW * win, int y, int x, char c);

        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW * curwin;
};

Player::Player(WINDOW * win, int y, int x, char c)
{
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void Player::mvup()
{
    yLoc--;
    if(yLoc < 1)
        yLoc = 1;
}

void Player::mvdown()
{
    yLoc++;
    if(yLoc > yMax - 2)
        yLoc = yMax - 2;
}

void Player::mvleft()
{
    xLoc--;
    if(xLoc < 1)
        xLoc = 1;
}

void Player::mvright()
{
    xLoc++;
    if(xLoc > xMax - 2)
        xLoc = xMax - 2;
}

int Player::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display()
{
    mvwaddch(curwin, yLoc, xLoc, character);

}

#endif
