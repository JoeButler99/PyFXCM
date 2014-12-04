#pragma once
#include "stdafx.h"

class LoginParams
{
public:

    LoginParams(std::string Login,
    		    std::string Password,
    			std::string Connection = "Real",
    			std::string URL = "http://www.fxcorporate.com/Hosts.jsp");
    ~LoginParams(void);

    const char *getLogin() const;
    const char *getPassword() const;
    const char *getURL() const;
    const char *getConnection() const;

private:
    const std::string mLogin;
    const std::string mPassword;
    const std::string mURL;
    const std::string mConnection;
    static const std::set<std::string> sConnectionTypes;
};

