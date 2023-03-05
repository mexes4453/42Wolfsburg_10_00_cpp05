/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/05 11:33:13 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include <fstream>
# include <sstream>
# include "AForm.hpp"

# define ROBOTOMY_GRADE_SIGN (72)
# define ROBOTOMY_GRADE_EXEC (45)
# define ROBOTOMY_MSG1 "Make some drilling sound."
# define ROBOTOMY_MSG2 " has been robotomized successfully 50% of the time"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string const _target;


    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm  &operator=(RobotomyRequestForm const &other);
        virtual ~RobotomyRequestForm(void);
        
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

std::ostream    &operator<<(std::ostream &o, RobotomyRequestForm const &f);

#endif