/*!
 * \file data.h
 * \brief Prototype d'une fonction et définition d'une énumération
 *        pour la génération de données.
 */
#ifndef DATA_H
#define DATA_H

#include <vector>
#include <utility>
#include <map>

/*!
 * \brief Espace de nom de Nicolas Vansteenkiste.
 *
 */
namespace nvs
{

/*!
 * \brief Énumération fortement typée pour contrôler le caractère
 *        reproductible ou non du comportement de la fonction
 *        nvs::data(Reproductible).
 */
enum class Reproductible
{
    /*!
     * \brief Pour indiquer qu'on désire un comportement _différent_
     *        de la fonction nvs::data(Reproductible)
     *        d'une exécution à l'autre du programme qui l'utilise.
     */
    FALSE,

    /*!
     * \brief Pour indiquer qu'on désire un comportement _identique_
     *        de la fonction nvs::data(Reproductible)
     *        d'une exécution à l'autre du programme qui l'utilise.
     */
    TRUE
};

/*!
 * \brief Fonction de production de données.
 *
 * La fonction retourne un std::vector de std::pair.
 *
 * Les seules
 * valeurs que peut prendre le champ `first` des std::pair sont
 * les caractères `m` ou `p`.
 *
 * Les std::map qui constituent le champ `second` des std::pair
 * peuvent éventuellement être vides. Aucune contrainte
 * ne repose sur les clés ou sur les valeurs des std::map.
 *
 * \param reproductible pour contrôler la nature reproductible ou
 *                      non de la fonction.
 *
 * \return données brutes.
 */
std::vector<std::pair<char, std::map<unsigned, int>>>
data(Reproductible reproductible = Reproductible::FALSE);

}

#endif // DATA_H
