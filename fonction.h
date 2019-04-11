
#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
SDL_Surface *screen;
SDL_Surface *image;
SDL_Rect positionecran;
}ecran;

typedef struct 
{
TTF_Font *font;
SDL_Surface *score;
SDL_Rect position_score;
int sscore;
int vie;
TTF_Font *fonte;
SDL_Surface * temp;
SDL_Rect postime;
int suiv,prec,tmp;
}score; 

SDL_Surface* Init_imagedefond( ecran *image ,ecran *positionecran,  int x , int y) ;
void Show_imagedefond (ecran *image , ecran *screen ,  ecran positionecran  ) ;
void initialiser_score(score *score,ecran ecran);
int vie(score *score, int v);
void times(score *score,ecran ecran);
#endif // JEU_H_INCLUDED
