/*!
 * \file data.h
 * \brief Définition d'une fonction pour la production de pronostics
 *        de lotto.
 */
#ifndef DATA_H
#define DATA_H

#include <vector>
#include <utility>

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
 * \brief Retourne des données pour produire des pronostics
 *        pour un jeu de lotto.
 *
 * _Préalable_ : idéallement, un pronostic est constitué de
 * `pronostic_size`
 * valeurs différentes allant de 1 à `pronostic_max`, ces valeurs
 * comprises.
 *
 * Les données produites par la fonction sont rassemblées dans
 * un std::vector. Chaque élément
 * de celui-ci correspond à un candidat pronostic. Voici comment
 * utiliser ces éléments pour tenter de construire un pronostic :
 *
 *  + le premier champ correspond à la valeur maximale acceptable
 *    pour les valeurs du pronostic, donc au nombre de chiffres
 *    possibles car le plus petit vaut 1 ;
 *  + le second champ correspond aux chiffres sélectionnés comme
 *    valeur du pronostic.
 *
 * Les données produites ne sont pas exemptes d'erreurs. Voici la
 * liste exhaustive des cas d'erreurs possibles :
 *
 *  + la valeur maximale peut être erronée, une ou des valeurs
 *    la dépassant ;
 *  + une des valeurs du second champ peut être dupliquée.
 *
 * Ces différents cas d'erreurs ne sont pas mutuellement
 * exclusifs.
 *
 * Outre ces cas d'erreur, certaines données retournées, bien que
 * valides, ne correspondent pas aux demandes exprimées via les
 * paramètres de la fonction. Voici ce qu'il en est :
 *
 *  + le paramètre `pronostic_size` indique le nombre désiré
 *    de valeurs d'un pronostic : il peut ne pas être respecté ;
 *  + le paramètre `pronostic_max` indique la valeur maximale
 *    possible pour les valeurs d'un pronostic : il peut être
 *    modifié.
 *
 * _Remarque_ : la fonction utilise le moteur aléatoire retourné
 * par la fonction nvs::urng(). Les données produites se répettent
 * identiquement d'une exécution à l'autre car la fonction
 * nvs::randomize() n'est pas invoquée. Lors du test de vos
 * classes et fonctions, n'oubliez pas d'invoquer celle-ci : vos
 * solutions doivent fonctionner quel que soit le jeu de données
 * produites.
 *
 * \param size le nombre de candidat pronostics à produire : ce
 *             nombre est toujours strictement respecté, même s'il
 *             est nul.
 * \param pronostic_size le nombre de valeurs d'un pronostic : ce
 *                       nombre n'est pas toujours respecté.
 * \param pronostic_max la valeur maximale possible pour les
 *                      valeurs d'un pronostic : ce nombre n'est
 *                      pas toujours respecté.
 *
 * \return des données pour produire des pronostics telles que
 *         décrites ci-dessus.
 *
 * \throw std::invalid_argument dans les trois cas suivants :
 *
 *  + le nombre désiré de valeurs d'un pronostic est nul ;
 *  + la valeur maximale possible d'un pronostic est nulle ;
 *  + la valeur maximale possible d'un pronostic est
 *    strictement inférieure au nombre de valeurs de celui-ci.
 */
std::vector<std::pair<unsigned, std::vector<unsigned>>>
data(unsigned pronostic_size = 7, unsigned pronostic_max = 50,
     unsigned size = 1000);

} // namespace lotto

} // namespace nvs

#endif // DATA_H
