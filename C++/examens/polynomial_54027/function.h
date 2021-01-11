/*!
 * \file function.h
 * \brief Définition de la classe nvs::Function.
 */
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <ostream>

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace nvs {

/*!
 * \brief Classe représentant une fonction mathématique.
 *
 * Il s'agit d'une classe abstraite. Elle est munie de méthodes
 * virtuelles pures.
 */
class Function {
  public:

    /*!
     * \brief Constructeur par défaut.
     *
     * Ce constructeur doit être disponible pour les classes
     * filles.
     */
    Function() = default;

    /*!
     * \brief Destructeur virtuel pur.
     *
     * Comme la classe est destinée à être héritée, son destructeur
     * doit être [virtuel]
     * (https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors).
     *
     * L'utilisation de la classe n'a de sens qu'à travers une
     * classe dérivée. Il s'agit donc d'une [classe abstraite]
     * (https://en.cppreference.com/w/cpp/language/abstract_class).
     * Le choix de la méthode virtuelle pure, pour obtenir une
     * classe abstraite, s'est porté sur le destructeur.
     *
     * Cependant, les classes filles vont implicitement utiliser
     * le destructeur de la classe mère. Le destructeur virtuel
     * pur requiert donc une implémentation. On trouve plus
     * d'informations sur les méthodes virtuelles pures dotées
     * d'une implémentation dans le [GotW #31]
     * (http://www.gotw.ca/gotw/031.htm). L'implémentation
     * du [destructeur](https://en.cppreference.com/w/cpp/language/destructor)
     * par défaut fait ici très bien l'affaire.
     *
     * Finalement, il est étiqueté [`inline`]
     * (https://stackoverflow.com/a/1759575) pour ne pas violer
     * la [One Definition Rule]
     * (https://en.wikipedia.org/wiki/One_Definition_Rule).
     *
     * \see https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
     * \see https://en.cppreference.com/w/cpp/language/abstract_class
     * \see http://www.gotw.ca/gotw/031.htm
     * \see https://en.cppreference.com/w/cpp/language/destructor
     * \see https://stackoverflow.com/a/1759575
     * \see https://en.wikipedia.org/wiki/One_Definition_Rule
     */
    virtual ~Function() = default;

    /*!
     * \brief Constructeur par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see https://stackoverflow.com/q/33957037
     * \see https://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Function(const Function &) = default;

    /*!
     * \brief Constructeur par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see https://stackoverflow.com/q/33957037
     * \see https://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Function(Function &&) = default;

    /*!
     * \brief Opérateur d'assignation par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see https://stackoverflow.com/q/33957037
     * \see https://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Function & operator=(const Function &) = default;

    /*!
     * \brief Opérateur d'assignation par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see https://stackoverflow.com/q/33957037
     * \see https://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Function & operator=(Function &&) = default;

    /*!
     * \brief Opérateur d'évaluation de la fonction.
     *
     * On ne considère ici qu'un seul paramètre de type `double`
     * avec un retour également `double`.
     * Mathématiquement, cela revient à se limiter aux fonctions
     * d'une variable réelle avec une valeur (une image) réelle.
     *
     * \param x valeur pour laquelle on désire évaluer la fonction.
     *
     * \return valeur de la fonction en `x`.
     */
    virtual double operator()(double x) const = 0;

    /*!
     * \brief Conversion d'une Function en std::string.
     *
     * Comme il n'est pas possible de représenter de manière
     * générique une fonction mathématique, cette méthode
     * est virtuelle pure sans implémentation.
     *
     * \return représentation de la Function sous la forme d'une
     *         std::string.
     */
    virtual std::string to_string() const = 0;
};

// prototypes

/*!
 * \brief Opérateur d'injection d'une Function dans un flux en sortie.
 *
 * C'est la représentation de la Function sous la forme d'une
 * std::string qui est injectée dans le std::ostream. Comme la
 * méthode Function::to_string est polymorphe, l'opérateur
 * d'injection l'est aussi.
 *
 * \param out flux dans lequel injecter `fct`.
 * \param fct Function à injecter.
 *
 * \return flux après injection.
 *
 * \see Function::to_string()
 */
inline std::ostream & operator<<(std::ostream & out,
                                 const Function & fct);

// implémentations

std::ostream & operator<<(std::ostream & out, const Function & fct) {
    return out << fct.to_string();
}

}

#endif // FUNCTION_H
