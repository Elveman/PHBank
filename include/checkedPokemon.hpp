/* 
 * File:   checkedPokemon.hpp
 * Author: elveman
 *
 * Created on October 18, 2015, 2:10 PM
 */
#include "box_viewer.hpp"
#include "pkbank.hpp"
#ifndef CHECKEDPOKEMON_HPP
#define	CHECKEDPOKEMON_HPP

class checkedPokemon: public Pokemon {
public:
    static bool isKalosBorn(vPkm_t vpkm);
    static bool isLegendary(vPkm_t vpkm);
    static bool hasOver510EVs(vPkm_t vpkm);
    static bool isUnreleased(vPkm_t vpkm);
    static bool isLegendaryWithWrongIVs(vPkm_t vpkm);
    static bool hasNoAmieAffection(vPkm_t vpkm);
    static bool hasSuspiciousIVs(vPkm_t vpkm);
    static bool hasUnreleasedAbility(vPkm_t vpkm);
    static bool hasWrongGender(vPkm_t vpkm);
    static void isChecked(vPkm_t vpkm);
private:

};

#endif	/* CHECKEDPOKEMON_HPP */

