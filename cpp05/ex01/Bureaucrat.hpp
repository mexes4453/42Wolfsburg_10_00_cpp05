/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/05 05:12:37 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"


# define COUT std::cout
# define CERR std::cerr
# define ENDL std::endl


class Form;
class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
        static int const _max_grade;
        static int const _min_grade;


    public:
        Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat  &operator=(Bureaucrat const &other);
        ~Bureaucrat(void);
        std::string const   getName(void) const;
        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);
        static int          getMaxGrade(void);
        static int          getMinGrade(void);
        void                signForm(Form &f);
        
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

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &b);

#endif