#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    class GradeTooHighException : public std::exception { // This allows our custom exception class to be caught using catch (std::exception& e). 
    public:
        const char * what() const throw(); // what() returns the error message, throw() - a throw specification indicating that what() does not throw exceptions.
    };
    class GradeTooLowException : public std::exception { 
    public:
        const char * what() const throw();
    };

    Form(std::string const& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
