


SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char* ) background_mask->pixels;
pPosition+= (background_mask->pitch * y);
pPosition+= (background_mask->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,background_mask->format->BytesPerPixel);
SDL_GetRGB(col,background_mask->format, &color.r, &color.g, &color.b);
return (color);
}

int detecter_collision_background (SDL_Surface *image, SDL_Rect position,SDL_Surface *background_mask)
{
  SDL_Color color[9];
  color [0] = GetPixel (image, position.x, position.y);
  color [1] = GetPixel (image, position.(x+w) /2, position.y);
  color [2] = GetPixel (image, position.x +w, position.y);
  color [3] = GetPixel (image, position.x, position.y +h /2);
  color [4] = GetPixel (image, position.x, position.y +h);
  color [5] = GetPixel (image, position.x +w /2, position.y+h);
  color [6] = GetPixel (image, position.x +w, position.y +h);
  color [7] = GetPixel (image, position.x +w, position.y +h /2);
  for (int i=0;i<8;i++)
  {
  if (color[i].r==255 && color[i].g==255 && color[i].b==255) return 1;
  }
  else {
  return 0;
  }
}
int load_files(SDL_Surface **background, SDL_Surface **imageDeFondCollision)
{
    *background = load_image( "map1.pbm" );
    *background_mask = load_image("map1mask.pbm");
    if( *background == NULL ) || ( *background_mask == NULL )
    {
        return 0;
    }
    return 1;
}
