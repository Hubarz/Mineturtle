#include "main.h"
#include "misc.h"
std::string misc::randString(int chars) {
	char val_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVFXYZ1234567890";
	std::string out;
	for(int i=0; i<chars; i++) out+=(&val_chars[rand()%sizeof(chars)]);
	return (out);
}

std::string misc::randBrowser() {
	std::vector<std::string> agents;
	agents.push_back("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:15.0) Gecko/20120427 Firefox/15.0a1");
	agents.push_back("Mozilla/5.0 (compatible; Windows; U; Windows NT 6.2; WOW64; en-US; rv:12.0) Gecko/20120403211507 Firefox/12.0");
	agents.push_back("Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.16) Gecko/20120421 Gecko Firefox/11.0");
	agents.push_back("Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:14.0) Gecko/20120405 Firefox/14.0a1");
	agents.push_back("Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; WOW64; Trident/6.0)");
	agents.push_back("Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; Trident/4.0; InfoPath.2; SV1; .NET CLR 2.0.50727; WOW64)");
	agents.push_back("Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; Media Center PC 6.0; InfoPath.3; MS-RTC LM 8; Zune 4.7)");
	agents.push_back("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1063.0 Safari/536.3");
	agents.push_back("Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/536.5 (KHTML, like Gecko) Chrome/19.0.1084.9 Safari/536.5");
	agents.push_back("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.1 Safari/536.3");
	agents.push_back("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_3) AppleWebKit/535.22 (KHTML, like Gecko) Chrome/19.0.1047.0 Safari/535.22");
	agents.push_back("Opera/9.80 (Macintosh; Intel Mac OS X 10.6.8; U; de) Presto/2.9.168 Version/11.52");
	agents.push_back("Opera/9.80 (Windows NT 6.1; U; es-ES) Presto/2.9.181 Version/12.00");
	return (agents[rand()%agents.size()]);
}

std::string misc::randIp() {
	std::string out;
	for(int i=0; i<4; i++) out+=(rand()%255+1);
	return out;
}