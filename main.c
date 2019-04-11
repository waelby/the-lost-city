#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
int main(void)
{
ecran ecran; 
score score;
rock r;
perso p;
int v=0;
int done=1;
int detection;
SDL_Surface* imagev1;
SDL_Surface* imagev2;
SDL_Surface* imagev3;
SDL_Event *felsa;
SDL_Rect positionecran,positionecran1,positionv1,positionv2,positionv3;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
score.sscore=0;
score.vie=1;
if( SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unabel to initialize SDL:%s\n",SDL_GetError());
return (-1);
}

ecran.screen=SDL_SetVideoMode(1800,400,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
ecran.image=SDL_LoadBMP("background.bmp");

ecran.positionecran.x=0;
ecran.positionecran.y=0;
ecran.positionecran.w=ecran.image->w;
ecran.positionecran.h=ecran.image->h;
ecran.positionecran1.x=0;
ecran.positionecran1.y=0;
ecran.positionecran1.w=ecran.image->w;
ecran.positionecran1.h=ecran.image->h;

positionv1.x=340;
positionv1.y=0;
positionv2.x=390;
positionv2.y=0;
positionv3.x=440;
positionv3.y=0;

r.posrock.x=500;
r.posrock.y=300;
r.posrock.w=r.imagerock->w;
r.posrock.h=r.imagerock->h;
p.posper.x=20;
p.posper.y=260;
p.posper.w=p.imageper->w;
p.posper.h=p.imageper->h;
score.position_score.x=60;
score.position_score.y=0;

imagev1=IMG_Load("imagevie1.png");
imagev2=IMG_Load("imagevie2.png");
imagev3=IMG_Load("imagevie3.png");
p.imageper=IMG_Load("imagep.png");
r.imagerock=IMG_Load("imager.png");

SDL_BlitSurface(ecran.image,&ecran.positionecran1,ecran.screen,&ecran.positionecran);
SDL_BlitSurface(p.imageper,NULL,ecran.screen,&p.posper);
SDL_BlitSurface(r.imagerock,NULL,ecran.screen,&r.posrock);
while(done)
{
SDL_PollEvent(&event);
deplacement(&p,event,done,&detection,&r,felsa,ecran);
   switch(event.type) 
    {
       case SDL_QUIT: 
         done = 0; 
        SDL_Quit();
          break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                         score.vie=score.vie+1;
                          break;                  
                    case SDLK_2:                                                 
                         score.vie=score.vie-1;
                          break;                                               
                    case SDLK_3: 
                       score.sscore=score.sscore+10;
                         break;
                    case SDLK_4: 
                       score.sscore=score.sscore-5;
                        break;
                 }
     break;
  }
v=vie(&score,v);
initialiser_score(&score,ecran);
times(&score,ecran);
switch(v)
{
case 1: 
SDL_BlitSurface(ecran.image,&ecran.positionecran1,ecran.screen,&ecran.positionecran);
SDL_BlitSurface(p.imageper,NULL,ecran.screen,&p.posper);
SDL_BlitSurface(r.imagerock,NULL,ecran.screen,&r.posrock);
SDL_BlitSurface(imagev1,NULL,ecran.screen,&positionv1);
SDL_BlitSurface(imagev2,NULL,ecran.screen,&positionv2);
SDL_BlitSurface(imagev3,NULL,ecran.screen,&positionv3);

break;
case 2:
SDL_BlitSurface(ecran.image,&ecran.positionecran1,ecran.screen,&ecran.positionecran);
SDL_BlitSurface(p.imageper,NULL,ecran.screen,&p.posper);
SDL_BlitSurface(r.imagerock,NULL,ecran.screen,&r.posrock);
SDL_BlitSurface(imagev1,NULL,ecran.screen,&positionv2);
SDL_BlitSurface(imagev2,NULL,ecran.screen,&positionv3);
break;
case 3:
SDL_BlitSurface(ecran.image,&ecran.positionecran1,ecran.screen,&ecran.positionecran);
SDL_BlitSurface(p.imageper,NULL,ecran.screen,&p.posper);
SDL_BlitSurface(r.imagerock,NULL,ecran.screen,&r.posrock);
SDL_BlitSurface(imagev1,NULL,ecran.screen,&positionv3);
break;
}
score.vie=0;
}

SDL_Quit();
return 0;
}
