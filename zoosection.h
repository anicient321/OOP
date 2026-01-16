#ifndef ZOOSECTION_H
#define ZOOSECTION_H

#include <vector>
#include <memory>
#include <stdexcept>

template<typename T>
class ZooSection {
private:
    std::vector<std::unique_ptr<T>> animals;

public:
    void addAnimal(std::unique_ptr<T> animal);
    double totalFood() const;
    size_t size() const;
    T* getAnimal(size_t index) const;
};

template<typename T>
void ZooSection<T>::addAnimal(std::unique_ptr<T> animal) {
    if (!animal) {
        throw std::runtime_error("ERR: ne moze se dodati nullptr");
    }
    animals.push_back(std::move(animal));
}

template<typename T>
double ZooSection<T>::totalFood() const {
    double total = 0;
    for (size_t i = 0; i < animals.size(); ++i) {
        total += animals[i]->getDailyFood();
    }
    return total;
}

template<typename T>
size_t ZooSection<T>::size() const {
    return animals.size();
}

template<typename T>
T* ZooSection<T>::getAnimal(size_t index) const {
    if (index >= animals.size()) {
        throw std::out_of_range("ERR:indeks izvan granica");
    }
    return animals[index].get();
}

#endif
