/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:01:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 10:48:24 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void) {
	ScavTrap dobby = ScavTrap("Dobby");
	ScavTrap elvis = ScavTrap("Elvis");

	dobby.status();
	elvis.status();
	
	std::cout << GREEN << std::endl << "--- Fight ---" << std::endl << std::endl;
	
	elvis.GuardGate();
	dobby.attack(elvis);
	elvis.attack(dobby);
	dobby.attack(elvis);
	elvis.beRepaired(10);
	dobby.attack(elvis);
	dobby.attack(elvis);
	dobby.attack(elvis);
	dobby.attack(elvis);
	dobby.attack(elvis);
	elvis.beRepaired(1000);
	dobby.status();
	elvis.status();
	
	std::cout << RED << std::endl << "--- Copying a dead ScavTrap ---" << std::endl << std::endl;
	ScavTrap fiona = elvis;
	fiona.status();
	fiona.beRepaired(50);
	fiona.set_name("Fiona");
	fiona.status();
	fiona.beRepaired(50);
	
	std::cout << BLUE <<std::endl << "--- ClapTrap vs Scavtrap ---" << std::endl << std::endl;
	ClapTrap gunther = ClapTrap("Gunther");
	gunther.status();
	gunther.attack(dobby);
	gunther.set_attackdamage(100);
	gunther.attack(dobby);
	
	std::cout << DEFAULT << std::endl;
}