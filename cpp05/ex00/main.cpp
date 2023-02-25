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
# define INFO(TXT,OBJ) \
    COUT << "\033[0;33mTEST: "#TXT" " <<  OBJ.getName() << " has grade: " \
         << OBJ.getGrade() << "\033[0m" <<ENDL;  



int main(void)
{
    COUT << ENDL;
    Bureaucrat p("peter", 200);
    INFO(INSTANTIATION_TOO_LOW, p);


    COUT << ENDL;
    Bureaucrat k("kitana", 0);
    INFO(INSTANTIATION_TOO_HIGH, k);
    
    
    COUT << ENDL;
    Bureaucrat m("michael", 1);
    INFO(INCREMENT,m);
    m.incrementGrade();
    

    COUT << ENDL;
    Bureaucrat g("george", 150);
    INFO(DECREMENT,g);
    g.decrementGrade();
    

    COUT << ENDL;
    Bureaucrat s("smith", 43);
    INFO(BEFORE_INCREMENT,s);
    s.incrementGrade();
    INFO(AFTER_INCREMENT,s);

    COUT << ENDL;
    INFO(BEFORE_DECREMENT,s);
    s.decrementGrade();
    INFO(AFTER_DECREMENT,s);
    
    COUT << ENDL;
    INFO(OVERLOADED_STREAM_INSERTION, s);
    COUT << s << ENDL << ENDL;
    return 0;
}