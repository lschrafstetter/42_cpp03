/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:31:41 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/29 10:33:19 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  std::cout << "Default Constructor called of ScavTrap" << std::endl;
	this->type_ = "ScavTrap";
  this->attackdamage_ = 20;
  this->hitpoints_ = 100;
  this->max_hitpoints_ = 100;
  this->energypoints_ = 50;
}

ScavTrap::ScavTrap(std::string name) {
  std::cout << "Name Constructor called of ScavTrap " << this->name_
            << std::endl;
  this->name_ = name;
	this->type_ = "ScavTrap";
  this->attackdamage_ = 20;
  this->hitpoints_ = 100;
  this->max_hitpoints_ = 100;
  this->energypoints_ = 50;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "Copy Constructor called of ScavTrap" << std::endl;
	this->name_ = copy.name_;
	this->type_ = copy.type_;
	this->hitpoints_ = copy.hitpoints_;
	this->max_hitpoints_ = copy.max_hitpoints_;
	this->energypoints_ = copy.energypoints_;
	this->attackdamage_ = copy.attackdamage_;
}

// Destructor
ScavTrap::~ScavTrap() {
  std::cout << "Destructor called of ScavTrap " << this->name_ << std::endl;
}

// Operators
void ScavTrap::swap(ScavTrap &first, ScavTrap &second) {
  std::swap(first.type_, second.type_);
  std::swap(first.name_, second.name_);
  std::swap(first.hitpoints_, second.hitpoints_);
	std::swap(first.max_hitpoints_, second.max_hitpoints_);
  std::swap(first.energypoints_, second.energypoints_);
  std::swap(first.attackdamage_, second.attackdamage_);
}

ScavTrap &ScavTrap::operator=(ScavTrap other) {
	std::cout << "Copy assignment operator called of ScavTrap " << std::endl;
  // Copy and swap idiom
  ScavTrap::swap(*this, other);
  return *this;
}


// Functions
void ScavTrap::attack(const std::string &target) {
	std::cout << "Using ScavTrap attack" << std::endl;
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

void ScavTrap::attack(ClapTrap &target) {
	std::cout << "Using ScavTrap attack" << std::endl;
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

void ScavTrap::GuardGate() {
  if (this->energypoints_ > 0) {
    std::cout << this->type_ << " " << this->name_
              << " is now in Gate keeper mode!" << std::endl;
  } else {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to guard the gate!" << std::endl;
  }
}