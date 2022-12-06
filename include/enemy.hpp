/**
 * @file enemy.hpp
 * @author Victória Tejada (victoriatsiqueiram@gmail.com)
 * @brief Classe principal com a lógica de enemy
 * @version 1.0
 * @date 2022-12-03
 * @details Responsável por processar e armazenar toda logica dos inimigos com atributos vindos dos monstros.
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include "monster.hpp"

/**
 * @brief Armazena todas informações referentes ao ataque e valor do monstro em ouro e experiência.
 *
 * @details Contém todas as informações sobre o possibilidade do monstro em acertar o golpe, errar ou obter acerto crítico, valor de cada monstro em experiência e valor em ouro após abate. Que futuramente serve para a compra de itens dentro da loja do jogo.
 */
class Enemy : public Monster
{

public:
    /**
     * @brief Constrói o objeto inimigo
     *
     * @details Inicializa os atributos dos monstros com seus respectivos valores numéricos.
     *
     * @param gold Valor do ouro
     * @param xpWorth Valor da XP
     * @param name Nome do personagem ou monstro
     * @param currentHp Valor do HP atual
     * @param maxHp Valor máximo de HP
     * @param maxDamage Valor máximo de dano
     * @param minDamage Valor mínimo de dano
     *
     */
    Enemy(uint gold,
          uint xpWorth,
          std::string name,
          int currentHp,
          uint maxHp,
          uint maxDamage,
          uint minDamage);

    /**
     * @brief Destroi o objeto inimigo
     *
     */
    ~Enemy();

    /**
     * @brief Valor de ouro
     *
     * @return retorna o quanto de ouro o monstro dropa ao morrer
     */
    unsigned int goldWorth() const;

    /**
     * @brief Valor da xp
     *
     * @return retorna o quanto de XP o monstro vale
     */
    unsigned int xpWorth();

private:
    uint _gold;
    uint _xpWorth;
};

#endif
