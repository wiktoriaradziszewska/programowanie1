#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void powitanie() {
    printf("Witaj w grze 'Zgadnij liczbe'!\n");
    printf("Zadaniem jest odgadniêcie liczby wylosowanej przez komputer.\n");
    printf("Po kazdej probie komputer poinformuje cie, czy twoja liczba jest za mala, za duza, czy trafiona.\n");
    printf("Powodzenia!\n\n");
}

int losuj_liczbe() {
    return rand() % 100 + 1; // Losowanie liczby z zakresu 1-100
}

void rozpocznij_runde(int rundy) {
    int liczba, proba, liczba_prob = 0;
    liczba = losuj_liczbe();
    printf("\nRunda %d\n", rundy);
    printf("Zgadnij liczbe (1-100): ");

    do {
        scanf("%d", &proba);
        liczba_prob++;

        if (proba < liczba) {
            printf("Za malo! Sprobuj wyzszej liczby: ");
        } else if (proba > liczba) {
            printf("Za duzo! Sprobuj nizszej liczby: ");
        } else {
            printf("Gratulacje! Zgadles liczbe %d w %d probach!\n", liczba, liczba_prob);
            return;
        }
    } while (1);
}

int main() {
    int liczba_rund = 0;
    int wybor;
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    powitanie();

    do {
        printf("\nWybierz opcje:\n");
        printf("1. Rozpocznij nowa runde\n");
        printf("2. Zakoncz gre\n");
        printf("Podaj numer opcji: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                liczba_rund++;
                rozpocznij_runde(liczba_rund);
                break;
            case 2:
                printf("Dziekujemy za gre! Do zobaczenia!\n");
                break;
            default:
                printf("Niepoprawny wybor! Sprobuj ponownie.\n");
        }
    } while (wybor != 2);

    return 0;
}
