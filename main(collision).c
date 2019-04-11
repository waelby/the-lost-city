#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int main()
{
    SDL_Surface *screen , *image , *background, *background_mask;
    SDL_Rect position1 ;
    int BOOM=0,dunno=0,count=0;


     if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  {
         printf ( "Can not init SDL \n " );

     }

     screen  =  SDL_SetVideoMode ( 1920 ,  1080 ,  16 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF );
     if  ( screen  ==  NULL )  {
         printf ( "Can not set video mode: \n ");


    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  90 ,  102 ));
    SDL_WM_SetCaption("Welcome  ------- ", NULL);

    while (dunno=0)
    {
        printf("can not load map %d fois",count);
        count++;
        dunno = load_files(SDL_Surface **background, SDL_Surface **imageDeFondCollision);
    }

     image1  =  IMG_Load( "image.png" );
     if  ( image1  ==  NULL )  {
         printf ( "Can not load image: %s \n " , SDL_GetError ());
         exit ( 1 );
         position1.x  =  600 ;
     position1.y  =  500 ;
     position1.w  =  image -> w ;
     position1.h  =  image -> h ;
         SDL_BlitSurface(image, NULL , screen, &position1);
          SDL_Flip(screen);

          hile  ( done==0 )  {
         while  (SDL_PollEvent ( &event ))  {
             switch  ( event.type )  {
             case  SDL_QUIT :
                 done  =  1 ;
                 break ;

             case SDL_KEYDOWN :
                     switch( event.key.keysym.sym )
                        {
							case SDLK_RIGHT :
							position1.x+=50;
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  90 ,  102 ));
							             SDL_BlitSurface(image, NULL, screen, &position1);
          SDL_Flip(screen);
							break ;
							case SDLK_LEFT :
							position1.x-=50 ;

							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  10,  90 ,  102 ));
							             SDL_BlitSurface(image, NULL, screen, &position1);
          SDL_Flip(screen);
							break ;

							BOOM = detecter_collision_background (&image,position1,&background_mask);
							if {BOOM=1)
							{
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  199, 199 , 199 ));
							    SDL_Flip(screen);
							}

    return 0;
}
