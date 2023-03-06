/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:58 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/01 04:14:39 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
: Form("RobotomyRequestForm", ROBOTOMY_GRADE_SIGN, ROBOTOMY_GRADE_EXEC),
_target("land")
{
    COUT << "call default constructor RobotomyRequestForm: " << _name << ENDL;
    return ;
}


RobotomyRequestForm::RobotomyRequestForm(std::string const target)
: Form("RobotomyRequestForm", ROBOTOMY_GRADE_SIGN, ROBOTOMY_GRADE_EXEC),
_target(target)
{
    COUT << "call parametric constructor RobotomyRequestForm: " << _name << ENDL;
}



RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
: Form(other)
{
    *this = other;
    COUT << "call copy constructor RobotomyRequestForm: " << _name << ENDL;
}



RobotomyRequestForm  &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    this->_state_sign = other._state_sign;
    COUT << "call copy assignment constructor RobotomyRequestForm: " << _name << ENDL;
    return (*this) ;
}



RobotomyRequestForm::~RobotomyRequestForm(void)
{
    COUT << "call destructor RobotomyRequestForm: " << _name << ENDL;
    return ;
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    try
    {
        checkFormExecGrade(b);
        COUT << AFORM_COL_BLUE ROBOTOMY_MSG1 << ENDL << _target
             << ROBOTOMY_MSG2 << ENDL;

        COUT << b.getName() << " executed " << _name
        << AFORM_COL_DEFAULT << ENDL;
    }
    catch(Form::GradeTooHighException &e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
    catch(Form::GradeTooLowException &e)
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

std::ostream    &operator<<(std::ostream &o, RobotomyRequestForm const &f)
{
    o << "FORM NAME:  " << f.getName() << ENDL
      << "SIGN GRADE: " << f.getSignGrade() << ENDL
      << "EXEC GRADE: " << f.getExecGrade() << ENDL
      << "SIGN STATE: " << f.getSignState() << ENDL;
    return (o);
}
