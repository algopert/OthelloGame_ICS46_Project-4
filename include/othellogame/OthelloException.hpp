// OthelloException.hpp
//
// ICS 46 Winter 2022
// Project #3: Black and White
//
// An exception that is thrown by OthelloGameState when, for example,
// invalid moves are made.

#ifndef OTHELLOEXCEPTION_HPP
#define OTHELLOEXCEPTION_HPP

#include <string>



class OthelloException
{
public:
    explicit OthelloException(const std::string& reason);
    const std::string& reason() const;


private:
    std::string reason_;
};



inline OthelloException::OthelloException(const std::string& reason)
    : reason_{reason}
{
}


inline const std::string& OthelloException::reason() const
{
    return reason_;
}



#endif

