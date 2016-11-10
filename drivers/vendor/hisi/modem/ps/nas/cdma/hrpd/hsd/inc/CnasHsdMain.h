
#ifndef _CNAS_HSD_MAIN_H_
#define _CNAS_HSD_MAIN_H_

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "PsCommonDef.h"
#include "PsTypeDef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

VOS_UINT32 CNAS_HSD_FsmProcessEvent(
    VOS_UINT32                          ulCurState,
    VOS_UINT32                          ulEventType,
    VOS_VOID                           *pRcvMsg
);

VOS_UINT32 CNAS_HSD_InitPid(
    enum VOS_INIT_PHASE_DEFINE         enInitPhase
);

VOS_UINT32  CNAS_HSD_InitTask(VOS_VOID);

VOS_VOID CNAS_HSD_MsgProc (struct MsgCB* pstMsg);

VOS_UINT32 CNAS_HSD_PreProcessMsg(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_VOID CNAS_HSD_ProcessHsdIntMsg(VOS_VOID);

VOS_VOID CNAS_HSD_ProcessBufferMsg(VOS_VOID);

VOS_UINT32 CNAS_HSD_ProcessMsgInFsm(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_VOID  CNAS_HSD_RegFsm(VOS_VOID);

VOS_UINT32 CNAS_HSD_RegL2Fsm(VOS_VOID);

VOS_UINT32 CNAS_HSD_RegMainL1Fsm(VOS_VOID);

VOS_UINT32 CNAS_HSD_RegPreFsm(VOS_VOID);

#endif

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif