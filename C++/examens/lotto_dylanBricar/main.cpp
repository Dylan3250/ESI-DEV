#include "main.h"
#include "pronostic.h"
#include "data/data.h"
#include "lotto.h"
#include <iostream>
#include <algorithm>

int main() {
    unsigned sizeNb = 10;
    unsigned maxNb = 100;

    g54027::Lotto lotto {sizeNb, maxNb};
    auto datas = nvs::lotto::data(sizeNb, maxNb, 1000);
    unsigned countFail = 0;
    unsigned countGood = 0;

    for (const auto & value : datas) {
        try {
            lotto.add(g54027::Pronostic {value.first, value.second});
            countGood++;
        }  catch (const std::exception & e) {
            countFail++;
        }
    }

    std::cout << "Nombre de tirage ajouté réussi : " << countGood <<
              std::endl;
    std::cout << "Nombre de tirage ajouté raté : " << countFail <<
              std::endl;

    lotto.set_draw();
    for (unsigned i = 0; i < sizeNb; i++) {
        std::cout << "Exactement " << i << " bons chiffres : "
                  << lotto.winner(i).size() << std::endl;
        std::cout << "Au moins " << i << " bons chiffres : "
                  << lotto.winner(
                      i, g54027::Equality::INCLUSIVE).size() << std::endl;
    }
}
