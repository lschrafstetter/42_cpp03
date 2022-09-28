#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class ClapTrap
{
 public:
	// Constructors
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	
	// Destructor
	~ClapTrap();
	
	// Operators
	ClapTrap &operator=(ClapTrap other);
	void swap(ClapTrap &first, ClapTrap &second); //normally "friend" swap, but not allowed due to 42 norm

	// Getters
	std::string get_type() const;
	std::string get_name() const;
	int get_hitpoints() const;
	int get_energypoints() const;
	int get_attackdamage() const;

	// Setters
	void set_type(std::string const name);
	void set_name(std::string const name);
	void set_hitpoints(int const hitpoints);
	void set_energypoints(int const energypoints);
	void set_attackdamage(int const attackdamage);

	// Functions
	void attack(const std::string &target);
	void attack(ClapTrap &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

 protected:
	std::string type_;
	std::string name_;
	int max_hitpoints_ = 10;
	int hitpoints_;
	int energypoints_;
	unsigned int	attackdamage_;
};

#endif