// Procedural_dungeon_generator.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln



#include <iostream>
#include <random>

constexpr int MAP_WIDTH = 20;
constexpr int MAP_HEIGHT = 20;

void printMap(char map[MAP_WIDTH][MAP_HEIGHT]);
void fillMap(char map[MAP_WIDTH][MAP_HEIGHT], char tileSymbol);
void placeRooms(char map[MAP_WIDTH][MAP_HEIGHT], int min_rooms, int max_rooms, int room_size);

int main()
{   
    char map[MAP_WIDTH][MAP_HEIGHT];
    int room_size = 3;

    fillMap(map, 282);
    placeRooms(map, 2, 5, 3);
    printMap(map);
    
    
}

/**
* @brief Prints a 2D map to the console   
*
* This function prints a 2D array 'map' row by row.
* 
* @param map - 2D array to be printed to the console
*/
void printMap(char map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int i = 0; i <= MAP_WIDTH - 1; i++) {
        for (int j = 0; j <= MAP_HEIGHT - 1; j++) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << "\n";
    }
}

/**
* @brief Fills a 2D map with a specified ASCII character
* 
* This function fills a 2D array row by row with the specified ASCII character
* 
* @param map - 2D array to be filled with the ASCII character
* @param tileSymbol - ASCII character used to fill the 2D array
*/
void fillMap(char map[MAP_WIDTH][MAP_HEIGHT], char tileSymbol) {
    for (int i = 0; i <= MAP_WIDTH - 1; i++) {
        for (int j = 0; j <= MAP_HEIGHT - 1; j++) {
            map[i][j] = tileSymbol;
        }
    }
}

/**
* @brief Places a random number of (N x N) rooms in a 2D map
* 
* This functions places a random number of (N x N) rooms in a 2D map
* by substituting the default tile symbol with 'x'
* 
* @param map - 2D array in which to place the (N x N) rooms
* @param min_rooms - The minimum number of rooms to be placed in the map
* @param max_rooms - The maximum number of rooms to be placed in the map
* @param room_size - The side of a room expressed in units
*/
void placeRooms(char map[MAP_WIDTH][MAP_HEIGHT], int min_rooms, int max_rooms, int room_size) {
    unsigned int seed = std::random_device{}();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> number_of_rooms(min_rooms, max_rooms);
    int rooms = number_of_rooms(gen);
    int room_extension = room_size / 2; // how much a room "protrudes" from its centre along the x and y-coordinates

    for (int r = rooms; r > 0; r--) {
        std::uniform_int_distribution<int> random_centre_x(room_extension, (MAP_WIDTH - 1) - room_extension); // set x-boundaries
        std::uniform_int_distribution<int> random_centre_y(room_extension, (MAP_HEIGHT - 1) - room_extension); // set y-boundaries
        int room_centre_x = random_centre_x(gen); // randomly generate the x-coordinate of the room centre
        int room_centre_y = random_centre_y(gen); // randomly generate the y-coordinate of the room centre 

        for (int i = room_centre_y - room_extension; i <= room_centre_y + room_extension; i++) {
            for (int j = room_centre_x - room_extension; j <= room_centre_x + room_extension; j++) {
                map[i][j] = 254;
            }
        }
    }

    std::cout << "Generation seed: " << seed << "\n\n";

}
