/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:31:45 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 10:22:46 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class ScavTrap : public virtual ClapTrap {
 public:
  // Constructors
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &copy);

  // Destructor
  ~ScavTrap();

  // Operators
  void swap(ScavTrap &first, ScavTrap &second);  // normally "friend" swap, but
                                                 // not allowed due to 42 norm
  ScavTrap &operator=(ScavTrap other);

  // Functions
  void attack(const std::string &target);
  void attack(ClapTrap &target);
  void GuardGate();
};

#endif