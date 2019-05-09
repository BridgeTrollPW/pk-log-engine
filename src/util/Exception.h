#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception
{
        private:
                std::string message;
                int code;

        public:
                Exception();
                Exception(std::string message);
                Exception(std::string message, int code) :
                                message(message), code(code)
                {
                }

                std::string getMessage() const;
                void setMessage(std::string);

                int getCode() const;
                void setCode(int code);

                enum ExceptionCode
                {
                        INVALID_LOG_FILE = 90,
                        INVALID_CONFIG_FILE = 91,
                        INVALID_ENGINE_FUNCTION = 92,

                        NO_SEARCHTERMS_PRESENT = 200

                };

};

#endif /* EXCEPTION_H */
