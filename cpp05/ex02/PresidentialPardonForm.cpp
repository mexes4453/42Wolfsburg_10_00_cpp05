/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:58 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/01 04:14:39 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) 
: AForm("PresidentialPardonForm", PRESIDENTIAL_GRADE_SIGN, PRESIDENTIAL_GRADE_EXEC),
_target("land")
{
    COUT << "call default constructor PresidentialPardonForm: " << _name << ENDL;
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(std::string const target)
: AForm("PresidentialPardonForm", PRESIDENTIAL_GRADE_SIGN, PRESIDENTIAL_GRADE_EXEC),
_target(target)
{
    COUT << "call parametric constructor PresidentialPardonForm: " << _name << ENDL;
}



PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
: AForm(other)
{
    *this = other;
    COUT << "call copy constructor PresidentialPardonForm: " << _name << ENDL;
}



PresidentialPardonForm  &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    this->_state_sign = other._state_sign;
    COUT << "call copy assignment constructor PresidentialPardonForm: " << _name << ENDL;
    return (*this) ;
}



PresidentialPardonForm::~PresidentialPardonForm(void)
{
    COUT << "call destructor PresidentialPardonForm: " << _name << ENDL;
    return ;
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    try
    {
        checkFormExecGrade(b);
        COUT << AFORM_COL_BLUE << _target << PRESIDENTIAL_MSG1 << ENDL;

        COUT << b.getName() << " executed " << _name
        << AFORM_COL_DEFAULT << ENDL;
    }
    catch(AForm::GradeTooHighException &e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
    catch(AForm::GradeTooLowException &e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
    catch(const std::exception& e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
}

std::ostream    &operator<<(std::ostream &o, PresidentialPardonForm const &f)
{
    o << "FORM NAME:  " << f.getName() << ENDL
      << "SIGN GRADE: " << f.getSignGrade() << ENDL
      << "EXEC GRADE: " << f.getExecGrade() << ENDL
      << "SIGN STATE: " << f.getSignState() << ENDL;
    return (o);
}
