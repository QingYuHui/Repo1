#include "SortOperate.h"

using namespace Sort;

int					SortOperate::p[200];
unsigned int		SortOperate::pLen = 0;
HANDLE				SortOperate::PMutex = NULL;
ESort				SortOperate::SortMethod = ESort::Select;