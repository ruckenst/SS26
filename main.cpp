#include "Animal.h"
#include "Elephant.h"
#include "Penguin.h"
#include "Lion.h"
#include "Zoo.h"

/*  PRÜFUNGSVORBEREITUNG (NUR SMART POINTER)
 *  1. Klassenhierarchie
 *     - Elternklasse: "Animal"
 *          - Constructor, der string "name"
 *            übernimmt und speichert
 *          - Rein Virtuelle:
 *            std::string getType()
 *          - Methode:
 *            void printStats()
 *            "[$getType()] $name"
 *            Beispiel: "[Lion] Hubert"
 *     - Kindklassen:
 *          - "Elephant"
 *              - getType => "Elephant"
 *          - "Penguin"
 *              - getType => "Penguin"
 *          - "Lion"
 *              - getType => "Lion"
 *
 *  2. Verwaltende Klasse
 *     - Klasse: "Zoo"
 *          - Privater Vector: "animals"
 *          - Methode:
 *            void addAnimal(Animal)
 *          - Methode:
 *            void printZooDetails()
 */

int main() {
    Zoo myZoo;

    myZoo.addAnimal(std::make_shared<Elephant>("Sepp"));
    myZoo.addAnimal(std::make_shared<Lion>("Anna"));
    myZoo.addAnimal(std::make_shared<Penguin>("Mimi", 123));

    /* NICHT GEFORDERT */
    myZoo.addAnimal<Elephant>("Sepp Unique");
    myZoo.addAnimal<Lion>("Anna Unique");
    myZoo.addAnimal<Penguin>("Mimi Unique", 123);

    myZoo.printZooDetails();

    return 0;
}