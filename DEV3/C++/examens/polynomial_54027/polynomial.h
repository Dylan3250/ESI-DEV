/*!
 * \file polynomial.h
 * \brief Définition de la classe nvs::Polynomial.
 */
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "function.h"
#include "monomial.h"

#include <map>
#include <vector>
#include <string>
#include <algorithm>

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace nvs {

/*!
 * \brief Classe représentant un polynôme d'une seule variable.
 *
 * Un polynôme est une somme de monômes. Il est donc caractérisé
 * par un ensemble de degrés et de coefficients. On
 * se limite :
 *
 *   + à des valeurs de degré entières nulles ou positives ;
 *   + à des valeurs de coefficient entières non nulles sauf si
 *     le polynôme est constitué d'un seul monôme de degré nul.
 *
 * Par exemple, le polynôme constitué des monômes :
 *
 *    + de degré 12 et de coefficient -5 ;
 *    + de degré 2 et de coefficient 12 ;
 *    + de degré 0 et de coefficient 8
 *
 * correspond à la fonction mathématique : 8 + 12 x - 5 x^12.
 *
 * Une valeur de coefficient nulle est interdite, sauf si le polynôme
 * est un monôme de degré zéro. Un tel polynôme correspond à la
 * fonction zéro : 0 x^0.
 *
 * _Remarque_ : il serait plus _propre_ d'utiliser une classe
 * spécifique pour la fonction zéro, mais cela complexifierait
 * le problème.
 */
class Polynomial :

    public Function {
    // clé : degré
    // valeur : coefficient
    const std::map<unsigned, int> polynomial_;

  public:

    /*!
     * \brief Constructeur.
     *
     * \param polynomial tableau associatif dont les clés sont les
     *                   degrés et les valeurs les coefficients des
     *                   monômes formant le polynôme.
     *
     * \throw std::invalid_argument si :
     *      + `polynomial` est vide ;
     *      + il existe au moins un coefficient nul alors que le
     *        polynôme n'est pas la fonction zéro.
     */
    explicit inline
    Polynomial(const std::map<unsigned, int> & polynomial);

    /*!
     * \brief Constructeur à partir d'un monôme.
     *
     * \param monomial monôme à convertir en polynôme.
     */
    explicit inline Polynomial(const Monomial & monomial);

    /*!
     * \brief Accesseur en lecture des degrés et coefficients des monômes
     *        du polynôme.
     *
     * \return tableau associatif dont les clés sont les degrés (rangés
     *         dans l'ordre croissant) et les valeurs sont les
     *         coefficients des monômes formant le polynôme.
     */
    inline const std::map<unsigned, int> & polynomial() const;

    /*!
     * \brief Opérateur d'évaluation du polynôme.
     *
     * \param x valeur pour laquelle on désire évaluer le polynôme.
     *
     * \return valeur du polynôme en `x`.
     */
    inline double operator()(double x) const override;

    /*!
     * \brief Conversion d'un polynôme en ses monômes.
     *
     * \return tableau des monômes formant le polynôme, rangés dans
     *         l'ordre croissant des degrés.
     */
    inline std::vector<Monomial> to_monomial() const;

    /*!
     * \brief Conversion d'un polynôme en std::string.
     *
     * Par exemple, le polynôme constitué des monômes :
     *
     *    + de degré 12 et de coefficient -5 ;
     *    + de degré 2 et de coefficient 12 ;
     *    + de degré 0 et de coefficient 8
     *
     * est représenté par la std::string : 8 + 12 x - 5 x^12.
     *
     * \return représentation du polynôme sous la forme d'une
     *         std::string.
     */
    std::string to_string() const override;
};

// prototypes

// implémentations

Polynomial::Polynomial(const std::map<unsigned, int> & polynomial) :
    polynomial_ {polynomial} {
    if (polynomial.size() == 0) {
        throw std::invalid_argument("Liste de polynome vide");
    }
    for (auto const & value : polynomial) {
        if (value.second == 0) {
            throw std::invalid_argument("Un des coéficient est 0");
        }
    }
}

Polynomial::Polynomial(const Monomial & monomial) :
    polynomial_ {std::map<unsigned, int> { monomial.degree(), static_cast<unsigned>(monomial.coefficient())} }
{}

const std::map<unsigned, int> & Polynomial::polynomial() const {
    return polynomial_;
}

double Polynomial::operator()(double x) const {
    double valueCalc = 0;
    for (auto const & value : polynomial()) {
        valueCalc += value.second * (pow(x, value.first));
    }
    return valueCalc;
}

std::vector<Monomial> Polynomial::to_monomial() const {
    std::vector<Monomial> allMono;
    for (auto const & value : polynomial_) {
        allMono.push_back(Monomial {value.first, value.second});
    }
    std::sort(allMono.begin(),
              allMono.end(), [](
                  const Monomial & a,
    const Monomial & b) -> bool {
        return a.degree() > b.degree();
    });

    return allMono;
}

}

#endif // POLYNOMIAL_H
