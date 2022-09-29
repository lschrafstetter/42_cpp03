/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:31:41 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 11:19:31 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
  std::cout << "Default Constructor called of DiamondTrap" << std::endl;
  this->type_ = "DiamondTrap";
  this->attackdamage_ = 30;
  this->hitpoints_ = 100;
  this->max_hitpoints_ = 100;
  this->energypoints_ = 50;
}

DiamondTrap::DiamondTrap(std::string name) {
  std::cout << "Name Constructor called of DiamondTrap " << std::endl;
  ClapTrap::name_ = name + "_clap_name";
  this->name_ = name;
  this->type_ = "DiamondTrap";
  this->attackdamage_ = 30;
  this->hitpoints_ = 100;
  this->max_hitpoints_ = 100;
  this->energypoints_ = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
  std::cout << "Copy Constructor called of DiamondTrap" << std::endl;
  this->name_ = copy.name_;
  this->type_ = copy.type_;
  this->hitpoints_ = copy.hitpoints_;
  this->max_hitpoints_ = copy.max_hitpoints_;
  this->energypoints_ = copy.energypoints_;
  this->attackdamage_ = copy.attackdamage_;
}

// Destructor
DiamondTrap::~DiamondTrap() {
  std::cout << "Destructor called of DiamondTrap " << this->name_ << std::endl;
}

// Operators
void DiamondTrap::swap(DiamondTrap &first, DiamondTrap &second) {
  std::swap(first.type_, second.type_);
  std::swap(first.name_, second.name_);
  std::swap(first.hitpoints_, second.hitpoints_);
  std::swap(first.max_hitpoints_, second.max_hitpoints_);
  std::swap(first.energypoints_, second.energypoints_);
  std::swap(first.attackdamage_, second.attackdamage_);
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap other) {
  std::cout << "Copy assignment operator called of DiamondTrap " << std::endl;
  // Copy and swap idiom
  DiamondTrap::swap(*this, other);
  return *this;
}

void DiamondTrap::whoAmI() {
  if (this->energypoints_ > 0) {
    this->energypoints_--;
    std::cout << "Hello, my name is " << this->name_
              << " and my ClapTrap name is " << ClapTrap::name_ << std::endl;
  } else {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to tell you who it is!"
              << std::endl;
  }
}
