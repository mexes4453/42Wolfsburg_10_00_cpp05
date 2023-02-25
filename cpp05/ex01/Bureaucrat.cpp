/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:58 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/25 08:35: by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define BUREAUCRAT_EXCEPTION_MSG(OBJ_FORM,OBJ_EXCEPT) CERR << this->_name \
             << " couldn't signed " \
             << f.getName() << " because " \
             << e.what() << ENDL; \

int const Bureaucrat::_max_grade = 1;
int const Bureaucrat::_min_grade = 150;

Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(_min_grade)
{
    COUT << "call default constructor Bureaucrat: " << _name << ENDL;
    return ;
}


Bureaucrat::Bureaucrat(std::string const name, int grade)
: _name(name)
{
    COUT << "call parametric constructor Bureaucrat: " << _name << ENDL;
    try
    {
        if (grade < Bureaucrat::_max_grade)
        {
            throw GradeTooHighException();
        }
        else if (grade > Bureaucrat::_min_grade)
        {
            throw GradeTooLowException();
        }
        else
        {
            _grade = grade;
        }
    }
    catch(GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
        COUT << "GRADE is set to maximum\n";
        _grade = Bureaucrat::_max_grade;
        
    }
    catch(GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
        COUT << "GRADE is set to minimum\n";
        _grade = Bureaucrat::_min_grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return ;
}



Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    *this = other;
    COUT << "call copy constructor Bureaucrat: " << _name << ENDL;
}



Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &other)
{
    //_name = const_cast<std::string *>(other)._name;
    _grade = other._grade;
    COUT << "call copy assignment constructor Bureaucrat: " << _name << ENDL;
    return (*this) ;
}



Bureaucrat::~Bureaucrat(void)
{
    COUT << "call destructor Bureaucrat: " << _name << ENDL;
    return ;
}



std::string const   Bureaucrat::getName(void) const
{
    return (_name);
}



int Bureaucrat::getGrade(void) const
{
    return (_grade);
}




void    Bureaucrat::incrementGrade(void)
{
    try
    {
        if (_grade == Bureaucrat::_max_grade)
        {
            throw GradeTooHighException();   
        }
        else
        {
            _grade--;
        }
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << e.what() << ENDL;
    }
}
void    Bureaucrat::decrementGrade(void)
{
    try
    {
        if (_grade == Bureaucrat::_min_grade)
        {
            throw GradeTooLowException();   
        }
        else
        {
            _grade++;
        }
    }
    catch (GradeTooLowException &e)
   {
        std::cerr << e.what() << ENDL;
    }
}



int    Bureaucrat::getMaxGrade(void)
{
    return (_max_grade);
}


int   Bureaucrat::getMinGrade(void)
{
    return (_min_grade);
}



void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        if (f.getSignState() == true)
        {
            COUT << this->_name << " signed " << f.getName() << ENDL;
        }
    }
    catch( Form::GradeTooLowException& e)
    {
        BUREAUCRAT_EXCEPTION_MSG(f,e);
        //CERR << this->_name << " couldn't signed " 
        //     << f.getName() << " because " 
        //     << e.what() << ENDL;
    }
    catch ( Form::GradeTooHighException &e)
    {
        BUREAUCRAT_EXCEPTION_MSG(f,e);
     //   CERR << this->_name << " couldn't signed " 
     //        << f.getName() << " because " 
     //        << e.what() << ENDL;
    }
    catch ( std::exception &e)
    {
        BUREAUCRAT_EXCEPTION_MSG(f,e);
     //   CERR << this->_name << " couldn't signed " 
     //        << f.getName() << " because " 
     //        << e.what() << ENDL;
        
    }
}



std::ostream    &operator<<(std::ostream &o, Bureaucrat const &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (o);
}