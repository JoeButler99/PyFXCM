#include "LoginParams.h"


const std::set<std::string> LoginParams::sConnectionTypes {"Real","Demo"};
LoginParams::~LoginParams(void){}

LoginParams::LoginParams(std::string Login,
			std::string Password,
			std::string Connection,
			std::string URL)
: mLogin(Login), mPassword(Password), mURL(URL)
{
	if(sConnectionTypes.find(Connection) != sConnectionTypes.end()) {
		mConnection = Connection;
	} else {
		char msg[200];
		sprintf(msg,"Unknown connection type: %s",Connection.c_str());
		throw FXCMAPIException(msg,1,__func__,__FILE__,__LINE__);
	}
}


const char *LoginParams::getLogin()
{
    return mLogin.c_str();
}

const char *LoginParams::getPassword()
{
    return mPassword.c_str();
}

const char *LoginParams::getURL()
{
    return mURL.c_str();
}

const char *LoginParams::getConnection()
{
    return mConnection.c_str();
}

