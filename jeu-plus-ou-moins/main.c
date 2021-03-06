
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int askDifficulty();
int askHowManyPlayers();//prototype

int main()
{
    int max = 0, min = 0;
    srand(time(NULL));
    int mysteryNumber = 0,  playerAnswer = 0,  counter = 0, continueGame = 0, howManyPlayers = 0, difficulty = 0;

    do{

        difficulty = askDifficulty();

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
        counter = 0;

        howManyPlayers = askHowManyPlayers();

        if (howManyPlayers ==1 ){
            printf("you choose the single player mode\n");
            printf ("Your are playing with the IA\n"); // pour confirmer que l'on joue bien en mode 1 joueur
            mysteryNumber = (rand() % (max - min + 1)) + min;
            printf("Nombre mystere :  %d\n", mysteryNumber); // affiche la valeur du nb myst�re
        }

        if (howManyPlayers == 2){

            printf("you choose the multiplayer mode\n");
            printf("Your are playing with an other player\n"); //pour confirmer que l'on joue bien en mode 1 joueur
            printf("Player 1 is choosing a number\n");

            do {
                if (mysteryNumber > max){ // changer lecriture de la variable en minuscule car il ne s'agit plus d'une constante
                    printf("\nPlease enter a number corresponding to the difficulty\n");
                }
                scanf("%d", &mysteryNumber);
                printf("%d", mysteryNumber); // pour afficher la valeur qu'� indiqu� le 1er joueur
            }while (mysteryNumber > max);

        }


        do{
            counter ++;
            printf("\nPlayer 2 guess the mystery number\n"); // on demande au joueur humain de deviner la valeur du nombre myst�re
            scanf("%d", &playerAnswer);

            if (abs(playerAnswer - mysteryNumber) <= 10 && mysteryNumber != playerAnswer){
                printf("\nclose to 10 you are not far from the value\n");
            }

            if (playerAnswer > mysteryNumber){
                printf("A little bit less\n");
            }
            else if (playerAnswer < mysteryNumber){
                printf("A little bit more\n");
            }
            else {
                printf("GG it's the right answer !\n");
                printf("you made %d strokes", counter);
                printf("\nDo you want to continue to play?\n");
                scanf("%d", &continueGame);
                counter = 0;
            }

            if (counter >= 3){
                printf("You are 3 strokes away\n"); // indique au joueur qu'il en est � 3 essais
            }

        } while(playerAnswer != mysteryNumber); // on ne s'arr�te pas tant que le nombre myst�re est diff�rent du bon nombre donn� auparavant.
    } while(continueGame == 1);

    return 0;
}


int askDifficulty(){
    int askedDifficulty = 0;
    printf ("Choose your difficulty\n1---easy---\n2---medium---\n3---hard---\n");
    scanf ("%d", &askedDifficulty);

    return askedDifficulty;
}

int askHowManyPlayers(){
    int askedHowManyPlayers = 0;
    printf ("Choose your game mode\n1-Solo\n2-Two players\n");
    scanf ("%d", &askedHowManyPlayers);

    return askedHowManyPlayers;
}
