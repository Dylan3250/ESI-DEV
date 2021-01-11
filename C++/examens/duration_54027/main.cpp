#include "main.h"
#include <iostream>
#include "duration.h"
#include "data.h"
#include <vector>

int main() {
    std::vector<g54027::Duration> durations;
    for (auto const & value : g54027::data_sidase(1000)) {
        durations.push_back({std::get<0>(value), std::get<1>(value), std::get<2>(value)});
    }

    unsigned long long min {};
    unsigned long long max {};
    for (unsigned long long i = 0; i < durations.size(); i++) {
        if (durations[i] > durations[max]) {
            max = i;
        }
        if (durations[i] < durations[min]) {
            min = i;
        }
        std::cout << "Duree " << i << " : " << durations[i] << std::endl;
    }
    std::cout << "\nDuree minimale : " << durations[min] << std::endl;
    std::cout << "Duree maximale : " << durations[max] << std::endl;

}
