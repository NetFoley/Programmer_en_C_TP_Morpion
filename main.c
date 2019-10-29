#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define NFOIS 5

/*
int main()
{
    float x;
    float racx;
    printf("Un nombre\n", x);

    for (int i=0; i < NFOIS; i++)
    {
        scanf("%f",&x);
        if (x<0.0)
            printf("Un nombre positif");
        else
        {
            racx=sqrt(x);
            printf("Le nombre %f a pour racide carree : %f\n", x, racx);
        }
    }
    return 0;
}
*/

//Définition constantes du tableau
#define tTAILLE 3
#define JOUEUR1 'X'
#define JOUEUR2 'O'


int changerCase(char tabMorpion[tTAILLE][tTAILLE], char joueur, int nPosX, int nPosY);
void initialiserMorpion(char tabMorpion[tTAILLE][tTAILLE]);
void afficherMorpion(char tabMorpion[tTAILLE][tTAILLE]);
int verifVictoire(char tabMorpion[tTAILLE][tTAILLE]);
int demandeNombre(char coord);

void main()
{
    /*float x;
    float racx;
    vprintf("Un nombre\n", x);
    {
        scanf("%f",&x);
        fflush(stdin); //Vide le buffer de la saisie
        if (x<0.0)
            printf("Un nombre positif");
        else
        {
            racx=sqrt(x);
            printf("Le nombre %f a pour racide carree : %f\n", x, racx);
        }
    }*/

    /*
    char car[30];
    for (int i = 0; i < 29; i++){
        car[i] = '\0';
    }
    int compteur = -1;

    do{
        compteur++;
        printf("Entrez un caractere\n");
        car[compteur]=getch();
        printf("%s\n",car);
        fflush(stdin);
    }while((car[compteur]>='a' && car[compteur] <='z' || car[compteur]>='A' && car[compteur]<='Z') && compteur < 30);*/


    //Definition des variables
    char tabMorpion[tTAILLE][tTAILLE];
    int nVictoire = 0;
    int nCompteur = 0;
    int nEntreeX = 0;
    int nEntreeY = 0;
    char joueurNow;

    //Initialisation du tableau
    initialiserMorpion(tabMorpion);

    //Boucle de jeu
    while (nVictoire == 0 && nCompteur < 9)
    {
        afficherMorpion(tabMorpion);
        //Première demande à l'utilisateur
        if (nCompteur == 0)
        {
            printf("Voici le plateau du morpion, :\nOu placez votre case ?\n", JOUEUR1);
        }

        do{
            if (nCompteur % 2 == 0) // Alterner joueur 1 et 2
            {
                joueurNow = JOUEUR1;
            }
            else
            {
                joueurNow = JOUEUR2;
            }
                printf("Joueur %c :", joueurNow);
                nEntreeX = demandeNombre('x');
                nEntreeY = demandeNombre('y');
        }while(changerCase(tabMorpion, joueurNow, nEntreeX, nEntreeY) == 0);

        nVictoire = verifVictoire(tabMorpion);
        nCompteur++;
    }

    //Fin de la partie, affichage du morpion et désignation des gagnants
    afficherMorpion(tabMorpion);
    switch (nVictoire){
    case 0 :
        printf ("Personne n'a gagne");
        break;
    case 1 :
        printf("Joueur 1 a gagne");
        break;
    case 2 :
        printf("Joueur 2 a gagne");
        break;}


}

void initialiserMorpion(char tabMorpion[tTAILLE][tTAILLE]){
    //initialisation du morpion sur des cases vides "étoiles"
    for ( int i = 0; i < tTAILLE; i++)
    {
        for ( int j = 0 ; j < tTAILLE; j++)
        {
            tabMorpion[i][j] = '*';
        }
    }
}

void afficherMorpion(char tabMorpion[tTAILLE][tTAILLE])
//Affiches toutes les valeurs d'un tableau morpion
{
    printf("\n");
    for ( int i = 0; i < tTAILLE ; i++)
    {
        for ( int j = 0 ; j < tTAILLE ; j++)
        {
            printf("%c ",tabMorpion[i][j]);
        }
        printf("\n");
    }
}

int changerCase(char tabMorpion[tTAILLE][tTAILLE], char joueur, int nPosX, int nPosY)
//Vérifie si une case est valide et effectue le changement en fonction
{
    int valider = 1;
    printf("Changement de la case en position [%i][%i]\n", nPosY, nPosX);
    if (tabMorpion[nPosY-1][nPosX-1] == '*')
        tabMorpion[nPosY-1][nPosX-1] = joueur;
    else
    {
        valider = 0;
        printf("Erreur tentative de changer une case invalide\n");
    }
    return valider;
}

int demandeNombre(char coord)
//Demande un nombre compris dans un intervalle et renvois ce nombre
{
    int nombre = 0;

    while (nombre < 1 || nombre > tTAILLE)
    {
        printf("Entrez la position %c comprise entre 1 et %i : \n", coord, tTAILLE);
        scanf("%i", &nombre);
    }

    return nombre;
}

int verifVictoire(char tabMorpion[tTAILLE][tTAILLE])
//Fonction qui vérifie si la partie est gagné ( s'il y a une ligne parmis 2 caractères )
//Renvoie le numéro du joueur gagnant ( 1 ou 2 ) sinon renvoie 0
{
    int nVictoire = 0;
    //Test de toutes les conditions de victoires possibles ( Lignes / colonnes / diagonales )
    if(tabMorpion[0][0] == JOUEUR1 && ( (tabMorpion[0][0] == tabMorpion[0][1]) && (tabMorpion[0][2] == tabMorpion[0][1]) )||
       tabMorpion[0][0] == JOUEUR1 && ( (tabMorpion[0][0] == tabMorpion[1][1]) && (tabMorpion[2][2] == tabMorpion[1][1]) )||
       tabMorpion[0][0] == JOUEUR1 && ( (tabMorpion[0][0] == tabMorpion[1][0]) && (tabMorpion[2][0] == tabMorpion[1][1]) )||
       tabMorpion[0][1] == JOUEUR1 && ( (tabMorpion[0][1] == tabMorpion[1][1]) && (tabMorpion[2][1] == tabMorpion[1][1]) )||
       tabMorpion[2][0] == JOUEUR1 && ( (tabMorpion[2][0] == tabMorpion[2][1]) && (tabMorpion[2][2] == tabMorpion[2][1]) )||
       tabMorpion[0][2] == JOUEUR1 && ( (tabMorpion[0][2] == tabMorpion[1][2]) && (tabMorpion[2][2] == tabMorpion[1][2]) )||
       tabMorpion[0][2] == JOUEUR1 && ( (tabMorpion[0][2] == tabMorpion[1][1]) && (tabMorpion[2][0] == tabMorpion[1][1]) )||
       tabMorpion[1][0] == JOUEUR1 && ( (tabMorpion[1][0] == tabMorpion[1][1]) && (tabMorpion[1][2] == tabMorpion[1][1])))
        {
            nVictoire = 1;
        }
    if(tabMorpion[0][0] == JOUEUR2 && ( tabMorpion[0][0] == tabMorpion[0][1] && tabMorpion[0][2] == tabMorpion[0][1] )||
       tabMorpion[0][0] == JOUEUR2 && ( tabMorpion[0][0] == tabMorpion[1][1] && tabMorpion[2][2] == tabMorpion[1][1] )||
       tabMorpion[0][0] == JOUEUR2 && ( tabMorpion[0][0] == tabMorpion[1][0] && tabMorpion[2][0] == tabMorpion[1][1] )||
       tabMorpion[0][1] == JOUEUR2 && ( tabMorpion[0][1] == tabMorpion[1][1] && tabMorpion[2][1] == tabMorpion[1][1] )||
       tabMorpion[2][0] == JOUEUR2 && ( tabMorpion[2][0] == tabMorpion[2][1] && tabMorpion[2][2] == tabMorpion[2][1] )||
       tabMorpion[0][2] == JOUEUR2 && ( tabMorpion[0][2] == tabMorpion[1][2] && tabMorpion[2][2] == tabMorpion[1][2] )||
       tabMorpion[0][2] == JOUEUR2 && ( tabMorpion[0][2] == tabMorpion[1][1] && tabMorpion[2][0] == tabMorpion[1][1] )||
       tabMorpion[1][0] == JOUEUR2 && ( tabMorpion[1][0] == tabMorpion[1][1] && tabMorpion[1][2] == tabMorpion[1][1]))
        {
            nVictoire = 2;
        }

    return nVictoire;
}
