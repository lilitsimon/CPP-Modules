#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
 : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other){
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}
int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw (){
    return "grade to high!";
}
const char* AForm::GradeTooLowException::what() const throw (){
    return "grade to low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade Required to Sign: " << form.getGradeToSign()
        << ", Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}
