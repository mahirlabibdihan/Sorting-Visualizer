# include "iGraphics.h"

int x[]={1,4,3,4,5,6,10,8,9,1,4,5,3,13,5,9,3,18,15,3,17,4,2,6,9,19,4,8,11,1,6,4,15,9,2,16,6}, y = 300, r = 15,n=sizeof(x)/sizeof(x[0]);
int j=n-1,i=0,max;
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	glutFullScreen();
    //place your drawing codes here
    iClear();
    iSetColor(20,200,255);
    int k;
    for(k=0;k<n;k++)
    {
        iSetColor(255,0,0);
        if(i==k) iSetColor(255,255,255);
        iLine((50*k)+50,0,(50*k)+50,50*x[k]);
    }
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}

void SelectionSort()
{
	i++;
	if(i>=j)
	{
        if(max!=j)
        {
            PlaySound("Data\\Music\\BallBlockCollision.wav",NULL,SND_ASYNC);
            x[j]^=x[max];
            x[max]^=x[j];
            x[j]^=x[max]; 
        }        
		j--; i=0;
        max=j;
	}

	if(j<0) 
    {
        Sleep(5000);exit(0);
    }
	if (x[max]<x[i])
    {
        max=i;
    }

}



int main()
{
    //place your own initialization codes here.
    iSetTimer(50,SelectionSort);
    iInitialize(1900,1000, "Sort");
    return 0;
}