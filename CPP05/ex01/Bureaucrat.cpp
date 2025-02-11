#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& name, int grade) :name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade = other.grade; //only ngrade since name is const
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const{
    return name;
}
int Bureaucrat::getGrade() const{
    return grade;
}

void Bureaucrat::incrementGrade(){
    if(grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade(){
    if(grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}
// Overrides what() to provide custom error messages.
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& form){
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
