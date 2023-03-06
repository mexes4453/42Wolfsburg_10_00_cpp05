/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:59:52 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/06 22:13:54 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern( void )
{
    COUT << "Calling default constructor : Intern\n";
}


Intern::Intern( Intern const &rhs )
{
    COUT << "Calling copy constructor : Intern\n";
    *this = rhs;
}

Intern::~Intern( void )
{
    COUT << "Calling destructor : Intern\n";
}

Form    *Intern::makeForm( std::string const formName, std::string const target)
{
    Form *f = NULL;
    int idx;
    
    for (idx=0; idx != Intern_MaxFormCnt; idx++)
    {
        if (tstForms[idx].formName == formName) break;
    }
    switch (idx)
    {
        case Intern_ShrubberyCreationForm:
            f = new ShrubberyCreationForm(target);
            SHOW_MSG(f);
            break ;
        case Intern_RobotomyRequestForm:
            f = new RobotomyRequestForm(target);
            SHOW_MSG(f);
            break ;
        case Intern_PresidentialPardonForm:
            f = new PresidentialPardonForm(target);
            SHOW_MSG(f);
            break ;
        default :
            COUT << AFORM_COL_MAGENTA "Error! Form does not exist.\n"\
            AFORM_COL_DEFAULT;
            break ;
    }
    return (f);
}

