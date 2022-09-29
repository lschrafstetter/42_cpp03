/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:01:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 10:46:46 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void) {
	ClapTrap jessy = ClapTrap("Jessy");
	ScavTrap kalle = ScavTrap("Kalle");
	FragTrap lilo = FragTrap("Lilo");

	jessy.status();
	kalle.status();
	lilo.status();
	
	std::cout << GREEN << std::endl << "--- Fight for the door ---" << std::endl << std::endl;
	
	kalle.GuardGate();
	lilo.highFivesGuys();
	kalle.attack(lilo);
	kalle.attack(jessy);
	lilo.attack(kalle);
	lilo.attack(kalle);
	lilo.attack(kalle);
	lilo.attack(kalle);
	lilo.status();
	lilo.beRepaired(20);
	
	std::cout << DEFAULT << std::endl;
}