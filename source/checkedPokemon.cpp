/* 
 * File:   checkedPokemon.cpp
 * Author: elveman
 * 
 * Created on October 18, 2015, 2:10 PM
 */
#include "pokemon.hpp"
#include "pkdata.hpp"
#include "checkedPokemon.hpp"

const int legendaryAmount=53;
const int legendaryID[legendaryAmount] =
    {144, 145, 146, 150, 151, 243, 244, 245, 249, 250, 251, 377, 378, 379,
    380, 381, 382, 383, 384, 385, 386, 480, 481, 482, 483, 484, 485, 486,
    487, 488, 490, 491, 492, 493, 494, 638, 639, 640, 641, 642, 643, 644,
    645, 646, 647, 648, 649, 716, 717, 718, 719, 720, 721};

bool checkedPokemon::isKalosBorn(vPkm_t vpkm) { return version(vpkm.pkm) >= 24; }
bool checkedPokemon::isLegendary(vPkm_t vpkm){
    int i;
    for(i=0;i<legendaryAmount;i++){
        if ((int)speciesID(vpkm.pkm)==(int)legendaryID[i]) return true;
    }
    return false;
}
bool checkedPokemon::hasOver510EVs(vPkm_t vpkm){ 
    return ((int)(checkedPokemon::EV_ATK(vpkm.pkm)+checkedPokemon::EV_DEF(vpkm.pkm)
        +checkedPokemon::EV_SPA(vpkm.pkm)+checkedPokemon::EV_SPD(vpkm.pkm)
        +checkedPokemon::EV_SPE(vpkm.pkm)+checkedPokemon::EV_HP(vpkm.pkm))>510);};
bool checkedPokemon::isUnreleased(vPkm_t vpkm){
    return ((int)speciesID(vpkm.pkm) == 721);
}
bool checkedPokemon::isLegendaryWithWrongIVs(vPkm_t vpkm){
    int i;
    int maxIVsAmount=0;
    int IVs[6]=
    {IV_HP(vpkm.pkm), IV_ATK(vpkm.pkm), IV_DEF(vpkm.pkm), IV_SPE(vpkm.pkm), IV_SPA(vpkm.pkm), IV_SPD(vpkm.pkm)};
    for (i=0;i<6;i++){
        maxIVsAmount+=(IVs[i]==31);
    }
    return(checkedPokemon::isLegendary(vpkm) and 
            (maxIVsAmount < 3) and 
            (checkedPokemon::isKalosBorn(vpkm)));
}
void checkedPokemon::isChecked(vPkm_t vpkm){
    uint32_t x=5, y=92;
    if (checkedPokemon::hasOver510EVs(vpkm))
        sftd_draw_text_pkm(x, (y += 15), "Pokemon has over 510 EVs!");
    if (checkedPokemon::isLegendaryWithWrongIVs(vpkm))
        sftd_draw_text_pkm(x, (y += 15), "Legendary but with 2-*31 IVs!");
    if (checkedPokemon::isUnreleased(vpkm))
        sftd_draw_text_pkm(x, (y += 15), "This Pokemon is not released!");
};
