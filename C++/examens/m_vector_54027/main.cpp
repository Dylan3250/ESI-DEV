#include <iostream>
#include "m_vector.h"
#include "data.h"
#include <functional>

int main() {
    std::vector<he2b::g54027::m_vector> m_vector;
    unsigned formatString {};
    unsigned zeroComposant {};
    unsigned diffSizeCompos {};

    for (auto const & value : he2b::nvs::data(100)) {
        unsigned size;
        try {
            size = std::stoul(std::get<0>(value));
        }  catch (const std::exception & e) {
            formatString++;
            continue;
        }

        if (size == 0) {
            zeroComposant++;
            continue;
        }

        unsigned count {};
        while (count < std::get<1>(value).size() && count < size) {
            count++;
        }

        if (count < size) {
            diffSizeCompos++;
            continue;
        }

        try {
            m_vector.push_back(he2b::g54027::m_vector {std::get<1>(value)});
        } catch (const std::exception & e) { };
    }

    std::cout << "Erreur suite aux strings non signes : "
              << formatString << std::endl;
    std::cout << "Erreur suite aux strings = 0 : "
              << zeroComposant << std::endl;
    std::cout << "Erreur size different du nombre de composantes : "
              << diffSizeCompos << std::endl;
    std::cout << "Vecteurs sans erreurs : "
              << m_vector.size() << std::endl;

    std::cout << "\nVecteurs crees : " << std::endl;
    for (auto const & value : m_vector) {
        std::cout << value.to_string() << std::endl;
    }

    std::vector<std::reference_wrapper<const he2b::g54027::m_vector>>
            p_vector;
    for (unsigned long long i = 0; i < m_vector.size(); i++) {
        p_vector.push_back(m_vector[i]);
    }

    std::sort(p_vector.begin(),
              p_vector.end(), [](
                  const std::reference_wrapper<const he2b::g54027::m_vector> & a,
    const std::reference_wrapper<const he2b::g54027::m_vector> & b) {
        return &a.get() > &b.get();
    });

    std::cout << "\nApres le tri : " << std::endl;
    for (auto value : p_vector) {
        std::cout << value.get().to_string() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
