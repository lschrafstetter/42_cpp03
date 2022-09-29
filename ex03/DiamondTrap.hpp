/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:36:37 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 11:04:17 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  // Constructors
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &copy);

  // Destructor
  ~DiamondTrap();

  // Operators
  void swap(DiamondTrap &first,
            DiamondTrap &second);  // normally "friend" swap, but
                                   // not allowed due to 42 norm
  DiamondTrap &operator=(DiamondTrap other);

  // Functions
	using ScavTrap::attack;
  void whoAmI();
 
 private:
	std::string name_;
};

#endif