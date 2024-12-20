
#include <iostream>
#include<cstdio>
#include <cstdlib>

#ifndef PROVASTRINGHE_FILE_MANAGEMENT_H
#define PROVASTRINGHE_FILE_MANAGEMENT_H

#endif //PROVASTRINGHE_FILE_MANAGEMENT_H


FILE *file;  //file principale


void readStringsFromFile(const char *filename, char *array[], size_t maxCount) {
    file = fopen(filename, "r");  // Apertura del file in modalità lettura
    if (file == nullptr) {
        printf("\nError opening the file for reading.\n");
        return;
    }

    size_t count = 0;
    char buffer[256];  // Buffer temporaneo per ogni riga letta
    while (fgets(buffer, sizeof(buffer), file) && count < maxCount) {
        // Rimuovere il carattere di newline, se presente
        buffer[strcspn(buffer, "\n")] = '\0';

        // Allocazione dinamica e copia della stringa letta nel array
        array[count] = strdup(buffer);
        count++;
    }
    for (size_t i = count; i < maxCount; i++) {
        array[i] = nullptr;  // Impostiamo gli slot vuoti su NULL per evitare accessi indesiderati
    }

    fclose(file);
    printf("\nStrings read from file successfully.\n");
}




void writeStringsToFile(const char *filename,char *array[], size_t count) {
    file = fopen(filename, "w");  // Apertura del file in modalità scrittura
    if (file == nullptr) {
        printf("\nError opening the file for writing.\n");
        return;
    }

    // Scrivere ogni stringa nel file, separata da una nuova riga
    for (size_t i = 0; i < count; i++) {
        fprintf(file, "%s\n", array[i]);
    }

    fclose(file);
    printf("\nStrings written to file successfully.\n");
}
