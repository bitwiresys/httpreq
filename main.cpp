#include <iostream>
#include "httpreq.h"
httpreq r;
int main()
{
	//GET request example
	std::cout << r.sendGetRequest((LPSTR)"yoursi.te", (LPSTR)"patch/phpscript.php?param=data") << std::endl;
	system("pause");
	return 0;
}
