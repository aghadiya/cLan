#include "linklist.h"


static int app_get_user_input(void);
static void app_err_chk(LINKLIST_RET eRet, char *pFunctionName);

int main()
{
	struct linklist oLinklist;
	LINKLIST_RET eRet;
	int nIp;
	int nData, nPos;

	eRet = linklist_init(&oLinklist, LINKLIST_SIZE);
	app_err_chk(eRet,"linklist_init");

	nIp = app_get_user_input();
	printf("APP>%d",nIp);
	while(nIp != 9)
	{
		switch(nIp)
		{
			case 1:
				printf("\n\rAPP> Enter data:");
				scanf("%d",&nData);
				eRet = linklist_append(&oLinklist,nData);
				app_err_chk(eRet,"linklist_append");
				break;
			case 2:
				printf("\n\rAPP> Enter data:");
				scanf("%d",&nData);
				eRet = linklist_addAtBeg(&oLinklist,nData);
				app_err_chk(eRet,"linklist_addAtBeg");
				break;
			case 3:
				printf("\n\rAPP> Enter data:");
				scanf("%d",&nData);
				printf("\n\rAPP> Enter position:");
				scanf("%d",&nPos);
				eRet = linklist_addAfter(&oLinklist,nData,nPos);
				app_err_chk(eRet,"linklist_addAfter");
				break;
			case 4:
				eRet = linklist_display(&oLinklist);
				app_err_chk(eRet,"linklist_display");
				break;
			case 5:
				printf("\n\rAPP> Enter data:");
				scanf("%d",&nData);
				eRet = linklist_delete(&oLinklist,nData);
				app_err_chk(eRet,"linklist_delete");
				break;
			default:
				printf("\n\rAPP> Invalid choice.");
				break;
		}
		nIp = app_get_user_input();
	}
	
return(0);
}

static int app_get_user_input(void)
{
	int nInput = 0;
	printf("\n\rAPP>Enter 1 to append");
	printf("\n\rAPP>Enter 2 to add at beggining");
	printf("\n\rAPP>Enter 3 to add after");
	printf("\n\rAPP>Enter 4 to display");
	printf("\n\rAPP>Enter 5 to delete");
	printf("\n\rAPP>Enter 9 to exit");
	printf("\n\rAPP>Input:");
	scanf("%d",&nInput);
return(nInput);
}


static void app_err_chk(LINKLIST_RET eRetCode, char *pFunctionName)
{
	if(eRetCode == LINKLIST_PASS)
	{
		printf("\n\rAPP> %s() returned with success.", pFunctionName);
	}
	else
	{
		printf("\n\rAPP> %s() retunred with error.Error Code %d", pFunctionName, eRetCode);
	}
}
