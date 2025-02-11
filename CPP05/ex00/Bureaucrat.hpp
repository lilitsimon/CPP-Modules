#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name; 
    int grade;

public:
    class GradeTooHighException : public std::exception { // This allows our custom exception class to be caught using catch (std::exception& e). 
    public:
        const char * what() const throw(); // what() returns the error message, throw() - a throw specification indicating that what() does not throw exceptions.
    };
    class GradeTooLowException : public std::exception { 
    public:
        const char * what() const throw();
    };

    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat); // allows us to use std::cout to print a Bureaucrat object directly

#endif

