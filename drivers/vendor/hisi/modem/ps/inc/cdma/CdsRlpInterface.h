/*******************************************************************************
  Copyright   : 2014-2019, Huawei Tech. Co., Ltd.
  File name   : RlpCdsInterface.h
  Version     : 
  Date        : 2014-10-22
  Description :
  History     :
  1. Date:2014-10-22
     Author: liukai
     Modification:Create
*******************************************************************************/

#ifndef _RLP_CDS_INTERFACE_H_
#define _RLP_CDS_INTERFACE_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "cds_1x_rlp_pif.h"
#include "cttf_1x_rrlp_data_pif.h"

/*****************************************************************************
  2 消息头定义
*****************************************************************************/

/*****************************************************************************
  3 宏定义
*****************************************************************************/



/*****************************************************************************
  4 消息定义
*****************************************************************************/
#pragma pack(4)



/*****************************************************************************
  5 STRUCT定义
*****************************************************************************/





/*****************************************************************************
  6 UNION定义
*****************************************************************************/


/*****************************************************************************
  7 全局变量声明
*****************************************************************************/

/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of CdsRlpInterface.h */

