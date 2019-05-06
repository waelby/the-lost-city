#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
#include "animation.h"


void scroll1(SDL_Surface *ecran,SDL_Surface *imageDeFond ,int *continuer,SDL_Rect positionFond,int save)
     {

    SDL_Surface *sprite=NULL , *sprite2=NULL , *sprite3=NULL ; 
    int running=1  ; 
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =720;
    positionFond.w =1280 ;
    SDL_Surface *mask ;
    mask=IMG_Load("mask13.png") ;
    imageDeFond = IMG_Load("map.png")  ;
   
  SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);              


    

    SDL_Event event;
   // SDL_EnableKeyRepeat(100,100) ; 


         animate(ecran,sprite,sprite2,sprite3,imageDeFond,positionFond,continuer,mask,save) ; 
        SDL_PollEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:

        switch(event.key.keysym.sym)
    
        {
      case SDLK_ESCAPE : 
continuer=0 ; 
running=0 ; 
break ; 
            case SDLK_RIGHT: // Flèche droite
        

         SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
 

                break;

            case SDLK_LEFT: // Flèche gauche
        animate(ecran,sprite,sprite2,sprite3,imageDeFond,positionFond,continuer,mask,save) ; 


     
         
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL );
				
                


                break;
              

        }

        break;    
        }
        
       
        
    SDL_Flip(ecran);
    
}
