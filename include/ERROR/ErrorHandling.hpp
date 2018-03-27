/*
** EPITECH PROJECT, 2018
** ErrorHandling
** File description:
** .hpp
*/

#ifndef ERRORHANDLING_HPP_
# define ERRORHANDLING_HPP_

# include <exception>
# include <string>

namespace errHand {

	#undef ERR
	#undef OK
	const char ERR = 84;
	const char OK = 0;
	const char ARGS_REQUIRED = 2;
	const std::string ERR_MAIN = "[ERROR]: command not found! retry please";

	class Error: public std::exception {
		public:
			virtual const char* what() const throw();
			Error(std::string const& msg="") throw();
			virtual ~Error() throw();
		private:
		std::string _errMsg;
	};
}

#endif /* !ERRORHANDLING_HPP_ */
