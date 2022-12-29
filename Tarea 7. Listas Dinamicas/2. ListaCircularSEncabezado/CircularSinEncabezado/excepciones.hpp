#ifndef EXCEPCIONES_HPP_INCLUDED
#define EXCEPCIONES_HPP_INCLUDED

class Exception : public std::exception {

private:
    std::string msg;

public:
    explicit Exception(const char* message):msg(message) {}

    explicit Exception(const std::string& message) : msg(message) {}

    virtual ~Exception()throw() {}

    virtual const char* what() const throw () {

        return msg.c_str();
        }
};

#endif // EXCEPCIONES_HPP_INCLUDED
