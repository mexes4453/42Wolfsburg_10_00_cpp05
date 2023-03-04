/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:18:36 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/17 00:2 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdint.h>

# define INFO(TXT,OBJ) \
    COUT << AFORM_COL_YELLOW "TEST: "#TXT" " <<  OBJ.getName() << " has grade: " \
         << OBJ.getGrade() << "\033[0m" <<ENDL;  


void    setGrade(uint8_t grade, Bureaucrat &b);

int main(void)
{
    COUT << ENDL;
//  Shrubbery Creation form
    COUT << ENDL << ENDL << AFORM_COL_MAGENTA " === SHRUBBERY CREATION FORM ==="
         << AFORM_COL_DEFAULT << ENDL;
    Bureaucrat p("peter", 137);
    //INFO(INSTANTIATION_TOO_LOW, p);

    COUT << ENDL;
    INFO(SIGN_FORM,p);
    ShrubberyCreationForm s1("plant");
    p.signForm(s1);

    INFO(EXECUTE_FORM,p);
    p.executeForm(s1);
    COUT << s1 << ENDL;


    COUT << ENDL;
    Bureaucrat k("kitana", 145);
    //INFO(INSTANTIATION_TOO_HIGH, k);
    
    COUT << ENDL;
    INFO(SIGN_FORM,k);
    k.signForm(s1);
    INFO(EXECUTE_FORM,k);
    k.executeForm(s1);
    COUT << s1 << ENDL;

    
    COUT << ENDL;
    Bureaucrat m("michael", 137);
    COUT << ENDL;
    INFO(SIGN_FORM,m);
    m.signForm(s1);
    INFO(EXECUTE_FORM,m);
    m.executeForm(s1);
    COUT << s1 << ENDL;


//  RobotomyRequest form
    COUT << ENDL << ENDL << AFORM_COL_MAGENTA " === ROBOTOMY REQUEST FORM ==="
         << AFORM_COL_DEFAULT << ENDL;
    RobotomyRequestForm r1("prisoner");
    Bureaucrat g("george", 150);
    INFO(DECREMENT,g); g.decrementGrade();
    INFO(SIGN_FORM,g); g.signForm(r1);
    INFO(EXECUTE_FORM,g); g.executeForm(r1);
    setGrade(71, g);
    INFO(SIGN_FORM,g); g.signForm(r1);
    setGrade(72, g);
    INFO(SIGN_FORM,g); g.signForm(r1);
    INFO(EXECUTE_FORM,g); g.executeForm(r1);
    setGrade(44, g);
    INFO(EXECUTE_FORM,g); g.executeForm(r1);
    setGrade(45, g);
    INFO(EXECUTE_FORM,g); g.executeForm(r1);
    COUT << r1 << ENDL;

    

//  Presidential pardon form

    COUT << ENDL << ENDL << AFORM_COL_MAGENTA " === PRESIDENTIAL PARDON FORM ==="
         << AFORM_COL_DEFAULT << ENDL;

    PresidentialPardonForm p1("war crime offenders");
    Bureaucrat s("smith", 0);
    INFO(DECREMENT,s); s.incrementGrade();
    INFO(SIGN_FORM,s); s.signForm(p1);
    INFO(EXECUTE_FORM,s); s.executeForm(p1);
    setGrade(27, s);
    INFO(SIGN_FORM,s); s.signForm(p1);
    setGrade(25, s);
    INFO(SIGN_FORM,s); s.signForm(p1);
    INFO(EXECUTE_FORM,s); s.executeForm(p1);
    setGrade(5, s);
    INFO(EXECUTE_FORM,s); s.executeForm(p1);
    COUT << p1 << ENDL << ENDL;

    return 0;
}


/**
 * @brief 
 * This function is used to increment or decrement the grades of bureaucrats
 * 
 * @param grade 
 * @param b 
 * @return 
 */
void    setGrade(uint8_t grade, Bureaucrat &b)
{

    if (b.getGrade() > grade)
    {
        while (b.getGrade() > grade)
        {
            b.incrementGrade();
        }
    }
    else 
    {
        while (b.getGrade() < grade)
        {
            b.decrementGrade();
        }
    }
}