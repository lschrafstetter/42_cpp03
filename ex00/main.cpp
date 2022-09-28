/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:01:09 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/28 11:25:01 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void) {
	ClapTrap alfons = ClapTrap("Alfons");
	ClapTrap berta = ClapTrap();
	berta.set_name("Berta");

	alfons.attack("something");
	alfons.set_attackdamage(4);
	
	std::cout << GREEN << std::endl << "--- Alfons attacks Berta, Berta heals to full ---" << std::endl << std::endl;
	alfons.attack(berta);
	berta.beRepaired(3);
	berta.beRepaired(3);
	
	std::cout << RED << std::endl << "--- Alfons attacks Berta to death, Berta can't heal ---" << std::endl << std::endl;
	alfons.attack(berta);
	alfons.attack(berta);
	alfons.attack(berta);
	berta.beRepaired(3);
	
	std::cout << BLUE <<std::endl << "--- Copying Alfons into new ClapTrap Charlie ---" << std::endl << std::endl;
	ClapTrap charlie = alfons;
	charlie.set_name("Charlie");
	charlie.attack(alfons);
	
	std::cout << YELLOW << std::endl << "--- Setting Energy to 0 ---" << std::endl << std::endl;
	charlie.set_energypoints(0);
	charlie.attack(alfons);
	alfons.attack(charlie);
	charlie.beRepaired(3);
	
	std::cout << DEFAULT << std::endl;
}