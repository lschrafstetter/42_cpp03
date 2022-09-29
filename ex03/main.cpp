/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:01:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 13:05:58 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void) {
	DiamondTrap mario = DiamondTrap("Mario");
	std::cout << std::endl;
	FragTrap nelly = FragTrap("Nelly");
	ScavTrap oliver = ScavTrap("Oliver");
	ClapTrap penny = ClapTrap("Penny");

	mario.status();
	nelly.status();
	oliver.status();
	penny.status();
	
	std::cout << RED << std::endl << "--- Special abilities ---" << std::endl << std::endl;
	mario.whoAmI();
	mario.GuardGate();
	mario.highFivesGuys();
	nelly.highFivesGuys();
	oliver.GuardGate();
	penny.attack("the air, because she can't do anything");
	
	std::cout << BLUE <<std::endl << "--- Attacks ---" << std::endl << std::endl;
	mario.attack(nelly);
	nelly.attack(oliver);
	oliver.attack(penny);
	penny.attack(mario);

	std::cout << YELLOW <<std::endl << "--- Copy assignment ---" << std::endl << std::endl;

	nelly = mario;
	oliver = mario;
	penny = mario;
	
	mario.status();
	nelly.status();
	oliver.status();
	penny.status();

	std::cout << DEFAULT << std::endl;
}
