/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:26:58 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/04 17:35:13 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) 
: AForm("ShrubberyCreationForm", SHRUBBERY_GRADE_SIGN, SHRUBBERY_GRADE_EXEC),
_target("land")
{
    COUT << "call default constructor ShrubberyCreationForm: " << _name << ENDL;
    return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
: AForm("ShrubberyCreationForm", SHRUBBERY_GRADE_SIGN, SHRUBBERY_GRADE_EXEC),
_target(target)
{
    COUT << "call parametric constructor ShrubberyCreationForm: " << _name << ENDL;
}



ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
: AForm(other)
{
    *this = other;
    COUT << "call copy constructor ShrubberyCreationForm: " << _name << ENDL;
}



ShrubberyCreationForm  &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    this->_state_sign = other._state_sign;
    COUT << "call copy assignment constructor ShrubberyCreationForm: " << _name << ENDL;
    return (*this) ;
}



ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    COUT << "call destructor ShrubberyCreationForm: " << _name << ENDL;
    return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
    std::ofstream xFileStream;
    std::ostringstream xFileName;
    try
    {
        checkFormExecGrade(b);
        xFileName << _target << "_shrubbery"; /* Populate filename */

        xFileStream.open((xFileName.str()).c_str(), std::ios::out);
        xFileStream << "         *             \n"
                    << "       /*|*\\          \n"
                    << "      /**|**\\   *     \n"
                    << "     /***|***\\ ***    \n"
                    << "    /****|****\\ ***   \n"
                    << "    -----|----- ****  \n"
                    << "         |      |     \n"
                    << "        /|\\     |     \n";
        xFileStream.close();
        COUT << AFORM_COL_BLUE "Create a file " << _target
         << "_shrubbery in the working directory and, writes ASCII trees inside it"
         << AFORM_COL_DEFAULT << ENDL;
        COUT << AFORM_COL_BLUE << b.getName() << " executed " << _name
        << AFORM_COL_DEFAULT << ENDL;
    }
    catch(AForm::GradeTooHighException &e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
    catch(AForm::GradeTooLowException &e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
    catch(const std::exception& e)
    {
        CERR << AFORM_COL_BLUE << b.getName() << " couldn't execute " << _name
        << " because " << e.what() << AFORM_COL_DEFAULT << ENDL;
    }
    //AFORM_MSG_EXECUTE(b,SHRUBBERY_MSG1,SHRUBBERY_MSG2);
}

std::ostream    &operator<<(std::ostream &o, ShrubberyCreationForm const &f)
{
    o << "FORM NAME:  " << f.getName() << ENDL
      << "SIGN GRADE: " << f.getSignGrade() << ENDL
      << "EXEC GRADE: " << f.getExecGrade() << ENDL
      << "SIGN STATE: " << f.getSignState() << ENDL;
    return (o);
}
