/* ********************************************************************* */
/*Fichiers d'ent�te inclus*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL.h>
#include <ctime>
#include <SDL_ttf.h>

/* ********************************************************************* */
/*Prototypes*/
/*Les commentaires sont dans les corps de fonction*/

/*Fonction de modification d'image*/
void balanceDesCouleurs(SDL_Surface *surface, int rAjout, int gAjout, int bAjout);

/*Fonctions utilis�es par la fonction de modification d'image*/
Uint8 addVal(Uint8 composante, int valeur);
Uint32 obtenirPixel(SDL_Surface *surface, int x, int y);
void definirPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
int Nbreturn(Uint8 composante, int valeur);

/* ********************************************************************* */
/*main : fonction principale*/
int main(int argc, char **argv)
{

    /* ************D�claration des variables************ */

    /*On d�clare les trois surfaces qui vont nous servir :*/
    /*L'�cran, et l'image originale et l'image � modifier*/
    srand(time(0));
    SDL_Surface *ecran = NULL, *imgOriginale = NULL, *imgBalanceCouleurs = NULL;
    SDL_Event event;

    /*Pour positionner les images*/
    SDL_Rect position;
    int continuer(1);
    Uint16 rouge(0);
    Uint16 vert(0);
    Uint16 bleu(0);
    /* ************Initialisation*********************** */

    /*On initialise la SDL.*/
    SDL_Init(SDL_INIT_VIDEO);


    /*On initialise l'�cran*/
    ecran = SDL_SetVideoMode(600, 600, 32,  SDL_ANYFORMAT |
                                            SDL_HWSURFACE );

    /*On change le titre de la fen�tre*/
    SDL_WM_SetCaption("Balance des couleurs", NULL);

    /*On charge notre image, notez qu'elle fait 200*200 pixels*/
    imgOriginale = IMG_Load("bloon_1.png");
    //imgOriginale=IMG_Load_RW(SDL_RWFromFile("bomber.png", "rb"), 1);
    if(!imgOriginale)
    {
        printf("IMG_Load_RW: %s\n", IMG_GetError());
    }
    //SDL_SetColorKey(imgOriginale , SDL_SRCCOLORKEY , SDL_MapRGB(imgOriginale->format , 0 , 0 , 0));

    /*On cr�� une surface vide de 200*200 pixels dans l'image*/
    /*Notez que cette image n'aura pas besoin de transparence alpha, les 4 derniers param�tres sont donc � 0*/
    imgBalanceCouleurs = SDL_CreateRGBSurface(SDL_HWSURFACE, imgOriginale->w, imgOriginale->h, 32, 0, 0, 0, SDL_SRCALPHA);

    /*On y copie ensuite l'image originale*/

    /* ************Modification de l'image************** */

    /*On traite l'image*/
    /*La balance des couleurs va enlever 10 en rouge, ajouter 100 en bleu et 20 en vert.*/
    vert = rand()%254;
    bleu = rand()%254;
     while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_KEYDOWN: /* Si appui sur une touche */
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        rouge++;
                        break;
                    case SDLK_LEFT:
                        rouge--;
                        break;
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                    case SDLK_r:
                        break;
                    case SDLK_s:
                        continuer = 0;
                    default:
                        break;
                }
            default:
                break;
        }
        /*
        rouge= rand()%254;
        vert = rand()%254;
        bleu = rand()%254;
        //*/
        SDL_BlitSurface(imgOriginale, NULL, imgBalanceCouleurs, NULL);
        balanceDesCouleurs(imgBalanceCouleurs, 0 , 0 , 0);

        /* ************Affichage du r�sultat**************** */

        /*Position de l'image originale dans l'�cran.*/
        position.x=0;
        position.y=0;
        /*On copie l'image originale dans l'�cran*/
        SDL_FillRect(ecran , 0 , SDL_MapRGB(ecran->format , 255 , 255 , 255));
        SDL_BlitSurface(imgOriginale, NULL, ecran, &position);

        /*Position de l'image modifi�e*/
        //position.x= imgOriginale->w + 10;
        position.x=0;
        position.y=imgOriginale->h + 10;
        /*On copie l'image modifi�e dans l'�cran*/
        //SDL_SetColorKey(imgBalanceCouleurs , SDL_SRCCOLORKEY , SDL_MapRGB(imgBalanceCouleurs->format , 0 , 0 , 255));
        SDL_BlitSurface(imgBalanceCouleurs, NULL, ecran, &position);

        SDL_Flip(ecran);
        if(rouge < 0)
            rouge=0;
        if(rouge > 255)
            rouge=255;
        SDL_SaveBMP(imgBalanceCouleurs , "bloon_3.bmp");
        continuer = 0;
    }

    /*Une fois les images affich�es, on n'a plus besoin d'elles*/
    //SDL_SaveBMP(imgBalanceCouleurs , "tank_2.bmp");
    SDL_FreeSurface(imgOriginale);
    SDL_FreeSurface(imgBalanceCouleurs);
    SDL_Quit();

    return EXIT_SUCCESS;

}

/* ********************************************************************* */
/*balanceDesCouleurs : permet d'ajouter ou d'enlever de la couleur � toute l'image.
Param�tres d'entr�e/sortie :
SDL_Surface *surface : la surface � modifier
int rAjout : La quantit� de rouge que l'on veut ajouter ou soustraire (entre -255 et +255)
int gAjout : La quantit� de vert que l'on veut ajouter ou soustraire (entre -255 et +255)
int bAjout : La quantit� de bleu que l'on veut ajouter ou soustraire (entre -255 et +255)
*/
void balanceDesCouleurs(SDL_Surface *surface, int rAjout, int gAjout, int bAjout)
{
    /*x et y sont les index permettant de se d�placer dans l'image*/
    int x,y;
    int inter(0);
    /*r,g,b,a vont stocker les composantes d'un pixel*/
    Uint8 r,g,b,a;
    /*pixel stocke le code couleur d'un pixel*/
    Uint32 pixel;

    /*On bloque la surface pour pouvoir travailler dessus */
    SDL_LockSurface(surface);
    /*Double boucle pour parcourir l'int�gralit� de l'image.*/
    for (y=0;y<surface->h;y++)
    {
        for (x=0;x<surface->w;x++)
        {
            /*On r�cup�re le code couleur du pixel.*/
            pixel=obtenirPixel(surface,x,y);
            /*On extrait les composantes rouge, vert, bleu et alpha*/
            SDL_GetRGBA(pixel, surface->format, &r, &g, &b, &a);

            /*On ajoute/soustrait la quantit� voulue aux 3 composantes rouge, vert, bleu.*/
            /*
            if(r>=200 && g>=200 && b>=200)
            {
                r = rAjout;
                r += rand()%10;
                b = r;
                g = r;
                a=0;
            }
            */

            if(r==255 && g==255 && b==255)
            {

            }

            else
            {
                inter = g;
                b=b;
                g=r;
                r=inter;
                //b=b;
                //g=g;
            }

            /*On retransforme les 4 composantes en un seul code couleur dans pixel */
            pixel=SDL_MapRGBA(surface->format, r, g, b, a);
            /*On injecte le code couleur pixel dans le pixel correspondant*/
            definirPixel(surface, x, y, pixel);
        }
    }
    /*On lib�re la surface, elle peut d�sormais �tre r�utilis�e pour autre chose*/
    SDL_UnlockSurface(surface);
}

/* ********************************************************************* */
/*addVal : ajoute une certaine valeur � une composante
en restant dans l'intervalle [0,255]
Param�tres d'entr�e/sortie :
Uint8 composante : la composante � modifier
int valeur : la valeur � ajouter ou enlever
*/
Uint8 addVal(Uint8 composante, int valeur)
{
    int tampon; /*Variable enti�re qui sert de tampon*/
    tampon=(int)composante + valeur;

    /*On fait en sorte que tampon reste dans l'intervalle [0,255] */
    while(tampon>255)
    {
        tampon-=255;
    }
    while(tampon<0)
    {
        tampon+=255;
    }

    /*Avec l'op�rateur cast (Uint8) on tranforme tampon en un entier de type Uint8*/
    return (Uint8)tampon;
}

/* ********************************************************************* */
/*obtenirPixel : permet de r�cup�rer la couleur d'un pixel
Param�tres d'entr�e/sortie :
SDL_Surface *surface : la surface sur laquelle on va r�cup�rer la couleur d'un pixel
int x : la coordonn�e en x du pixel � r�cup�rer
int y : la coordonn�e en y du pixel � r�cup�rer

Uint32 resultat : la fonction renvoie le pixel aux coordonn�es (x,y) dans la surface
*/
Uint32 obtenirPixel(SDL_Surface *surface, int x, int y)
{
    /*nbOctetsParPixel repr�sente le nombre d'octets utilis�s pour stocker un pixel.
    En multipliant ce nombre d'octets par 8 (un octet = 8 bits), on obtient la profondeur de couleur
    de l'image : 8, 16, 24 ou 32 bits.*/
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    /* Ici p est l'adresse du pixel que l'on veut connaitre */
    /*surface->pixels contient l'adresse du premier pixel de l'image*/
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * nbOctetsParPixel;

    /*Gestion diff�rente suivant le nombre d'octets par pixel de l'image*/
    switch(nbOctetsParPixel)
    {
        case 1:
            return *p;

        case 2:
            return *(Uint16 *)p;

        case 3:
            /*Suivant l'architecture de la machine*/
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;

        case 4:
            return *(Uint32 *)p;

        /*Ne devrait pas arriver, mais �vite les erreurs*/
        default:
            return 0;
    }
}

/* ********************************************************************* */
/*definirPixel : permet de modifier la couleur d'un pixel
Param�tres d'entr�e/sortie :
SDL_Surface *surface : la surface sur laquelle on va modifier la couleur d'un pixel
int x : la coordonn�e en x du pixel � modifier
int y : la coordonn�e en y du pixel � modifier
Uint32 pixel : le pixel � ins�rer
*/
void definirPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    /*nbOctetsParPixel repr�sente le nombre d'octets utilis�s pour stocker un pixel.
    En multipliant ce nombre d'octets par 8 (un octet = 8 bits), on obtient la profondeur de couleur
    de l'image : 8, 16, 24 ou 32 bits.*/
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    /*Ici p est l'adresse du pixel que l'on veut modifier*/
    /*surface->pixels contient l'adresse du premier pixel de l'image*/
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * nbOctetsParPixel;

    /*Gestion diff�rente suivant le nombre d'octets par pixel de l'image*/
    switch(nbOctetsParPixel)
    {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *)p = pixel;
            break;

        case 3:
            /*Suivant l'architecture de la machine*/
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            }
            else
            {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
}

int Nbreturn(Uint8 composante, int valeur)
{
    int tampon; /*Variable enti�re qui sert de tampon*/
    int nbpass(0);
    tampon=(int)composante + valeur;

    /*On fait en sorte que tampon reste dans l'intervalle [0,255] */
    while(tampon>255)
    {
        tampon-=255;
        nbpass++;
    }
    while(tampon<0)
    {
        tampon+=255;
        nbpass--;
    }

    /*Avec l'op�rateur cast (Uint8) on tranforme tampon en un entier de type Uint8*/
    return nbpass;
}

