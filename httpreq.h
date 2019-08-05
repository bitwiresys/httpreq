#ifndef _HTTP_REQ_H
#define _HTTP_REQ_H


#include <Windows.h>
#include <WinInet.h>

#pragma comment(lib,"wininet.lib")

class httpreq {

private:
	LPSTR m_Site_Url = (LPSTR)"google.com";
	LPSTR m_Site_Page = (LPSTR)"/";
	LPSTR m_UserAgent = (LPSTR)"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36";
	LPSTR m_method = (LPSTR)"GET";
	LPSTR m_Header = NULL;
	LPSTR m_PostData = NULL;
	LPSTR m_GetData = NULL;
	HINTERNET m_hInternet;
	HINTERNET m_hConnect;
	HINTERNET m_hRequest;


public:
	HINTERNET _initWinInet(LPSTR m_UserAgent);
	HINTERNET _OpenHttpConnect(LPSTR m_Site_Url, HINTERNET m_hInternet);
	HINTERNET Post(HINTERNET m_hConnect);
	HINTERNET Get(HINTERNET m_hConnect);

	LPSTR sendGetRequest(LPSTR host, LPSTR param);
	LPSTR sendRequest();
	LPSTR getData(HINTERNET m_hRequest);

	void closeHandle();

	void setSiteUrl(LPSTR SiteUrl);
	void setUserAgent(LPSTR UserAgent);
	void setRequestMethod(LPSTR method);
	void setSitePage(LPSTR page);
	void setheader(LPSTR header);
	void setPostData(LPSTR PostData);
	void setGetData(LPSTR GetData);



};
#endif