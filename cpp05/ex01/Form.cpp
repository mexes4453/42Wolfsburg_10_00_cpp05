/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:58 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/25 20:00:43 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Initialise the static member variables */
int const Form::_min_grade = Bureaucrat::getMinGrade();
int const Form::_max_grade = Bureaucrat::getMaxGrade();


Form::Form(void) 
: _name("Form"), _state_sign(false), _grade_sign(20), _grade_exec(5)
{
    COUT << "call default constructor Form: " << _name << ENDL;
    return ;
}


Form::Form(std::string const name, bool signState, int const signGrade, \
                                                int const execGrade)
: _name(name), _state_sign(signState), _grade_sign(signGrade), _grade_exec(execGrade)
{
    COUT << "call parametric constructor Form: " << _name << ENDL;
}



Form::Form(Form const &other)
: _name(other._name), _state_sign(other._state_sign), _grade_sign(other._grade_sign),
 _grade_exec(other._grade_exec)
{
    *this = other;
    COUT << "call copy constructor Form: " << _name << ENDL;
}



Form  &Form::operator=(Form const &other)
{
    this->_state_sign = other._state_sign;
    COUT << "call copy assignment constructor Form: " << _name << ENDL;
    return (*this) ;
}



Form::~Form(void)
{
    COUT << "call destructor Form: " << _name << ENDL;
    return ;
}



std::string const   Form::getName(void) const
{
    return (_name);
}



bool   Form::getSignState(void) const
{
    return (_state_sign);
}



int   Form::getSignGrade(void) const
{
    return (_grade_sign);
}


int  Form::getExecGrade(void) const
{
    return (_grade_exec);
}



void    Form::beSigned(Bureaucrat &b)
{
        if (b.getGrade() <= _grade_exec)
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




std::ostream    &operator<<(std::ostream &o, Form const &f)
{
    o << "FORM NAME:  " << f.getName() << ENDL
      << "SIGN GRADE: " << f.getSignGrade() << ENDL
      << "EXEC GRADE: " << f.getExecGrade() << ENDL
      << "SIGN STATE: " << f.getSignState() << ENDL;
    return (o);
}
