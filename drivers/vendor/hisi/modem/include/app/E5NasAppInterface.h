

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#ifndef _E5NASAPPINTERFACE_H_
#define _E5NASAPPINTERFACE_H_


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/

/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/



/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
  8 UNION定义
*****************************************************************************/

/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

/*****************************************************************************
  10 函数声明
*****************************************************************************/

typedef int  (*pAppComRecv)(unsigned char  ucPortNo, unsigned char* pucData, unsigned short uslength);


/*****************************************************************************
 函 数 名  :  E5_APP_RegCallBack
 功能描述  : 提供给应用注册回调指针,APP向协议栈注册发送数据的函数指针,同时通知协议栈接收数据的指针
 输入参数  :  uPortNo：串口实例号。
              pRcvCallback : APP接收数据的函数指针
 输出参数  :  pCallback   :APP发送数据到协议栈的函数指针
 返回值     :  0:注册成功
               1:注册失败
*****************************************************************************/
extern int  E5_APP_RegCallBack(unsigned char  ucPortNo, pAppComRecv pRcvCallback ,pAppComRecv *pSendCallback);
#define APP_E5_APP_REG_CALLBACK(ucPortNo,pRcvCallback,pSendCallback)   E5_APP_RegCallBack(ucPortNo,pRcvCallback,pSendCallback)


extern int E5_com_get_status(unsigned char no);
#define APP_E5_COM_GET_STATUS(no)   E5_com_get_status(no)

/* 提供手机模式给APP */
#define MN_PH_MODE_MINI                 0   /* minimum functionality*/
#define MN_PH_MODE_FULL                 1   /* full functionality */
#define MN_PH_MODE_TXOFF                2   /* disable phone transmit RF circuits only */
#define MN_PH_MODE_RXOFF                3   /* disable phone receive RF circuits only */
#define MN_PH_MODE_RFOFF                4   /* disable phone both transmit and receive RF circuits */
#define MN_PH_MODE_FT                   5   /* factory-test functionality */
#define MN_PH_MODE_LOWPOWER             7

extern unsigned char MN_PH_AppQryPhMode (void);
#define APP_MN_PH_AppQryPhMode() MN_PH_AppQryPhMode()

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

