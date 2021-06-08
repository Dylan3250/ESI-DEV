#include "data.h"
#include <iostream>
#include "monomial.h"
#include "polynomial.h"
#include "function.h"
#include <vector>

int main(int argc, char ** argv) {
    std::vector<nvs::Monomial> vm;
    std::vector<nvs::Polynomial> vp;
    unsigned countErrorM { };
    unsigned countErrorP { };

    for (const auto & values : nvs::data()) {
        if (values.first == 'm') {
            try {
                vm.push_back(nvs::Monomial {static_cast<unsigned int>(values.second.at(0)), values.second.at(1)});
            }  catch (const std::exception & e) {
                std::cerr << "Erreur : " << e.what() << std::endl;
                countErrorM++;
            }
        } else {
            try {
                vp.push_back(nvs::Polynomial {nvs::Monomial {static_cast<unsigned int>(values.second.at(0)), values.second.at(1)}});
            }  catch (const std::exception & e) {
                std::cerr << "Erreur : " << e.what() << std::endl;
                countErrorP++;
            }
        }
    }

    std::cout << "Nombre d'erreur pour les Monomial : " << countErrorM <<
              std::endl;
    std::cout << "Nombre d'erreur pour les Polynomial : " << countErrorP
              << std::endl;

    std::vector<std::reference_wrapper<nvs::Function>> vf;
    std::cout << "\nNombre de Monomial : " << vm.size() << std::endl;
    for (const auto & valuesVM : vm) {
        std::cout << valuesVM.to_string() << std::endl;
        // vf.push_back(&valuesVM));
    }

    std::cout << "\nNombre de Polynomial : " << vp.size() << std::endl;
    for (const auto & valuesVP : vp) {
        std::cout << valuesVP.to_string() << std::endl;
        // vf.push_back(&valuesVP));
    }

    char * end;
    double threshold = 1;

    if (argc > 0) {
        try {
            threshold = std::strtod(argv[0], &end);
        }  catch (const std::exception & e) { }
    }

    std::cout << "\nNombre d'élément de VF : " << vf.size() <<
              std::endl;
    for (const auto & value : vf) {
        // std::cout << value(threshold) << std::endl;
    }

}
