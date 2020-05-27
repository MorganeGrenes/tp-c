
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int max = 0, min = 0;
    srand(time(NULL));
    int mysteryNumber = 0,  playerAnswer = 0,  compteur = 0, continueGame = 0, howManyPlayers = 0, difficulty = 0;

    do{
        printf ("Choose your game mode\n1-Solo\n2-Two players\n");
        scanf ("%d", &howManyPlayers);
        printf ("Choose your difficulty\n1---easy---\n2---medium---\n3---hard---\n");
        scanf ("%d", &difficulty);
        if (difficulty == 1){
            max = 100, min = 1;
            printf("\nyou are in easy difficulty\n");
        }
        if (difficulty == 2){
            max = 1000, min = 1;
            printf("\nyou are in medium difficulty\n");
        }
        if (difficulty == 3){
            max = 10000, min = 1;
            printf("\nyou are in hard difficulty\n");
        }
        compteur = 0;


        if (howManyPlayers ==1 ){
            printf("you choose the single player mode\n");
            printf ("Your are playing with the IA\n");//pour confirmer que l'on joue bien en mode 1 joueur
            mysteryNumber = (rand() % (max - min + 1)) + min;
            printf("Nombre mystere :  %d", mysteryNumber);//affiche la valeur du nb mystère
        }

        if (howManyPlayers == 2){

            printf("you choose the multiplayer mode\n");
            printf("Your are playing with an other player\n");//pour confirmer que l'on joue bien en mode 1 joueur
            printf("Player 1 is choosing a number\n");
          do {
            if (mysteryNumber > max){//changer lecriture de la variable en minuscule car il ne s'agit plus d'une constante
                printf("\nPlease enter a number corresponding to the difficulty\n");
            }
            scanf("%d", &mysteryNumber);
            printf("%d", mysteryNumber); //pour afficher la valeur qu'à indiqué le 1er joueur
          }while (mysteryNumber > max);

        }




        do{
            compteur ++;
            printf("\nPlayer 2 guess the mystery number\n");//on demande au joueur humain de deviner la valeur du nombre mystère
            scanf("%d", &playerAnswer);

            if (playerAnswer > mysteryNumber){
                printf("A little bit less\n");

            }
            else if (playerAnswer < mysteryNumber){
                printf("A little bit more\n");
            }
            else{
                printf("GG it's the right answer !\n");
                printf("you made %d strokes", compteur);
                printf("\nDo you want to continue to play?\n");
                scanf("%d", &continueGame);
                compteur = 0;
            }

            if (compteur >= 3){
                printf("You are 3 strokes away\n");//indique au joueur qu'il en est à 3 essais
            }

        }while(playerAnswer != mysteryNumber);//on ne s'arrête pas tant que le nombre mystère est différent du bon nombre donné auparavant.
    }while(continueGame == 1);






    return 0;
}
