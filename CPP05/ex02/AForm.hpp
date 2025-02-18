#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    class GradeTooHighException : public std::exception { // This allows our custom exception class to be caught using catch (std::exception& e).
    public:
        const char *what() const throw(); // what() returns the error message, throw() - a throw specification indicating that what() does not throw exceptions.
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw();

    };

    AForm(std::string const& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
