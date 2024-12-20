#include <iostream>
#include<cstdio>
#include<cstring>
#include"beckend/database.h"
#define MAX_CONTENT_LEN 100

/*
  * portata e scalabilità delle funzioni ridotte,dato che
  * nel caso di ritorno stringhe,si stampa direttamente nella funzione
  */

int main() {
    char path[MAX_CONTENT_LEN];

    printf("enter the path without quotes\n"
           " (make sure this file.txt is empty!!)  :  ");

    fgets(path, MAX_CONTENT_LEN, stdin);
    path[strcspn(path, "\n")] = 0; //chiude la posizione

    file_name=path;

    //se il path è sbagliato,il sistema lo creerà per te

    int psw=0;  //password per l'ingresso

    do {
        printf("\nenter password : ");
        scanf("%d",&psw);
        getchar();

    } while (psw!=1234);






    open();  //chiamata per riempire l'array

    printf("\nSet all tasks from now to 30 days!!\n");

    char choice;
    printf("\nMENU:\n"
           "e) exit\n"
           "a) save all\n"
           "n) new note\n"
           "p) print all notes\n"
           "c) clear all notes\n"
           "s) edit note by day\n"
           "r) remove note by title\n\n");

    do {
        printf("\nenter choice: ");
        scanf("%c", &choice);  // Legge il carattere
        while (getchar() != '\n');  // Pulisce il buffer di input

        printf("\n");

        switch (choice) {
            case 'e':
                break;
            case 'a':
                close();
                break;
            case 'n':
                char content[MAX_CONTENT_LEN];

                printf("Enter content: ");
                // Usa fgets per leggere una stringa con spazi
                fgets(content, MAX_CONTENT_LEN, stdin);
                // Rimuove il carattere di nuova linea '\n' che fgets può aggiungere
                content[strcspn(content, "\n")] = 0; //chiude la posizione

                newNote(content);
                break;
            case 'p':
                printAll();
                printf("\n");
                break;
            case 'c':
                clearAll();
                break;
            case 's':
                int d;
                printf("Enter day: ");
                scanf("%d",&d);

                getchar();   //rimuove lo \n di troppo che da problemi con lo switch

                char new_content[MAX_CONTENT_LEN];

                printf("Enter content: ");
                // Usa fgets per leggere una stringa con spazi
                fgets(new_content, MAX_CONTENT_LEN, stdin);
                // Rimuove il carattere di nuova linea '\n' che fgets può aggiungere
                new_content[strcspn(new_content, "\n")] = 0; //chiude la posizione

                search(d,new_content);


                break;
            case 'r':
                int day;
                printf("Enter day: ");
                scanf("%d",&day);

                getchar();    //rimuove lo \n di troppo che da problemi con lo switch

                remove(day);
                break;
            default:
                printf("\nenter valid choice!!\n");
        }

    } while (choice != 'e' && choice != 'E');


    close();  //prima di chiudere il programma,riscrive sul file in modo da salvare tutto




}

