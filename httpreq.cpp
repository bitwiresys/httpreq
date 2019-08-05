#include "httpreq.h"

LPSTR httpreq::sendGetRequest(LPSTR host, LPSTR param)
{
	setSiteUrl(host);
	setGetData(param);
	setRequestMethod((LPSTR)"GET");
	return sendRequest();
}

LPSTR httpreq::sendRequest() 
{
	httpreq::m_hInternet = _initWinInet(httpreq::m_UserAgent);
	httpreq::m_hConnect = _OpenHttpConnect(m_Site_Url, m_hInternet);
	if (httpreq::m_method = (LPSTR)"Get")
		httpreq::m_hRequest = Get(httpreq::m_hConnect);
	else
		httpreq::m_hRequest = Post(httpreq::m_hConnect);

	LPSTR Data = getData(httpreq::m_hRequest);

	return Data;
}

HINTERNET httpreq::_initWinInet(LPSTR m_UserAgent) {

	HINTERNET m_hInternet = InternetOpen(m_UserAgent,INTERNET_OPEN_TYPE_PRECONFIG,NULL, NULL,0);
	return m_hInternet;
}

HINTERNET httpreq::_OpenHttpConnect(LPSTR m_Site_Url, HINTERNET m_hInternet) {

	HINTERNET hConnect = InternetConnect(m_hInternet,m_Site_Url,INTERNET_DEFAULT_HTTP_PORT,NULL, NULL,INTERNET_SERVICE_HTTP,0,1u);
	return hConnect;
}

HINTERNET httpreq::Post(HINTERNET m_hConnect) 
{
	HINTERNET hRequest = HttpOpenRequest(m_hConnect,TEXT("POST"),NULL,NULL,NULL,0,INTERNET_FLAG_KEEP_CONNECTION,1);
	return hRequest;
}

HINTERNET httpreq::Get(HINTERNET m_hConnect) 
{
	HINTERNET hRequest = HttpOpenRequest(m_hConnect,TEXT("GET"),m_GetData,NULL,NULL,0,INTERNET_FLAG_KEEP_CONNECTION,1);
	return hRequest;
}

LPSTR httpreq::getData(HINTERNET m_hRequest) 
{
	HttpSendRequest(m_hRequest, httpreq::m_Header, 4096, httpreq::m_PostData, 4096);
	char  szData[8112];
	DWORD dwBytesRead;
	BOOL bRead = InternetReadFile(m_hRequest,szData, sizeof(szData) - 1,&dwBytesRead);
	return szData;
}

void httpreq::setSiteUrl(LPSTR SiteUrl) 
{
	httpreq::m_Site_Url = SiteUrl;
}

void httpreq::setUserAgent(LPSTR UserAgent) 
{
	httpreq::m_UserAgent = UserAgent;
}

void httpreq::setRequestMethod(LPSTR method) 
{
	httpreq::m_method = method;
}

void httpreq::setSitePage(LPSTR page) 
{
	httpreq::m_Site_Page = page;
}

void httpreq::setheader(LPSTR header) 
{
	httpreq::m_Header = header;
}

void httpreq::setPostData(LPSTR PostData) 
{
	httpreq::m_PostData = PostData;
}
void httpreq::setGetData(LPSTR GetData) 
{
	httpreq::m_GetData = GetData;
}

void httpreq::closeHandle() 
{
	InternetCloseHandle(httpreq::m_hRequest);
	InternetCloseHandle(httpreq::m_hConnect);
	InternetCloseHandle(httpreq::m_hInternet);
}