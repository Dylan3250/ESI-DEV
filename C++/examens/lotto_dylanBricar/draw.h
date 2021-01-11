/*!
 * \file draw.h
 * \brief Définition d'une classe implémentant un tirage au sort
 *        de jeu de lotto.
 */
#ifndef DRAW_H
#define DRAW_H

#include <set>
#include <string>
#include <ostream>

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace nvs
{

/*!
 * \brief Sous-espace de nom de l'application _Lotto_.
 *
 */
namespace lotto
{

/*!
 * \brief Classe implémentant un tirage au sort de lotto.
 */
class Draw
{
    unsigned max_;
    std::set<unsigned> value_;

  public:

    /*!
     * \brief Constructeur qui fait tout le boulot.
     *
     * Les chiffres tirés au sort sont au nombre de
     * `size`. Ils sont tous différents les uns des autres et
     * sont compris entre 1 et `max`, ces valeurs comprises.
     *
     * _Remarque_ : le constructeur utilise le moteur aléatoire
     * retourné par la fonction nvs::urng(). Les données produites
     * se répettent identiquement d'une exécution à l'autre car
     * la fonction nvs::randomize() n'est pas invoquée. Lors des
     * tests de vos classes et fonctions, n'oubliez pas d'invoquer
     * celle-ci : vos solutions doivent fonctionner quel que soit
     * le résultat du tirage du lotto.
     *
     * \param size la nombre de chiffres à tirer.
     * \param max la valeur maximale des chiffres à tirer.
     *
     * \throw std::invalid_argument dans les trois cas suivants :
     *
     *  + le nombre de chiffres du tirage est nul ;
     *  + la valeur maximale possible du tirage est nulle ;
     *  + la valeur maximale possible du tirage est
     *    strictement inférieure au nombre de valeurs de celui-ci.
     */
    Draw(unsigned size = 7, unsigned max = 50);

    /*!
     * \brief Accesseur en lecture du nombre de chiffres du tirage.
     *
     * \return le nombre de chiffres du tirage.
     */
    inline unsigned size() const;

    /*!
     * \brief Accesseur en lecture de la valeur maximale des
     *        chiffres à tirer.
     *
     * \return la valeur maximale des chiffres à tirer.
     */
    inline unsigned max() const;

    /*!
     * \brief Accesseur en lecture des chiffres tirés.
     *
     * \return les chiffres tirés.
     */
    inline const std::set<unsigned> & value() const;

    /*!
     * \brief Conversion en une chaîne de caractères du tirage.
     *
     * Les données converties en std::string sont :
     *
     *  + le nombre de chiffres tirés ;
     *  + la valeur maximale qu'il est possible de tirer ;
     *  + les chiffres tirés.
     *
     * \return une représentation sous la forme d'une chaîne de
     *         caractères du tirage.
     */
    std::string to_string() const;
};

// prototypes

/*!
 * \brief Opérateur d'injection d'un tirage de lotto dans un flux en
 *        sortie.
 *
 * Les données injectées dans le std::ostream sont :
 *
 *  + le nombre de chiffres tirés ;
 *  + la valeur maximale qu'il est possible de tirer ;
 *  + les chiffres tirés.
 *
 * \param out le flux dans lequel injecter les données.
 * \param draw le tirage à injecter dans le flux.
 *
 * \return le flux dans lequel les données ont été injectées.
 */
std::ostream & operator<<(std::ostream & out, const Draw & draw);

/*!
 * \brief Conversion en une chaîne de caractères du tirage.
 *
 * Les données converties en std::string sont :
 *
 *  + le nombre de chiffres tirés ;
 *  + la valeur maximale qu'il est possible de tirer ;
 *  + les chiffres tirés.
 *
 * \param draw le tirage à convertir en std::string.
 *
 * \return une représentation sous la forme d'une chaîne de
 *         caractères du tirage.
 */
inline std::string to_string(const Draw & draw);

// méthodes inline

unsigned Draw::size() const
{
    return static_cast<unsigned>(value_.size());
}

unsigned Draw::max() const
{
    return max_;
}

const std::set<unsigned> & Draw::value() const
{
    return value_;
}

// fonctions inline

std::string to_string(const Draw & draw)
{
    return draw.to_string();
}

} // namespace lotto

} // namespace nvs

#endif // DRAW_H
