/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/17 00:18:58 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define COUT std::cout
# define ENDL std::endl

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _state_sign;
        int const           _grade_sign;
        int const           _grade_exec;
        static int const    _min_grade;
        static int const    _max_grade;


    public:
        Form(void);
        Form(std::string const name, bool state, int const signGrade, \
                                                int const signExec);
        Form(Form const &other);
        Form  &operator=(Form const &other);
        ~Form(void);
        std::string const   getName(void) const;
        bool                getSignState(void) const;
        int                 getSignGrade(void) const;
        int                 getExecGrade(void) const;
        void                beSigned(Bureaucrat &b);
        
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

std::ostream    &operator<<(std::ostream &o, Form const &f);

#endif