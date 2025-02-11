#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute) 
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
 : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other){
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}
int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw (){
    return "grade to high!";
}
const char* Form::GradeTooLowException::what() const throw (){
    return "grade to low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade Required to Sign: " << form.getGradeToSign() 
        << ", Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}
