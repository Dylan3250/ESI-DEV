/*!
 * \file duration.h
 *
 * \brief Définition de la classe nvs::Duration et de fonctions
 *        associées.
 */
#ifndef DURATION_H
#define DURATION_H

#include <string>
#include <ostream>
#include <tuple>

// TODO : éventuellement ajouter include

#include "sign.h"
#include <string>

namespace g54027 {

/*!
 * \brief Classe représentant une durée.
 *
 * La durée peut être positive ou négative.
 *
 * Son signe est représenté par un nvs::Sign, stocké dans \ref sign_.
 *
 * Sa valeur numérique  est constituée de deux parties entières
 * positives :
 *
 *  + un nombre de jours, stocké dans \ref days_ ;
 *  + un nombre de secondes, stocké dans \ref seconds_.
 *
 * La valeur de cette dernière est toujours strictement inférieur
 * au nombres de secondes dans une journée, \ref SECONDS_IN_DAY.
 *
 * La valeur absolue de la durée totale est égale
 * à \ref days_ + \ref seconds_.
 *
 * Une durée nulle, c'est-à-dire formée de zéro jour et zéro
 * seconde, peut être de signe positif ou négatif, indistinctement.
 *
 */
class Duration {
  public:

    /*!
     * \brief Nombre de secondes dans une minute.
     */
    constexpr static unsigned SECONDS_IN_MINUTE { 60 };

    /*!
     * \brief Nombre de minutes dans une heure.
     */
    constexpr static unsigned MINUTES_IN_HOUR { 60 };

    /*!
     * \brief Nombre d'heures dans un jour.
     */
    constexpr static unsigned HOURS_IN_DAY { 24 };

    /*!
     * \brief Nombre de secondes dans un jour.
     */
    constexpr static unsigned SECONDS_IN_DAY { SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY };

  private:

    /*!
     * \brief Signe de la Duration.
     */
    const Sign sign_;

    /*!
     * \brief Nombre de jours de la Duration.
     *
     * La valeur absolue de la durée totale est égale
     * à \ref days_ + \ref seconds_.
     */
    const unsigned days_;

    /*!
     * \brief Nombre de secondes de la Duration.
     *
     * Ce nombre est dans l'intervalle [ 0, \ref SECONDS_IN_DAY [.
     *
     * La valeur absolue de la durée totale est égale
     * à \ref days_ + \ref seconds_.
     */
    const unsigned seconds_;

  public:

    /*!
     * \brief Fabrique d'une durée à partir d'un signe et d'un nombre
     *        de secondes.
     *
     * L'utilisation de cette fabrique palie le fait qu'il est
     * impossible d'avoir de constructeur sur base d'un signe
     * et d'un nombre de secondes simultanément à l'existence du
     * constructeur
     * Duration(Sign, unsigned, unsigned), de ses valeurs par
     * défaut et des ambiguïtés d'appel qui en résulteraient.
     *
     * La valeur absolue de la durée totale de la Duration construite
     * égale `seconds`.
     *
     * _Remarque_ : il est tout à fait possible, voire très probable,
     * que le nombre de
     * secondes fourni excède la durée d'un jour. Dans ce cas, il
     * faut tenir compte de ces jours dans l'initialisation de
     * l'attribut \ref days_.
     *
     * \param sign un signe.
     * \param seconds un nombre de secondes.
     *
     * \return une Duration de signe `sign` et de durée totale
     *         égale en valeur absolue à `seconds`.
     */
    constexpr static Duration durationFromSeconds(Sign sign = Sign::PLUS,
            unsigned long seconds = 0);

    /*!
     * \brief Constructeur de Duration à partir d'un signe, d'un
     *        nombre de jours et de secondes.
     *
     * La valeur absolue de la durée totale de la Duration construite
     * égale à la somme `days` + `seconds`.
     *
     * _Remarque_ : il est tout à fait possible que le nombre de
     * secondes fourni excède la durée d'un jour. Dans ce cas, il
     * faut tenir compte de ces jours dans l'initialisation de
     * l'attribut \ref days_.
     *
     * \param sign un signe.
     * \param days un nombre de jours.
     * \param seconds un nombre de secondes.
     */
    constexpr Duration(Sign sign = Sign::PLUS,
                       unsigned days = 0,
                       unsigned seconds = 0);

    /*!
     * \brief Constructeur de Duration à partir d'un nombre de secondes.
     *
     * Ce constructeur ne sert qu'à la construction de durées
     * positives : le signe est ici fixé à Sign::PLUS.
     *
     * La durée totale de la Duration construite égale `seconds`.
     *
     * _Remarque_ : il est tout à fait possible que le nombre de
     * secondes fourni excède la durée d'un jour. Dans ce cas, il
     * faut tenir compte de ces jours dans l'initialisation de
     * l'attribut \ref days_.
     *
     * \param seconds un nombre de secondes.
     */
    constexpr Duration(unsigned long seconds);

    /*!
     * \brief Accesseur en lecture du signe.
     *
     * \return le signe de la Duration.
     */
    constexpr Sign sign() const;

    /*!
     * \brief Accesseur en lecture du nombre de secondes.
     *
     * \return le nombre de secondes de la Duration.
     */
    constexpr unsigned seconds() const;

    /*!
     * \brief Accesseur en lecture du nombre de jours.
     *
     * \return le nombre de jours de la Duration.
     */
    constexpr unsigned days() const;

    /*!
     * \brief Conversion d'une durée en secondes.
     *
     * Par exemple, si l'attribut :
     *
     *  + \ref sign_ vaut Sign::MINUS ;
     *  + \ref days_ vaut 23 ;
     *  + \ref seconds_ vaut 34589 ;
     *
     * le long retourné vaut :
     * ```
     * -2021789
     * ```
     * car 23 jours correspondent à 1987200 secondes, auxquelles
     * on ajoute 34589 secondes.
     *
     * \return le nombre total de secondes de la Duration.
     */
    constexpr long to_seconds() const;

    /*!
     * \brief Conversion d'une durée en jours.
     *
     * Par exemple, si l'attribut :
     *
     *  + \ref sign_ vaut Sign::MINUS ;
     *  + \ref days_ vaut 23 ;
     *  + \ref seconds_ vaut 34589 ;
     *
     * le double retourné affiché avec 4 chiffres après la virgule
     * est :
     * ```
     * -23.4003
     * ```
     * car 34589 secondes correspondent à 0,400335648... jours.
     *
     * \return le nombre total de jours de la Duration.
     */
    constexpr double to_days() const;

    /*!
     * \brief Conversion d'une durée en
     *        <signe, jours, heures, minutes, secondes>.
     *
     * Dans le std::tuple retourné, le champ d'index :
     *
     *  + 0 : représente le signe de la Duration ;
     *  + 1 : représente le nombre de jours complets de la Duration ;
     *  + 2 : représente le nombre d'heures complètes de la Duration
     *    sans compter les jours ;
     *  + 3 : représente le nombre de minutes complètes de la Duration
     *    sans compter les jours ni les heures ;
     *  + 4 : représente le nombre de secondes complètes de la Duration
     *    sans compter les jours, les heures ni le minutes.
     *
     * Par exemple, si l'attribut :
     *
     *  + \ref sign_ vaut Sign::PLUS ;
     *  + \ref days_ vaut 23 ;
     *  + \ref seconds_ vaut 34589 ;
     *
     * le std::tuple retourné est :
     * ```
     * < Sign::PLUS, 23, 9, 36, 29 >
     * ```
     * car 34589 secondes correspondent à 9 heures 36 minutes et
     * 29 secondes.
     *
     * \return un std::tuple tel que décrit ci-dessus.
     */
    constexpr std::tuple<Sign, unsigned, unsigned, unsigned, unsigned>
    sdhms() const;

    /*!
     * \brief Représentation d'une durée sous la forme d'une chaîne
     *        de caractères.
     *
     * Il s'agit d'afficher le signe, le nombre de jours et celui
     * de secondes de la durée, en indiquant clairement quel chiffre
     * est celui des jours ou des secondes.
     *
     * \return la Duration comme une std::string.
     */
    inline std::string to_string() const;
};

// prototypes de fonctions

/*!
 * \brief Conversion d'une durée en secondes.
 *
 * \param duration la Duration à convertir en secondes.
 *
 * \return le nombre total de secondes de `duration`.
 *
 * \see Duration::to_seconds().
 */
constexpr long to_seconds(const Duration & duration);

/*!
 * \brief Conversion d'une durée en jours.
 *
 * \param duration la Duration à convertir en jours.
 *
 * \return le nombre total de jours de `duration`.
 *
 * \see Duration::to_days().
 */
constexpr double to_days(const Duration & duration);

/*!
* \brief Représentation d'une durée sous la forme d'une chaîne
*        de caractères.
*
* \param duration la Duration à convertir en std::string.
*
* \return la std::string représentant `duration`.
*
* \see Duration::to_string().
*/
inline std::string to_string(const Duration & duration);

/*!
 * \brief Opérateur d'injection d'une durée dans un flux en sortie.
 *
 * La std::string retournée par la méthode Duration::to_string()
 * de l'objet `duration` est injectée dans `out`.
 *
 * \param out le flux dans lequel l'injection a lieu.
 * \param duration la Duration à injecter.
 *
 * \return le flux après l'injection de la Duration.
 *
 * \see Duration::to_string().
 */
inline std::ostream & operator<<(std::ostream & out,
                                 const Duration & duration);

/*!
 * \brief Opérateur de comparaison pour tester l'égalité de deux
 *        durées.
 *
 * Le signe intervient lors de la comparaison, comme pour les
 * entiers signés en mathématique.
 *
 * _Remarque_ : deux durées nulles sont égales, même si leurs signes
 * diffèrent.
 *
 * \param lhs une Duration.
 * \param rhs une Duration
 *
 * \return `true` si `lhs` et `rhs` sont égales, `false` sinon.
 */
constexpr bool operator==(const Duration & lhs, const Duration & rhs);

/*!
 * \brief Opérateur de comparaison pour tester la différence de deux
 *        durées.
 *
 * Le signe intervient lors de la comparaison, comme pour les
 * entiers signés en mathématique.
 *
 * _Remarque_ : deux durées nulles sont égales, même si leurs signes
 * diffèrent.
 *
 * \param lhs une Duration.
 * \param rhs une Duration
 *
 * \return `true` si `lhs` et `rhs` sont différentes, `false` sinon.
 */
constexpr bool operator!=(const Duration & lhs, const Duration & rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        strictement inférieur de deux durées.
 *
 * Le signe intervient lors de la comparaison, comme pour les
 * entiers signés en mathématique.
 *
 * \param lhs une Duration.
 * \param rhs une Duration
 *
 * \return `true` si `lhs` est strictement inférieure à `rhs`,
 *         `false` sinon.
 */
constexpr bool operator<(const Duration & lhs, const Duration & rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        inférieur ou égal de deux durées.
 *
 * Le signe intervient lors de la comparaison, comme pour les
 * entiers signés en mathématique.
 *
 * _Remarque_ : deux durées nulles sont égales, même si leurs signes
 * diffèrent.
 *
 * \param lhs une Duration.
 * \param rhs une Duration
 *
 * \return `true` si `lhs` est inférieure ou égale à `rhs`,
 *         `false` sinon.
 */
constexpr bool operator<=(const Duration & lhs, const Duration & rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        strictement supérieur de deux durées.
 *
 * Le signe intervient lors de la comparaison, comme pour les
 * entiers signés en mathématique.
 *
 * \param lhs une Duration.
 * \param rhs une Duration
 *
 * \return `true` si `lhs` est strictement supérieur à `rhs`,
 *         `false` sinon.
 */
constexpr bool operator>(const Duration & lhs, const Duration & rhs);

/*!
 * \brief Opérateur de comparaison pour tester la relation d'ordre
 *        supérieur ou égal de deux durées.
 *
 * Le signe intervient lors de la comparaison, comme pour les
 * entiers signés en mathématique.
 *
 * _Remarque_ : deux durées nulles sont égales, même si leurs signes
 * diffèrent.
 *
 * \param lhs une Duration.
 * \param rhs une Duration
 *
 * \return `true` si `lhs` est supérieur ou égal à `rhs`,
 *         `false` sinon.
 */
constexpr bool operator>=(const Duration & lhs, const Duration & rhs);

/*!
 * \brief Opérateur d'inversion du signe d'une Duration.
 *
 * Par exemple, la durée inverse de :
 * ```
 * { - [ 60d : 85934s ] }
 * ```
 * est :
 * ```
 * { + [ 60d : 85934s ] }
 * ```
 *
 * _Remarque_ : on parle d'_inversion_ et d'_inverse_ mais il s'agit
 * plutôt d'_opposition_ et d'_opposée_ au sens mathématique.
 *
 * \param duration la Duration à inverser.
 *
 * \return la Duration correspondant à l'inverse de `duration`.
 */
constexpr Duration operator-(const Duration & duration);

/*!
 * \brief Opérateur d'addition de durées.
 *
 * Par exemple, si les valeurs des attributs de `lhs` sont tels que :
 *
 *  + \ref Duration::sign_ égal Sign::PLUS ;
 *  + \ref Duration::days_ égal 23 ;
 *  + \ref Duration::seconds_ égal 34589 ;
 *
 * tandis que pour ceux de `rhs`, on a :
 *
 *  + \ref Duration::sign_ égal Sign::MINUS ;
 *  + \ref Duration::days_ égal 12 ;
 *  + \ref Duration::seconds_ égal 64589 ;
 *
 * la durée retournée a pour valeurs d'attibuts :
 *
 *  + \ref Duration::sign_ égal à Sign::PLUS ;
 *  + \ref Duration::days_ égal à 10 ;
 *  + \ref Duration::seconds_ égal à 56400 ;
 *
 * car :
 *
 * ```
 * { + [ 23d : 34589s ] } + { - [ 12d : 64589s ] } =  { + [ 10d : 56400s ] }
 * ```
 *
 * \param lhs une durée.
 * \param rhs une durée.
 *
 * \return la durée cumulée `lhs` et `rhs`.
 */
constexpr Duration operator+(const Duration & lhs,
                             const Duration & rhs);

// implémentation méthodes

constexpr Duration::Duration(Sign sign, unsigned days,
                             unsigned seconds) :
    sign_ { sign },
    days_ { days + seconds / (3600 * 24)},
    seconds_ { seconds % (3600 * 24) }
{ }

constexpr Duration::Duration(unsigned long seconds) :
    sign_ { Sign::PLUS },
    days_ { seconds / (3600 * 24)},
    seconds_ { seconds % (3600 * 24) }
{ }

constexpr Duration Duration::durationFromSeconds(Sign sign,
        unsigned long seconds) {
    return { Duration {sign, 0, seconds} };
}

constexpr Sign Duration::sign() const {
    return sign_;
}

constexpr unsigned Duration::seconds() const {
    return seconds_;
}

constexpr unsigned Duration::days() const {
    return days_;
}

constexpr long Duration::to_seconds() const {
    long calcul = seconds() + (days() * Duration::SECONDS_IN_DAY);
    if (sign() == Sign::MINUS) {
        calcul *= -1;
    }
    return calcul;
}

constexpr double Duration::to_days() const {
    double calcul = seconds() / (3600 * 24) + days();
    if (sign() == Sign::MINUS) {
        calcul *= -1;
    }
    return calcul;
}

std::string Duration::to_string() const {
    std::string str = sign_ == Sign::MINUS ? "- " : "+ ";
    str += std::to_string(days()) + " jour(s) ";
    str += std::to_string(seconds()) + " seconde(s)";
    return str;
}

constexpr std::tuple<Sign, unsigned, unsigned, unsigned, unsigned>
Duration::sdhms() const {
    return {
        sign(),
        days(),
        seconds() / 3600,
        seconds() / 60 % 60,
        seconds()
    };
}

// implémentation fonctions

constexpr long to_seconds(const Duration & duration) {
    long calcul = duration.seconds() + (duration.days() *
                                        Duration::SECONDS_IN_DAY);
    if (duration.sign() == Sign::MINUS) {
        calcul *= -1;
    }
    return calcul;
}

constexpr double to_days(const Duration & duration) {
    double calcul = duration.seconds() / (3600 * 24) +
                    duration.days();
    if (duration.sign() == Sign::MINUS) {
        calcul *= -1;
    }
    return calcul;
}

std::string to_string(const Duration & duration) {
    std::string str = duration.sign() == Sign::MINUS ? "-" : "+";
    str += std::to_string(duration.days()) + "jour(s)";
    str += std::to_string(duration.days()) + "seconde(s)";
    return str;
}

std::ostream & operator<<(std::ostream & out,
                          const Duration & duration) {
    return out << duration.to_string();
}

constexpr bool operator==(const Duration & lhs,
                          const Duration & rhs) {
    return lhs.to_seconds() == rhs.to_seconds();
}

constexpr bool operator!=(const Duration & lhs,
                          const Duration & rhs) {
    return lhs.to_seconds() != rhs.to_seconds();
}

constexpr bool operator<(const Duration & lhs, const Duration & rhs) {
    return lhs.to_seconds() < rhs.to_seconds();
}

constexpr bool operator<=(const Duration & lhs,
                          const Duration & rhs) {
    return lhs.to_seconds() <= rhs.to_seconds();
}

constexpr bool operator>(const Duration & lhs, const Duration & rhs) {
    return lhs.to_seconds() > rhs.to_seconds();
}

constexpr bool operator>=(const Duration & lhs,
                          const Duration & rhs) {
    return lhs.to_seconds() >= rhs.to_seconds();
}

constexpr Duration operator-(const Duration & duration) {
    return Duration {-duration.sign(), duration.days(), duration.seconds()};
}

constexpr Duration operator+(const Duration & lhs,
                             const Duration & rhs) {
    return { Duration {lhs.to_seconds() + rhs.to_seconds() > 0 ? Sign::PLUS : Sign::MINUS,
                       0,
                       static_cast<unsigned>(lhs.to_seconds() + rhs.to_seconds()) } };
}

}   // namespace g54027

#endif // DURATION_H
