/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:59:50 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/06 22:08:37 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Form.hpp"
# include <unistd.h>
# define SHOW_MSG(FORM_OBJ) COUT << AFORM_COL_MAGENTA "Intern creates " \
<< FORM_OBJ->getName() << AFORM_COL_DEFAULT << ENDL;

enum e_InternForm
{
    Intern_ShrubberyCreationForm,
    Intern_RobotomyRequestForm,
    Intern_PresidentialPardonForm,
    /* Max form */
    Intern_MaxFormCnt
};

typedef struct s_InternForm
{
    enum e_InternForm   formIdx;
    std::string const   formName;
}   t_InternForm;

t_InternForm  const tstForms[] =
{
    { Intern_ShrubberyCreationForm , "Shrubbery Form" },
    { Intern_RobotomyRequestForm   , "Robotomy Form" },
    { Intern_PresidentialPardonForm, "Presidential Form" }
};

class Intern
{
    public:
        Intern( void );
        Intern( Intern const &rhs );
        ~Intern( void );
        Form    *makeForm(std::string const formName, std::string const target);

};


#endif  // INTERN_HPP