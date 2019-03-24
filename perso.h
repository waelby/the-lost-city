#ifndef _perso_H_
    #define _perso_H_
 
#include <SDL.h>

//Notre personnage
class AGENT
{
    private:
    //coordonnées
    int offSet;

    //sa vitesse de deplacement
    int velocity;

    //sa frame courante
    int frame;

    //Son statut d'animation
    int status;

    public:
    //Le constructeur permettant l'initialisation des variables
    AGENT();
    
    
    void handle_events();

    //montrer le personnage
    void affichage();
};






