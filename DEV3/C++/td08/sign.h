/*!
 * \file sign_incomplete.h
 *
 * \brief Définition de l'énumération fortement typée g54027::Sign
 *        et de fonctions associées.
 */
#ifndef SIGN_INCOMPLETE_H
#define SIGN_INCOMPLETE_H

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
     *        [nombre (strictement) positif]
     *        (https://fr.wikipedia.org/wiki/Nombre_positif).
     *
     * Lorsqu'on transtype Sign::PLUS en entier, on obtient la
     * valeur +1.
     */
    PLUS = +1,

    /*!
     * \brief Constante d'énumération destinée à représenter le
     *        signe « moins » (-), c'est-à-dire celui d'un
     *        [nombre (strictement) négatif]
     *        (https://fr.wikipedia.org/wiki/Nombre_n%C3%A9gatif).
     *
     * Lorsqu'on transtype Sign::MINUS en entier, on obtient la
     * valeur -1.
     */
    MINUS = -1,

    /*!
     * \brief Constante d'énumération destinée à représenter le
     *        signe du nombre [zéro]
     *        (https://fr.wikipedia.org/wiki/Z%C3%A9ro).
     *
     * Lorsqu'on transtype Sign::ZERO en entier, on obtient la
     * valeur 0.
     */
    ZERO = 0
};

// prototypes (pas vraiment nécesssaire si fonction inline)

/*!
 * \brief Fonction retournant le signe d'un entier donné.
 *
 * \param value l'entier dont on désire le signe.
 *
 * \return le signe de `value`.
 */
constexpr Sign sign(int value);

/*!
 * \brief Fonction retournant le signe opposé d'un signe donné.
 *
 * On a :
 *
 * |    sign     | opposite(sign) |
 * |:-----------:|:--------------:|
 * | Form::PLUS  |  Form::MINUS   |
 * | Form::MINUS |  Form::PLUS    |
 * | Form::ZERO  |  Form::ZERO    |
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
 * | Form::ZERO  |  Form::ZERO   |
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
 * est étendue pour prendre en compte le signe de zéro :
 *
 * |     lhs     |     rhs     | product(lhs, rhs) |
 * |:-----------:|:-----------:|:-----------------:|
 * | Form::PLUS  | Form::PLUS  |     Form::PLUS    |
 * | Form::PLUS  | Form::MINUS |     Form::MINUS   |
 * | Form::PLUS  | Form::ZERO  |     Form::ZERO    |
 * | Form::MINUS | Form::PLUS  |     Form::MINUS   |
 * | Form::MINUS | Form::MINUS |     Form::PLUS    |
 * | Form::MINUS | Form::ZERO  |     Form::ZERO    |
 * | Form::ZERO  | Form::PLUS  |     Form::ZERO    |
 * | Form::ZERO  | Form::MINUS |     Form::ZERO    |
 * | Form::ZERO  | Form::ZERO  |     Form::ZERO    |
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
 * est étendue pour prendre en compte le signe de zéro :
 *
 * |     lhs     |     rhs     |    lhs * rhs   |
 * |:-----------:|:-----------:|:--------------:|
 * | Form::PLUS  | Form::PLUS  |   Form::PLUS   |
 * | Form::PLUS  | Form::MINUS |   Form::MINUS  |
 * | Form::PLUS  | Form::ZERO  |   Form::ZERO   |
 * | Form::MINUS | Form::PLUS  |   Form::MINUS  |
 * | Form::MINUS | Form::MINUS |   Form::PLUS   |
 * | Form::MINUS | Form::ZERO  |   Form::ZERO   |
 * | Form::ZERO  | Form::PLUS  |   Form::ZERO   |
 * | Form::ZERO  | Form::MINUS |   Form::ZERO   |
 * | Form::ZERO  | Form::ZERO  |   Form::ZERO   |
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
 * \param out le flux dans lequel l'injection est réalisée.
 * \param sign le signe à injecter.
 *
 * \return le flux après injection.
 */
inline std::ostream & operator<<(std::ostream & out, Sign sign);

// implémentations

constexpr Sign sign(int value) {
    if (value == 0) {
        return Sign::ZERO;
    } else if (value > 0) {
        return Sign::PLUS;
    }
    return Sign::MINUS;
}

constexpr Sign opposite(Sign sign) {
    if (sign == Sign::MINUS) {
        return Sign::PLUS;
    } else if (sign == Sign::PLUS) {
        return Sign::MINUS;
    }
    return Sign::ZERO;
}

constexpr Sign operator-(Sign sign) {
    return opposite(sign);
}

constexpr Sign product(Sign lhs, Sign rhs) {
    if (lhs == Sign::ZERO || rhs == Sign::ZERO) {
        return Sign::ZERO;
    } else if (lhs == rhs) {
        return Sign::PLUS;
    }
    return Sign::MINUS;

}

constexpr Sign operator*(Sign lhs, Sign rhs) {
    return product(lhs, rhs);
}

inline std::string to_string(Sign sign) {
    switch (sign) {
    case Sign::MINUS:
        return " - ";
    case Sign::PLUS:
        return " + ";
    case Sign::ZERO:
        return " 0 ";
    }
    return " ? ";
}

inline std::ostream & operator<<(std::ostream & out, Sign sign) {
    return out << to_string(sign);
}

}

#endif // SIGN_INCOMPLETE_H
