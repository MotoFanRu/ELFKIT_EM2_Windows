#ifndef APP_H
#define APP_H

//Must be always included!
#include <apps.h>
#include <loader.h>

//Another includes...
#include <dl.h>
#include <uis.h>
#include <java.h>
#include <filesystem.h>
#include <resources.h>
#include <utilities.h>

const WCHAR *icons[6] =
{
    L"restart.gif",
    L"turn_off.gif",
    L"lock_keyb.gif",
    L"apps.gif",
    L"end_java.gif"
};

typedef enum
{
    APP_STATE_ANY,
    APP_STATE_INIT,
    APP_STATE_MAIN,
    APP_STATE_MAX
} APP_STATES_T;

typedef struct
{
    APPLICATION_T apt;

    BOOL isShow;    		// ����� ������ (FALSE - �������, TRUE - �� �������)
    UINT32 EntriesNum;		// ���-�� ������� ����
    LIST_ENTRY_T* plist;	// ������ ������� ����
    LIST_IMAGE_ELEMENT_T* ilist;
} APP_T;
#define thisapp(app) ((APP_T *)(app))

//Enry, Start, End functions
UINT32 ELF_Entry    (ldrElf *ela, WCHAR *params);
UINT32 ELF_Start	(EVENT_STACK_T *ev_st, REG_ID_T reg_id, REG_INFO_T *reg_info);
UINT32 ELF_Exit		(EVENT_STACK_T *ev_st, APPLICATION_T *app);

//Change background/focus modes
UINT32 ELF_ChangeRStack (EVENT_STACK_T *ev_st, APPLICATION_T *app, BOOL show);
UINT32 ELF_APPShow (EVENT_STACK_T *ev_st, APPLICATION_T *app);
UINT32 ELF_APPHide (EVENT_STACK_T *ev_st, APPLICATION_T *app);

UINT32 MainStateEnter (EVENT_STACK_T *ev_st, APPLICATION_T *app, ENTER_STATE_TYPE_T type);
UINT32 HandleSelect (EVENT_STACK_T *ev_st, APPLICATION_T *app);
UINT32 HandlePowerDown (EVENT_STACK_T *ev_st, APPLICATION_T *app);
UINT32 HandleUITokenGranted (EVENT_STACK_T *ev_st, APPLICATION_T *app);

//utils
UINT32 Util_MakeItems (LIST_ENTRY_T *plist, LIST_IMAGE_ELEMENT_T *ilist, UINT32 num);
BOOL   Util_isKeypadLock (void);
#endif
