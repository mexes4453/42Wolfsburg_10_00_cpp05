/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:58 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/26 12:33:09 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Initialise the static member variables */
int const AForm::_min_grade = Bureaucrat::getMinGrade();
int const AForm::_max_grade = Bureaucrat::getMaxGrade();


AForm::AForm(void) 
: _name("AForm"), _state_sign(false), _grade_sign(20), _grade_exec(5)
{
    COUT << "call default constructor AForm: " << _name << ENDL;
    return ;
}


AForm::AForm(std::string const name, int const signGrade, int const execGrade)
: _name(name), _state_sign(false), _grade_sign(signGrade), _grade_exec(execGrade)
{
    COUT << "call parametric constructor AForm: " << _name << ENDL;
}



AForm::AForm(AForm const &other)
: _name(other._name), _state_sign(other._state_sign), _grade_sign(other._grade_sign),
 _grade_exec(other._grade_exec)
{
    *this = other;
    COUT << "call copy constructor AForm: " << _name << ENDL;
}



AForm  &AForm::operator=(AForm const &other)
{
    this->_state_sign = other._state_sign;
    COUT << "call copy assignment constructor AForm: " << _name << ENDL;
    return (*this) ;
}



AForm::~AForm(void)
{
    COUT << "call destructor AForm: " << _name << ENDL;
    return ;
}



std::string const   AForm::getName(void) const
{
    return (_name);
}



bool   AForm::getSignState(void) const
{
    return (_state_sign);
}



int   AForm::getSignGrade(void) const
{
    return (_grade_sign);
}


int  AForm::getExecGrade(void) const
{
    return (_grade_exec);
}



void    AForm::beSigned(Bureaucrat &b)
{
        if (b.getGrade() < _grade_sign)
        {
            throw GradeTooHighException();   
        }
        else if (b.getGrade() > _grade_sign)
        {
            throw GradeTooLowException();   
        }
        else if (b.getGrade() <= _grade_sign && b.getGrade() > _grade_exec)
        {
            _state_sign = true;
        }
}



bool AForm::checkFormExecGrade(Bureaucrat const &b) const
{
    bool boReturn = false;

    if (b.getGrade() < _grade_exec )
    {
        throw GradeTooHighException();
    }
    else if (b.getGrade() > _grade_exec)
    {
        throw GradeTooLowException();
    }
    boReturn = true;
    return (boReturn);
}

std::ostream    &operator<<(std::ostream &o, AForm const &f)
{
    o << "FORM NAME:  " << f.getName() << ENDL
      << "SIGN GRADE: " << f.getSignGrade() << ENDL
      << "EXEC GRADE: " << f.getExecGrade() << ENDL
      << "SIGN STATE: " << f.getSignState() << ENDL;
    return (o);
}
