#include "Zoo.h"

void Zoo::addAnimal(std::shared_ptr<Animal> animal) {
    animals.push_back(animal);
}

void Zoo::printZooDetails() const {
    for(const auto& animal : animals) {
        animal->printStats();
    }

    /* NICHT GEFORDERT */
    for(const auto& animal : uniqueAnimals) {
        animal->printStats();
    }
}