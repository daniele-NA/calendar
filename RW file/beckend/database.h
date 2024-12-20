
#include <iostream>
#include<cstdio>
#include <cstdlib>

#include "file-management.h"

#ifndef PROVASTRINGHE_FUNCTION_H
#define PROVASTRINGHE_FUNCTION_H
#endif //PROVASTRINGHE_FUNCTION_H

#define MAX_NOTES 30  //numero massimo di note,rappresenta un mese generico


char *notes[MAX_NOTES];    //array di note

const char *file_name = "";   //path file


void printAll();

void close();

void remove(int day);

void search(int day, char *content);


void open() {
    for (int i = 0; i < MAX_NOTES; ++i) {    //apertura con pulizia della lista e successivo riempimento
        notes[i] = nullptr;
    }
    readStringsFromFile(file_name, notes, MAX_NOTES);
}

void close() {
    int number_of_notes = 0;
    for (int i = 0; i < MAX_NOTES; ++i) {     //calcolo note NON-NULL e riempimento array
        if (notes[i] != nullptr) {
            number_of_notes = number_of_notes + 1;
        }
    }
    writeStringsToFile(file_name, notes, number_of_notes);
}

void clearAll() {
    file = fopen(file_name, "wb");    //pulizia file e array
    fprintf(file, "");

    for (int i = 0; i < MAX_NOTES; ++i) {
        notes[i] = nullptr;
    }

}

void printAll() {
    for (size_t i = 0; i < MAX_NOTES; i++) {   //stampa creativa delle note libere(null) e di quelle piene
        if (i == 0) {
            printf("today(1) : %s\n", notes[i]);   //se è il primo giorno,mettiamo todaye  passiamo all'iterazione successiva
            continue;
        }

        printf("day %zu: %s\t\t\t", i + 1, notes[i]);
        if (i % 2 == 0) {
            printf("\n");       //gestione spazi
        }
    }
}


// Funzione per creare una nuova "Note" con stringhe dinamiche
void newNote(char *content) {
    for (int i = 0; i < MAX_NOTES; ++i) {    //prima nota libera,gli si alloca del testo e si scrive su file
        if (notes[i] == NULL) {
            notes[i] = strdup(content);
            printf("\nnote added successfully");
            close();
            return;
        }
    }
    printf("\nmaximum size reached");
}


/*
 * per facilitare l'utente,il giorno viene visualizzato da 1 a 30,e non da 0 a 29
 * si sottrae quindi sempre 1 per non incombere in IndexOutOfBoundException
 */


void remove(int day) {    //rimozione per indice(si mette a null)
    day = day - 1;
    if (day >= 1 && day < MAX_NOTES) {
        notes[day] = nullptr;
        printf("note removed successfully");
    } else {
        printf("day not found");
    }
}

void search(int day, char *content) {   //ricerca per indice
    day = day - 1;
    if (day >= 1 && day < MAX_NOTES) {
        notes[day] = content;
        printf("note edited successfully");
    } else {
        printf("day not found");
    }

}
