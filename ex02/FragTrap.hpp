/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:36:37 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 10:23:48 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

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

class FragTrap : public ClapTrap {
 public:
  // Constructors
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &copy);

  // Destructor
  ~FragTrap();

  // Operators
  void swap(FragTrap &first, FragTrap &second);  // normally "friend" swap, but
                                                 // not allowed due to 42 norm
  FragTrap &operator=(FragTrap other);

  // Functions
  void attack(const std::string &target);
  void attack(ClapTrap &target);
  void highFivesGuys(void);
};

#endif