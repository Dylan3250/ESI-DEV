/*!
 * \file data.h
 * \brief Prototypes de deux fonctions et définition d'une énumération
 *        pour la génération de données.
 */
#ifndef DATA_H
#define DATA_H

#include <vector>
#include <tuple>

#include "sign.h"

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace g54027 {

/*!
 * \brief Énumération fortement typée pour contrôler le caractère
 *        reproductible ou non du comportement des fonctions
 *        pour la génération des données.
 */
enum class Reproductible {
    /*!
     * \brief Pour indiquer qu'on désire un comportement _différent_
     *        des fonctions pour la génération des données
     *        d'une exécution à l'autre du programme qui l'utilise.
     */
    FALSE,

    /*!
     * \brief Pour indiquer qu'on désire un comportement _identique_
     *        des fonctions pour la génération des données
     *        d'une exécution à l'autre du programme qui l'utilise.
     */
    TRUE
};

/*!
 * \brief Fonction de production de données sur base d'un signe,
 *        d'un nombre de jours et d'un nombre de secondes.
 *
 * Pour chaque std::tuple retourné, le champ d'index :
 *
 *  + 0 : correspond au signe d'une Duration à construire ;
 *  + 1 : correspond à un nombre de jours d'une Duration à
 *        construire ;
 *  + 2 : correspond à un nombre de secondes d'une Duration à
 *        construire.
 *
 * _Remarque_ : si le paramètre `reproductible` est mis à
 * Reproductible::FALSE pour un appel, cela rend non reproductible
 * d'une exécution à l'autre cet appel de fonction,
 * mais également celui de toutes les fonctions avec un argument
 * de type \ref Reproductible appelées utlérieurement, car les
 * fonctions de random.hpp utilisent toutes le même générateur
 * aléatoire.
 *
 * \param size pour contrôler le nombre d'élements du std::vector
 *             retourné.
 * \param reproductible pour contrôler la nature reproductible ou
 *                      non de la fonction.
 *
 * \return données brutes telles que décrites ci-dessus.
 *
 * \see Duration::Duration(Sign, unsigned, unsigned).
 */
std::vector<std::tuple<Sign, unsigned, unsigned>>
        data_sidase(unsigned size = 100000,
                    Reproductible reproductible = Reproductible::FALSE);

/*!
 * \brief Fonction de production de données sur base d'un signe
 *        et d'un nombre de secondes.
 *
 * Pour chaque std::tuple retourné, le champ d'index :
 *
 *  + 0 : correspond au signe d'une Duration à construire ;
 *  + 1 : correspond à un nombre de secondes d'une Duration à
 *        construire.
 *
 * _Remarque_ : si le paramètre `reproductible` est mis à
 * Reproductible::FALSE pour un appel, cela rend non reproductible
 * d'une exécution à l'autre cet appel de fonction,
 * mais également celui de toutes les fonctions avec un argument
 * de type \ref Reproductible appelées utlérieurement, car les
 * fonctions de random.hpp utilisent toutes le même générateur
 * aléatoire.
 *
 * \param size pour contrôler le nombre d'élements du std::vector
 *             retourné.
 * \param reproductible pour contrôler la nature reproductible ou
 *                      non de la fonction.
 *
 * \return données brutes telles que décrites ci-dessus.
 *
 * \see Duration::durationFromSeconds(Sign, unsigned long).
 */
std::vector<std::tuple<Sign, unsigned long>>
        data_sise(unsigned size = 100000,
                  Reproductible reproductible = Reproductible::FALSE);

} // namespace g54027

#endif // DATA_H
