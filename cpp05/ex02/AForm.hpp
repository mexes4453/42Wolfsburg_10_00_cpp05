/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/17 00:18:58 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define COUT std::cout
# define ENDL std::endl
# define AFORM_COL_BLUE "\033[0;34m"
# define AFORM_COL_YELLOW "\033[0;33m"
# define AFORM_COL_MAGENTA "\033[0;35m"
# define AFORM_COL_DEFAULT "\033[0m"
# define AFORM_MSG_EXECUTE(TARGET_OBJ,MSG1,MSG2) COUT << AFORM_COL_BLUE \
MSG1 << TARGET_OBJ.getName() << MSG2 AFORM_COL_DEFAULT << ENDL;  


class Bureaucrat;

class AForm
{
    protected:
        std::string const   _name;
        bool                _state_sign;
        int const           _grade_sign;
        int const           _grade_exec;
        static int const    _min_grade;
        static int const    _max_grade;


    public:
        AForm(void);
        AForm(std::string const name, int const signGrade, int const signExec);
        AForm(AForm const &other);
        AForm  &operator=(AForm const &other);
        virtual ~AForm(void);
        std::string const   getName(void) const;
        bool                getSignState(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        void                beSigned(Bureaucrat &b);
        bool                checkFormExecGrade(Bureaucrat const &b) const;
        virtual void        execute(Bureaucrat const &executor) const = 0;
        
        /*------------ EXCEPTION ----------------------*/
        class GradeTooHighException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &o, AForm const &f);

#endif