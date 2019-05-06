#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "animation.h"

void init_enigme(Perso * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->image=NULL ;

}

 void generate_afficher (SDL_Surface * screen  , char image [],Perso *e,int *alea)
{ 
  
	int test=*alea ;
 do{
 *alea = 1+rand()%3;
 }while(*alea==test) ;
  
 sprintf(image ,"%d.jpg",*alea);
 e->image= IMG_Load(image);
 SDL_BlitSurface(e->image,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
	
}
 
 int solution_e (char image [])
 {
 	int solution =0 ;

 	if(strcmp(image,"1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution =1;	
 	}

 	return solution;
 }

int resolution (int * running,int *run )
{

	SDL_Event event ;
  int r=0 ;
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_b :
			   r= 2;
			   break;
			   case SDLK_c: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}

  return r ;
}
 
 void afficher_resultat (SDL_Surface * screen,int s,int r,Perso *en)
 {
 
 	if (r==s)
 	{
 		en->image=IMG_Load("000.jpg");
 		SDL_BlitSurface(en->image, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->image=IMG_Load("11.jpg");
 		SDL_BlitSurface(en->image, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 }
void update_fonts(int *tempsActuel,int *tempsPrecedent,int *compteurr,int *seconde,char temps [],char score [],int *score_finale,SDL_Surface **texte,SDL_Surface **gestion_score,TTF_Font *police,SDL_Color couleurBlanche,int  *minute )
{
 int heure = 0  ;	
                         (*tempsActuel) = SDL_GetTicks();
                       if ((*tempsActuel) -  (*tempsPrecedent) >= 1000) 
                      {
/*                        (*compteurr) += 100; 
                       if((*compteurr) % 1000<=0)
                         { */
													 
                            (*seconde) +=1 ;
                             if((*seconde) %10==0)
                              (*score_finale)-=10 ;
															 if(*seconde==60)
															   {
																	 (*seconde)=0 ;
																	  *minute= 1 ;
																 }
                        // }
                           sprintf(temps, " %d: %d: %d",heure,*minute, *seconde); 
                          sprintf(score, "Score: %d", *score_finale); 
													
                          SDL_FreeSurface(*texte); 
                          SDL_FreeSurface(*gestion_score);    
                          (*gestion_score)=TTF_RenderText_Blended(police,score, couleurBlanche) ;  
                          (*texte) = TTF_RenderText_Blended(police, temps, couleurBlanche); 
                          (*tempsPrecedent) = (*tempsActuel);  

                      }
                        
}
