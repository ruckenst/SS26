#ifndef SS26_ZOO_H
#define SS26_ZOO_H

#include "Animal.h"
#include <vector>
#include <memory>

class Zoo {
public:
    void addAnimal(std::shared_ptr<Animal> animal);
    void printZooDetails() const;
    
    /* NICHT GEFORDERT */
    template<typename T, typename... Args>
        requires std::derived_from<T, Animal>
    void addAnimal(Args&&... args) {
        uniqueAnimals.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

private:
    std::vector<std::shared_ptr<Animal>> animals;

    /* NICHT GEFORDERT */
    std::vector<std::unique_ptr<Animal>> uniqueAnimals;
};


#endif //SS26_ZOO_H
