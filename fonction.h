
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeux.h"

SDL_Surface * Init_imagedefond( ecran *image ,ecran *positionecran ,  int x , int y) 
 {
	       ecran.image =  IMG_Load("map.png"); 

	      if  ( ecran.image==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
                  } 
     else 
     {
 
     positionecran->x  =  x ; 
     positionecran->y  = y ;
     positionecran->h= ecran.image->h ;
     positionecran->w= ecran.image->w ;  
       }
     
     return (ecran.image) ; 
}

 void Show_imagedefond (ecran *image, SDL_Surface *screen,ecran positionecran ) 
  {

	 SDL_BlitSurface(ecran.image, NULL, ecran.screen, &ecran.positionecran);
   }



      /* Quitte la SDL */
      SDL_Quit();


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
SDL_Delay(1000);
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
