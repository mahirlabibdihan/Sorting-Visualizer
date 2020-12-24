# include "iGraphics.h"
# include<math.h>
# define width 1900
# define height 1000
# define pi acos(-1)

int Framey,LastMx,LastMy,mode,curves,SelectedTracer,SelectedCurve,i,j,Base,ToggleCT,Fx,Fy,x,y,Negative,CurveSelect;
double Zoom;
int CurveType[11];
double Amplitude[11];
double Frequency[11];
int Phase[11];
int TVisibility[11];
int CVisibility[11];
int Active[11];
int Ballx[11];
int Bally[11];
int SpeedDir[11];
double SpeedValue[11];
int PauseTracer[11];
int DR[11]=            { 255, 120,   0,   0, 120, 120,  60, 120,   0, 120, 0};
int DG[11]=            { 128,   0, 120,   0,  60, 120,   0,   0, 120,   0, 0};
int DB[11]=            {   0,   0,   0, 120,   0,   0, 120,  60, 120, 120, 0};
int LR[11]=            { 255, 153,   0,   0, 153, 153,  77, 153,   0, 153,255};
int LG[11]=            { 128,   0, 153,   0,  77, 153,   0,   0, 153,   0,255};
int LB[11]=            {   0,   0,   0, 153,   0,   0, 153,  77, 153, 153,255};

char Number[]= {0,'!','@','#','$','%','^','&','*','('};
void iReset()
{
    mode=1;
    ToggleCT=0;
    Framey=height/2;
    curves=3;
    SelectedCurve=10;
    SelectedTracer=10;
    Base=1;
    Zoom=1;
    Negative=0;
    LastMx=-1;
    LastMy=-1;
    CurveSelect=0;
    CurveType[0]=   0,  CurveType[1]=   0,  CurveType[2]=   1,  CurveType[3]=   0,  CurveType[4]=   1,  CurveType[5]=   0,  CurveType[6]=   0,  CurveType[7]=   0,  CurveType[8]=   1,  CurveType[9]=   0,  CurveType[10]=   0,
    Amplitude[0]=   0,  Amplitude[1]=  60,  Amplitude[2]=  90,  Amplitude[3]= 120,  Amplitude[4]=  60,  Amplitude[5]= 160,  Amplitude[6]=  40,  Amplitude[7]=  80,  Amplitude[8]=  30,  Amplitude[9]= 150,  Amplitude[10]=   0,
    Frequency[0]=   0,  Frequency[1]= 240,  Frequency[2]= 240,  Frequency[3]= 350,  Frequency[4]= 560,  Frequency[5]=  100,  Frequency[6]= 120,  Frequency[7]= 560,  Frequency[8]= 450,  Frequency[9]= 210,  Frequency[10]=   0,
        Phase[0]=   0,      Phase[1]=   0,      Phase[2]=   0,      Phase[3]=   0,      Phase[4]=   0,      Phase[5]=   0,      Phase[6]=   0,      Phase[7]=   0,      Phase[8]=   0,      Phase[9]=   0,      Phase[10]=   0,
  TVisibility[0]=   1,TVisibility[1]=   1,TVisibility[2]=   1,TVisibility[3]=   1,TVisibility[4]=   1,TVisibility[5]=   1,TVisibility[6]=   1,TVisibility[7]=   1,TVisibility[8]=   1,TVisibility[9]=   1,TVisibility[10]=   1,
  CVisibility[0]=   1,CVisibility[1]=   1,CVisibility[2]=   1,CVisibility[3]=   1,CVisibility[4]=   1,CVisibility[5]=   1,CVisibility[6]=   1,CVisibility[7]=   1,CVisibility[8]=   1,CVisibility[9]=   1,CVisibility[10]=   1,
       Active[0]=   1,     Active[1]=   1,     Active[2]=   1,     Active[3]=   1,     Active[4]=   0,     Active[5]=   0,     Active[6]=   0,     Active[7]=   0,     Active[8]=   0,     Active[9]=   0,     Active[10]=   0,
        Ballx[0]= 100,      Ballx[1]= 300,      Ballx[2]= 500,      Ballx[3]= 700,      Ballx[4]= 900,      Ballx[5]=1100,      Ballx[6]=1300,      Ballx[7]=1500,      Ballx[8]=1700,      Ballx[9]=1900,      Ballx[10]=   0,
        Bally[0]=   0,      Bally[1]=   0,      Bally[2]=   0,      Bally[3]=   0,      Bally[4]=   0,      Bally[5]=   0,      Bally[6]=   0,      Bally[7]=   0,      Bally[8]=   0,      Bally[9]=   0,      Bally[10]=   0,
     SpeedDir[0]=   1,   SpeedDir[1]=  -1,   SpeedDir[2]=   1,   SpeedDir[3]=  -1,   SpeedDir[4]=   1,   SpeedDir[5]=  -1,   SpeedDir[6]=   1,   SpeedDir[7]=  -1,   SpeedDir[8]=   1,   SpeedDir[9]=  -1,   SpeedDir[10]=   1,
   SpeedValue[0]=   5, SpeedValue[1]=   5, SpeedValue[2]=   5, SpeedValue[3]=   5, SpeedValue[4]=   5, SpeedValue[5]=   5, SpeedValue[6]=   5, SpeedValue[7]=   5, SpeedValue[8]=   5, SpeedValue[9]=   5, SpeedValue[10]=   5,
  PauseTracer[0]=   0,PauseTracer[1]=   0,PauseTracer[2]=   0,PauseTracer[3]=   0,PauseTracer[4]=   0,PauseTracer[5]=   0,PauseTracer[6]=   0,PauseTracer[7]=   0,PauseTracer[8]=   0,PauseTracer[9]=   0,PauseTracer[10]=   0;
}
void iDrawTracer()
{
    int Resulty=0;
    for(i=1; i<=curves; i++)
    {
        double A=Amplitude[i],F=Frequency[i];
        int H=Framey,P=Phase[i],x=Ballx[i],C=CurveType[i],y;
        if(C&Active[i])
        {
            Resulty+=Zoom*A*cos((Zoom*Ballx[0]-P)*(F/(10000*Zoom)));
        }

        else if(Active[i])
        {
            Resulty+=Zoom*A*sin((Zoom*Ballx[0]-P)*(F/(10000*Zoom)));
        }

        if(C)
        {
            Bally[i]=y=Zoom*A*cos((Zoom*x-P)*(F/(10000*Zoom)));
        }

        else
        {
            Bally[i]=y=Zoom*A*sin((Zoom*x-P)*(F/(10000*Zoom)));
        }
        if(!TVisibility[i]|!Active[i]) continue;

        if(SelectedCurve==i)
        {
            iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
        }

        else
        {
            iSetColor(!Negative?0:255,!Negative?0:255,!Negative?0:255);
        }

        iFilledCircle(Zoom*x,H+y,Zoom*11);
        if(SelectedTracer==i)iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
        else iSetColor(Negative?LR[i]:DR[i],Negative?LG[i]:DG[i],Negative?LB[i]:DB[i]);
        iFilledCircle(Zoom*x,H+y,Zoom*8);
    }
    if(TVisibility[0])
    {
        Bally[0]=Resulty;
        if(SelectedCurve==0)
        {
            iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
        }
        else
        {
            iSetColor(!Negative?0:255,!Negative?0:255,!Negative?0:255);
        }

        iFilledCircle(Zoom*Ballx[0],Framey+Resulty,13*Zoom);
        if(SelectedTracer==0)iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
        else
        iSetColor(Negative?LR[0]:DR[0],Negative?LG[0]:DG[0],Negative?LB[0]:DB[0]);
        iFilledCircle(Zoom*Ballx[0],Framey+Resulty,10*Zoom);
    }
}
void iDrawCurve()
{
    for(double x=0; x<width; x+=.2)
    {
        double y,Resulty;
        int H=Framey;
        Resulty=0;

        for(i=1; i<=curves; i++)
        {
            double A=Amplitude[i],F=Frequency[i];
            int P=Phase[i],C=CurveType[i];


            if(C&Active[i])
            {
                y=Zoom*A*cos((x-P)*(F/(10000*Zoom)));
            }
            else if(Active[i])
            {
                y=Zoom*A*sin((x-P)*(F/(10000*Zoom)));
            }

            if(SelectedCurve==i)
            {
                iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
            }
            else
            {
                iSetColor(Negative?LR[i]:DR[i],Negative?LG[i]:DG[i],Negative?LB[i]:DB[i]);
            }
            if(!Active[i]) continue;

            if(CVisibility[i])
            {
                iPoint(x,H+y,(Negative?1:.7)*Zoom);
            }

            Resulty+=y;
        }

        if(CVisibility[0])
        {
            if(SelectedCurve==0)
            {
                iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
            }

            else
            {
                iSetColor(Negative?LR[0]:DR[0],Negative?LG[0]:DG[0],Negative?LB[0]:DB[0]);
            }

            iPoint(x,Framey+Resulty,(Negative?1:.7)*Zoom);
        }
    }
}
void iDrawCurveMeter()
{
    char s[]="1";
    s[0]=curves+48;
    iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
    iRectangle(1850,930,30,30);
    iSetColor(Negative?0:255,Negative?0:255,Negative?255:0);
    iRectangle(1848,908,34,73);
    iText(1860,938,s,GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(Negative?55:200,Negative?55:200,Negative?55:200);
    iFilledRectangle(1849,960,31,20);
    iFilledRectangle(1849,910,31,20);
    iSetColor(!Negative?0:255,!Negative?0:255,!Negative?0:255);
    iText(1859,914,"-",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1859,964,"+",GLUT_BITMAP_TIMES_ROMAN_24);
}
void iDrawBase()
{
    if(Base)
    {
        iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
        for(i=0; i<=width; i+=(5*Zoom>=1?5*Zoom:5))
        {
            iPoint(i,Framey,.5*Zoom);
        }
    }

}
void iDrawHelp()
{
    iSetColor(255,0,0);
    iText(50,940,"KEYBOARD ",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
    iText(50,900,"Toggle Help/Main page   :  F1",GLUT_BITMAP_HELVETICA_18);
    iText(50,870,"Toggle all curve show / hide   :  s / S",GLUT_BITMAP_HELVETICA_18);
    iText(50,840,"Toggle all tracer show / hide   :  t / T",GLUT_BITMAP_HELVETICA_18);
    iText(50,810,"Toggle single curve show / hide  :  <curve_No>",GLUT_BITMAP_HELVETICA_18);
    iText(50,780,"Toggle single tracer show / hide   :  <tracer_No>",GLUT_BITMAP_HELVETICA_18);
    iText(50,750,"Toggle single curve active / deactive   :  SHIFT + <curve_No>",GLUT_BITMAP_HELVETICA_18);

    iSetColor(Negative?0:255,Negative?0:255,Negative?255:0);
    iText(500,795,"*Toggle Curve/Tracer   :  ENTER ",GLUT_BITMAP_HELVETICA_18);
    iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
    iText(50,720,"Toggle baseline show / hide   :  b / B",GLUT_BITMAP_HELVETICA_18);
    iText(50,690,"Toggle mode Dark / Light   :  m / M",GLUT_BITMAP_HELVETICA_18);
    iText(50,660,"Increase Number of curves   :  n",GLUT_BITMAP_HELVETICA_18);
    iText(50,630,"Decrease Number of curves   :  N",GLUT_BITMAP_HELVETICA_18);
    iText(50,600,"Zoom in   :  i / I ",GLUT_BITMAP_HELVETICA_18);
    iText(50,570,"Zoom out   :  o / O",GLUT_BITMAP_HELVETICA_18);
    iText(50,540,"Move upward   :  Up arrow",GLUT_BITMAP_HELVETICA_18);
    iText(50,510,"Move downward   :  Down arrow",GLUT_BITMAP_HELVETICA_18);
    iText(50,480,"Reset   :  x / X",GLUT_BITMAP_HELVETICA_18);
    iText(50,450,"Exit   :  q / Q / END",GLUT_BITMAP_HELVETICA_18);
    iSetColor(Negative?0:255,Negative?0:255,Negative?255:0);
    iText(50,410,"*Select a curve to perform the following actions for a single curve / tracer ",GLUT_BITMAP_HELVETICA_18);
    iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
    iText(50,380,"Increase speed   :  +",GLUT_BITMAP_HELVETICA_18);
    iText(50,350,"Decrease speed   :  -",GLUT_BITMAP_HELVETICA_18);
    iText(50,320,"Change direction of tracer   :  BACKSPACE",GLUT_BITMAP_HELVETICA_18);
    iText(50,290,"Change curve type sin / cos   :  c / C",GLUT_BITMAP_HELVETICA_18);
    iText(50,260,"Decrease phase constant   :  Right arrow",GLUT_BITMAP_HELVETICA_18);
    iText(50,230,"Increase phase contant  :  Left arrow",GLUT_BITMAP_HELVETICA_18);
    iText(50,200,"Increase Amplitude   :  a",GLUT_BITMAP_HELVETICA_18);
    iText(50,170,"Decrease Amplitude   :  A",GLUT_BITMAP_HELVETICA_18);
    iText(50,140,"Increase Frequency   :  f ",GLUT_BITMAP_HELVETICA_18);
    iText(50,110,"Decrease Frequency   :  F",GLUT_BITMAP_HELVETICA_18);
    iText(50,80,"Pause animation   :  p / P / SPACE",GLUT_BITMAP_HELVETICA_18);
    iText(50,50,"Resume animation   :  r / R / SPACE",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,0,0);


    iText(1000,940,"MOUSE",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(Negative?0:255,Negative?0:255,Negative?255:0);
    iText(1000,900,"*Select a curve by left clicking on a curve and unselect a curve by right clicking anywhere in the screen",GLUT_BITMAP_HELVETICA_18);
    iSetColor(Negative?0:255,Negative?0:255,Negative?0:255);
    iText(1000,870,"Increase Amplitude   :  Drag Upward",GLUT_BITMAP_HELVETICA_18);
    iText(1000,840,"Decrease Amplitude   :  Drag Downward",GLUT_BITMAP_HELVETICA_18);
    iText(1000,810,"Increase Frequency   :  Drag Leftward",GLUT_BITMAP_HELVETICA_18);
    iText(1000,780,"Decrease Frequency   :  Drag Rightward",GLUT_BITMAP_HELVETICA_18);

    iSetColor(Negative?0:255,Negative?0:255,Negative?255:0);
    iText(1000,730,"*Click and drag anywhere in the screen to move the curves",GLUT_BITMAP_HELVETICA_18);
}
void iDraw()
{
    iClear();


    iSetColor(Negative?LR[10]:DR[10],Negative?LG[10]:DG[10],Negative?LB[10]:DB[10]);
    iFilledRectangle(0,0,width,height);
    if(mode)
    {
        iDrawBase();
        iDrawCurve();
        iDrawTracer();
        iDrawCurveMeter();
    }
    else
    {
        iDrawHelp();
    }
}
void iAmplitudeChange(double dA)
{
    if(SelectedCurve==0)
    {
        for(i=1; i<=curves; i++)
        {
            if(Active[i])
                Amplitude[i]*=(1+dA);
        }
    }
    else
    {
        Amplitude[SelectedCurve]*=(1+dA);
    }
}
void iFrequencyChange(double dF)
{
    if(SelectedCurve==0)
    {
        for(i=1; i<=curves; i++)
        {
            if(Active[i])
                Frequency[i]*=(1+dF);
        }
    }
    else
    {
        Frequency[SelectedCurve]*=(1+dF);
    }
}
void iPhaseChange(double dP)
{
    if(SelectedCurve%10==0)
    {
            for(i=1; i<=curves; i++)
            {
                if(Active[i])
                Phase[i]+=dP;
            }
    }
    else
    {
        Phase[SelectedCurve]+=dP;
    }
}
void iMouseDirection(int Mx,int My)
{
    int dx=Mx-LastMx,dy=My-LastMy;
    double Dir=(atan(abs(1.0*dy/dx))*180)/acos(-1);
    if(dx>=0&&dy>=0)
    {
        if(Dir<45)
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect)iFrequencyChange(-.004);
            else iPhaseChange(5);
        }
        else
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect) iAmplitudeChange((Fy>Framey?.02:-.02));
            else if(SelectedCurve==10) Framey+=dy;
        }
    }
    else if(dx>=0&&dy<0)
    {
        if(Dir<45)
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect) iFrequencyChange(-.004);
            else iPhaseChange(5);
        }
        else
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect) iAmplitudeChange((Fy>Framey?-.02:.02));
            else if(SelectedCurve==10)Framey+=dy;
        }
    }
    else if(dx<0&&dy>=0)
    {
        if(Dir<45)
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect) iFrequencyChange(.004);
            else iPhaseChange(-5);
        }
        else
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect)iAmplitudeChange((Fy>Framey?.02:-.02));
            else if(SelectedCurve==10) Framey+=dy;
        }
    }
    else if(dx<0&&dy<0)
    {
        if(Dir<45)
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect) iFrequencyChange(.004);
            else iPhaseChange(-5);
        }
        else
        {
            if(SelectedTracer<10) Ballx[SelectedTracer]+=dx;
            else if(CurveSelect) iAmplitudeChange((Fy>Framey?-.02:.02));
            else Framey+=dy;
        }
    }
}
void iMouseMove(int Mx, int My)
{
    if(mode)
    {
        iMouseDirection(Mx,My);
        LastMx=Mx;
        LastMy=My;
    }
}
int iTracerSelect(int Mx,int My)
{
    for(i=0; i<=curves; i++)
    {
        if(Mx>=Zoom*(Ballx[i]-7)&&Mx<=Zoom*(Ballx[i]+7)&&My>=Framey+(Bally[i]-Zoom*7)&&My<=Framey+(Bally[i]+Zoom*7))
        {
            SelectedTracer=i;
            if(SelectedCurve!=i) SelectedCurve=10;
            return 1;
        }
    }
    SelectedTracer=10;
    return 0;
}
int iCurveSelect(int Mx,int My)
{
    int H=Framey,y,Resulty;

    //for(x=Mx-3*Zoom;x<Mx+6*Zoom;x++)
    {
    for(i=1,Resulty=0;i<=curves; i++)
    {
        double A=Amplitude[i],F=Frequency[i],C=CurveType[i];
        int P=Phase[i];

        if(C)
        {
            y=Zoom*A*cos((Mx-P)*(F/(10000*Zoom)));
        }

        else
        {
            y=Zoom*A*sin((Mx-P)*(F/(10000*Zoom)));
        }

        Resulty+=y;
        if(My>=H+y-3*Zoom&& My<=H+y+5*Zoom)
        {
            SelectedCurve=i;

            return 1;
        }
    }
    if(My>=H+Resulty-3*Zoom&& My<=H+Resulty+5*Zoom)
    {
        SelectedCurve=0;
        return 1;
    }

    return 0;
    }

}
void iMouseLeftButtonDown(int Mx,int My)
{
    if(Mx>=1849&&Mx<=1879&&My>=960&&My<=980)
    {
        if(curves<9) curves++;
        for(i=1; i<=curves; i++)
            Active[i]=1;
    }
    else if(Mx>=1849&&Mx<=1879&&My>=910&&My<=930)
    {
        if(curves>0) curves--;
        for(i=curves+1; i<10; i++)
            Active[i]=0;
        if(SelectedCurve>curves) SelectedCurve=10;
    }

    else
    {
        if(!iTracerSelect(Mx,My))
        CurveSelect=iCurveSelect(Mx,My);

        Fx=LastMx=Mx;
        Fy=LastMy=My;
    }
}
void iMouse(int button, int state, int Mx, int My)
{
    if(mode)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            iMouseLeftButtonDown(Mx,My);
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            LastMx=-1;
            LastMy=-1;
        }
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            SelectedCurve=10;
        }

    }

    else
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mode=!mode;
        }

    }
}
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(mode)
    {
        if(key=='s'|key=='S')
        {
            CVisibility[10]=!CVisibility[10];
            for(i=0; i<10; i++)
            {
                if(CVisibility[10]) CVisibility[i]=1;
                else CVisibility[i]=0;
            }
        }

        else if(key=='c' & SelectedCurve<10&SelectedCurve>0)
        {
            CurveType[SelectedCurve]=!CurveType[SelectedCurve];
        }
        else if(key=='\r')
        {
            ToggleCT=!ToggleCT;
        }
        else if(key=='t' | key=='T' )
        {
            TVisibility[10]=!TVisibility[10];
            for(i=0; i<10; i++)
            {
                if(TVisibility[10]) TVisibility[i]=1;
                else TVisibility[i]=0;
            }
        }
        else if(key=='b' | key=='B')
        {
            Base=!Base;
        }
        else if(key == 'p' |key=='p'| key == ' ' && !PauseTracer[SelectedTracer]  )
        {
            for(i=0; i<=10; i++)
                if(SelectedCurve==10|SelectedCurve==i|SelectedTracer==i)
                    PauseTracer[i]=1;

        }
        else if(key == 'r' |key=='R'| key == ' ' && PauseTracer[SelectedTracer])
        {
            for(i=0; i<=10; i++)
                if(SelectedCurve==10|SelectedCurve==i|SelectedTracer==i)
                    PauseTracer[i]=0;
        }
        else if(key == '+')
        {
            for(i=0; i<=10; i++)
            {
                if(SelectedCurve==10|SelectedCurve==i|SelectedTracer==i)
                {
                    SpeedValue[i]+=.5;
                }
            }
        }
        else if(key == '-')
        {
            for(i=0; i<=10; i++)
            {
                if(SelectedCurve==10|SelectedCurve==i|SelectedTracer==i)
                {
                    if(SpeedValue[i]>=.5)
                    {
                        SpeedValue[i]-=.5;
                    }
                }
            }
        }

        else if(key=='i' | key=='I')
        {
            Zoom+=.1;
        }
        else if(key=='o' | key=='O')
        {
            if(Zoom>=.1)
                Zoom-=.1;
        }

        else if(key=='N')
        {
            if(curves>0) curves--;
            for(i=curves+1; i<10; i++)
                Active[i]=0;
            if(SelectedCurve>curves) SelectedCurve=10;
        }

        else if(key=='n')
        {
            if(curves<9) curves++;
            for(i=1; i<=curves; i++)
                Active[i]=1;
        }

        else if(key=='u'|key=='U')
        {
            if(SelectedCurve%10)
                Amplitude[SelectedCurve]*=-1;
        }

        else if(key == 'f')
        {
            iFrequencyChange(.003);
        }

        else if(key == 'F')
        {
            iFrequencyChange(-.003);
        }

        else if(key == 'a')
        {
            iAmplitudeChange(.01);
        }

        else if(key == 'A')
        {
            iAmplitudeChange(-.01);
        }

        else if(key=='x'|key=='X')
        {
            iReset();
        }


        else if(key=='\b')
        {
            for(i=0; i<10; i++)
            {
                if(SelectedCurve==10|SelectedCurve==i|SelectedTracer==i)
                {
                    SpeedDir[i]*=-1;
                }
            }
        }
        else if(key>='0'&&key<='9')
        {
            if(ToggleCT)
            {
                if(key-48<=curves)
                    CVisibility[key-48]=!CVisibility[key-48];
            }

            else
            {
                if(key-48<=curves)
                    TVisibility[key-48]=!TVisibility[key-48];
            }
        }
        else
        {
            for(i=1; i<=curves; i++)
            {
                if(key==Number[i])
                {
                    Active[i]=!Active[i];
                }
            }
        }
    }
    else if(key=='\r')
    {
        mode=1 ;
    }

     if(key=='m'|key=='M')
        {
            Negative=!Negative;
        }

}
void iSpecialKeyboard(unsigned char key)
{

    if(mode)
    {
        if(key == GLUT_KEY_LEFT)
        {
            iPhaseChange(-5);
        }

        else if(key == GLUT_KEY_RIGHT)
        {
            iPhaseChange(5);
        }

        else if(key == GLUT_KEY_UP)
        {
             Framey +=5;
        }

        else if(key == GLUT_KEY_DOWN)
        {
             Framey-=5;
        }

    }
    if(key == GLUT_KEY_F1)
    {
        mode=!mode;
    }

    if(key==GLUT_KEY_END)
    {
        exit(0);
    }
}
void iTracerchange()
{
    if(mode)
    {
        for(i=0; i<=10; i++)
        {
            if(!PauseTracer[i])
            {
                Ballx[i]+=(SpeedDir[i]*SpeedValue[i]);
            }

            if(Zoom*Ballx[i]>=width)
            {
                SpeedDir[i]=-SpeedDir[i];
                Ballx[i]=width/Zoom;
            }
            else if(Zoom*Ballx[i]<=0)
            {
                SpeedDir[i]=-SpeedDir[i];
            }
        }
    }
   //glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}
int main()
{
    iSetTimer(0,iTracerchange);
    iReset();
    mode=0;

    iInitialize(width,height,"DIHAN");
    return 0;

}

