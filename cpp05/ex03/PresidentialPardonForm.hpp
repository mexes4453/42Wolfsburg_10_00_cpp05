/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/04 01:23:06 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include <fstream>
# include <sstream>
# include "Form.hpp"

# define PRESIDENTIAL_GRADE_SIGN (25)
# define PRESIDENTIAL_GRADE_EXEC (5)
# define PRESIDENTIAL_MSG1 " has been pardoned by zaphod Beeblebrox."

class Bureaucrat;

class PresidentialPardonForm : public Form
{
    private:
        std::string const _target;


    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm  &operator=(PresidentialPardonForm const &other);
        virtual ~PresidentialPardonForm(void);
        
        void execute(Bureaucrat const &b) const;
        /*------------ EXCEPTION ----------------------*/
        class GradeTooHighException : public std::exception
        {
            public:
                virtual char const *what() const throw()
                {
                    return ("Error! Grade is too high");
                }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const *what() const throw()
                {
                    return ("Error! Grade is too low");
                }

        };
};

std::ostream    &operator<<(std::ostream &o, PresidentialPardonForm const &f);

#endif