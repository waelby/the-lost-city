#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"fonction.h"

void setrects_right(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=00;
clip[0].w=45;
clip[0].h=256;

clip[1].x=70;
clip[1].y=0;
clip[1].w=45;
clip[1].h=256;

clip[2].x=140;
clip[2].y=0;
clip[2].w=45;
clip[2].h=256;

clip[3].x=200;
clip[3].y=0;
clip[3].w=45;
clip[3].h=256;

clip[4].x=250;
clip[4].y=0;
clip[4].w=45;
clip[4].h=256;

clip[5].x=250;
clip[5].y=0;
clip[5].w=45;
clip[5].h=256;



}

void setrects_left(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=00;
clip[0].w=45;
clip[0].h=256;

clip[1].x=70;
clip[1].y=0;
clip[1].w=45;
clip[1].h=256;

clip[2].x=140;
clip[2].y=0;
clip[2].w=45;
clip[2].h=256;

clip[3].x=200;
clip[3].y=0;
clip[3].w=45;
clip[3].h=256;

clip[4].x=250;
clip[4].y=0;
clip[4].w=45;
clip[4].h=256;

clip[5].x=250;
clip[5].y=0;
clip[5].w=45;
clip[5].h=256;


}
void scrollingleft(SDL_Rect *rect , SDL_Rect *positionFond )
     {

  

 if ( rect->x==0 )
{
 positionFond->x-=320;
rect->x=80-rect->x ; 

}



}
void scrollingright(SDL_Rect *rect , SDL_Rect *positionFond )
     {

  

  if ((( rect->x>=160 )||(rect->x>=320))&&(positionFond->x<3840))
{
 positionFond->x+=160;
rect->x=0 ; 

}

}
void animation(acteur *acteur){
int tempsPrecedent = 0, tempsActuel = 0;
char temps[20];
SDL_Rect camera1,back1,camera2,back2;
SDL_Init(SDL_INIT_VIDEO);
acteur->screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
acteur->background1=IMG_Load( "map1.png" );
acteur->background2=IMG_Load( "map2.png" ); 
acteur->frame=0;
acteur->running=1;
acteur->image=IMG_Load("image1.png");
acteur->image2=IMG_Load("image2.png");
acteur->rect.x=200;
acteur->rect.y=100;

acteur->rect2.x=300;
acteur->rect2.y=100;

back1.x=0;
back1.y=0;


camera1.x=0;
camera1.y=(720-480)/2; 
camera1.h=480 ; 
camera1.w=640/2 ;

back2.x=320;
back2.y=0;

camera2.x=320;
camera2.y=0; 
camera2.h=480 ; 
camera2.w=320 ;


SDL_FillRect(acteur->screen,&acteur->screen->clip_rect,0x00);
//SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));
SDL_BlitSurface ( acteur->background1 ,  &camera1 ,  acteur->screen ,  NULL); 
SDL_Flip(acteur->screen);
//SDL_BlitSurface ( acteur->background2 ,  &camera2 ,  acteur->screen ,  NULL); 
SDL_Flip(acteur->screen);
SDL_EnableKeyRepeat(100,100);

while (acteur->running)
    {
        SDL_WaitEvent(&acteur->event);
        switch(acteur->event.type)
        {
            case SDL_QUIT:
                acteur->running = 0;
                break;
            case SDL_KEYDOWN:
                switch(acteur->event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Flèche droite
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){
                        acteur->rect.x=10+acteur->rect.x;
 scrollingright(&(acteur->rect) , &camera1) ;
setrects_right(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0;
}	
tempsPrecedent = tempsActuel;
}	
                        break;
                    case SDLK_LEFT: // Flèche gauche
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){
                        acteur->rect.x=-10+acteur->rect.x;
 scrollingleft(&(acteur->rect) , &camera1) ;
setrects_left(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0;
}
tempsPrecedent = tempsActuel;
}


                        break;
                }
                break;
        }
SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));
SDL_BlitSurface ( acteur->background1 ,  &camera1 ,  acteur->screen ,  NULL); 
SDL_BlitSurface ( acteur->background2 ,  NULL ,  acteur->screen ,&back2); 
SDL_BlitSurface(acteur->image,&acteur->rects[acteur->frame],acteur->screen,&acteur->rect);
SDL_BlitSurface(acteur->image2,NULL,acteur->screen,&(acteur->rect2));
SDL_Flip(acteur->screen);
}
}
