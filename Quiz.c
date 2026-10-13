#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {
    char question[200];
    char A[100];
    char B[100];
    char C[100];
    char D[100];
    char reponse;
} Question;

int main() {

    // manpivoka le accent eo @consoles
    SetConsoleOutputCP(CP_UTF8);

    Question quiz[20] = {
        // question 20 

        {"Quelle est la capitale de Madagascar ?",
         "Antananarivo", "Toamasina", "Mahajanga", "Fianarantsoa", 'A'},

        {"Combien font 5 + 7 ?",
         "10", "11", "12", "13", 'C'},

        {"Quel langage utilise l'extension .c ?",
         "Python", "C", "Java", "HTML", 'B'},

        {"Combien y a-t-il de continents ?",
         "5", "6", "7", "8", 'C'},

        {"Quelle est la planète la plus proche du Soleil ?",
         "Mars", "Vénus", "Mercure", "Jupiter", 'C'},

        {"Combien font 10 * 10 ?",
         "10", "50", "100", "1000", 'C'},

        {"Quel est le plus grand océan ?",
         "Atlantique", "Indien", "Arctique", "Pacifique", 'D'},

        {"Combien de côtés possède un triangle ?",
         "2", "3", "4", "5", 'B'},

        {"Quel langage est utilisé pour les pages Web ?",
         "HTML", "C", "C++", "Python", 'A'},

        {"Bleu + jaune donne quelle couleur ?",
         "Rouge", "Vert", "Orange", "Violet", 'B'},

        {"Combien font 8 * 5 ?",
         "30", "35", "40", "45", 'C'},

        {"Quel est le symbole chimique de l'eau ?",
         "CO2", "O2", "H2O", "NaCl", 'C'},

        {"Combien de jours y a-t-il dans une semaine ?",
         "5", "6", "7", "8", 'C'},

        {"Quel animal est appelé le roi de la jungle ?",
         "Lion", "Tigre", "Éléphant", "Loup", 'A'},

        {"Combien font 100 / 4 ?",
         "20", "25", "30", "40", 'B'},

        {"Quel langage utilise ce programme ?",
         "Java", "Python", "C", "PHP", 'C'},

        {"Quelle est la capitale de la France ?",
         "Madrid", "Paris", "Rome", "Berlin", 'B'},

        {"Combien font 9 + 6 ?",
         "13", "14", "15", "16", 'C'},

        {"Quel est le satellite naturel de la Terre ?",
         "Mars", "Le Soleil", "La Lune", "Vénus", 'C'},

        {"Combien font 7 * 7 ?",
         "42", "49", "56", "63", 'B'}
    };

    int indices[20];
    char reponses[10];

    int i, j, temp;
    int score = 0;
    char reponse;

    /* mpamorina indices 0 à 0*/
    for (i = 0; i < 20; i++) {
        indices[i] = i;
    }

    /*
       ty mahatonga leh izy aleatoire rhf misikotra 
    */
    srand(time(NULL));

    /*
       le indices

    */
    for (i = 19; i > 0; i--) {

        j = rand() % (i + 1);

        temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    printf("=====================================\n");
    printf("          QUIZ DE 10 QUESTIONS      \n");
    printf("=====================================\n");

    /*
       questions folo mivoka rhf mifangaroo
    */
    for (i = 0; i < 10; i++) {

        Question q = quiz[indices[i]];

        printf("\nQuestion %d/10\n", i + 1);
        printf("%s\n\n", q.question);

        printf("A. %s\n", q.A);
        printf("B. %s\n", q.B);
        printf("C. %s\n", q.C);
        printf("D. %s\n", q.D);

        printf("\nVotre réponse : ");
        scanf(" %c", &reponse);

        /* ato ndray mamadika ho majiscul */
        if (reponse >= 'a' && reponse <= 'd') {
            reponse = reponse - 'a' + 'A';
        }

        /* misauv an'leh valina */
        reponses[i] = reponse;

        /* mialcule leh score */
        if (reponse == q.reponse) {
            score++;
        }
    }

    /*
       leh ato mijery ny resulat ndrayy
    */
    printf("\n\n=====================================\n");
    printf("              RESULTAT               \n");
    printf("=====================================\n");

    printf("Votre score : %d/10\n", score);

    /*
       Ato ny correction am'leh diso rhtra 
    */
    printf("\n========== CORRECTIONS ==============\n");

    for (i = 0; i < 10; i++) {

        Question q = quiz[indices[i]];

        printf("\nQuestion %d : %s\n",
               i + 1, q.question);

        printf("Votre réponse : %c\n",
               reponses[i]);

        printf("Bonne réponse : %c\n",
               q.reponse);

        if (reponses[i] == q.reponse) {
            printf("Résultat : CORRECT\n");
        } else {
            printf("Résultat : FAUX\n");
        }
    }

    printf("\n=====================================\n");
    printf("Score final : %d/10\n", score);
    printf("=====================================\n");

    return 0;
}