#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() {
  std::cout << "Default Constructor called of ClapTrap" << std::endl;
  this->type_ = "ClapTrap";
  this->attackdamage_ = 0;
  this->hitpoints_ = 10;
  this->max_hitpoints_ = 10;
  this->energypoints_ = 10;
}

ClapTrap::ClapTrap(std::string name) {
  std::cout << "Name Constructor called of ClapTrap " << std::endl;
  this->name_ = name;
  this->type_ = "ClapTrap";
  this->attackdamage_ = 0;
  this->hitpoints_ = 10;
  this->max_hitpoints_ = 10;
  this->energypoints_ = 10;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  std::cout << "Copy Constructor called of ClapTrap" << std::endl;
  this->name_ = copy.name_;
  this->type_ = copy.type_;
  this->hitpoints_ = copy.hitpoints_;
	this->max_hitpoints_ = copy.max_hitpoints_;
  this->energypoints_ = copy.energypoints_;
  this->attackdamage_ = copy.attackdamage_;
}

// Destructor
ClapTrap::~ClapTrap() {
  std::cout << "Destructor called of ClapTrap " << this->name_ << std::endl;
}

// Operators
void ClapTrap::swap(ClapTrap &first, ClapTrap &second) {
  std::swap(first.type_, second.type_);
  std::swap(first.name_, second.name_);
  std::swap(first.hitpoints_, second.hitpoints_);
  std::swap(first.max_hitpoints_, second.max_hitpoints_);
  std::swap(first.energypoints_, second.energypoints_);
  std::swap(first.attackdamage_, second.attackdamage_);
}

ClapTrap &ClapTrap::operator=(ClapTrap other) {
	std::cout << "Copy Assignment operator called of ClapTrap" << std::endl;
  // Copy and swap idiom
  ClapTrap::swap(*this, other);
  return *this;
}

// Getters
std::string ClapTrap::get_type() const { return this->type_; }

std::string ClapTrap::get_name() const { return this->name_; }

int ClapTrap::get_hitpoints() const { return this->hitpoints_; }

int ClapTrap::get_max_hitpoints() const { return this->max_hitpoints_; }

int ClapTrap::get_energypoints() const { return this->energypoints_; }

int ClapTrap::get_attackdamage() const { return this->attackdamage_; }

// Setters
void ClapTrap::set_type(std::string const type) { this->type_ = type; }

void ClapTrap::set_name(std::string const name) { this->name_ = name; }

void ClapTrap::set_hitpoints(int const hitpoints) {
  this->hitpoints_ = hitpoints;
}

void ClapTrap::set_max_hitpoints(int const max_hitpoints) {
  this->max_hitpoints_ = max_hitpoints;
}

void ClapTrap::set_energypoints(int const energypoints) {
  this->energypoints_ = energypoints;
}

void ClapTrap::set_attackdamage(int const attackdamage) {
  this->attackdamage_ = attackdamage;
}

// Functions
void ClapTrap::attack(const std::string &target) {
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
    std::cout << this->type_ << " " << this->name_ << " is dead and can't attack!"
              << std::endl;
  }
}

void ClapTrap::attack(ClapTrap &target) {
  if (energypoints_ == 0) {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to attack!" << std::endl;
    return;
  }
  if (this->hitpoints_ > 0) {
    this->energypoints_--;
    std::cout << this->type_ << " " << this->name_ << " attacks " << target.get_name()
              << ", causing " << this->attackdamage_ << " points of damage!"
              << std::endl;
    target.takeDamage(this->attackdamage_);
  } else {
    std::cout << this->type_ << " " << this->name_ << " is dead and can't attack!"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitpoints_ == 0) {
    std::cout << this->type_ << " " << this->name_ << " is already dead!" << std::endl;
    return;
  }
  std::cout << this->type_ << " " << this->name_ << " takes " << amount
            << " points of damage";
  this->hitpoints_ -= amount;
  if (this->hitpoints_ <= 0) {
    this->hitpoints_ = 0;
    std::cout << " and dies!" << std::endl;
		return;
  }
  std::cout << " and now has " << this->hitpoints_ << " hitpoints!"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energypoints_ == 0) {
    std::cout << this->type_ << " " << this->name_
              << " doesn't have enough energy to repair itself!" << std::endl;
    return;
  }
  if (this->hitpoints_ > 0) {
		this->energypoints_--;
    if (this->hitpoints_ + amount > this->max_hitpoints_) {
      this->hitpoints_ = this->max_hitpoints_;
      std::cout << this->type_ << " " << this->name_
                << " repairs itself to full hitpoints and now has "
                << this->hitpoints_ << " hitpoints!" << std::endl;
    } else {
      this->hitpoints_ += amount;
      std::cout << this->type_ << " " << this->name_ << " repairs itself by " << amount
                << " hitpoints and now has " << this->hitpoints_
                << " hitpoints!" << std::endl;
    }
    return;
  } else {
    std::cout << this->type_ << " " << this->name_ << " is dead and can't heal itself!"
              << std::endl;
  }
}

void ClapTrap::status(void) const {
  std::cout << "Name: " << this->name_ << " HP: " << this->hitpoints_
            << " EP: " << this->energypoints_ << " ATT: " << this->attackdamage_
            << std::endl;
}
