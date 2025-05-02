/**
 * @file main.cpp
 * @author Fabxx
 * @brief Rendiamola semplice:
 * 
 *                  - Un oggetto è usato per accedere posizioni in memoria indirettamente
 *                  
 *                  - Un oggetto è una sezione di memoria che contiene dati.
 *                    Una variabile è un oggetto con un identificatore (Nome)
 *                  
 *                  - In C++ il termine "oggetto" non fa riferimento alle funzioni.
 *                  
 *                  - La definizione delle variabili può essere nella stessa (se dello stesso tipo) o diverse righe.
 * 
 * 
 *                  Differenti tipi di inizializzazione:
 * 
                    int b = 5;     // Inizializzazione con copia (Valore iniziale dopo simbolo di ugualianza)
                    int c ( 6 );   // Inizializzazione diretta (Valore iniziale in parentesi tonde)

                    // Forme moderne di inizializzazione (consigliate):
                    int d { 7 };   // Inizializzazione diretta a lista (Valore iniziale in parentesi graffe)
                    int f {};      // Inizializzazione a valore (Parentesi graffe vuote)


                    Il vantaggio principale di questi stili moderni di inizializzazione è la capacità di essere analizzati dal compilatore se un certo valore è compatibile con la variabile a cui sta venendo assegnato. Se questo non lo fosse viene generato un errore. Inoltre progette i valori dall'essere erroneamente convertiti in formati che potrebbero non contenerli completamente.


                    L'attributo [[maybe_unused]] ci permette di avere variabili inutilizzate che possiamo utilizzare in futuro senza che il compilatore ci avverta del loro mancato uso.
 * 
 *              NOTE:
 * 
 *                  1) C++ scoraggia l'accesso diretto alla memoria esattamente come C, ma è comunque permesso se
                       necessario con l'utilizzo dei puntatori.
 * 
 *                  2) Non è consigliato definire molteplici variabili sulla stessa riga per una questione di pulizia.
                       Codice pulito permette anche una più facile documentazione. E' comunque possibile farlo se non è necessario spiegare l'utilizzo di certe variabili.
 * 
 *                  3) Il termine "oggetto" non solo rappresenta una regione di memoria di una certa classe, ma tutte
                       le regioni di memooria utilizzate.
 * 
 *                  4) Una variabile non inizializzata può portare a comportamenti inaspettati.
                        Se non si ha un valore specifico da assegnare alla variabile, può essere riempita con dei valori iniziali:
 *          
 *                      Inizializzando le variabili tradizionalmente è buona pratica impostare:
 *                      - i puntatori a null
 *                      - le variabili numeriche a 0
 *                      - le stringhe a "" (stringa vuota)
 *                      - le variabili binarie/boolean a false
 *                      - le variabili da singolo carattere (char) a ''
 *                      - le variabili enumeratrici (enum) al primo valore compatibile
 *                      - tutti i valori di un array a 0 con `= {}` o memset
 * 
 *                      L'utilizzo della inizializzazione moderna ci scarica da questa necessità.
 * @version 0.1
 * @date 2024-09-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

int main(void)
{
    int x = 0; //La variabile `x` è inizializzata a 0.

    int a = 0, b; //Dichiarazione di molteplici variabili sulla stessa riga. `a` è inizializzato a 0, `b` non è inizializzato.

    int y {5}; //Inizializzazione moderna

    [[maybe_unused]] int z {4}; //Il compilatore non avviserà il mancato utilizzo di questa variabile grazie a [[maybe_unused]]

    std::cout << "Value is: " << x << std::endl;
}
