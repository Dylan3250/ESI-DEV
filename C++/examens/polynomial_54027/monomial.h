/*!
 * \file monomial.h
 * \brief Définition de la classe nvs::Monomial.
 */
#ifndef MONOMIAL_H
#define MONOMIAL_H

#include "function.h"
#include <cmath>
#include <string>

// TODO : modifier / compléter ici éventuellement : début

// TODO : modifier / compléter ici éventuellement : fin

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace nvs {

/*!
 * \brief Classe représentant un monôme d'une seule variable.
 *
 * Un monôme est caractérisé par un degré et un coefficient. On
 * se limite :
 *
 *   + à des valeurs de degré entières nulles ou positives ;
 *   + à des valeurs de coefficient entières non nulles sauf si
 *     le degré est lui-même nul.
 *
 * Par exemple, le monôme de degré 12 et de coefficient -5
 * correspond à la fonction mathématique : -5 x^12.
 *
 * Une valeur de coefficient nulle est interdite, sauf si le degré
 * est également égal à zéro. Un tel monôme correspond à la
 * fonction zéro : 0 x^0.
 *
 * _Remarque_ : il serait plus _propre_ d'utiliser une classe
 * spécifique pour la fonction zéro, mais cela complexifierait
 * le problème.
 */
class Monomial :

    public Function {
    const unsigned degree_;

    const int coefficient_;

  public:

    /*!
     * \brief Constructeur.
     *
     * \param degree degré du monôme.
     * \param coefficient coefficient du monôme.
     *
     * \throw std::invalid_argument si le coefficient est nul
     *        alors que le degré ne l'est pas.
     */
    explicit inline Monomial(unsigned degree = 0, int coefficient = 1);

    /*!
     * \brief Accesseur en lecture du degré.
     *
     * \return degré du monôme.
     */
    inline unsigned degree() const;

    /*!
     * \brief Accesseur en lecture du coefficient.
     *
     * \return coefficient du monôme.
     */
    inline int coefficient() const;

    /*!
     * \brief Opérateur d'évaluation du monôme.
     *
     * \param x valeur pour laquelle on désire évaluer le monôme.
     *
     * \return valeur du monôme en `x`.
     */
    inline double operator()(double x) const override;

    /*!
     * \brief Conversion d'un monôme en std::string.
     *
     * Le monôme de degré 12 et de coefficient -5 est
     * représenté par la std::string -5 x^12.
     *
     * \return représentation du monôme sous la forme d'une
     *         std::string.
     */
    std::string to_string() const override;
};

// prototypes

// implémentations

Monomial::Monomial(unsigned degree, int coefficient) :
    degree_ { degree },
    coefficient_ { coefficient } {
    if (coefficient == 0 && degree != 0) {
        throw std::invalid_argument("Coef nul mais degré non");
    }
}

unsigned Monomial::degree() const {
    return degree_;
}

int Monomial::coefficient() const {
    return coefficient_;
}

double Monomial::operator()(double x) const {
    return coefficient() * (pow(x, degree()));
}

}

#endif // MONOMIAL_H
