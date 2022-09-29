/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:31:41 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 10:33:14 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
  std::cout << "Default Constructor called of FragTrap" << std::endl;
  this->type_ = "FragTrap";
  this->attackdamage_ = 30;
  this->hitpoints_ = 100;
  this->max_hitpoints_ = 100;
  this->energypoints_ = 100;
}

FragTrap::FragTrap(std::string name) {
  std::cout << "Name Constructor called of FragTrap " << std::endl;
  this->name_ = name;
  this->type_ = "FragTrap";
  this->attackdamage_ = 30;
  this->hitpoints_ = 100;
  this->max_hitpoints_ = 100;
  this->energypoints_ = 100;
}

FragTrap::FragTrap(const FragTrap &copy) {
  std::cout << "Copy Constructor called of FragTrap" << std::endl;
  this->name_ = copy.name_;
  this->type_ = copy.type_;
  this->hitpoints_ = copy.hitpoints_;
  this->max_hitpoints_ = copy.max_hitpoints_;
  this->energypoints_ = copy.energypoints_;
  this->attackdamage_ = copy.attackdamage_;
}

// Destructor
FragTrap::~FragTrap() {
  std::cout << "Destructor called of FragTrap " << this->name_ << std::endl;
}

// Operators
void FragTrap::swap(FragTrap &first, FragTrap &second) {
  std::swap(first.type_, second.type_);
  std::swap(first.name_, second.name_);
  std::swap(first.hitpoints_, second.hitpoints_);
	std::swap(first.max_hitpoints_, second.max_hitpoints_);
  std::swap(first.energypoints_, second.energypoints_);
  std::swap(first.attackdamage_, second.attackdamage_);
}

FragTrap &FragTrap::operator=(FragTrap other) {
	std::cout << "Copy assignment operator called of FragTrap " << std::endl;
  // Copy and swap idiom
  FragTrap::swap(*this, other);
  return *this;
}

// Functions
void FragTrap::attack(const std::string &target) {
	std::cout << "Using FragTrap attack" << std::endl;
  if (energypoints_ == 0) {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to attack!" << std::endl;
    return;
  }
  if (this->hitpoints_ > 0) {
    this->energypoints_--;
    std::cout << this->type_ << " " << this->name_ << " attacks " << target
              << ", causing " << this->attackdamage_ << " points of damage!"
              << std::endl;
  } else {
    std::cout << this->type_ << " " << this->name_
              << " is dead and can't attack!" << std::endl;
  }
}

void FragTrap::attack(ClapTrap &target) {
	std::cout << "Using FragTrap attack" << std::endl;
  if (energypoints_ == 0) {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to attack!" << std::endl;
    return;
  }
  if (this->hitpoints_ > 0) {
    this->energypoints_--;
    std::cout << this->type_ << " " << this->name_ << " attacks "
              << target.get_name() << ", causing " << this->attackdamage_
              << " points of damage!" << std::endl;
    target.takeDamage(this->attackdamage_);
  } else {
    std::cout << this->type_ << " " << this->name_
              << " is dead and can't attack!" << std::endl;
  }
}

void FragTrap::highFivesGuys() {
  if (this->energypoints_ > 0) {
    std::cout << this->type_ << " " << this->name_
              << " is enthusiastically offering a high five!" << std::endl;
  } else {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to high five people!"
              << std::endl;
  }
}