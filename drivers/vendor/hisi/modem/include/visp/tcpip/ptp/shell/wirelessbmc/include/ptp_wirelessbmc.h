
#ifndef _PTP_BMC_H_
#define _PTP_BMC_H_

/*addtional header files*/
#include "ptp/cbb/include/ptp_inc.h"

#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
*Func Name   : PTP_Shell_CompareClockQuality
*Description : 时钟质量比较函数
*Input       : pstPtpPort      时钟端口指针 
               pstForeMasterA  需比较时钟质量的foreignmaster结构的指针
               pstForeMasterB  需比较时钟质量的foreignmaster结构的指针
*Output      : N/A
*Return      : 成功返回PTP_OK，失败返回错误码
*Caution     :
*Calls       :
*Called by   :
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME               DESCRIPTION
*
*******************************************************************************/
ULONG PTP_Shell_CompareClockQuality(PTP_PORT_S *pstPtpPort,
                                    PTP_FOREIGN_MASTER_S *pstForeMasterA,
                                    PTP_FOREIGN_MASTER_S *pstForeMasterB);

/******************************************************************************
*Func Name   : PTP_Shell_IsForeMasterValid
*Description : 时钟有效性判断函数
*Input       : pstForeMaster  需判断时钟有效性的foreignmaster结构的指针               
*Output      : N/A
*Return      : 成功返回PTP_OK，失败返回错误码PTP_ERR_BMC_MASTER_INVALID
*Caution     :
*Calls       :
*Called by   :
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME               DESCRIPTION
*
*******************************************************************************/
ULONG PTP_Shell_IsForeMasterValid(PTP_FOREIGN_MASTER_S *pstForeMaster);

/******************************************************************************
*Func Name   : PTP_Shell_BMC
*Description : 定制选源函数
*Input       : pstPtpPort      时钟端口指针                
*Output      : *pulRecommendState   返回给调用者的推荐状态
*Return      : 成功返回PTP_OK，失败返回错误码
*Caution     :
*Calls       :
*Called by   :
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME               DESCRIPTION
*
*******************************************************************************/
ULONG PTP_Shell_BMC(PTP_PORT_S *pstPtpPort, ULONG *pulRecommendState);

#ifdef __cplusplus
}
#endif
#endif /*_PTP_BMC_H_*/
