# include "iGraphics.h"
#include<windows.h>
FILE* resume;
int x = 0, y = 0,gamestate=0,busket_cox=100,busket_coy=50,k=0,gametime=9000,score=0,levelmode=1,highscore[3];
int eggcntgolden[8],eggcogoldenx[9][100000],speed=40,eggcogoldeny[9][100000],limitgolden[8],limit[8]={0},egggoldencntbool[8][100000];
int eggcntgreen[8],eggcogreenx[9][100000],eggcogreeny[9][100000],limitgreen[8],limit4[8]={0};
int eggcntwhite[8],eggcowhitex[9][100000],eggcowhitey[9][100000],limitwhite[8],limit2[8]={0},whitetime[8],eggwhitecntbool[8][100000];
int shitcnt[8],shitx[9][100000],shity[9][100000],limitshit[8],limit3[8]={0},shittime[8],shitcntbool[8][100000];
int check_highscore=0,check_help_button=0,mousecox=0,mousecoy=0,mouselight=0,check_sound=1,gameshesh=0;
int chgreen=0,gap=0;
double r,g,b;
char image[][100]={"start.BMP"},button_pictures[][500]={"level_img.BMP","exit.BMP","sound_button.BMP","help.BMP","resume_button.BMP","start_button.BMP"};
char front_gretings[][100]={"catch_the_egg.BMP"},score_board[100],timme[][100]={"time.BMP"};
char welcome_pictures[][100]={"welcome_button.BMP"};
char murgi[][100]={"murgi.BMP"},game_time[100];
char endgame[][100]={"endgame.BMP"};
char chicken_shit[][100]={"chicken_shit.BMP"};
char busket[][500]={"busket.BMP"};
char img_start_background[][500]={"img_start_background.BMP"};
char egg[3][500]={"white_egg.BMP","golden_egg.BMP","green_egg.BMP"};
char see_score[][100]={"score.BMP"};
char highestscore[][100]={"highestscore.BMP"};
char checksound[][100]={"off.BMP","on.BMP"};
char level_img[][100]={"level_1.BMP","level_2.BMP","level_3.BMP"};
bool music_start_homepage=true;
void img_start_backgroundd();
void img_chicken();
void img_busket();
void game_end();
void help_button();
void level_button();
void highscore_button();
void front_end();
void sound_button();
void resume_button();
void resumeaction_button();
void start_button();
void HIGH_SCORE();
void GET_HIGH_SCORE();
void highscore_button()
{
    iSetColor(r=255,g=255,b=255);
    iFilledRectangle(700,600,570,450);
    int p=800,q=900;
    for(int i=0;i<3;i++)
    {
        iShowBMP2(p,q,level_img[i],0x00FFFFFF);
        char pp[100];
        sprintf(pp,"%d",highscore[i]);
        iSetColor(r=255,g=0,b=0);
        iText(p+300,q+70,pp,((void*)5));
        q-=130;
    }
}
void GET_HIGH_SCORE()
{
    FILE* high;
    high=fopen("tttt.txt","r");
    for(int i=0;i<3;i++)
    fscanf(high,"%d\n",&highscore[i]);
}
void HIGH_SCORE()
{
    FILE* high;
    high=fopen("tttt.txt","w");
    for(int i=0;i<3;i++)
    fprintf(high,"%d\n",highscore[i]);
}
void start_button()
{
    score=0;
    busket_cox=100;busket_coy=50;k=0;
    if(levelmode==1)
    {
        gametime=9000;
        speed=50;
    }
    if(levelmode==2)
        {
            gametime=6000;
            speed=60;
        }
    if(levelmode==3)
       {
           gametime=3000;
           speed=70;
       }
    for(int i=0;i<8;i++)
        eggcntgolden[i]=0;
    for(int i=0;i<8;i++)
        eggcntwhite[i]=0;
     for(int i=0;i<8;i+=2)
    {
        eggcntgolden[i]=1;
    }
    for(int i=1;i<8;i+=3)
    {
        eggcntgreen[i]=1;
    }
    int p=speed;
    if(speed==50)
        p-=10;
    else if(speed==60)
        p-=25;
    else if(speed==70)
        p-=40;
    for(int i=0;i<8;i++)
    {
        limitgolden[i]=p;
        p+=10;
    }
    //m
    p=70;
    if(speed==50)
        p-=10;
    else if(speed==60)
        p-=25;
    else if(speed==70)
        p-=40;
    for(int i=0;i<8;i++)
    {
        limitgreen[i]=p;
        p+=10;
    }
    int res=200;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10000;j++)
        {
            eggcogoldenx[i][j]=res;
        }
        res+=200;
    }
    res=200;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10000;j++)
        {
            eggcogreenx[i][j]=res;
        }
        res+=200;
    }
    for(int j=0;j<8;j++)
    for(int i=0;i<10000;i++)
    {
        eggcogoldeny[j][i]=900;
    }
    for(int j=0;j<8;j++)
    for(int i=0;i<10000;i++)
    {
        eggcogreeny[j][i]=900;
    }
    for(int i=1;i<8;i+=2)
    {
        eggcntwhite[i]=1;
    }
    p=speed;
    if(speed==50)
        p-=5;
    else if(speed==60)
        p-=20;
    else if(speed==70)
        p-=35;
    for(int i=0;i<8;i++)
    {
        limitwhite[i]=p;
        p+=10;
    }
     res=200;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10000;j++)
        {
            eggcowhitex[i][j]=res;
        }
        res+=200;
    }
    for(int j=0;j<8;j++)
    for(int i=0;i<10000;i++)
    {
        eggcowhitey[j][i]=900;
    }
    p=speed;
    if(speed==50)
        p-=0;
    else if(speed==60)
        p-=15;
    else if(speed==70)
        p-=30;
    for(int i=0;i<8;i++)
        shitcnt[i]=0;
    for(int i=0;i<8;i++)
    {
        limitshit[i]=p;
        p+=10;
    }
     res=200;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10000;j++)
        {
           shitx[i][j]=res;
        }
        res+=200;
    }
    for(int j=0;j<8;j++)
    for(int i=0;i<10000;i++)
    {
        shity[j][i]=900;
    }
}
void resume_button()
{

    resume=fopen("action.txt","w");
    fprintf(resume,"%d\n",chgreen);
    fprintf(resume,"%d\n",gap);
    fprintf(resume,"%d\n%d\n",busket_cox,busket_coy);
    for(int i=0;i<8;i++)
        fprintf(resume,"%d\n",eggcntgolden[i]);
    for(int i=0;i<8;i++)
        fprintf(resume,"%d\n",eggcntwhite[i]);
    for(int i=0;i<8;i++)
        fprintf(resume,"%d\n",shitcnt[i]);
    for(int i=0;i<8;i++)
        fprintf(resume,"%d\n",eggcntgreen[i]);
    for(int i=0;i<8;i++)
        for(int j=0;j<eggcntgolden[i];j++)
            {
                fprintf(resume,"%d\n",eggcogoldenx[i][j]);
                fprintf(resume,"%d\n",eggcogoldeny[i][j]);
            }
    for(int i=0;i<8;i++)
        for(int j=0;j<eggcntwhite[i];j++)
            {
                fprintf(resume,"%d\n",eggcowhitex[i][j]);
                fprintf(resume,"%d\n",eggcowhitey[i][j]);
            }
    for(int i=0;i<8;i++)
        for(int j=0;j<shitcnt[i];j++)
            {
                fprintf(resume,"%d\n",shitx[i][j]);
                fprintf(resume,"%d\n",shity[i][j]);
            }
    for(int i=0;i<8;i++)
        for(int j=0;j<eggcntgreen[i];j++)
            {
                fprintf(resume,"%d\n",eggcogreenx[i][j]);
                fprintf(resume,"%d\n",eggcogreeny[i][j]);
            }
    fprintf(resume,"%d\n",gametime);
    fprintf(resume,"%d\n",score);
    fprintf(resume,"%d\n",speed);
    fprintf(resume,"%d\n",levelmode);
    for(int i=0;i<8;i++){
    fprintf(resume,"%d\n",limitgolden[i]);
    fprintf(resume,"%d\n",limitgreen[i]);
    fprintf(resume,"%d\n",limitwhite[i]);
    fprintf(resume,"%d\n",limitshit[i]);
    fprintf(resume,"%d\n",limit[i]);
    fprintf(resume,"%d\n",limit2[i]);
    fprintf(resume,"%d\n",limit3[i]);
    fprintf(resume,"%d\n",limit4[i]);
    }
}
void resumeaction_button()
{
    if(gameshesh==0)
    start_button();
    resume=fopen("action.txt","r");
    fscanf(resume,"%d\n",&chgreen);
    fscanf(resume,"%d\n",&gap);
    fscanf(resume,"%d\n%d\n",&busket_cox,&busket_coy);
    for(int i=0;i<8;i++)
        fscanf(resume,"%d\n",&eggcntgolden[i]);
    for(int i=0;i<8;i++)
        fscanf(resume,"%d\n",&eggcntwhite[i]);
    for(int i=0;i<8;i++)
        fscanf(resume,"%d\n",&shitcnt[i]);
    for(int i=0;i<8;i++)
        fscanf(resume,"%d\n",&eggcntgreen[i]);
    for(int i=0;i<8;i++)
        for(int j=0;j<eggcntgolden[i];j++)
            {
                fscanf(resume,"%d\n",&eggcogoldenx[i][j]);
                fscanf(resume,"%d\n",&eggcogoldeny[i][j]);
            }
    for(int i=0;i<8;i++)
        for(int j=0;j<eggcntwhite[i];j++)
            {
                fscanf(resume,"%d\n",&eggcowhitex[i][j]);
                fscanf(resume,"%d\n",&eggcowhitey[i][j]);
            }
    for(int i=0;i<8;i++)
        for(int j=0;j<shitcnt[i];j++)
            {
                fscanf(resume,"%d\n",&shitx[i][j]);
                fscanf(resume,"%d\n",&shity[i][j]);
            }
    for(int i=0;i<8;i++)
        for(int j=0;j<eggcntgreen[i];j++)
            {
                fscanf(resume,"%d\n",&eggcogreenx[i][j]);
                fscanf(resume,"%d\n",&eggcogreeny[i][j]);
            }
    fscanf(resume,"%d\n",&gametime);
    fscanf(resume,"%d\n",&score);
    fscanf(resume,"%d\n",&speed);
    fscanf(resume,"%d\n",&levelmode);
    for(int i=0;i<8;i++){
    fscanf(resume,"%d\n",&limitgolden[i]);
    fscanf(resume,"%d\n",&limitgreen[i]);
    fscanf(resume,"%d\n",&limitwhite[i]);
    fscanf(resume,"%d\n",&limitshit[i]);
    fscanf(resume,"%d\n",&limit[i]);
    fscanf(resume,"%d\n",&limit2[i]);
    fscanf(resume,"%d\n",&limit3[i]);
    fscanf(resume,"%d\n",&limit4[i]);
    }
}
void sound_button()
{
    if(music_start_homepage)
        music_start_homepage=0;
    else
        music_start_homepage=1;
    if(music_start_homepage)
    {
         PlaySound("chicken.wav",NULL,SND_LOOP|SND_ASYNC);
         check_sound=1;
    }
    else
    {
        PlaySound(0,0,0);
        check_sound=2;
    }

}
void front_end()
{
    iShowBMP(0,0,image[0]);
    if(check_help_button==0&&check_highscore==0){
    iShowBMP2(500,300,front_gretings[0],0x00FFFFFF);
    iShowBMP2(630,550,welcome_pictures[0],0x00FFFFFF);}
    int   p=0,q=0;
    int sum=300;
    iShowBMP2(100,200,highestscore[0],0x00FFFFFF);
    GET_HIGH_SCORE();
    for(int i=0;i<6;i++)
    {
        p=100;
        q=sum;
        iShowBMP2(p,q,button_pictures[i],0x00FFFFFF);
        sum+=100;
    }
    if(check_highscore)
        highscore_button();
    if(check_help_button)
        help_button();
    return ;
}
void game_end()
{
      iShowBMP(0,0,endgame[0]);
      iShowBMP2(800,200,highestscore[0],0x00FFFFFF);
       int sum=300;
        for(int i=0;i<6;i++)
        {
           if(i==4)
            continue;
           int p=800;
           int q=sum;
           iShowBMP2(p,q,button_pictures[i],0x00FFFFFF);
           sum+=100;
        }
        Sleep(25);
        sprintf(score_board,"%d",score);
        iSetColor(r=255,g=0,b=0);
        iShowBMP2(800,780,see_score[0],0x00FFFFFF);
        iText(945,800,score_board,((void*)5));
       return ;
}
void help_button()
{
    iSetColor(r=255,g=255,b=255);
    iFilledRectangle(380,320,1080,380);
    iSetColor(r=255,g=0,b=100);
    iText(400,600,"You should catch the egg in the basket",((void*)5));
    iText(400,550,"If u catch white egg u will get 10 points.",((void*)5));
    iText(400,500,"If u catch green egg u will get 15 points and 30ms extra",((void*)5));
    iText(400,450,"For golden egg u will get 5 points and if u catch shit u will loose 30 points.",((void*)5));
    iText(400,400,"You should drag ur mouse for moving the basket.",((void*)5));
    iText(400,350,"Lets Enjoy The Game!!",((void*)5));
    return ;
}
void level_button()
{
    iShowBMP(0,0,image[0]);
    int p=500;
    for(int i=0;i<3;i++)
    {
        iShowBMP2(800,p,level_img[i],0x00FFFFFF);
        p+=150;
    }
    return;
}
void change()
{

    return ;
}
void img_chicken()
{
    int murgix=50,murgiy=870;
    for(int i=0;i<8;i++)
    {
        iShowBMP2(murgix,murgiy,murgi[0],0x00FFFFFF);
        murgix+=200;
    }
    return ;
}
void img_busket()
{
    iShowBMP2(busket_cox,busket_coy,busket[0],0x00F6F6F6);
    return ;
}
void  img_start_backgroundd()
{
    iShowBMP(0,0,img_start_background[0]);
}
void iDraw()
{
    iClear();
    if(gamestate==0)
    {
        front_end();
    }
    else if(gamestate==10)
    {
        gameshesh=1;
        img_start_backgroundd();
        img_chicken();
        img_busket();
        for(int j=0;j<8;j++)
        for(int i=0;i<eggcntgolden[j];i++)
        {
            if((eggcogoldenx[j][i]<busket_cox||eggcogoldenx[j][i]>busket_cox+150)||eggcogoldeny[j][i]>150)
            iShowBMP2(eggcogoldenx[j][i],eggcogoldeny[j][i],egg[1],0x00FFFFFF);
        }
        for(int j=0;j<8;j++)
        for(int i=0;i<eggcntgreen[j];i++)
        {
            if((eggcogreenx[j][i]<busket_cox||eggcogreenx[j][i]>busket_cox+150)||eggcogreeny[j][i]>150)
            iShowBMP2(eggcogreenx[j][i],eggcogreeny[j][i],egg[2],0x00FFFFFF);
        }
        for(int j=0;j<8;j++)
        for(int i=0;i<shitcnt[j];i++)
        {
            if((shitx[j][i]<busket_cox||shitx[j][i]>busket_cox+150)||shity[j][i]>150)
              iShowBMP2(shitx[j][i],shity[j][i],chicken_shit[0],0x00FFFFFF);
        }
        for(int j=0;j<8;j++)
        for(int i=0;i<eggcntwhite[j];i++)
        {
            if((eggcowhitex[j][i]<busket_cox||eggcowhitex[j][i]>busket_cox+150)||eggcowhitey[j][i]>150)
            iShowBMP2(eggcowhitex[j][i],eggcowhitey[j][i],egg[0],0x00FFFFFF);
        }
        int sum=300;
        for(int i=0;i<6;i++)
        {
           int p=1660;
           int q=sum;
           iShowBMP2(p,q,button_pictures[i],0x00FFFFFF);
           sum+=100;
        }
        sprintf(score_board,"%d",score);
        iSetColor(r=255,g=0,b=0);
        iShowBMP2(1660,880,see_score[0],0x00FFFFFF);
        iText(1805,900,score_board,((void*)5));
        iShowBMP2(1660,980,timme[0],0x00FFFFFF);
        sprintf(game_time,"%d",gametime);
        iSetColor(r=255,g=0,b=0);
        iText(1805,1010,game_time,((void*)5));
        if(gamestate==3)
         {
           level_button();
         }
    }
    else if(gamestate==1)
    {
        gameshesh=1;
        img_start_backgroundd();
        img_chicken();
        img_busket();
        for(int j=0;j<8;j++)
        for(int i=0;i<eggcntgolden[j];i++)
        {
            if((eggcogoldenx[j][i]<busket_cox||eggcogoldenx[j][i]>busket_cox+150)||eggcogoldeny[j][i]>150)
            iShowBMP2(eggcogoldenx[j][i],eggcogoldeny[j][i],egg[1],0x00FFFFFF);
            else if(eggcogoldenx[j][i]>busket_cox&&eggcogoldenx[j][i]<busket_cox+150&&eggcogoldeny[j][i]<=155&&eggcogoldeny[j][i]>=100&&egggoldencntbool[j][i]==0)
            {
                score+=5;
                sprintf(score_board,"%d",score);
                iSetColor(r=255,g=0,b=0);
                iShowBMP2(1660,880,see_score[0],0x00FFFFFF);
                iText(1805,900,score_board,((void*)5));
                egggoldencntbool[j][i]=1;
            }
            eggcogoldeny[j][i]-=speed;
        }
        for(int i=0;i<8;i++)
        {
            if(limit[i]>limitgolden[i])
            {
                eggcntgolden[i]++;
                limit[i]=0;
                if(limitgolden[i]>30)
                limitgolden[i]--;
            }
            limit[i]++;
        }
        //egggreen
        for(int j=0;j<8;j++)
        for(int i=0;i<eggcntgreen[j];i++)
        {
            if((eggcogreenx[j][i]<busket_cox||eggcogreenx[j][i]>busket_cox+150)||eggcogreeny[j][i]>150)
            iShowBMP2(eggcogreenx[j][i],eggcogreeny[j][i],egg[2],0x00FFFFFF);
            else if(eggcogreenx[j][i]>busket_cox&&eggcogreenx[j][i]<busket_cox+150&&eggcogreeny[j][i]<=155&&eggcogreeny[j][i]>=100)
            {
                score+=15;
                gametime+=30;
                sprintf(score_board,"%d",score);
                iSetColor(r=255,g=0,b=0);
                iShowBMP2(1660,880,see_score[0],0x00FFFFFF);
                iText(1805,900,score_board,((void*)5));
                iShowBMP2(1660,980,timme[0],0x00FFFFFF);
                sprintf(game_time,"%d",gametime);
                iSetColor(r=255,g=0,b=0);
                iText(1805,1010,game_time,((void*)5));
            }
            eggcogreeny[j][i]-=60;
        }
        for(int i=0;i<8;i++)
        {
            if(limit4[i]>200)
            {
                eggcntgreen[i]++;
                limit4[i]=0;
                if(limitgreen[i]>30)
                limitgreen[i]--;
            }
            if(chgreen==0)
            limit4[i]++;
            chgreen=!chgreen;
        }
        //egggreen
        for(int j=0;j<8;j++)
        for(int i=0;i<shitcnt[j];i++)
        {
            if((shitx[j][i]<busket_cox||shitx[j][i]>busket_cox+150)||shity[j][i]>150)
              iShowBMP2(shitx[j][i],shity[j][i],chicken_shit[0],0x00FFFFFF);
            else if(shitx[j][i]>busket_cox&&shitx[j][i]<busket_cox+150&&shity[j][i]<=155&&shity[j][i]>=100&&shitcntbool[j][i]==0)
            {
                score-=30;
                sprintf(score_board,"%d",score);
                iSetColor(r=255,g=0,b=0);
                iShowBMP2(1660,880,see_score[0],0x00FFFFFF);
                iText(1805,900,score_board,((void*)5));
                shitcntbool[j][i]=1;
            }
            shity[j][i]-=speed;
        }
        for(int i=0;i<8;i++)
        {
            if(limit3[i]>limitshit[i])
            {
                shitcnt[i]++;
                limit3[i]=0;
                if(limitshit[i]>40)
                limitshit[i]--;
            }
            limit3[i]++;
        }
        for(int j=0;j<8;j++)
        for(int i=0;i<eggcntwhite[j];i++)
        {
            if((eggcowhitex[j][i]<busket_cox||eggcowhitex[j][i]>busket_cox+150)||eggcowhitey[j][i]>150)
            iShowBMP2(eggcowhitex[j][i],eggcowhitey[j][i],egg[0],0x00FFFFFF);
            else if(eggcowhitex[j][i]>busket_cox&&eggcowhitex[j][i]<busket_cox+150&&eggcowhitey[j][i]<=155&&eggcowhitey[j][i]>=100&&eggwhitecntbool[j][i]==0)
            {
                score+=10;
                sprintf(score_board,"%d",score);
                iSetColor(r=255,g=0,b=0);
                iShowBMP2(1660,880,see_score[0],0x00FFFFFF);
                iText(1805,900,score_board,((void*)5));
                eggwhitecntbool[j][i]=1;
            }
            eggcowhitey[j][i]-=speed;
        }
        for(int i=0;i<8;i++)
        {
            if(limit2[i]>limitwhite[i])
            {
                eggcntwhite[i]++;
                limit2[i]=0;
                if(limitwhite[i]>35)
                limitwhite[i]--;
            }
            limit2[i]++;
        }
        int sum=400;
        for(int i=0;i<5;i++)
        {
           int p=1660;
           int q=sum;
           iShowBMP2(p,q,button_pictures[i],0x00FFFFFF);
           sum+=100;
        }
        Sleep(25);
        sprintf(score_board,"%d",score);
        iSetColor(r=255,g=0,b=0);
        iShowBMP2(1660,880,see_score[0],0x00FFFFFF);
        iText(1805,900,score_board,((void*)5));
        iShowBMP2(1660,980,timme[0],0x00FFFFFF);
        sprintf(game_time,"%d",gametime);
        iSetColor(r=255,g=0,b=0);
        iText(1805,1010,game_time,((void*)5));
        gametime-=10;
        if(gametime==0)
            {
                gamestate=5;
                GET_HIGH_SCORE();
                if(levelmode==1&&score>highscore[0])
                highscore[0]=score;
                if(levelmode==2&&score>highscore[1])
                highscore[1]=score;
                if(levelmode==3&&score>highscore[2])
                highscore[2]=score;
                HIGH_SCORE();
            }
       if(check_sound==1)
         {

          iShowBMP2(1800,610,checksound[1],0x00FFFFFF);
         }
       if(check_sound==2)
        {
          iShowBMP2(1800,610,checksound[0],0x00FFFFFF);
        }
    }
    if(gamestate==5)
    {
        game_end();
    }
    if(gamestate==3)
    {
        level_button();
    }
    if(gamestate==0)
    {
        if(check_sound==1)
         {

          iShowBMP2(250,510,checksound[1],0x00FFFFFF);
         }
       if(check_sound==2)
        {
          iShowBMP2(250,510,checksound[0],0x00FFFFFF);
        }
    }
     if(gamestate==5)
    {

        if(check_sound==1)
         {

          iShowBMP2(980,515,checksound[1],0x00FFFFFF);
         }
       if(check_sound==2)
        {
          iShowBMP2(980,515,checksound[0],0x00FFFFFF);
        }
        int p=score;
        start_button();
        resume_button();
        score=p;
    }




}
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    if(gamestate!=10){
    busket_cox=mx+100;
    if(busket_cox>1900)
    busket_cox=1900;
    if(busket_cox<100)
        busket_cox=100;}

}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        printf("x = %d, y= %d\n",mx,my);
        mousecox=mx;mousecoy=my;
        if(mx>=575&&mx<=655&&my>=546&&my<=584&&gamestate==5)
            {
                gamestate=3;
                mouselight=1;
                mousecox=610;
                mousecoy=565;
            }
         if(mx>=572&&mx<=680&&my>=480&&my<=572&&gamestate==5)
            {
                gamestate=0;
                check_help_button=0;
                check_highscore=1;
                mouselight=1;
                mousecox=635;
                mousecoy=550;
            }
        if(mx>=575&&mx<=655&&my>=615&&my<=650&&gamestate==5)
           {
               resumeaction_button();
               exit(0);
           }
        if(mx>=575&&mx<=655&&my>=692&&my<=717&&gamestate==5)
            {
                sound_button();
                 mouselight=1;
                mousecox=620;
                mousecoy=705;
            }
        if(mx>=575&&mx<=655&&my>=754&&my<=790&&gamestate==5)
            {
                check_help_button=1;
                check_highscore=0;
                gamestate=0;
            }
        if(mx>=575&&mx<=655&&my>=824&&my<=854&&gamestate==5)
               {
                   score=0;
                   gamestate=1;
                   if(levelmode==1)
                   gametime=9000;
                   if(levelmode==2)
                    gametime=6000;
                   if(levelmode==3)
                    gametime=3000;
                   start_button();
               }
        if(mx>=575&&mx<=760&&my>=695&&my<=753&&gamestate==3)
            {
                speed=40;
                gametime=9000;
                levelmode=1;
                gamestate=1;
                score=0;
                gamestate=0;
            }
        if(mx>=575&&mx<=760&&my>=811&my<=864&&gamestate==3)
            {

                speed=50;
                gametime=6000;
                levelmode=2;
                gamestate=1;
                score=0;
                gamestate=0;
            }

        if(mx>=575&&mx<=760&&my>=915&&my<=968&&gamestate==3)
           {
               speed=60;
               gametime=3000;
              gamestate=1;
              levelmode=3;
              score=0;
              gamestate=0;
           }
        if(mx>=73&&mx<=165&&my>=546&&my<=584&&gamestate==0)
            {
                gamestate=3;
                 check_help_button=0;
                check_highscore=0;
            }
        if(mx>=73&&mx<=165&&my>=616&&my<=651&&gamestate==0)
            {

                check_help_button=0;
                check_highscore=0;
                exit(0);
            }
        if(mx>=73&&mx<=165&&my>=688&&my<=715&&gamestate==0)
            {
                sound_button();
                 mouselight=1;
                mousecox=130;
                mousecoy=705;
            }
        if(mx>=73&&mx<=165&&my>=754&&my<=794&&gamestate==0)
            {
                check_help_button=1;
                check_highscore=0;
            }
        if(mx>=73&&mx<=187&&my>=480&&my<=513&&gamestate==0)
            {
                check_highscore=1;
                check_help_button=0;
            }
        if(mx>=73&&mx<=165&&my>=892&&my<=929&&gamestate==0)
            {
                check_help_button=0;
                check_highscore=0;
                start_button();
                gamestate=1;
            }
        if(mx>=73&&mx<=165&&my>=822&&my<=857&&gamestate==0)
           {
               check_help_button=0;
               check_highscore=0;
               resumeaction_button();
               gamestate=10;
           }
      if(mx>=1190&&mx<=1270&&my>=689&&my<=720&&gamestate==1)
            {
                check_help_button=0;
                check_highscore=0;
                resume_button();
                GET_HIGH_SCORE();
                if(levelmode==1&&score>highscore[0])
                highscore[0]=score;
                if(levelmode==2&&score>highscore[1])
                highscore[1]=score;
                if(levelmode==3&&score>highscore[2])
                highscore[2]=score;
                HIGH_SCORE();
                exit(0);
            }
        if(mx>=1190&&mx<=1270&&my>=762&&my<=786&&gamestate==1)
            {
                sound_button();
                 mouselight=1;
                mousecox=1235;
                mousecoy=746;
            }
        if(mx>=1190&&mx<=1270&&my>=616&&my<653&&gamestate==1)
            {
                gamestate=3;
            }
        if(mx>=1190&&mx<=1270&&my>=824&&my<=854&&gamestate==1)
            {
                check_help_button=1;
                check_highscore=0;
                resume_button();
                gamestate=0;
            }
        if(mx>=1190&&mx<=1270&&my>=899&&my<=928&&gamestate==1)
           {
               resume_button();
               gamestate=0;
           }
      if(mx>=1190&&mx<=1270&&my>=616&&my<=652&&gamestate==10)
            {
                check_help_button=0;
                check_highscore=0;
                resume_button();
                GET_HIGH_SCORE();
                if(levelmode==1&&score>highscore[0])
                highscore[0]=score;
                if(levelmode==2&&score>highscore[1])
                highscore[1]=score;
                if(levelmode==3&&score>highscore[2])
                highscore[2]=score;
                HIGH_SCORE();
                exit(0);
            }
        if(mx>=1190&&mx<=1270&&my>=689&&my<=711&&gamestate==10)
            {
                sound_button();
                mouselight=1;
                mousecox=1235;
                mousecoy=700;
            }
        if(mx>=1190&&mx<=1270&&my>=547&&my<582&&gamestate==10)
            {
                gamestate=3;
            }
        if(mx>=1190&&mx<=1270&&my>=755&&my<=786&&gamestate==10)
            {
                check_help_button=1;
                check_highscore=0;
                resume_button();
                gamestate=0;
            }
        if(mx>=1190&&mx<=1270&&my>=825&&my<=858&&gamestate==10)
           {
               resume_button();
               gamestate=0;
           }
        if(mx>=1190&&mx<=1270&&my>=895&&my<=928&&gamestate==10)
           {
               gamestate=1;
                mouselight=1;
                mousecox=1235;
                mousecoy=910;
           }



    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x -= 5;
        y -= 5;
    }

}
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
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

}


int main()
{
    iSetTimer(25,change);
   if(music_start_homepage)
        PlaySound("chicken.wav",NULL,SND_LOOP|SND_ASYNC);
    iInitialize(1920,1080, "Demo!");
    return 0;
}
