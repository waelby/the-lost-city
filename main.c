//Les attributs de l'écran (640 * 480)
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
 
//Les attributs de la feuille de sprites (200 * 200)
const int SHEET_WIDTH = 200;
const int SHEET_HEIGHT = 200;
 
//Les surfaces
SDL_Surface *faces = NULL;
SDL_Surface *screen = NULL;
 
//La structure d'événements
SDL_Event event;
 
//Les différentes parties de la feuille de sprites qui vont être blittés
SDL_Rect clip[ 4 ];
