/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/03 14:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string>
# include <iostream>

class Base
{
	protected:
		std::string _type;
	public:
		Base();
		virtual ~Base();

		static Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

#endif
