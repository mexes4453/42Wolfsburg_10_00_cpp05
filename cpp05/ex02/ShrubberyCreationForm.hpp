/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/05 11:33:25 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include <fstream>
# include <sstream>
# include "AForm.hpp"

# define SHRUBBERY_GRADE_SIGN (145)
# define SHRUBBERY_GRADE_EXEC (137)
# define SHRUBBERY_MSG1 "Create a file "
# define SHRUBBERY_MSG2 "_shrubbery in the working directory,\
 and writes ASCII trees inside it"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const _target;


    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm  &operator=(ShrubberyCreationForm const &other);
        virtual ~ShrubberyCreationForm(void);
        
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

std::ostream    &operator<<(std::ostream &o, ShrubberyCreationForm const &f);

#endif