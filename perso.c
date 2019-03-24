void set_clips()
{
    //On coupe la feuille de sprite
    clipsRight[ 0 ].x = 0;
    clipsRight[ 0 ].y = 0;
    clipsRight[ 0 ].w = AGENT_WIDTH;
    clipsRight[ 0 ].h = AGENT_HEIGHT;

    clipsRight[ 1 ].x = AGENT_WIDTH;
    clipsRight[ 1 ].y = 0;
    clipsRight[ 1 ].w =  AGENT_WIDTH;
    clipsRight[ 1 ].h =  AGENT_HEIGHT;

    clipsRight[ 2 ].x =  AGENT_WIDTH * 2;
    clipsRight[ 2 ].y = 0;
    clipsRight[ 2 ].w =  AGENT_WIDTH;
    clipsRight[ 2 ].h =  AGENT_HEIGHT;

    clipsLeft[ 0 ].x = 0;
    clipsLeft[ 0 ].y =  AGENT_HEIGHT;
    clipsLeft[ 0 ].w =  AGENT_WIDTH;
    clipsLeft[ 0 ].h =  AGENT_HEIGHT;

    clipsLeft[ 1 ].x =  AGENT_WIDTH;
    clipsLeft[ 1 ].y = AGENT_HEIGHT;
    clipsLeft[ 1 ].w = AGENT_WIDTH;
    clipsLeft[ 1 ].h =  AGENT_HEIGHT;

    clipsLeft[ 2 ].x =  AGENT_WIDTH * 2;
    clipsLeft[ 2 ].y =  AGENT_HEIGHT;
    clipsLeft[ 2 ].w =  AGENT_WIDTH;
    clipsLeft[ 2 ].h =  AGENT_HEIGHT;
}

AGENT::AGENT()
{
    //Initialisation des variables de mouvement
    offSet = 0;
    velocity = 0;

    //Initialisation des variables d'animation
    frame = 0;
    status = AGENT_RIGHT;
}

void AGENT::handle_events()
{
    //Si une touche est préssée
    if( event.type == SDL_KEYDOWN )
    {
        //Mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity += AGENT_WIDTH / 4; break;
            case SDLK_LEFT: velocity -= AGENT_WIDTH / 4; break;
            default: break;
        }
    }

void AGENT::show()
{
    //Mouvement
    offSet += velocity;

    //On garde le personnage dans les limites de la fenêtre SDL
    if( offSet < 0 ) 
    {
        offSet = 0;
    }
    if( offSet + AGENT_WIDTH > SCREEN_WIDTH ) 
    {
        offset = SCREEN_WIDTH - AGENT_WIDTH;
    }
    //Si agent bouge à gauche
    if( velocity < 0 )
    {
        //On prend le personnage de profil gauche
        status = CAT_LEFT;

        //On bouge à la prochaine image de l'animation
        frame++;
    }
    //Si Cat bouge à droite
    else if( velocity > 0 )
    {
        //On prend le personnage de profil droit
        status = AGENT_RIGHT;

        //On bouge à la prochaine image de l'animation
        frame++;
    }
    //Si agent ne bouge plus
    else
    {
        //Restart the animation
        frame = 1;
    }
    //Boucle l'animation
    if( frame >= 3 )
    {
        frame = 0;
    }
    //Affichage
    if( status == AGENT_RIGHT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - AGENT_HEIGHT, agent, screen, &clipsRight[ frame ] );
    }
    else if( status == CAT_LEFT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - AGENT_HEIGHT, agent, screen, &clipsLeft[ frame ] );
    }
