#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y);
int detecter_collision_background (SDL_Surface *image, SDL_Rect position,SDL_Surface *background_mask);

#endif // HEAD_H_INCLUDED
