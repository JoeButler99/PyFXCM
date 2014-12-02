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

    const char *getLogin();
    const char *getPassword();
    const char *getURL();
    const char *getConnection();

private:
    std::string mLogin;
    std::string mPassword;
    std::string mURL;
    std::string mConnection;
    static const std::set<std::string> sConnectionTypes;
};

