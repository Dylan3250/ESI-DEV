/*!
 * \file sign.h
 *
 * \brief Définition de l'énumération fortement typée g54027::Sign
 *        et de fonctions associées.
 */
#ifndef SIGN_H
#define SIGN_H

#include <string>
#include <ostream>

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 */
namespace g54027 {

/*!
 * \brief Énumération fortement typée représentant un [signe]
 *        (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique))
 *        au sens mathématique.
 */
enum class Sign {
    /*!
     * \brief Constante d'énumération destinée à représenter le
     *        signe « plus » (+), c'est-à-dire celui d'un
     *        [nombre positif]
     *        (https://fr.wikipedia.org/wiki/Nombre_positif).
     *
     * Lorsqu'on transtype Sign::PLUS en entier, on obtient la
     * valeur +1.
     */
    PLUS = +1,

    /*!
     * \brief Constante d'énumération destinée à représenter le
     *        signe « moins » (-), c'est-à-dire celui d'un
     *        [nombre négatif]
     *        (https://fr.wikipedia.org/wiki/Nombre_n%C3%A9gatif).
     *
     * Lorsqu'on transtype Sign::MINUS en entier, on obtient la
     * valeur -1.
     */
    MINUS = -1
};

// prototypes (pas vraiment nécesssaire si fonction inline)

/*!
 * \brief Fonction retournant le signe d'un entier donné.
 *
 * De manière arbitraire, cette fonction retourne Sign::PLUS
 * si `value` vaut zéro.
 *
 * \param value l'entier dont on désire le signe.
 *
 * \return le signe de `value`.
 */
template <typename T>
constexpr Sign sign(T value);

/*!
 * \brief Fonction retournant le signe opposé d'un signe donné.
 *
 * On a :
 *
 * |    sign     | opposite(sign) |
 * |:-----------:|:--------------:|
 * | Form::PLUS  |  Form::MINUS   |
 * | Form::MINUS |  Form::PLUS    |
 *
 * \param sign signe dont on désire obtenir l'opposé.
 *
 * \return le signe opposé de `sign`.
 *
 * \see operator-(Sign).
 */
constexpr Sign opposite(Sign sign);

/*!
 * \brief Opérateur retournant le signe opposé d'un signe donné.
 *
 * On a :
 *
 * |    sign     |     - sign    |
 * |:-----------:|:-------------:|
 * | Form::PLUS  |  Form::MINUS  |
 * | Form::MINUS |  Form::PLUS   |
 *
 * \param sign signe dont on désire obtenir l'opposé.
 *
 * \return le signe opposé de `sign`.
 *
 * \see opposite(Sign).
 */
constexpr Sign operator-(Sign sign);

/*!
 * \brief Fonction retournant le signe produit de deux g54027::Sign.
 *
 * La [règle des signes]
 * (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique)#R%C3%A8gle_des_signes)
 * est appliquée :
 *
 * |     lhs     |     rhs     | product(lhs, rhs) |
 * |:-----------:|:-----------:|:-----------------:|
 * | Form::PLUS  | Form::PLUS  |     Form::PLUS    |
 * | Form::PLUS  | Form::MINUS |     Form::MINUS   |
 * | Form::MINUS | Form::PLUS  |     Form::MINUS   |
 * | Form::MINUS | Form::MINUS |     Form::PLUS    |
 *
 * \param lhs un premier Sign.
 * \param rhs un second Sign.
 *
 * \return le signe produit de `lhs` et `rhs` comme dans le tableau
 *         ci-dessus.
 *
 * \see operator*(Sign, Sign).
 */
constexpr Sign product(Sign lhs, Sign rhs);

/*!
 * \brief Opérateur retournant le signe produit de deux g54027::Sign.
 *
 * La [règle des signes]
 * (https://fr.wikipedia.org/wiki/Signe_(arithm%C3%A9tique)#R%C3%A8gle_des_signes)
 * est appliquée :
 *
 * |     lhs     |     rhs     |    lhs * rhs   |
 * |:-----------:|:-----------:|:--------------:|
 * | Form::PLUS  | Form::PLUS  |   Form::PLUS   |
 * | Form::PLUS  | Form::MINUS |   Form::MINUS  |
 * | Form::MINUS | Form::PLUS  |   Form::MINUS  |
 * | Form::MINUS | Form::MINUS |   Form::PLUS   |
 *
 * \param lhs un premier Sign.
 * \param rhs un second Sign.
 *
 * \return le signe produit de `lhs` et `rhs` comme dans le tableau
 *         ci-dessus.
 *
 * \see product(Sign, Sign).
 */
constexpr Sign operator*(Sign lhs, Sign rhs);

/*!
 * \brief Fonction de conversion d'un g54027::Sign en std::string.
 *
 * \param sign le signe à convertir.
 *
 * \return une std::string représentant `sign`.
 */
inline std::string to_string(Sign sign);

/*!
 * \brief Opérateur d'injection d'un g54027::Sign dans un flux en
 *        sortie.
 *
 * La std::string retournée par l'appel de fonction to_string(Sign)
 * avec `sign` en argument est injectée dans `out`.
 *
 * \param out le flux dans lequel l'injection est réalisée.
 * \param sign le signe à injecter.
 *
 * \return le flux après injection.
 *
 * \see to_string(Sign).
 */
inline std::ostream & operator<<(std::ostream & out, Sign sign);

// implémentations

template <typename T>
constexpr Sign sign(T value) {
    return value < static_cast<T>(0) ? Sign::MINUS : Sign::PLUS;
}

constexpr Sign opposite(Sign sign) {
    return -sign;
}

constexpr Sign operator-(Sign sign) {
    return sign == Sign::PLUS ? Sign::MINUS : Sign::PLUS;
}

constexpr Sign product(Sign lhs, Sign rhs) {
    return lhs * rhs;
}

constexpr Sign operator*(Sign lhs, Sign rhs) {
    return lhs == rhs ? Sign::PLUS : Sign::MINUS;
}

inline std::string to_string(Sign sign) {
    std::string result;

    switch (sign) {
        case Sign::PLUS:
            result = "+";
            break;
        case Sign::MINUS:
            result = "-";
            break;
    }

    return result;
}

inline std::ostream & operator<<(std::ostream & out, Sign sign) {
    return out << to_string(sign);
}

}

#endif // SIGN_H
