#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

void initialiser_score(score *score,ecran ecran)
{
TTF_Init();
score->font=TTF_OpenFont("BebasNeue-Book.ttf", 50);
SDL_Color color={255,0,0};
char ch[10];
score->sscore;
sprintf(ch,"%d XP",score->sscore);
score->score=TTF_RenderText_Solid(score->font,ch,color);
SDL_BlitSurface(score->score,NULL,ecran.screen,&score->position_score);
SDL_Delay(100);
SDL_Flip(ecran.screen);
TTF_Quit();
}

int vie(score *score , int v)
{
    if (score->vie==1)
          {
         if(v<3)
                v++;
          }
      else
          if(score->vie==-1)
              v--;
                 else
                    return v;
 return v;
}

int collision (perso *p, rock *r)
{
if (p->posper.y>=r->posrock.y+r->posrock.h)
return 0;
if (p->posper.x>=r->posrock.x+r->posrock.w)
return 0;
if (p->posper.y+p->posper.h<=r->posrock.y)
return 0 ;
if (p->posper.x+p->posper.w<=r->posrock.x)
return 0 ;
return 1 ;
}

void deplacement(perso *p,SDL_Event event,int done,int *detection,rock *r,SDL_Event *felsa ,ecran ecran)
{
while(SDL_PollEvent(&event))
{switch(event.type)
 { case SDL_QUIT:
    done=0;
   break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
     {
      case  SDLK_UP:
      
           if(*detection==0)
          {
          p->posper.y-=4;
         *detection=collision(p,r);
      
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.y-=4;
         *detection=collision(p,r);
         
         }
         
         felsa->key.keysym.sym=event.key.keysym.sym;
        break;
       case SDLK_DOWN:
         
           if(*detection==0)
          {
          p->posper.y+=4;
         *detection=collision(p,r);
         
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.y+=4;
         *detection=collision(p,r);
       
         }
        
         felsa->key.keysym.sym=event.key.keysym.sym;
        break;
       case SDLK_RIGHT:
         
            if(*detection==0)
          {
          p->posper.x+= 4;
         *detection=collision(p,r);
         
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.x+= 4;
         *detection=collision(p,r);
        
         }
         

         felsa->key.keysym.sym=event.key.keysym.sym;


        break;
       case SDLK_LEFT:
            
            if(*detection==0)
          {
          p->posper.x-= 4;
         *detection=collision(p,r);
   
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.x-= 4;
         *detection=collision(p,r);
      
         }
        
         felsa->key.keysym.sym=event.key.keysym.sym;


         break;
}
}
}
}


void times(score *score,ecran ecran)
{
TTF_Init();
char ch[50];
score->fonte=TTF_OpenFont("BebasNeue-Book.ttf", 70);
SDL_Color color={255,0,0};
score->suiv = SDL_GetTicks();
if (score->suiv - score->prec>=1000)
{
score->tmp ++;
if (score->tmp<10)
{
sprintf(ch,"00:0%d",score->tmp);
}
else if (score->tmp==10)
{
sprintf(ch,"00:%d",score->tmp);
}
score->prec=score->suiv;
}
score->temp=TTF_RenderText_Solid(score->fonte,ch,color);
SDL_BlitSurface(score->temp,NULL,ecran.screen,&score->postime);
if (score->tmp==10)
{ 
score->tmp = 0 ;
TTF_Quit();
}
}
    
