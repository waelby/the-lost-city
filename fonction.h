#ifndef JEUX
#define JEUX
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
SDL_Surface *screen;
SDL_Surface *image;
SDL_Rect positionecran,positionecran1;
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

typedef struct
{
SDL_Surface* imageper;
SDL_Rect posper;
}perso;
typedef struct
{
SDL_Surface* imagerock;
SDL_Rect posrock;
}rock;


void initialiser_score(score *score,ecran ecran);
int vie(score *score, int v);
int collision (perso *p, rock *r);
void deplacement(perso *p,SDL_Event event,int done,int *detection,rock *r,SDL_Event *felsa ,ecran ecran);
void times(score *score,ecran ecran);
#endif
